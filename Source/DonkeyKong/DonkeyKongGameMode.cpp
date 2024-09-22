// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKongGameMode.h"
#include "DonkeyKongCharacter.h"
#include "Math/UnrealMathUtility.h"
#include "UObject/ConstructorHelpers.h"

ADonkeyKongGameMode::ADonkeyKongGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

//void ADonkeyKongGameMode::prueba()
//{
//	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, TEXT("Hola Mundo"));
//}

void ADonkeyKongGameMode::GenerarPlataformas()
{
	
	//1.25f / 3.0f
	//tamanio de la plataforma = 551
	e = FMath::RoundToInt(FMath::FRandRange(3.0f, 5.0f));
	float varAux = 551.0f;
	//e = FMath::FRandRange(3.0f, 5.0f);
	// -516.0f+((e*551.0f/2.0f)-551.0f/2.0f)
	FVector plataformaPosicion = FVector(1207.0f, -516+551/2*(e-1), 780.0f);
	FRotator plataformaRotacion = FRotator(0.0f, 0.0f, 0.0f);
	//para acceder a la plataforma en el futuro
	
	
	APlataforma* ceroPlataforma;
	clavePlataformacero = 0;
	for (int k = 0; k < e*2; k++) {

		ceroPlataforma = GetWorld()->SpawnActor<APlataforma>(FVector(1207.0f,  ( - 516.0f + 551.0f*e)-varAux, 80.0f), FRotator(0.0f, 0.0f, 0.0f));
		varAux += 551.0f;
		PlataformaMapcero.Add(clavePlataformacero, ceroPlataforma);
		clavePlataformacero++;
	}
	clavePlataforma = 1;
	varAux = 1.0f;
	APlataforma* NuevaPlataforma;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < e; j++) {
			if (j == 0 || j + 1 == e) {
				plataformaRotacion.Roll =-15.0f*varAux;
				plataformaPosicion.Z -= FMath::Tan(FMath::DegreesToRadians(15.0f))*551/2 ;
				NuevaPlataforma = GetWorld()->SpawnActor<APlataforma>(plataformaPosicion, plataformaRotacion);
				plataformaPosicion.Z -= FMath::Tan(FMath::DegreesToRadians(15.0f))*551 /2 ;
			}
			else {
				plataformaRotacion.Roll = 0.0f;
				NuevaPlataforma = GetWorld()->SpawnActor<APlataforma>(plataformaPosicion, plataformaRotacion);
			}
			if (NuevaPlataforma) {

				PlataformaMap.Add(clavePlataforma, NuevaPlataforma);
				clavePlataforma++;
			}

			plataformaPosicion.Y -= 551.0f*varAux;
		}

		//plataformaPosicion.Y *= varAux;
		varAux *= -1;
		plataformaPosicion.Z += 900.0f;
	}
	for (int z = 0; z < 3; z++) {
		numRandoms = FMath::RoundToInt(FMath::FRandRange(1.0f, 5 * e));

		APlataforma** PlataformaEncontrada = PlataformaMap.Find(numRandoms);
		if (PlataformaEncontrada) {
			(*PlataformaEncontrada)->SetMoverse(true);
		}
	}

}

void ADonkeyKongGameMode::GenerarCuboDisparador()
{
	for (int x = 0; x < 3; x++)
	{
		numRandoms = FMath::RoundToInt(FMath::FRandRange(1.0f, 5 * e));
		APlataforma* PlataformaEncontrada = PlataformaMap[numRandoms];
		FVector UbicacionCubo = PlataformaEncontrada->GetActorLocation() + FVector(0, 0, 100);
		ACuboDisparador* NuevoCubo = GetWorld()->SpawnActor<ACuboDisparador>(UbicacionCubo, FRotator(0, 0, 0));
		if (NuevoCubo) {
			CubosDisparadores.Add(NuevoCubo);
		}
	}

}

void ADonkeyKongGameMode::BeginPlay()
{
	Super::BeginPlay();
	GenerarPlataformas();
	GetWorld()->SpawnActor<ACieloNoche>(FVector(1207.0f, -516 , 780.0f), FRotator(90, 0, 0));
	GenerarCuboDisparador();

}


