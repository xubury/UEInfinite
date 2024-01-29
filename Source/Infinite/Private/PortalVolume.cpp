// Fill out your copyright notice in the Description page of Project Settings.

#include "PortalVolume.h"
#include "MainCharacter.h"

APortalVolume::APortalVolume()
{
    OnActorBeginOverlap.AddDynamic(this, &APortalVolume::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &APortalVolume::OnOverlapEnd);
}

void APortalVolume::BeginPlay()
{
    Super::BeginPlay();
    // check(this != OtherPortal);
}

void APortalVolume::OnOverlapBegin(AActor *OverlappedActor, AActor *OtherActor)
{
    GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, "OnTouchBegin");
    // GEngine->AddOnScreenDebugMessage(-1, 1.5);

    AMainCharacter *character = Cast<AMainCharacter>(OtherActor);
    if (OtherPortal != nullptr && OtherPortal != this && character != nullptr) {
        FBoxSphereBounds bounds = GetBounds();

        FRotator myRot     = GetActorRotation();
        FRotator targetRot = character->GetActorRotation();

        FRotator deltaRot = myRot - targetRot;
        deltaRot.Normalize();
        // float angle = delta.GetComponentForAxis(EAxis::Z);
        // GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, FString::SanitizeFloat(angle));
        // if (abs(angle) >= 90) {
        // }
        FVector  dstLoc = OtherPortal->GetActorLocation();
        FRotator dstRot = OtherPortal->GetActorRotation();

        FVector newLoc = dstLoc + dstRot.RotateVector(FVector(bounds.SphereRadius, 0, 0));
        GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, "Teleport");
        character->SetActorLocation(newLoc);
        character->GetController()->SetControlRotation(dstRot + deltaRot + FRotator(0, 180, 0));
        // character->GetMovementComponent();
    }
}

void APortalVolume::OnOverlapEnd(AActor *OverlappedActor, AActor *OtherActor)
{
    GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, "OnTouchEnd");
}
