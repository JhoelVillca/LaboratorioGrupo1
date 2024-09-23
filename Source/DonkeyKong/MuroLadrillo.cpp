// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroLadrillo.h"

// Sets default values
AMuroLadrillo::AMuroLadrillo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	static ConstructorHelpers::FObjectFinder<UMaterial> MuroLadrilloMaterialasset(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));	



	if (MuroLadrilloMaterialasset.Succeeded())
	{
		MuroLadrilloMaterial = MuroLadrilloMaterialasset.Object;
		MuroMalla->SetMaterial(0, MuroLadrilloMaterial);
	}

}

// Called when the game starts or when spawned
void AMuroLadrillo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuroLadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMuroLadrillo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor && OtherActor->IsA(ADonkeyKongCharacter::StaticClass()))
	{

		Mensaje();
	}
}

void AMuroLadrillo::Mensaje()
{
		
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MuroLadrillo"));
}

