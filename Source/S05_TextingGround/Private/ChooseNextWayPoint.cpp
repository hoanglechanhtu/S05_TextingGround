// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TextingGround.h"
#include "Public/ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Public/PatrolRoute.h" //TODO remove later

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	//Get patrol points
	 
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
	auto PatrolPoints = PatrolRoute->GetPatrolRoute();

	//Set next waypoint

	if (PatrolPoints.Num() == 0) {
		UE_LOG(LogTemp, Warning, TEXT("zero member of patrol points"));
		return EBTNodeResult::Failed;
	}
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackBoardComp->SetValueAsObject(WaypointKey.SelectedKeyName,PatrolPoints[Index]);
	 
	//Cycle index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackBoardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex); 
	UE_LOG(LogTemp, Warning, TEXT("Index : %i"),Index);
	return EBTNodeResult::Succeeded;

}