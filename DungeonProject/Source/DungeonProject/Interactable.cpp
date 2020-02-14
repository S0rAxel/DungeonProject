#include "Interactable.h"
#include "Engine.h"
#include "InteractableWidget.h"
#include "Components/WidgetComponent.h"

// Sets default values
AInteractable::AInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxComponent->AttachToComponent(MeshComponent,FAttachmentTransformRules::KeepRelativeTransform);

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widgetcomponent"));

}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
	auto Widget = WidgetComponent->GetUserWidgetObject();
	auto Text = Cast<UInteractableWidget>(Widget);
	Text->interactable = this;
}

void AInteractable::Interact()
{
}

// Called every frame
void AInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

