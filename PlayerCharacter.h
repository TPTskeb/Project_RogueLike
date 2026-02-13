#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"


UCLASS()
class PROJECT_ROUGELIKE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputMappingContext* PlayerMappingContext;

	//Input Action Move
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookupAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* TurnAction;

	//Function to move any direction
	void Move(const FInputActionValue& Value);

	void Turn(const FInputActionValue& Value);
	void LookUp(const FInputActionValue& Value);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CameraSet, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	
public:
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

};
