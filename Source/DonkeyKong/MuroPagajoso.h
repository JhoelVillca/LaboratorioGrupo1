// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroPagajoso.generated.h"

UCLASS()
class DONKEYKONG_API AMuroPagajoso : public AMuro
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMuroPagajoso();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	UMaterial* MuroPagajosoMaterial;

protected:

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void  Mensaje() override;
};
