// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/MyLambdaActor.h"

// Sets default values
AMyLambdaActor::AMyLambdaActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cubeMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	UStaticMesh* cubeMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;
	cubeMeshComponent->SetStaticMesh(cubeMesh);
	//cubeMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SetRootComponent(cubeMeshComponent);
}

// Called when the game starts or when spawned
void AMyLambdaActor::BeginPlay()
{
	Super::BeginPlay();

	//WRONG!! https://www.orfeasel.com/understanding-lambda-expressions/
	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AActor::Destroy(), 5.f);

	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate;
	//Binding our Lambda expression
	TimerDelegate.BindLambda([&]()
		{
			//Typing the logic of our function here just like any other function...
			GLog->Log("Destroying Actor now...");
			Destroy();
		});//Don't forget the ";" in the end of your parenthesis!
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 5.f, false);

	//Declaring an Array of Actors
	TArray<AActor*> ActorsArray;
	//Declaring a delegate with one int32 parameter
	DECLARE_DELEGATE_OneParam(MyUsefulDelegate, int32);
	//The following functions populates the ActorsArray with all the Actors which reside inside our current level
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), ActorsArray);
	//Declaring a MyUsefulDelegate
	MyUsefulDelegate Del;
	//Binding a Lambda to it
	//In this lambda we pass the ActorsArray by value since we won't make any changes
	//or want any changes reflected outside the lambda expression
	//If we don't pass the ActorsArray in the capturelist then we won't be able to have access to it!
	Del.BindLambda([ActorsArray](int32 ActorIndex)
		{
			//Print the name of the Actor which has an index equal to the one we provided (ActorIndex)
			//Make sure we provided a valid index for our array
			if (ActorsArray.IsValidIndex(ActorIndex))
				GLog->Log("Actor with given index:" + ActorsArray[ActorIndex]->GetName());
			else
				GLog->Log("You've entered an invalid index. That's unfortunate :(");
		});

	//Show me the 16th Actor of the Array - Don't forget that TArray is zero-based!
	Del.ExecuteIfBound(15);


	//if (const int32* Val = MyArrayOfInts.FindByPredicate([](int32 n) { return n % 1; }))
	//{
		// Val points to odd number
	//}
	//arrayWithStructs.Sort([](const FMyStruct& a, const FMyStruct& b) { return a.field < b.field; });
	
}

// Called every frame
void AMyLambdaActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

