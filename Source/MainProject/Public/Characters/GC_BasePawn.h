#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GC_BasePawn.generated.h"

UCLASS()
class MAINPROJECT_API AGC_BasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGC_BasePawn();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float value);
	void MoveRight(float value);

	UPROPERTY(VisibleAnywhere)
	class UPawnMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* CollisionComponent;
};