#include "Interactable.h"
#include "Engine.h"
#include "InteractableWidget.h"
#include "DungeonProjectCharacter.h"
#include "Components/SceneComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AInteractable::AInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	RootComponent = BoxComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->AttachToComponent(BoxComponent,FAttachmentTransformRules::KeepRelativeTransform);


	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	WidgetComponent->AttachToComponent(BoxComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
	auto widget = Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject());
	if (widget != nullptr)
	{
		widget->interactable = this;
		widget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AInteractable::Interact(ADungeonProjectCharacter* Character) { } //Called when interacted with object 

void AInteractable::NotifyActorBeginOverlap(AActor* OtherActor) 
{
	if (OtherActor != nullptr && Cast<ADungeonProjectCharacter>(OtherActor))
	{
		if (WidgetComponent->GetUserWidgetObject() != nullptr)
		{
			Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

void AInteractable::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (OtherActor != nullptr && Cast<ADungeonProjectCharacter>(OtherActor))
	{
		if (WidgetComponent->GetUserWidgetObject() != nullptr)
		{
			Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

// Called every frame
void AInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto camera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	if (camera != nullptr)
	{
		WidgetComponent->SetWorldRotation(UKismetMathLibrary::FindLookAtRotation(WidgetComponent->GetComponentLocation(), camera->GetCameraLocation()));
	}
}

