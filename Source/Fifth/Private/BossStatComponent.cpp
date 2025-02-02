// Fill out your copyright notice in the Description page of Project Settings.


#include "BossStatComponent.h"
#include "MyGameInstance.h"

// Sets default values for this component's properties
UBossStatComponent::UBossStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;

	Level = 1;
	// ...
}


// Called when the game starts
void UBossStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBossStatComponent::InitializeComponent()
{
	Super::InitializeComponent();
	SetNewLevel(1);
	// ...
}

void UBossStatComponent::SetNewLevel(int32 NewLevel)
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	ABCHECK(nullptr != MyGameInstance);
	CurrentStatData = MyGameInstance->GetBossTankData(NewLevel);
	if (nullptr != CurrentStatData)
	{
		Level = NewLevel;
		CurrentHP = CurrentStatData->MaxHP;
	}
	else {
		ABLOG(Error, TEXT("Boss Level (%d) data doesn't exist"), NewLevel);
	}
}

void UBossStatComponent::SetDamage(float NewDamage)
{
	ABCHECK(nullptr != CurrentStatData);
	CurrentHP = FMath::Clamp<float>(CurrentHP - NewDamage, 0.0f, CurrentStatData->MaxHP);
	if (CurrentHP <= 0.0f)
	{
		OnHPIsZero.Broadcast();
	}
}

float UBossStatComponent::GetAttack()
{
	ABCHECK(nullptr != CurrentStatData, 0.0f);
	return CurrentStatData->Attack;
}

float UBossStatComponent::GetKick()
{
	ABCHECK(nullptr != CurrentStatData, 0.0f);
	return CurrentStatData->SAttack;
}

float UBossStatComponent::GetSkill()
{
	ABCHECK(nullptr != CurrentStatData, 0.0f);
	return CurrentStatData->Skill;
}