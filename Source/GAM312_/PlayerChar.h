// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Resource_M.h"
#include "Kismet/GameplayStatics.h"
#include "BuildingPart.h"
#include "PlayerWidget.h"
#include "PlayerChar.generated.h"

UCLASS()
class GAM312__API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION() //Binds the function to the input
	void MoveForward(float axisvalue);
	
	UFUNCTION()
	void MoveRight(float axisvalue);

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();

	UFUNCTION()
	void FindObject();

	UPROPERTY(VisibleAnywhere) //Makes sure the camera is able to be controlled
		UCameraComponent* PlayerCamComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats") // Creates player stats
		float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Hunger = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Stamina = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Resources") // Sets Resources into property that you could edit and puts into category
		int Wood;

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Stone;

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Berry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
		TArray<int> ResourcesArray;

	UPROPERTY(EditAnywhere, Category = "Resources")
		TArray<FString> ResourcesNameArray;

	UPROPERTY(EditAnywhere, Category = "HitMarker") // Creates Property for decal
		UMaterialInterface* hitDecal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Supplies")//Creates Building Array for supplies
		TArray<int> BuildingArray;

	UPROPERTY() //Bool for if you are building or not
		bool isBuilding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite) // Adds Building parts
		TSubclassOf<ABuildingPart> BuildPartClass;

	UPROPERTY() // Spawn part at certain location
		ABuildingPart* spawnedPart; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPlayerWidget* playerUI;

	UFUNCTION(BlueprintCallable) // Sets function for health, hunger, and stamina
		void SetHealth(float amount);

	UFUNCTION(BlueprintCallable)
		void SetHunger(float amount);

	UFUNCTION(BlueprintCallable)
		void SetStamina(float amount);

	UFUNCTION()
		void DecreaseStats();

	UFUNCTION() // Function to collect resources
		void GiveResource(float amount, FString resourceType);

	UFUNCTION(BlueprintCallable)
		void UpdateResources(float woodAmount, float stoneAmount, FString buildingObject);

	UFUNCTION(BlueprintCallable)
		void SpawnBuilding(int buildingID, bool& isSuccess);

	UFUNCTION() // Function for rotate building
		void RotateBuilding();
};
