#ifndef BRANCHGENERIC_H
#define BRANCHGENERIC_H

#include <CoreMinimal.h>
#include <Containers/Array.h>
#include "CharacterEnums.h"
#include <UObject/ObjectMacros.h>
#include <Misc/HashBuilder.h>
#include "Notify.h"

// BranchGeneric is what determines what animation is playing
// Within Branch Generic we have all the information that determines the current animation state.
// Create Getters and Setters for Each Relevant Paramater that determines the Animation State
// For My Class it extends Character Enums so we can access all the Enum Data inside Branch Generic


class BranchGeneric : public CharacterEnums {
public:
    BranchGeneric() {}

    BranchGeneric(FName StateName) : BStateName(StateName) {}

    void BasicAttack(EAttackName Attack, ECharacterState CharacterState, EDamagedState DamagedState) {
        BAttack = Attack;
        BCharacterState = CharacterState;
        BDamagedState = DamagedState;
    }

    void SetAttackType(EAttackType AttackType) {
        BAttackType = AttackType;
    }

    void Move(FName MoveType, ECharacterState CharacterState, EDamagedState DamagedState) {
        BMoveType = MoveType;
        BCharacterState = CharacterState;
        BDamagedState = DamagedState;
    }

    void AddFlipped(int IsFlipped) {
        BIsFlipped = IsFlipped;
    }

    void AddPosSpeed(float Speed) {
        Pos_Speed = Speed;
    }

    void AddNegSpeed(float Speed) {
        Neg_Speed = Speed;
    }

    void AddPosAirSpeed(float AirSpeed) {
        Pos_AirSpeed = AirSpeed;
    }

    void AddNegAirSpeed(float AirSpeed) {
        Neg_AirSpeed = AirSpeed;
    }

    void AddPlayerHealth(int64 PlayerHealth) {
        BPlayerHealth = PlayerHealth;
    }

    void AddNotify(F_Notify Notify) {
        Animation_NotifyQueue.Add(Notify);
    }

    FName GetStateName() const {
        return BStateName;
    }

    int64 GetPlayerHealth() const {
        return BPlayerHealth;
    }

    void SetPlayRate(float _rate) {
        Anim_PlayRate =_rate;
    }

    void SetPriorMoveDirection(ECharacterState Direction){
        BPriorMoveDirection = Direction;
    }

    // Comparison Operator

    bool operator==(const BranchGeneric& Other) const {
        return BStateName == Other.BStateName &&
               BAttack == Other.BAttack &&
               BCharacterState == Other.BCharacterState &&
               BAttackType == Other.BAttackType &&
               BDamagedState == Other.BDamagedState &&
               BMoveType == Other.BMoveType &&
               BPlayerHealth == Other.BPlayerHealth &&
               BIsFlipped == Other.BIsFlipped &&
               Pos_Speed == Other.Pos_Speed &&
               Neg_Speed == Other.Neg_Speed &&
               Pos_AirSpeed == Other.Pos_AirSpeed &&
               Neg_AirSpeed == Other.Neg_AirSpeed;
    }

public:

   // Make sure to set default values for Each Paramater within Branch Generic
   // The CodeBased State Machine will check to see if the current Character Paramaters
   // Match the Branch, if it's set to none or default then this paramater is not used in the check

    FName BStateName;
    EAttackName BAttack = EAttackName::VE_None;
    ECharacterState BCharacterState = ECharacterState::VE_None;
    ECharacterState BPriorMoveDirection = ECharacterState::VE_None;
    EAttackType BAttackType = EAttackType::VE_None;
    EDamagedState BDamagedState = EDamagedState::VE_None;
    FName BMoveType;

    int64 BPlayerHealth = -100;
    int BIsFlipped = -100;
    float Pos_Speed = 0.0f;
    float Neg_Speed = 0.0f;
    float Pos_AirSpeed = 0.0f;
    float Neg_AirSpeed = 0.0f;
    float Anim_PlayRate = 1.0f;

    // TArray That Stores All the Notifies that will Fire During the Animation.

    TArray<F_Notify> Animation_NotifyQueue;
};

#endif // BRANCHGENERIC_H
