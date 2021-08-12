// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "MyMessageReceiverActor.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FMyMessageSenderActorEventDispatcher_SinglecastDelegate);

UCLASS()
class STUDY_API AMyMessageReceiverActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyMessageReceiverActor();

	UPROPERTY()
	FMyMessageSenderActorEventDispatcher_SinglecastDelegate OutputDelegate;

	UFUNCTION()
	virtual void MyMessageSenderActorEventDispatcher_Event();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
