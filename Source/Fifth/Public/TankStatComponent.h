// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fifth.h"
#include "Components/ActorComponent.h"
#include "TankStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnHPIsZeroDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIFTH_API UTankStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:	
	void SetNewLevel(int32 NewLevel);
	void SetDamage(float NewDamage);
	float GetAttack();

	FOnHPIsZeroDelegate OnHPIsZero;

private:
	struct FTankData* CurrentStatData = nullptr;

	UPROPERTY(EditInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		int32 Level;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		float CurrentHP;

		
};
