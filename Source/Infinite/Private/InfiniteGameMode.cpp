// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteGameMode.h"
#include "MainCharacter.h"

AInfiniteGameMode::AInfiniteGameMode()
{
    DefaultPawnClass = AMainCharacter::StaticClass();
}
