// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroCongelado.h"

// Sets default values
AMuroCongelado::AMuroCongelado()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UMaterial> MuroCongeladoMaterialasset0(TEXT("Material'/Game/Geometry/MisMallas/muro/MuroCongelado/M_Water_Lake1.M_Water_Lake1'"));
		if (MuroCongeladoMaterialasset0.Succeeded())
		{
			MuroCongeladoMaterial = MuroCongeladoMaterialasset0.Object;
			MuroMalla->SetMaterial(0, MuroCongeladoMaterial);
		}
		else
		{
			static ConstructorHelpers::FObjectFinder<UMaterial> MuroCongeladoMaterialasset(TEXT("Material'/Game/StarterContent/Materials/M_Water_Lake.M_Water_Lake'"));
			if (MuroCongeladoMaterialasset.Succeeded())
			{
				MuroCongeladoMaterial = MuroCongeladoMaterialasset.Object;
				MuroMalla->SetMaterial(0, MuroCongeladoMaterial);
			}
		}

}

// Called when the game starts or when spawned
void AMuroCongelado::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuroCongelado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMuroCongelado::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->IsA(ADonkeyKongCharacter::StaticClass()))
	{

		Mensaje();
	}
}

void AMuroCongelado::Mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MuroCongelado"));
}

