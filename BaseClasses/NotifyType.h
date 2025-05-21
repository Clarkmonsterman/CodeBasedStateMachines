#ifndef NotifyType_H
#define NotifyType_H




// These are all the events that would normally be triggered by a notify event inside the animation
// For example, spwaning the hitboxes, removing hit boxes, Checking Combos, Spawning a Projectile, etc

// This Enum Class should have every type of notify event that you will require to fire during the animations

enum class NotifyType : uint8
{
    None,
    AttackStart,
    AttackActive,
    RMH,
    NewDamage,
    MoveStart,
    MoveEnd,
    CheckCombo,
    SpawnProjectile
};

// Function to convert the enum to a string
static FString ToString(NotifyType Type)
{
    switch (Type)
    {
        case NotifyType::None: return TEXT("None");
        case NotifyType::AttackStart: return TEXT("AttackStart");
        case NotifyType::AttackActive: return TEXT("AttackActive");
        case NotifyType::RMH: return TEXT("RMH");
        case NotifyType::NewDamage: return TEXT("NewDamage");
        case NotifyType::MoveStart: return TEXT("MoveStart");
        case NotifyType::MoveEnd: return TEXT("MoveEnd");
        case NotifyType::CheckCombo: return TEXT("CheckCombo");
        case NotifyType::SpawnProjectile: return TEXT("SpawnProjectile");
        default: return TEXT("Unknown");
    }
}



#endif