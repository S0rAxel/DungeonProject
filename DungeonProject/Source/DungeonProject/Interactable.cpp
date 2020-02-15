#include "Interactable.h"
#include "Engine.h"
#include "InteractableWidget.h"
#include "DungeonProjectCharacter.h"
#include "Components/WidgetComponent.h"

// Sets default values
AInteractable::AInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	BoxComponent->AttachToComponent(MeshComponent,FAttachmentTransformRules::KeepRelativeTransform);

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	WidgetComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
	auto widget = Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject());
	widget->interactable = this;
	widget->SetVisibility(ESlateVisibility::Hidden);
}

void AInteractable::Interact()
{
}

void AInteractable::NotifyActorBeginOverlap(AActor* OtherActor) 
{
	if (OtherActor != nullptr && Cast<ADungeonProjectCharacter>(OtherActor))
	{
		Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Visible);
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Green, TEXT("Character inside"));
	}
}

void AInteractable::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (OtherActor != nullptr && Cast<ADungeonProjectCharacter>(OtherActor))
	{
		Cast<UInteractableWidget>(WidgetComponent->GetUserWidgetObject())->SetVisibility(ESlateVisibility::Hidden);
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Green, TEXT("Character Outside"));

	}
}

// Called every frame
void AInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	WidgetComponent->SetWorldRotation(UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraRotation());
	WidgetComponent->AddLocalRotation(FRotator(0, 180, 0));
}

