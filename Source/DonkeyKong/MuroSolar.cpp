// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroSolar.h"

// Sets default values
AMuroSolar::AMuroSolar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UMaterial> MuroSolarMaterialAsset(TEXT("Material'/Game/Geometry/MisMallas/Proyectilmalla/luz.luz'"));

	if (MuroSolarMaterialAsset.Succeeded())
	{
		MuroSolarMaterial = MuroSolarMaterialAsset.Object;
		MuroMalla->SetMaterial(0, MuroSolarMaterial);
	}

}

// Called when the game starts or when spawned
void AMuroSolar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuroSolar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMuroSolar::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor && OtherActor->IsA(ADonkeyKongCharacter::StaticClass()))
	{

		Mensaje();
	}
}

void AMuroSolar::Mensaje()
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Muro Solar"));
}
