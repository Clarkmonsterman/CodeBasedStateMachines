#ifndef Notify_H
#define Notify_H

#include "NotifyType.h"

class F_Notify 
{
   

    

public:

    NotifyType Notify;
    int64 FrameToFire;

    // Just two key paramaters the type of Notify event
    // and the Frame To Fire
    // The Frame to fire will be set based on the frame the animation starts + Frame To Fire
    // For example, if the animation starts on frame 1600 and the Frame to Fire Add Hitbox is 13, then it will fire this notify event
    // on frame 1613

    // Constructors
    F_Notify() : Notify(NotifyType::None), FrameToFire(0) {}

    F_Notify(NotifyType Notify, int64 Frame) : Notify(Notify), FrameToFire(Frame) {}

    // Setting and Getting Frame to Fire

    void SetFireFrame(int64 Frame) { FrameToFire = Frame; }
    int64 GetFireFrame() const { return FrameToFire; }

    // Setting and Getting Notify Type
    void SetNotifyType(NotifyType _Notify) { Notify = _Notify; }
    NotifyType GetNotifyType() const { return Notify; }

    // Overriden Comparison Operator so we can check for specific Notifies

    bool operator==(const F_Notify& Other) const
    {
        return Notify == Other.Notify && FrameToFire == Other.FrameToFire;
    }

    

    bool operator!=(const F_Notify& Other) const
    {
        return !(*this == Other);
    }
};

#endif