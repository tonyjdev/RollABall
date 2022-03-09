// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"

#include "Coins.h"
#include "Engine/World.h"
#include "RollABallGameModeBase.h"
#include "GameFramework/GameMode.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // AddScore(5);
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	TArray<UActorComponent*> Comps;
	GetComponents(UActorComponent::StaticClass(), Comps, true);
	for (auto element : Comps)
	{
		UE_LOG(LogTemp, Display, TEXT(">>> Component : %s is from class : %s"), *element->GetName(), *element->GetClass()->GetName());
		if (element->IsA(UStaticMeshComponent::StaticClass()))
		{
			BallMesh = Cast<UStaticMeshComponent>(element);
			UE_LOG(LogTemp, Warning, TEXT("Encontrado STATIC MESH: %s"), *element->GetName());
			UE_LOG(LogTemp, Warning, TEXT("Encontrado STATIC MESH: %s"), *BallMesh->GetName());
			BallMesh->AddForce(FVector(100, 0, 0));
			break;
		}
	}
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	InputComponent->BindAxis("MoveHorizontal", this, &AMyPlayer::MoveHorizontal);
	InputComponent->BindAxis("MoveVertical", this, &AMyPlayer::MoveVertical);
	InputComponent->BindAction("Exit", IE_Pressed, this, &AMyPlayer::ExitToMenu);
}


void AMyPlayer::MoveHorizontal(float axisValue)
{
	float deltaTime = GetWorld()->GetDeltaSeconds();
	FVector ForceToAdd = FVector(0, 1 * axisValue * MovementForce * deltaTime, 0);
	BallMesh->AddForce(ForceToAdd);
}

void AMyPlayer::MoveVertical(float axisValue)
{
	float deltaTime = GetWorld()->GetDeltaSeconds();
	FVector ForceToAdd = FVector(1 * axisValue * MovementForce * deltaTime, 0, 0);
	BallMesh->AddForce(ForceToAdd);
}

void AMyPlayer::ExitToMenu()
{
	GetWorld()->ServerTravel("MainMenu");
}


void AMyPlayer::AddScore(int points)
{
	Score += points;
	
	AGameModeBase* gameModeBase = GetWorld()->GetAuthGameMode();
	ARollABallGameModeBase* gameMode = Cast<ARollABallGameModeBase>(gameModeBase);

	if (gameMode != nullptr)
	{
		gameMode->coins += 1;
	}
}
