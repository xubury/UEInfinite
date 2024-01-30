// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMainCharacter::MoveRight(float value)
{
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(Direction, value);
}

void AMainCharacter::MoveForward(float value)
{
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
    AddMovementInput(Direction, value);
}

void AMainCharacter::TurnHorizontal(float value)
{
    AddControllerYawInput(value);
}

void AMainCharacter::TurnVertical(float value)
{
    AddControllerPitchInput(-1.0 * value);
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Setup player input"));
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Here's my formatted string: %d"), 123));
    PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
    PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
    PlayerInputComponent->BindAxis("Turn", this, &AMainCharacter::TurnHorizontal);
    PlayerInputComponent->BindAxis("LookUp", this, &AMainCharacter::TurnVertical);
}

