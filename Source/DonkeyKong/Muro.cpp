// Fill out your copyright notice in the Description page of Project Settings.


#include "Muro.h"

// Sets default values
AMuro::AMuro()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MuroMalla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroMalla"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Muro0Mesh(TEXT("StaticMesh'/Game/Geometry/MisMallas/muro/MuroLadrllo/muro_de_ladrillo_0922200136_refine.muro_de_ladrillo_0922200136_refine'"));
	if (Muro0Mesh.Succeeded())
	{
		MuroMalla->SetStaticMesh(Muro0Mesh.Object);
		MuroMalla->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		MuroMalla->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	}
	else {
		static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

		if (MuroMesh.Succeeded())
		{
			MuroMalla->SetStaticMesh(MuroMesh.Object);

			//MuroMalla->SetMaterial(0, MuroMaterial.Object);
		}

		MuroMalla->SetRelativeScale3D(FVector(1.5f, 0.2f, 3.0f));
	}
	RootComponent = MuroMalla;

	MuroColision = CreateDefaultSubobject<UBoxComponent>(TEXT("Muro_Colision"));
	MuroColision->SetVisibility(true);
	MuroColision->SetRelativeScale3D(FVector(2.5f, 2.2f, 3.0f));
	MuroColision->SetCollisionProfileName(TEXT("Triger"));
	MuroColision->SetupAttachment(GetRootComponent());

	MuroColision->OnComponentBeginOverlap.AddDynamic(this, &AMuro::OnOverlapBegin);

	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AMuro::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMuro::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("OnOverlapBegin called"));

	if (OtherActor && OtherActor->IsA(ADonkeyKongCharacter::StaticClass()))
	{
		
		Mensaje();
	}
}


void AMuro::Mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hola Mundo!"));
}

// Called every frame
void AMuro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

