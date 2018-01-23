// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TextingGround.h"
#include "Public/ChooseNextWayPoint.h"




EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	UE_LOG(LogTemp, Warning, TEXT("Yay, AI in c++"));
	return EBTNodeResult::Succeeded;

}