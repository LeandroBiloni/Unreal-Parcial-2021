// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "MySceneManager.generated.h"

UCLASS()
class UNREAL_PARCIAL_1_API AMySceneManager : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMySceneManager();

	/*UPROPERTY(EditAnywhere)
		TArray<UObject*> enemies;*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Restart();
	void LoadNextLevel();
	void Win();
	void Lose();

};
