// Fill out your copyright notice in the Description page of Project Settings.


#include "Coins.h"
#include "MyPlayer.h"

// Sets default values
ACoins::ACoins()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACoins::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ACoins::OnOverlap);
}

// Called every frame
void ACoins::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(rotation * SpeedRotation * DeltaTime);

}

void ACoins::OnOverlap(AActor* me, AActor* other)
{
	AMyPlayer* player = Cast<AMyPlayer>(other);
	
	if (player != nullptr)
	{
		player->AddScore(Points);
	}

	Destroy();
}
