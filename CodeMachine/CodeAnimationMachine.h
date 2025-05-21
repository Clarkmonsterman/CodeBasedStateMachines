#pragma once

#include "CoreMinimal.h"
#include "../BaseClasses/BranchGeneric.h"
#include "../BaseClasses/Notify.h"
#include "CharacterRenderMachine.generated.h"




/**
 * 
 */
UCLASS()
class POLITICALUNDERGROUND_API ACharacterRenderMachine : public YourCharacterClass
{
	GENERATED_BODY()

public:


    ACharacterRenderMachine();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

    UFUNCTION(BlueprintImplementableEvent)
	void ChangeAnimation();

    bool CheckBlendOuts();
    int64 BlendOutFrame = -1

    bool CheckForAnimationChange();

    TArray<BranchGeneric> AnimationBranches;
    bool CheckBranches();

    void PlayCharacterMontage(FString _MontagePath);

    BranchGeneric currentAnim;


	void SetPreviousAnimation();
	void CheckNotifies(int32 gameFrame, bool _IsRollBack);
	void MachineEndAttack(bool IsRollBack);
	void CheckForAnimations(bool IsRollBack);
	
	void BlendOutMoveForward();
	void BlendOutMoveBackward();
	void BlendOutGetUp();

	void ReplayIdle();
	
	void ResetBlendOuts();
	TArray<F_Notify> NotifyQueue;


	


	void FireNotify();


    




    EDamagedState prevDamageState = EDamagedState::VE_None;
    FName prevMove;
    EAttackName prevAttackName;


    UFUNCTION(BlueprintImplementableEvent)
	void CallAttackStart();

	UFUNCTION(BlueprintImplementableEvent)
	void CallAttackActive();

	UFUNCTION(BlueprintImplementableEvent)
	void CallRMH();

	UFUNCTION(BlueprintImplementableEvent)
	void CallSpawnProjectile();

}
		