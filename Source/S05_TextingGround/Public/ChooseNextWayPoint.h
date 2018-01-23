// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWayPoint.generated.h"

/**
 * 
 */
UCLASS()
class S05_TEXTINGGROUND_API UChooseNextWayPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:

	UPROPERTY(EditAnywhere, Category = BlackBoard)
		struct FBlackboardKeySelector IndexKey;
	UPROPERTY(EditAnywhere, Category = BlackBoard)
		struct FBlackboardKeySelector WaypointKey;
};
