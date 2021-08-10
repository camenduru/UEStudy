// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "EMSActorSaveInterface.h"
#include "MyGameInstance.h"
#include "MyActor.generated.h"

UCLASS()
class STUDY_API AMyActor : public AActor, public IEMSActorSaveInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* cubeMeshComponent;

	UPROPERTY(EditAnywhere, Category = Movement)
	float PitchValue;

	UPROPERTY(EditAnywhere, Category = Movement)
	float YawValue;

	UPROPERTY(EditAnywhere, Category = Movement)
	float RollValue;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(meta = (CallInEditor = "true"), Category = "test")
	void DisplayByStaticmethod();

	UFUNCTION(meta = (CallInEditor = "true"), Category = "test")
	void DisplayByActor();

public:
	virtual void ActorLoaded_Implementation();


	virtual void ActorSaved_Implementation();


	virtual void ActorPreSave_Implementation();


	virtual void ComponentsToSave_Implementation(TArray<UActorComponent*>& Components);

};
