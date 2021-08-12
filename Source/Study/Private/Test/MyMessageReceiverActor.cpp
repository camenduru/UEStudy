// Fill out your copyright notice in the Description page of Project Settings.

#include "Test/MyMessageSenderActor.h"
#include "Test/MyMessageReceiverActor.h"

// Sets default values
AMyMessageReceiverActor::AMyMessageReceiverActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
}

// Called when the game starts or when spawned
void AMyMessageReceiverActor::BeginPlay()
{
	Super::BeginPlay();

	AMyMessageSenderActor* GetActorOfClass_ReturnValue = CastChecked<AMyMessageSenderActor>(UGameplayStatics::GetActorOfClass(this, AMyMessageSenderActor::StaticClass()), ECastCheckedType::NullAllowed);
	OutputDelegate.BindUFunction(this, "MyMessageSenderActorEventDispatcher_Event");
	if (::IsValid(GetActorOfClass_ReturnValue))
	{
		GetActorOfClass_ReturnValue->MyMessageSenderActorEventDispatcher.AddUnique(OutputDelegate);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, GetActorOfClass_ReturnValue->GetName());
	}
}

void AMyMessageReceiverActor::MyMessageSenderActorEventDispatcher_Event()
{
	//GLog->Log("C++ Message Receiver: I got the Message");
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("C++ Message Receiver: I got the Message"));
}