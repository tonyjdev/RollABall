// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coins.generated.h"

UCLASS()
class ROLLABALL_API ACoins : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ACoins();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpeedRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Points;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator rotation;

	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
