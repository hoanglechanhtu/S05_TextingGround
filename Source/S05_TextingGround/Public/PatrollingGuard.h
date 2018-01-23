// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class S05_TEXTINGGROUND_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public: //TODO fix to protected-> provide get
	UPROPERTY(EditInstanceOnly, Category = Setup)
		TArray<AActor*> PatrolPointsCpp;
	
	
};
