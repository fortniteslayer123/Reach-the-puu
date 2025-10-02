// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int MyTestFunction(float MyFloatParam, FString MyStringParam)
{
	// Just a test function to demonstrate parameters and FString usage
	UE_LOG(LogTemp, Display, TEXT("MyFloatParam %f"), MyFloatParam);
	UE_LOG(LogTemp, Display, TEXT("MyStringParam %s"), *MyStringParam);


	return 40;



}








// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	FString MyName = GetName();
	int ReturnValue = MyTestFunction(3.5f, MyName);
	UE_LOG(LogTemp, Display, TEXT("ReturnValue is %d"), ReturnValue);

	StartLocation = GetActorLocation();
	

	

}

// Called every frameS
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);


}


void AMovingPlatform::MovePlatform(float DeltaTime)
{

	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);

	SetActorLocation(CurrentLocation);


	DistanceMoved = GetDistanceMoved();

	if (DistanceMoved >= MoveDistance)

	{

		float Overshoot = DistanceMoved - MoveDistance;	
		FString PlatformName = GetName();	
		UE_LOG(LogTemp, Display, TEXT("%s Overshoot: %f"), *PlatformName, Overshoot);


		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		FVector NewStartLocation = CurrentLocation + MoveDirection * MoveDistance;
		SetActorLocation(NewStartLocation);
		StartLocation = NewStartLocation;


		PlatformVelocity = -PlatformVelocity;
		

	}
	else
	{
		FVector CurrentLocation = GetActorLocation();

		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);

		SetActorLocation(CurrentLocation);
	}
	


}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
}

float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

