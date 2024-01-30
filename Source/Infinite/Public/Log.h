#pragma once

#include "CoreMinimal.h"

inline void ScreenLog(const FString &string, const FColor &color = FColor::Green, float time = 1.5)
{
    GEngine->AddOnScreenDebugMessage(-1, time, color, string);
}
