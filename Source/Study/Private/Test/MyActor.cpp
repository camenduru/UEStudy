// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PitchValue = 0.f;
	YawValue = 0.f;
	RollValue = 0.f;

	cubeMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));	
	UStaticMesh* cubeMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;
	cubeMeshComponent->SetStaticMesh(cubeMesh);
	//cubeMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SetRootComponent(cubeMeshComponent);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FQuat QuatRotation = FRotator(PitchValue, YawValue, RollValue).Quaternion();
	cubeMeshComponent->AddLocalRotation(QuatRotation, false, 0, ETeleportType::None);
	//AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}

void AMyActor::DisplayByStaticmethod()
{
	UMyGameInstance* instance = UMyGameInstance::GetInstance();
	if (instance)
	{
		instance->DisplayDebugMessage(FString("DisplayByStaticmethod"));
	}
}

void AMyActor::DisplayByActor()
{
	UMyGameInstance* instance = Cast<UMyGameInstance>(GetGameInstance());
	if (instance)
	{
		instance->DisplayDebugMessage("DisplayByActor");
	}
}

void AMyActor::ComponentsToSave_Implementation(TArray<UActorComponent*>& Components)
{
	//UE_LOG(LogTemp, Warning, TEXT("ComponentsToSave_Implementation"));
}

void AMyActor::ActorPreSave_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ActorPreSave_Implementation"));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Some variable values: x: %f, y: %f"), x, y));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ActorPreSave_Implementation"));
}

void AMyActor::ActorSaved_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ActorSaved_Implementation"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ActorSaved_Implementation"));
}

void AMyActor::ActorLoaded_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ActorLoaded_Implementation"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ActorLoaded_Implementation"));
}

