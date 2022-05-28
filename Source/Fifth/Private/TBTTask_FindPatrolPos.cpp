// Fill out your copyright notice in the Description page of Project Settings.


#include "TBTTask_FindPatrolPos.h"
#include "TankAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

UTBTTask_FindPatrolPos::UTBTTask_FindPatrolPos()
{
	NodeName = TEXT("FindPatrolPos");
}

EBTNodeResult::Type UTBTTask_FindPatrolPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory)
{
	
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)
		return EBTNodeResult::Failed;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
	if (nullptr == NavSystem) {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Debug %f"), 123.0f));
		return EBTNodeResult::Failed;

	}

	FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(ATankAIController::HomePosKey);
	FNavLocation NextPatrol;
	
	if(NavSystem->GetRandomPointInNavigableRadius(Origin, 500.0f, NextPatrol) == false)
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("NotPatrol")));
	if(NavSystem != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("DebugH %f"), Origin.X));
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("DebugP %f"), NextPatrol.Location.X));
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(ATankAIController::PatrolPosKey,
			NextPatrol.Location);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;

}


