// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MyPlayer.h"
#include "GameFramework/GameModeBase.h"
#include "RollABallGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ROLLABALL_API ARollABallGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	int coins;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int levelCoins;

	ARollABallGameModeBase();

	void Tick(float DeltaSeconds) override;

};
