// Fill out your copyright notice in the Description page of Project Settings.


#include "BossDecorator_IsInAttackRange.h"
#include "BossAIController.h"
#include "MyCharacter.h"
#include "BossTank.h"
#include "BehaviorTree/BlackboardComponent.h"

UBossDecorator_IsInAttackRange::UBossDecorator_IsInAttackRange()
{
	NodeName = TEXT("CanAttack");
}

bool UBossDecorator_IsInAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory) const

{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)
		return false;

	auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(ABossAIController::TargetKey));
	if (nullptr == Target)
		return false;

	bResult = (Target->GetDistanceTo(ControllingPawn) <= 1000.0f);
	return bResult;
}


