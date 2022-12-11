// Fill out your copyright notice in the Description page of Project Settings.


#include "SVCameraTrigger.h"

#include "Components/BoxComponent.h"

ACameraTrigger::ACameraTrigger()
{
	bGenerateOverlapEventsDuringLevelStreaming = true;

#if WITH_EDITOR
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
#endif
}

bool ACameraTrigger::ShouldTickIfViewportsOnly() const
{
	if (GetWorld() != nullptr &&
		GetWorld()->WorldType == EWorldType::Editor)
	{
		return true;
	}
	return false;
}

void ACameraTrigger::Tick(float dt)
{
	#if WITH_EDITOR
	if (GetWorld() != nullptr &&
		GetWorld()->WorldType == EWorldType::Editor)
	{
		BP_EditorTick(dt);
	}
	else
	#endif
	{
		Super::Tick(dt);
	}
}
