// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "GameFramework/Actor.h"
#include "Cono.generated.h"
UCLASS()
class DONKEYKONG_API ACono : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACono();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ConoMalla;

	void DispararE();

private:
	FTimerHandle TimerHandle;


};
