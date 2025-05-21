
#ifndef CharacterEnums_H
#define CharacterEnums_H
#include <string>
#include <map>

class CharacterEnums {

public:
    CharacterEnums() {}

    // Replace with Enums Specific to controlling the animations in your game

    enum class ECheckMove_Type : uint8
    {
        VE_None UMETA(DisplayName = "None"),
        VE_Normal UMETA(DisplayName = "Normal"),
        VE_EndAttack UMETA(DisplayName = "EndAttack"),
    };

    enum class EAI_Delay_Action : uint8
    {
        VE_None UMETA(DisplayName = "None"),
        VE_MoveRight UMETA(DisplayName = "MoveRight"),
        VE_Attack1 UMETA(DisplayName = "Attack1"),
        VE_Attack2 UMETA(DisplayName = "Attack2"),
        VE_Attack3 UMETA(DisplayName = "Attack3"),
        VE_Attack4 UMETA(DisplayName = "Attack4"),
        VE_Sp1 UMETA(DisplayName = "Sp1"),
        VE_Sp2 UMETA(DisplayName = "Sp2"),
        VE_Jump UMETA(DisplayName = "Jump"),
        VE_Duck UMETA(DisplayName = "Duck"),
    };

    enum class ECharacterState : uint8
    {
        VE_None UMETA(DisplayName = "None"),
        VE_Standing UMETA(DisplayName = "Standing"),
        VE_MovingForward UMETA(DisplayName = "MovingForward"),
        VE_MovingBackward UMETA(DisplayName = "MovingBackward"),
        VE_Crouch UMETA(DisplayName = "Crouch"),
        VE_Jump UMETA(DisplayName = "Jump"),
        VE_Blocking UMETA(DisplayName = "Blocking"),
        VE_Attacking UMETA(DisplayName = "Attacking"),
        VE_Hurt UMETA(DisplayName = "Hurt"),
        VE_WallBounce UMETA(DisplayName = "WallBounce"),
        VE_LandedOnCharacter UMETA(DisplayName = "LandedOnCharacter"),
    };

    enum class EAttackType : uint8
    {
        VE_None UMETA(DisplayName = "None"),
        VE_Normal UMETA(DisplayName = "NormalAttack"),
        VE_CrouchAttack UMETA(DisplayName = "CrouchAttack"),
        VE_JumpAttack UMETA(DisplayName = "JumpAttack"),
        VE_StepAttack UMETA(DisplayName = "StepAttack"),
        VE_ComboAttack UMETA(DisplayName = "ComboAttack"),
    };

    enum class EHitState : uint8
    {
        VE_None UMETA(DisplayName = "None"),
        VE_LandedHit UMETA(DisplayName = "LandedHit"),
        VE_LandedGrab UMETA(DisplayName = "LandedGrab"),
        VE_LandedThrow UMETA(DisplayName = "LandedThrow")
    };

    enum class EDamagedState : uint8
    {
        VE_None UMETA(DisplayName = "None"),
        VE_Hit UMETA(DisplayName = "Hit"),
        VE_Grabbed UMETA(DisplayName = "Grabbed"),
        VE_Thrown UMETA(DisplayName = "Thrown"),
        VE_KnockUp UMETA(DisplayName = "KnockUp"),
        VE_KnockDown UMETA(DisplayName = "KnockDown"),
        VE_GetUp UMETA(DisplayName = "GetUp"),
        VE_Bounce UMETA(DisplayName = "Bounce"),
    };

    enum class EAttackName : uint8
    {
        VE_None UMETA(DisplayName = "None"),
        VE_A UMETA(DisplayName = "A"),
        VE_B UMETA(DisplayName = "B"),
        VE_X UMETA(DisplayName = "X"),
        VE_Y UMETA(DisplayName = "Y"),
        VE_Sp1 UMETA(DisplayName = "Sp1"),
        VE_Sp2 UMETA(DisplayName = "Sp2"),
        VE_ComboA UMETA(DisplayName = "ComboA"),
        VE_ComboB UMETA(DisplayName = "ComboB"),
        VE_ComboX UMETA(DisplayName = "ComboX"),
        VE_ComboY UMETA(DisplayName = "ComboY"),
        VE_ComboSp1 UMETA(DisplayName = "ComboSp1"),
        VE_ComboSp2 UMETA(DisplayName = "ComboSp2"),
        VE_Projectile UMETA(DisplayName = "Projectile"),
        VE_Throw UMETA(DisplayName = "Throw"),
        VE_Grab UMETA(DisplayName = "Grab"),
        VE_Sweep UMETA(DisplayName = "Sweep"),
        VE_KnockDown UMETA(DisplayName = "KnockDown"),
        VE_Hold UMETA(DisplayName = "Hold"),
        VE_MultiHit UMETA(DisplayName = "MultiHit"),
        VE_Super UMETA(DisplayName = "Super"),
    };

    enum class EDamageLocation : uint8
    {
        VE_Leg UMETA(DisplayName = "Leg"),
        VE_Chest UMETA(DisplayName = "Chest"),
        VE_Face UMETA(DisplayName = "Face"),
        VE_Groin UMETA(DisplayName = "Groin")
    };

    // Static methods to convert enum to string

    // methods to return std:string from the Enum

    static std::string enumToString(ECheckMove_Type enumValue);
    static std::string enumToString(EAI_Delay_Action enumValue);
    static std::string enumToString(ECharacterState enumValue);
    static std::string enumToString(EAttackType enumValue);
    static std::string enumToString(EHitState enumValue);
    static std::string enumToString(EDamagedState enumValue);
    static std::string enumToString(EAttackName enumValue);
    static std::string enumToString(EDamageLocation enumValue);

    //method to return enum from std string
    static EAttackName stringToEnum(const std::string& str);
};


#endif