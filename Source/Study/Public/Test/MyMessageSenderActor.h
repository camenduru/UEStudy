// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyMessageSenderActor.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMyMessageSenderActorEventDispatcher_MulticastDelegate);

UCLASS()
class STUDY_API AMyMessageSenderActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyMessageSenderActor();

	UPROPERTY(BlueprintAssignable)
	FMyMessageSenderActorEventDispatcher_MulticastDelegate MyMessageSenderActorEventDispatcher;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
