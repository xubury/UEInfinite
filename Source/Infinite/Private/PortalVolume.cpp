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
}

void APortalVolume::OnOverlapBegin(AActor *OverlappedActor, AActor *OtherActor)
{
    GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, "OnTouchBegin");

    AMainCharacter *character = Cast<AMainCharacter>(OtherActor);
    if (OtherPortal != nullptr && OtherPortal != this && character != nullptr) {
        FBoxSphereBounds bounds = GetBounds();

        FRotator myRot     = GetActorRotation();
        FRotator targetRot = character->GetActorRotation();

        FRotator deltaRot = targetRot - (myRot + FRotator(0, 180, 0));
        deltaRot.Normalize();
        FVector  dstLoc = OtherPortal->GetActorLocation();
        FRotator dstRot = OtherPortal->GetActorRotation();

        FVector newLoc = dstLoc + dstRot.RotateVector(FVector(bounds.SphereRadius, 0, 0));
        GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, "Teleport");
        character->SetActorLocation(newLoc);
        character->GetController()->SetControlRotation(dstRot + deltaRot);
    }
}

void APortalVolume::OnOverlapEnd(AActor *OverlappedActor, AActor *OtherActor)
{
    GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, "OnTouchEnd");
}
