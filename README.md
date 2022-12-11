# PreRendTest
Prerendered Backgrounds Demo for UE 4/5

This is the project files from my prerendered backgroudns tutorial https://youtu.be/OdlQMwFJuwA

Please note this is just a demo and not production ready. This has not been tested in a real shipping game (yet)

The blender folder contains two plugins: 
- The batch render plugin: Iterates on all camers in the scene and renders images to output folder
- The Blender-for-unreal-engine plugin: This is used to export camera settings and geometry/collision from Blender to Unreal.
    - Please note at the time of making the demo, the camera feature in that plugin was in beta
    - The way it works is you just select the cameras from blender (multi select works), and just hit "Copy Regular Cameras For Unreal"
    - Then you just paste in Unreal. There, I wrote a little script that listens for that camera copy, it tries to find an existing camera with the same name, it it doesn't find one it create a new one, else it just copies the settings from the blender-pasted camera and deletes the blender-pasted camera. The reason its done this way is because the cameras in Unreal are referenced in the camera/zone triggers, so we can't just delete them, instead we just update their settings from the blender cameras.
    - For this to work you have to be consistent with the camera naming convention so the cameras are synced. I used "Camera_1" etc.
    - The rest of the scene is exported normally through the plugin via "Export for UnrealEngine 4" button
    - For more info on the plugin: https://blendermarket.com/products/blender-for-unreal-engine The plugin itself is free on Github, but its well worth paying for. The author is extremely helpful and implemented every feature I asked for to support this demo: https://github.com/xavier150/Blender-For-UnrealEngine-Addons/issues/153
    
  
