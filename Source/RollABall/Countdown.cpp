// Fill out your copyright notice in the Description page of Project Settings.


#include "Countdown.h"
#include "Engine/World.h"

#include "UObject/UObjectClusters.h"

// Sets default values
ACountdown::ACountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();

	
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ACountdown::Countdown, 1, true, 1);
}

// Called every frame
void ACountdown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACountdown::Countdown()
{
	if (Seconds > 0)
	{
		Seconds--;
		UE_LOG(LogTemp, Warning, TEXT("Han pasado %d segundos."), Seconds);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(TimerHandle);
		UE_LOG(LogTemp, Warning, TEXT("Se acabó el tiempo"));

		GetWorld()->ServerTravel("LoseLevel");
	}
}
