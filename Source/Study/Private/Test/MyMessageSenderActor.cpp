// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/MyMessageSenderActor.h"

// Sets default values
AMyMessageSenderActor::AMyMessageSenderActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
}

// Called when the game starts or when spawned
void AMyMessageSenderActor::BeginPlay()
{
	Super::BeginPlay();
	//UKismetSystemLibrary::PrintString(this, FString(TEXT("C++ Message Sender: I send the Message")), true, true, FLinearColor(0.000000, 0.660000, 1.000000, 1.000000), 5.000000);
	//GLog->Log("C++ Message Sender: I send the Message");
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("C++ Message Sender: I send the Message"));
	MyMessageSenderActorEventDispatcher.Broadcast();
}

