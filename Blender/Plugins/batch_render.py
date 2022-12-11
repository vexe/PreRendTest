import bpy
import os

bl_info = {
    "name": "Batch Render Cameras",
    "blender": (3, 1, 0),
    "category": "Object",
}

class BatchRender(bpy.types.Operator):
    """Iterates through all cameras in the scene rendering each one out to a file. Filename is the camera name. Folder output and file format are defined in the Output Properties"""
    bl_idname = "object.batch_render"
    bl_label = "Batch Render"

    def execute(self, context):

        path_dir = bpy.context.scene.render.filepath #save for restore

        for cam in [obj for obj in bpy.data.objects if obj.type == 'CAMERA']:
            bpy.context.scene.camera = cam
            bpy.context.scene.render.filepath = os.path.join(path_dir, cam.name)
            bpy.ops.render.render(write_still=True)
            bpy.context.scene.render.filepath = path_dir
        
        self.report({'INFO'}, "Batch render complete!")
            
        return {'FINISHED'}

class MY_PT_custom(bpy.types.Panel):
    """Creates a Batch Render panel in the Property Area of the 3D View"""
    bl_label = "Batch Render"
    bl_space_type = "VIEW_3D"
    bl_region_type = "UI"
    bl_category = "Tool"

    def draw(self, context):
        layout = self.layout

        row = layout.row()
        row.operator(BatchRender.bl_idname)
        layout.separator()

        #row = layout.row()
        #row.label(text="{} Objects in Selection".format(len(sel_objs)))

def menu_func(self, context):
    self.layout.operator(BatchRender.bl_idname, text=BatchRender.bl_label)

# Register and add to the "object" menu (required to also use F3 search "Simple Object Operator" for quick access)
def register():
    bpy.utils.register_class(MY_PT_custom)
    bpy.utils.register_class(BatchRender)
    bpy.types.VIEW3D_MT_object.append(menu_func)

def unregister():
    bpy.utils.unregister_class(MY_PT_custom)
    bpy.utils.unregister_class(BatchRender)
    bpy.types.VIEW3D_MT_object.remove(menu_func)

if __name__ == "__main__":
    register()

    # test call
    bpy.ops.object.batch_render()
