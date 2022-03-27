// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "MyCharacter.h"
#include "ManOfFire.h"
#include "MyPlayerController.h"

AMyGameMode::AMyGameMode()
{
	//DefaultPawnClass = AMyCharacter::StaticClass();
	DefaultPawnClass = AManOfFire::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}

void AMyGameMode::PostLogin(APlayerController* NewPlayer)
{
	ABLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	ABLOG(Warning, TEXT("PostLogin End"));
}

