// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ILabel.generated.h"

class UWidgetComponent;

UINTERFACE(MinimalAPI)
class UILabel : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DUNGEONPROJECT_API IILabel
{
	GENERATED_BODY()

public:
	void RotateTextWidget(UWidgetComponent TextWidgetComponent);
	void DisplayTextWidget(UWidgetComponent TextWidgetComponent);
	void HideTextWidget(UWidgetComponent TextWidgetComponent);
};
