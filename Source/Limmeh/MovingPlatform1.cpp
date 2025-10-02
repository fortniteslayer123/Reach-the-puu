// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform1.h"

// Sets default values
AMovingPlatform1::AMovingPlatform1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingPlatform1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

