// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "CieloNoche.h"
#include "CuboDisparador.h"
#include "Muro.h"
#include "Cono.h"
#include "MuroLadrillo.h"
#include "MuroCongelado.h"
#include "MuroElectrico.h"
#include "MuroPagajoso.h"
#include "MuroSolar.h"
#include "GameFramework/GameModeBase.h"
#include "DonkeyKongGameMode.generated.h"
UCLASS(minimalapi)
class ADonkeyKongGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADonkeyKongGameMode();

	//void prueba();

private:

	APlataforma* movPlataforma;
	APlataforma* movPlataforma2;

	void GenerarPlataformas();
	void GenerarCuboDisparador();
	void GenerarMuros();
	void GenerarConos();

    float e;

	int32 clavePlataformacero;
	int32 clavePlataforma;


	TMap<int32, APlataforma*> PlataformaMap;
	TArray<APlataforma*> ArrayDePlataformas;

	TMap<int32, APlataforma*> PlataformaMapcero;
	TArray<ACuboDisparador*> CubosDisparadores;

	TArray<TSubclassOf<class AMuro>> Muros;
	TSubclassOf<class AMuro> MuroAleatoria;
	

	

	float numRandoms;
	float numRandoms2;

	FTimerHandle Timer;

protected:
	virtual void BeginPlay() override;
};



