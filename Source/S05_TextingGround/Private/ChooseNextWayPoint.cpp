// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TextingGround.h"
#include "Public/ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	UE_LOG(LogTemp, Warning, TEXT("Index : %i"),Index);
	return EBTNodeResult::Succeeded;

}