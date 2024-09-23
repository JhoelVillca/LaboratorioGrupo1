// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroElectrico.h"

AMuroElectrico::AMuroElectrico()
{


	PrimaryActorTick.bCanEverTick = true;

	//MuroElectricoMaterial = CreateDefaultSubobject<UMaterial>(TEXT("MuroElectricoMaterial"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MuroElectricoMaterialAsset(TEXT("Material'/Game/Geometry/MisMallas/muro/MuroElectrico/M_Tech_Hex_Tile_Pulse1.M_Tech_Hex_Tile_Pulse1'"));
	if (MuroElectricoMaterialAsset.Succeeded())
	{
		MuroElectricoMaterial = MuroElectricoMaterialAsset.Object;
		MuroMalla->SetMaterial(0, MuroElectricoMaterial);
	}
	
}

void AMuroElectrico::BeginPlay()
{

	Super::BeginPlay();
}

void AMuroElectrico::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
}

void AMuroElectrico::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->IsA(ADonkeyKongCharacter::StaticClass()))
	{

		Mensaje();
	}
}

void AMuroElectrico::Mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MuroElectrico"));
}
