// Fill out your copyright notice in the Description page of Project Settings.


#include "CuboDisparador.h"
#include "Proyectil.h"

// Sets default values
ACuboDisparador::ACuboDisparador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mallaCuboDisparador = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla Cubo Disparador"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> cuboMalla(TEXT("StaticMesh'/Game/Geometry/MisMallas/CuboDisaparador/cuboMalla.cuboMalla'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> cubomaterial(TEXT("Material'/Game/Geometry/MisMallas/CuboDisaparador/CuboMaterial.CuboMaterial'"));
	//static ConstructorHelpers::FObjectFinder<UTexture2D> cubotextura(TEXT("Texture2D'/Game/Geometry/MisMallas/CuboDisaparador/T_diffuse.T_diffuse'"));
	if (cuboMalla.Succeeded() && cubomaterial.Succeeded()) {
		mallaCuboDisparador->SetStaticMesh(cuboMalla.Object);
		mallaCuboDisparador->SetMaterial(0, cubomaterial.Object);
		mallaCuboDisparador->SetWorldScale3D(FVector(2.5f, 2.5f, 2.5f));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Carga Fallida"));
	}
	
	
	RootComponent = mallaCuboDisparador;
}

// Called when the game starts or when spawned
void ACuboDisparador::BeginPlay()
{
	Super::BeginPlay();
	TimerHandle;

	// Configurar el temporizador para llamar a DispararD cada 3 segundos
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ACuboDisparador::DispararD, 3.0f, true);
}

// Called every frame
void ACuboDisparador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACuboDisparador::DispararD()
{
	GetWorld()->SpawnActor<AProyectil>(GetActorLocation()+FVector(0.0f, 100.0f, 0.0f), FRotator(0, 0, 0))->Disparar(FVector(0.0f, 1.0f, 0.0f), false);
	GetWorld()->SpawnActor<AProyectil>(GetActorLocation()- FVector(0.0f, 100.0f, 0.0f), FRotator(0, 0, 0))->Disparar(FVector(0.0f, -1.0f,0.0f), false);
}

