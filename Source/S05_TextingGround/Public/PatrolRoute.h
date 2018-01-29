// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"

/*
A route card to help AI choose their next waypoint


*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S05_TEXTINGGROUND_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrolRoute();
	UFUNCTION(BlueprintCallable, Category = Setup)
		TArray<AActor*> GetPatrolRoute() const;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly, Category = Setup)
		TArray<AActor*> PatrolPointsCpp;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
