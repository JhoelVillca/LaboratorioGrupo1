// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"  // para el movimiento del proyectil
#include "Proyectil.generated.h"

UCLASS()
class DONKEYKONG_API AProyectil : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProyectil();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void DestroyProyectil();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Proyectil")
	UStaticMeshComponent* ProyectilMesh;
	UMaterial* MaterialBueno;
	UMaterial* MaterialMalo;

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* MovimientoDeProyectil;

	void Disparar(FVector direccion, bool YesOrNot);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
	FTimerHandle DestroyTimerHandle;

};
