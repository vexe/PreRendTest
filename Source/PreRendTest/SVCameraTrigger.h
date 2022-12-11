// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SVCameraTrigger.generated.h"

UCLASS(Abstract)
class PRERENDTEST_API ACameraTrigger : public AActor
{
	GENERATED_BODY()

public:
	ACameraTrigger();

	virtual bool ShouldTickIfViewportsOnly() const override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "Events")
	void BP_EditorTick(float DeltaTime);
};
