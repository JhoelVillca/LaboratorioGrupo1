// Fill out your copyright notice in the Description page of Project Settings.


#include "Cono.h"

// Sets default values
ACono::ACono()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ConoMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));

	ConoMalla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ConoMalla"));
	ConoMalla->SetStaticMesh(ConoMesh.Object);
	RootComponent = ConoMalla;

}

// Called when the game starts or when spawned
void ACono::BeginPlay()
{
	Super::BeginPlay();
	TimerHandle;

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ACono::DispararE, FMath::FRandRange(2.0f, 4.0f), true);
	
}

// Called every frame
void ACono::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACono::DispararE()
{

	GetWorld()->SpawnActor<AProyectil>(GetActorLocation() + FVector(0.0f, 100.0f, 0.0f), FRotator(0, 0, 0))->Disparar(FVector(0.0f, FMath::RandRange(0.0f, 1.0f) > 0.5 ? 1.0f : -1.0f, 0.0f), false);
	GetWorld()->SpawnActor<AProyectil>(GetActorLocation() + FVector(0.0f, 100.0f, 0.0f), FRotator(0, 0, 0))->Disparar(FVector(0.0f, FMath::RandRange(0.0f, 1.0f) > 0.5 ? 1.0f : -1.0f, 0.0f), false);
	GetWorld()->SpawnActor<AProyectil>(GetActorLocation() + FVector(0.0f, 100.0f, 0.0f), FRotator(0, 0, 0))->Disparar(FVector(0.0f, FMath::RandRange(0.0f, 1.0f) > 0.5 ? 1.0f : -1.0f, 0.0f), false);
	//GetWorld()->SpawnActor<AProyectil>(GetActorLocation() - FVector(0.0f, 100.0f, 0.0f), FRotator(0, 0, 0))->Disparar(FVector(0.0f, -1.0f, 0.0f), false);

}