#include "Characters/GC_BasePawn.h"
#include "Components/SphereComponent.h"
#include "Engine/CollisionProfile.h"
#include "GameFramework/FloatingPawnMovement.h"

AGC_BasePawn::AGC_BasePawn()
{
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Collision component"));
	CollisionComponent->SetSphereRadius(50.0f);
	CollisionComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	RootComponent = CollisionComponent;

	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("Movement component"));
	MovementComponent->SetUpdatedComponent(CollisionComponent);
}

// Called to bind functionality to input
void AGC_BasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("LookUp", this, &Super::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &Super::AddControllerYawInput);
	PlayerInputComponent->BindAxis("MoveForward", this, &AGC_BasePawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGC_BasePawn::MoveRight);
}

void AGC_BasePawn::MoveForward(float value)
{
	if (value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}

void AGC_BasePawn::MoveRight(float value)
{
	if (value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}

