// Fill out your copyright notice in the Description page of Project Settings.

#include "Proyectil.h"
#include "DonkeyKongCharacter.h"

AProyectil::AProyectil()
{
    
    PrimaryActorTick.bCanEverTick = true;

    ProyectilMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProyectilMesh"));
    ProyectilMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ProyectilMeshAsset(TEXT("StaticMesh'/Game/Geometry/MisMallas/Proyectilmalla/PoryectirlNew.PoryectirlNew'"));
    //static ConstructorHelpers::FObjectFinder<UMaterial> ProyectilMaterial(TEXT("Material'/Game/Geometry/MisMallas/Proyectilmalla/luz.luz'"));
    static ConstructorHelpers::FObjectFinder<UMaterial> ProyectilMaterialBueno(TEXT("Material'/Game/Geometry/MisMallas/Proyectilmalla/luzBueno.luzBueno'"));
    static ConstructorHelpers::FObjectFinder<UMaterial> ProyectilMaterialMalo(TEXT("Material'/Game/Geometry/MisMallas/Proyectilmalla/luz.luz'"));

    if (ProyectilMeshAsset.Succeeded()) {
        ProyectilMesh->SetStaticMesh(ProyectilMeshAsset.Object);
        //if (ProyectilMaterial.Succeeded()) {
         //   ProyectilMesh->SetMaterial(0, ProyectilMaterial.Object);
        //}
    }
    if (ProyectilMaterialBueno.Succeeded()) {
        MaterialBueno = ProyectilMaterialBueno.Object;
    }
    if (ProyectilMaterialMalo.Succeeded()) {
        MaterialMalo = ProyectilMaterialMalo.Object;
    }

	
	ProyectilMesh->SetNotifyRigidBodyCollision(true);
	ProyectilMesh->OnComponentHit.AddDynamic(this, &AProyectil::OnHit);


    RootComponent = ProyectilMesh;


    MovimientoDeProyectil = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovimientoDeProyectil"));
    MovimientoDeProyectil->UpdatedComponent = RootComponent;
    MovimientoDeProyectil->InitialSpeed = 3000.0f;
    MovimientoDeProyectil->MaxSpeed = 3000.0f;
    MovimientoDeProyectil->bRotationFollowsVelocity = true;
    MovimientoDeProyectil->bShouldBounce = false; 
    MovimientoDeProyectil->Bounciness = 0.0f; 
    MovimientoDeProyectil->ProjectileGravityScale = 0.0f;
   // SetLifeSpan(4.0f);
}

void AProyectil::BeginPlay()
{
    Super::BeginPlay();
   // ProyectilMesh->OnComponentHit.AddDynamic(this, &AProyectil::OnHit); 
    GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &AProyectil::DestroyProyectil, 4.0f, false);
}

void AProyectil::DestroyProyectil()
{
	Destroy();
}

void AProyectil::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AProyectil::Disparar(FVector direccion, bool YesOrNot)
{
    if (YesOrNot) {
        ProyectilMesh->SetMaterial(0, MaterialBueno);
    }
    else {
        ProyectilMesh->SetMaterial(0, MaterialMalo);
    }
    MovimientoDeProyectil->Velocity = direccion.GetSafeNormal() * MovimientoDeProyectil->InitialSpeed;
}

void AProyectil::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
        Destroy();
}

