// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "PortalVolume.generated.h"

/**
 *
 */
UCLASS()
class APortalVolume : public ATriggerVolume {
    GENERATED_BODY()
  protected:
    virtual void BeginPlay() override;

  public:
    APortalVolume();

    UFUNCTION()
    void OnOverlapBegin(AActor *OverlappedActor, AActor *OtherActor);
    UFUNCTION()
    void OnOverlapEnd(AActor *OverlappedActor, AActor *OtherActor);
    UPROPERTY(EditAnyWhere)
    APortalVolume *OtherPortal;
};
