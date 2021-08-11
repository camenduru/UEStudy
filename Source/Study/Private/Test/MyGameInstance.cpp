// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/MyGameInstance.h"
#include "GameFramework/GameUserSettings.h"

void UMyGameInstance::Init()
{
	Super::Init();

	//Hardware Benchmark
	//Initialize Settings
	//Load Game From Game Slot
	//Spawn Cube

	//UGameUserSettings::GetGameUserSettings()->RunHardwareBenchmark(10, 1.0, 1.0);
	//UGameUserSettings::GetGameUserSettings()->ApplyHardwareBenchmarkResults();

	const Scalability::FQualityLevels State = Scalability::BenchmarkQualityLevels(10, 1.0, 1.0);
	Scalability::SetQualityLevels(State, true);
	DisplayDebugMessage(FString::FromInt(State.ResolutionQuality));
	DisplayDebugMessage(FString::FromInt(State.ViewDistanceQuality));
	DisplayDebugMessage(FString::FromInt(State.AntiAliasingQuality));
	DisplayDebugMessage(FString::FromInt(State.ShadowQuality));
	DisplayDebugMessage(FString::FromInt(State.PostProcessQuality));
	DisplayDebugMessage(FString::FromInt(State.TextureQuality));
	DisplayDebugMessage(FString::FromInt(State.EffectsQuality));
	DisplayDebugMessage(FString::FromInt(State.FoliageQuality));

	//IConsoleManager::Get().RegisterConsoleVariable(TEXT("Game.IconSet"), TEXT("xb1"), TEXT(""));
	//IConsoleManager::Get().RegisterConsoleVariable(TEXT("Camera.FOV"), 90.0f, TEXT(""));
	//IConsoleManager::Get().RegisterConsoleVariable(TEXT("Character.GravityScale"), 1.0f, TEXT(""));
	//IConsoleManager::Get().RegisterConsoleVariable(TEXT("Character.WalkSpeed"), 600.0f, TEXT(""));
	//IConsoleManager::Get().RegisterConsoleVariable(TEXT("Input.Sensitivity"), 2.5f, TEXT(""));
}

void UMyGameInstance::IsGameStarted_Implementation()
{
	
}

UMyGameInstance* UMyGameInstance::GetInstance()
{
	UMyGameInstance* instance = nullptr;

	if (GEngine)
	{
		FWorldContext* context = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
		instance = Cast<UMyGameInstance>(context->OwningGameInstance);
	}

	return instance;
}


void UMyGameInstance::DisplayDebugMessage(FString message)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, message);
	}
}

