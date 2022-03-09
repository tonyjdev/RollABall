// Copyright Epic Games, Inc. All Rights Reserved.


#include "RollABallGameModeBase.h"
#include "Engine/World.h"

ARollABallGameModeBase::ARollABallGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	levelCoins = 46;
}

void ARollABallGameModeBase::Tick(float DeltaSeconds)
{
	if (coins >= levelCoins)
	{
		GetWorld()->ServerTravel("WinLevel");
	}
}
