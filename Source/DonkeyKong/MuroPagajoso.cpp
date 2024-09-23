// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroPagajoso.h"

// Sets default values
AMuroPagajoso::AMuroPagajoso()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UMaterial> MuroPegajosoMaterialasset(TEXT("Material'/Game/Geometry/MisMallas/muro/MuroPegajoso/Plastic017A_1K-JPG_Color_Mat.Plastic017A_1K-JPG_Color_Mat'"));

	if (MuroPegajosoMaterialasset.Succeeded())
	{
		MuroPagajosoMaterial = MuroPegajosoMaterialasset.Object;
		MuroMalla->SetMaterial(0, MuroPagajosoMaterial);
	}
	else
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MuroPagajosoMaterialasset(TEXT("Material'/Game/StarterContent/Materials/M_Ground_Moss.M_Ground_Moss'"));

		if (MuroPagajosoMaterialasset.Succeeded())
		{
			MuroPagajosoMaterial = MuroPagajosoMaterialasset.Object;
			MuroMalla->SetMaterial(0, MuroPagajosoMaterial);
		}
	}


}

// Called when the game starts or when spawned
void AMuroPagajoso::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuroPagajoso::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMuroPagajoso::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->IsA(ADonkeyKongCharacter::StaticClass()))
	{

		Mensaje();
	}
}

void AMuroPagajoso::Mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MuroPagajoso"));
}

