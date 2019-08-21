// Copyright Peter Glenn 2019.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HOUSEESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// How far ahead of the player can we reach in cm
	float Reach = 100.0f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
		
	// Ray-cast and grab what is in reach
	void Grab();
	void Release();

	// Find attached physics handle component
	void FindPhysicsHandleComponent();

	// Setup assumed input component
	void SetupInputComponent();

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
	
};
