// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "DonkeyKongGameMode.h"
#include "Plataforma.generated.h"
UCLASS()
class DONKEYKONG_API APlataforma : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	APlataforma();


	bool cValue;
	bool cValue2;
	void SetMoverse(bool bValue);
	void SetMoverse2(bool bValue);

	//void movimiento()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//float TheTime;
	void movimiento(float TheTime);

	void movimiento2(float TheTime);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Plataforma")
	UStaticMeshComponent* PlataformaMallaComponente;

};
