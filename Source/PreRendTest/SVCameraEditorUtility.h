// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityActor.h"
#include "SVCameraEditorUtility.generated.h"

UCLASS()
class PRERENDTEST_API ACameraEditorUtility : public AEditorUtilityActor
{
	GENERATED_BODY()

public:
	ACameraEditorUtility();

	virtual bool ShouldTickIfViewportsOnly() const override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, CallInEditor)
	void BP_EditorTick(float dt);

	UFUNCTION(BlueprintCallable)
	void BP_SetActorLabel(AActor* Actor, const FString& NewActorLabel, bool MarkDirty=true);
};
