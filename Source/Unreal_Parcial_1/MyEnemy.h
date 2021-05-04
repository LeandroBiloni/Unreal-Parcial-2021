// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "MyEnemy.generated.h"

UENUM()
enum class EBehavioursEnemy : uint8
{
	BE_Follow UMETA(DisplayName = "Follow"),
	BE_LookPlayer UMETA(DisplayName = "Look"),
	BE_Avoidance UMETA(DisplayName = "Avoid")
};

UCLASS()
class UNREAL_PARCIAL_1_API AMyEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyEnemy();

	USphereComponent* Sphere;
	TArray<AActor*> Overlap;
	AActor* Player;
	
	UPROPERTY(EditAnywhere, Category = Enum)
	EBehavioursEnemy myEnum;


	UPROPERTY(EditAnywhere)
		float Speed;
	UPROPERTY(EditAnywhere)
		float SpeedRot;
	UPROPERTY(EditAnywhere)
		float AvoidWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* ClosestObstacle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
		int MaxLife;
	UPROPERTY(EditAnywhere)
		int CurrentLife;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GetDamage(int damage);
	void LookTarget();
	void FollowTarget(float deltaTime);
	void Avoidance(float deltaTime);
	UFUNCTION(BlueprintCallable)
		void MyBeginOverlap(AActor* actorOverlap);
};
