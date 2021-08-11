// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/MyTestLevelScriptActor.h"

void AMyTestLevelScriptActor::SpawnMyCube(TSubclassOf<AActor> MyBPCube, FTransform MyTransform)
{
	GLog->Log("Does something");
	GetWorld()->SpawnActor<AActor>(MyBPCube, MyTransform.GetLocation(), MyTransform.Rotator());

	//UObject* SpawnActor = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/DEXIED/Foliage/Tree/BP_TreeDestroyed_Style_1.BP_TreeDestroyed_Style_1")));

	//UBlueprint* GeneratedBP = Cast<UBlueprint>(SpawnActor);
	//if (!SpawnActor)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("CANT FIND OBJECT TO SPAWN")));
	//	return;
	//}

	//UClass* SpawnClass = SpawnActor->StaticClass();
	//if (SpawnClass == NULL)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("CLASS == NULL")));
	//	return;
	//}

	//UWorld* World = GetWorld();
	//FActorSpawnParameters SpawnParams;
	//SpawnParams.Owner = this;
	//SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	//World->SpawnActor<AActor>(GeneratedBP->GeneratedClass, GetActorLocation(), GetActorRotation(), SpawnParams);

}