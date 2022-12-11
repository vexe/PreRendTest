// Fill out your copyright notice in the Description page of Project Settings.

#include "SVCameraEditorUtility.h"

//NOTE(Ali): I had to create this script solely because of "SetActorLabel" function.
// For some reason calling this function directly from blueprint causes compile errors in the 
// Editor sometimes after you restart the Editor (UE 4.27). But it seems to work if you wrap
// it in C++ and call the wrapper...

ACameraEditorUtility::ACameraEditorUtility()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ACameraEditorUtility::Tick(float dt)
{
	#if WITH_EDITOR
	UWorld* World = GetWorld();
	if (World == nullptr ||
		World->WorldType == EWorldType::Editor ||
		World->WorldType == EWorldType::EditorPreview)
	{
		BP_EditorTick(dt);
	}
	else
	#endif
	{
		Super::Tick(dt);
	}
}

void ACameraEditorUtility::BP_SetActorLabel(AActor* Actor, const FString& NewActorLabel, bool MarkDirty)
{
	#if WITH_EDITOR
	if (IsValid(Actor)) Actor->SetActorLabel(NewActorLabel, MarkDirty);
	#endif
}

bool ACameraEditorUtility::ShouldTickIfViewportsOnly() const
{
	UWorld* World = GetWorld();
	if (World == nullptr ||
		World->WorldType == EWorldType::Editor ||
		World->WorldType == EWorldType::EditorPreview)
	{
		return true;
	}

	return false;
}
