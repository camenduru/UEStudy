// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstanceInterface.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class STUDY_API UMyGameInstance : public UGameInstance, public IMyGameInstanceInterface
{
	GENERATED_BODY()
	
public:
	void Init() override;
	virtual void IsGameStarted_Implementation();

	static UMyGameInstance* GetInstance();
	void DisplayDebugMessage(FString message);

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool IsGameStarted;
};
