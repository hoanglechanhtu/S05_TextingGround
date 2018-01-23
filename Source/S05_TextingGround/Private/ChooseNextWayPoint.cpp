// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TextingGround.h"
#include "Public/ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Public/PatrollingGuard.h" //TODO remove later

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	//Get patrol points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrollPoints = PatrollingGuard->PatrolPointsCpp;

	//Set next waypoint

	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackBoardComp->SetValueAsObject(WaypointKey.SelectedKeyName,PatrollPoints[Index]);
	 
	//Cycle index
	auto NextIndex = (Index + 1) % PatrollPoints.Num();
	BlackBoardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex); 
	UE_LOG(LogTemp, Warning, TEXT("Index : %i"),Index);
	return EBTNodeResult::Succeeded;

}