// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlataformaMallaComponente = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlataformaMallaComponente"));
	PlataformaMallaComponente->SetRelativeScale3D(FVector(1.0f, 1.25f / 3.0f, 1.0f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlataformaMalla(TEXT("StaticMesh'/Game/Geometry/MisMallas/Plataforma/untitled.untitled'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> PlataformaMaterial(TEXT("Material'/Game/Geometry/MisMallas/Plataforma/rojito.rojito'"));
	//static ConstructorHelpers::FObjectFinder<UTexture2D> PlataformaTextura2D(TEXT("Texture2D'/Game/Geometry/MisMallas/Plataforma/118.118'"));

	if (PlataformaMalla.Succeeded() && PlataformaMaterial.Succeeded() /* && PlataformaTextura2D.Succeeded()*/) {
		PlataformaMallaComponente->SetStaticMesh(PlataformaMalla.Object);
		PlataformaMallaComponente->SetMaterial(0, PlataformaMaterial.Object);
	//	PlataformaMallaComponente->SetTexture2D(PlataformaTextura2D.Object, true);
		
	}
	RootComponent = PlataformaMallaComponente;
	//XDdd = FMath::FRandRange(0.0f, 30.0f);
}

void APlataforma::SetMoverse(bool bValue)
{
	cValue = bValue ;
}


// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (cValue) {
		movimiento(DeltaTime);
	}

}

void APlataforma::movimiento( float TheTime)
{
	float velocidadMovPlataforma = 1.0f;
	float distanciaMovPlataforma = 100.0f;
	float tiempoMovPlataforma = GetWorld()->GetTimeSeconds();

	FVector NewLocation = GetActorLocation();

	NewLocation.Z += FMath::Sin(tiempoMovPlataforma * velocidadMovPlataforma) * distanciaMovPlataforma * TheTime;

	SetActorLocation(NewLocation);
}




