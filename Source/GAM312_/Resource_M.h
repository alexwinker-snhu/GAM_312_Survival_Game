// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Resource_M.generated.h"

UCLASS()
class GAM312__API AResource_M : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResource_M();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FString resourceName = "Wood"; // Creates property for resources names

	UPROPERTY(EditAnywhere) // Creates Resource amount and total resources
	int resourceAmount = 5;

	UPROPERTY(EditAnywhere)
	int totalResource = 100;

	UPROPERTY()
	FText tempText; // Text for testing

	UPROPERTY(EditAnywhere)
	UTextRenderComponent* ResourceNameTxt; //Creates resource name text

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh; //Creates mesh component for resources

};
