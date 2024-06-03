// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NeitherboundPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class ITargetInterface;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API ANeitherboundPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ANeitherboundPlayerController();

	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> HeroContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	
	TObjectPtr<ITargetInterface> LastActor;
	TObjectPtr<ITargetInterface> CurrentActor;
};
