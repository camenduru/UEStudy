// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "MyTestLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class STUDY_API AMyTestLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = LevelBlueprint)
	void SpawnMyCube(TSubclassOf<AActor> MyBPCube, FTransform MyTransform);
};
