// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CieloNoche.generated.h"

UCLASS()
class DONKEYKONG_API ACieloNoche : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACieloNoche();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UClass* cieloNocturnoBP;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CieloNoche")
	UStaticMeshComponent* CieloNocheMallaComponente;
};
