#include "CharacterEnums.h"

std::string CharacterEnums::enumToString(ECheckMove_Type enumValue)
{
    switch (enumValue)
    {
        case ECheckMove_Type::VE_None: return "None";
        case ECheckMove_Type::VE_Normal: return "Normal";
        case ECheckMove_Type::VE_EndAttack: return "EndAttack";
        default: return "Unknown";
    }
}

std::string CharacterEnums::enumToString(EAI_Delay_Action enumValue)
{
    switch (enumValue)
    {
        case EAI_Delay_Action::VE_None: return "None";
        case EAI_Delay_Action::VE_MoveRight: return "MoveRight";
        case EAI_Delay_Action::VE_Attack1: return "Attack1";
        case EAI_Delay_Action::VE_Attack2: return "Attack2";
        case EAI_Delay_Action::VE_Attack3: return "Attack3";
        case EAI_Delay_Action::VE_Attack4: return "Attack4";
        case EAI_Delay_Action::VE_Sp1: return "Sp1";
        case EAI_Delay_Action::VE_Sp2: return "Sp2";
        case EAI_Delay_Action::VE_Jump: return "Jump";
        case EAI_Delay_Action::VE_Duck: return "Duck";
        default: return "Unknown";
    }
}

std::string CharacterEnums::enumToString(ECharacterState enumValue)
{
    switch (enumValue)
    {
        case ECharacterState::VE_None: return "None";
        case ECharacterState::VE_Standing: return "Standing";
        case ECharacterState::VE_MovingForward: return "MovingForward";
        case ECharacterState::VE_MovingBackward: return "MovingBackward";
        case ECharacterState::VE_Crouch: return "Crouch";
        case ECharacterState::VE_Jump: return "Jump";
        case ECharacterState::VE_Blocking: return "Blocking";
        case ECharacterState::VE_Attacking: return "Attacking";
        case ECharacterState::VE_Hurt: return "Hurt";
        case ECharacterState::VE_WallBounce: return "WallBounce";
        case ECharacterState::VE_LandedOnCharacter: return "LandedOnCharacter";
        default: return "Unknown";
    }
}

std::string CharacterEnums::enumToString(EAttackType enumValue)
{
    switch (enumValue)
    {
        case EAttackType::VE_None: return "None";
        case EAttackType::VE_Normal: return "NormalAttack";
        case EAttackType::VE_CrouchAttack: return "CrouchAttack";
        case EAttackType::VE_JumpAttack: return "JumpAttack";
        case EAttackType::VE_StepAttack: return "StepAttack";
        case EAttackType::VE_ComboAttack: return "ComboAttack";
        default: return "Unknown";
    }
}

std::string CharacterEnums::enumToString(EHitState enumValue)
{
    switch (enumValue)
    {
        case EHitState::VE_None: return "None";
        case EHitState::VE_LandedHit: return "LandedHit";
        case EHitState::VE_LandedGrab: return "LandedGrab";
        case EHitState::VE_LandedThrow: return "LandedThrow";
        default: return "Unknown";
    }
}

std::string CharacterEnums::enumToString(EDamagedState enumValue)
{
    switch (enumValue)
    {
        case EDamagedState::VE_None: return "None";
        case EDamagedState::VE_Hit: return "Hit";
        case EDamagedState::VE_Grabbed: return "Grabbed";
        case EDamagedState::VE_Thrown: return "Thrown";
        case EDamagedState::VE_KnockUp: return "KnockUp";
        case EDamagedState::VE_KnockDown: return "KnockDown";
        case EDamagedState::VE_GetUp: return "GetUp";
        case EDamagedState::VE_Bounce: return "Bounce";
        default: return "Unknown";
    }
}

std::string CharacterEnums::enumToString(EAttackName enumValue)
{
    switch (enumValue)
    {
        case EAttackName::VE_None: return "None";
        case EAttackName::VE_A: return "A";
        case EAttackName::VE_B: return "B";
        case EAttackName::VE_X: return "X";
        case EAttackName::VE_Y: return "Y";
        case EAttackName::VE_Sp1: return "Sp1";
        case EAttackName::VE_Sp2: return "Sp2";
        case EAttackName::VE_ComboA: return "ComboA";
        case EAttackName::VE_ComboB: return "ComboB";
        case EAttackName::VE_ComboX: return "ComboX";
        case EAttackName::VE_ComboY: return "ComboY";
        case EAttackName::VE_ComboSp1: return "ComboSp1";
        case EAttackName::VE_ComboSp2: return "ComboSp2";
        case EAttackName::VE_Projectile: return "Projectile";
        case EAttackName::VE_Throw: return "Throw";
        case EAttackName::VE_Grab: return "Grab";
        case EAttackName::VE_Sweep: return "Sweep";
        case EAttackName::VE_KnockDown: return "KnockDown";
        case EAttackName::VE_Hold: return "Hold";
        case EAttackName::VE_MultiHit: return "MultiHit";
        case EAttackName::VE_Super: return "Super";
        default: return "Unknown";
    }
}




std::string CharacterEnums::enumToString(EDamageLocation enumValue)
{
    switch (enumValue)
    {
        case EDamageLocation::VE_Leg: return "Leg";
        case EDamageLocation::VE_Chest: return "Chest";
        case EDamageLocation::VE_Face: return "Face";
        case EDamageLocation::VE_Groin: return "Groin";
        default: return "Unknown";
    }
}


CharacterEnums::EAttackName CharacterEnums::stringToEnum(const std::string& str)
{
    if (str == "None") return EAttackName::VE_None;
    else if (str == "A") return EAttackName::VE_A;
    else if (str == "B") return EAttackName::VE_B;
    else if (str == "X") return EAttackName::VE_X;
    else if (str == "Y") return EAttackName::VE_Y;
    else if (str == "Sp1") return EAttackName::VE_Sp1;
    else if (str == "Sp2") return EAttackName::VE_Sp2;
    else if (str == "ComboA") return EAttackName::VE_ComboA;
    else if (str == "ComboB") return EAttackName::VE_ComboB;
    else if (str == "ComboX") return EAttackName::VE_ComboX;
    else if (str == "ComboY") return EAttackName::VE_ComboY;
    else if (str == "ComboSp1") return EAttackName::VE_ComboSp1;
    else if (str == "ComboSp2") return EAttackName::VE_ComboSp2;
    else if (str == "Projectile") return EAttackName::VE_Projectile;
    else if (str == "Throw") return EAttackName::VE_Throw;
    else if (str == "Grab") return EAttackName::VE_Grab;
    else if (str == "Sweep") return EAttackName::VE_Sweep;
    else if (str == "KnockDown") return EAttackName::VE_KnockDown;
    else if (str == "Hold") return EAttackName::VE_Hold;
    else if (str == "MultiHit") return EAttackName::VE_MultiHit;
    else if (str == "Super") return EAttackName::VE_Super;
    else return EAttackName::VE_None; // Return a default value or handle error
}