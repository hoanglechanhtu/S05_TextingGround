// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "S05_TextingGround.h"
#include "S05_TextingGroundGameMode.h"
#include "S05_TextingGroundHUD.h"
#include "Player/FirstPersonCharacter.h"

AS05_TextingGroundGameMode::AS05_TextingGroundGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behavior/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS05_TextingGroundHUD::StaticClass();
}
