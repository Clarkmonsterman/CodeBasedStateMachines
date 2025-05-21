ACharacterRenderMachine::ACharacterRenderMachine(){

    currentNotify = NotifyType::None;
    currentAnim = BranchGeneric(FName(TEXT("Current")));
    Start_Frame.set(0);
    Render_Frame.set(0);

    // Set Information For ANimation State
    BranchGeneric Idle =  BranchGeneric(FName(TEXT("Idle")));
    Idle.BasicAttack(EAttackName::VE_None, ECharacterState::VE_Standing, EDamagedState::VE_None);
    Idle.Move(MoveName, ECharacterState::VE_Standing, EDamagedState::VE_None);


    BranchGeneric JabAttack =  BranchGeneric(FName(TEXT("Jab")));
    JabAttack.BasicAttack(EAttackName::VE_B, ECharacterState::VE_Attacking, EDamagedState::VE_None);
    JabAttack.Move(MoveName, ECharacterState::VE_Attacking, EDamagedState::VE_None);
    JabAttack.SetAttackType(EAttackType::VE_Normal);

    // Set when to fire notifies

    F_Notify  JabAttack_Start = F_Notify(NotifyType::AttackStart, 1);
    F_Notify  JabAttack_Active = F_Notify(NotifyType::AttackActive, 9);
    F_Notify  JabAttack_RMH = F_Notify(NotifyType::RMH, 14);

    // Add NOtifiees
    JabAttack.AddNotify(JabAttack_Start);
    JabAttack.AddNotify(JabAttack_Active);
    JabAttack.AddNotify(JabAttack_RMH);

   
    // Add To Animation Branches
    AnimationBranches.Add(Idle);
    AnimationBranches.Add(JabAttack);

}


void ACharacterRenderMachine::BeginPlay(){
    Super::BeginPlay();
    CheckForAnimations();
}


void ACharacterRenderMachine::Tick(float DeltaTime){
  Super::Tick(DeltaTime);
   CheckForAnimations();
}




bool ACharacterRenderMachine::CheckForAnimationChange(){

    if(YourCharacterState != prevCharacterState || YourDamageState != prevDamageState || prevMove != MoveName){
        //GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Purple, FString::Printf(TEXT("Should Change Animation!!!")));
        
        return true;
    } else {
        return false;
    }
}

void ACharacterRenderMachine::SetPreviousAnimation(){
    prevCharacterState = currentCharacterState
    prevDamageState = currentDamageState
    prevAttackName = currentAttackName
    prevMove = MoveName;
}



bool ACharacterRenderMachine::CheckBlendOuts(){

    ECharacterState currentState = currentCharacterState

    bool idle_test = (gameTick.get() == BlendOutFrame && currentState == ECharacterState::VE_Standing);
    
    if(idle_test){
        //GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Should Replay Idle!!!")));
        ReplayIdle();
        return true;
    }



    bool mf_test = false;
    mf_test = gameTick.get() == BlendOutFrame && currentState == ECharacterState::VE_MovingForward;
    if(mf_test){
        BlendOutMoveForward();
        return true;
    }


    bool mb_test = false;
    mb_test = gameTick.get() == BlendOutFrame && currentState == ECharacterState::VE_MovingBackward;
    if(mb_test){
        BlendOutMoveBackward();
        return true;
    }

    

   
   return false;

}


void ACharacterRenderMachine::ResetBlendOuts(){
	BlendOutFrame = -1
}


void ACharacterRenderMachine::CheckForAnimations(){

    
    CheckBlendOuts();
    
    // Checks to See if we have a possible ANimation State Change
    if(CheckForAnimationChange()){
       
        //GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Animation Change!!!")));

        if(CheckBranches()){
            FString MontagePath = FString(TEXT("/Game/ThirdPerson/YourPathToMontage")) + currentAnim.BStateName.ToString() + FString(TEXT(".")) + currentAnim.BStateName.ToString();
            
            PlayCharacterMontage(MontagePath);
            
        
        }
        SetPreviousAnimation();
        
    }

    

}


void ACharacterRenderMachine::PlayCharacterMontage(FString MontagePath){
   

    // Load the Montage
    UAnimMontage* LoadedMontage = LoadObject<UAnimMontage>(nullptr, *MontagePath);

    if (LoadedMontage)
    {
        // Get the Total Length of the Montage
        float MontageLength = LoadedMontage->GetPlayLength();
        float MontageBlendOut;

        // Can Set the Blend Out Frame Based on the Type of Animation

        // current Anim is of type Branch Generic
        // hence why we need the comparison operator overloaded
        if(currentAnim.BCharacterState == ECharacterState::VE_Attacking){
            MontageBlendOut = MontageLength*0.7f;
        } else {
            MontageBlendOut = MontageLength*0.8f;
        }

        int32 BlendOut = FMath::CeilToInt(MontageBlendOut * 60);
        // Multiplying but the frame rate to get the correct blend out frame
        int32 TotalFrames = FMath::CeilToInt(MontageLength * 60);
        // Total Frames in the Montage
        // We need to get the AnimInstance to Play the Montage
        UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
        

        if (AnimInstance)
        {   
            // this empties the current notify Queue that is set in the class
            // then appends the notifies the exist in the current Branch Generic
            NotifyQueue.Empty();
            NotifyQueue.Append(currentAnim.Animation_NotifyQueue); 
            float PlayRate = currentAnim.Anim_PlayRate;
            float PlayTime = static_cast<float>(frames_skipped) / 60;
            // logic for frame skipping
            // by default set this PLayTime to 0.0f
            PlayTime  = 0.0f;


            AnimInstance->Montage_Play(LoadedMontage, PlayRate, EMontagePlayReturnType::MontageLength, PlayTime, true);
            // sets the blend out frame to -1
            ResetBlendOuts();
           
             // Set the BlendOutFrame
            int BlendOut_Idle_Frame = gameTick.get() + BlendOut;
            BlendOutFrame = BlendOut_Idle_Frame

         
            
            

        } 
    } else {
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Failed To Load Montage!!!")));
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Failed Path: %s"), *MontagePath));
    }
    
   

}


void ACharacterRenderMachine::BlendOutMoveForward(){
    
    FString MontagePath = FString(TEXT("/Game/ThirdPerson/YourPath")) + currentAnim.BStateName.ToString() + FString(TEXT(".")) + currentAnim.BStateName.ToString();
    UAnimMontage* LoadedMontage = LoadObject<UAnimMontage>(nullptr, *MontagePath);
    if (LoadedMontage)
    {
        float MontageLength = LoadedMontage->GetPlayLength();
        float MontageBlendOut = MontageLength*MoveBlendOutPercent;
        int32 BlendOut = FMath::CeilToInt(MontageBlendOut * 60);
        UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
        if (!AnimInstance)
        {
            //GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("AnimInstance is invalid!"));
            return;
        }
        AnimInstance->Montage_Play(LoadedMontage, 1.0f, EMontagePlayReturnType::MontageLength, 0.0f, true);
        BlendOutFrame = gameTick.get() + BlendOut;
    }

}
	
void ACharacterRenderMachine::BlendOutMoveBackward(){

   
    FString MontagePath = FString(TEXT("/Game/ThirdPerson/Tremp/Montages/")) + currentAnim.BStateName.ToString() + FString(TEXT(".")) + currentAnim.BStateName.ToString();
    UAnimMontage* LoadedMontage = LoadObject<UAnimMontage>(nullptr, *MontagePath);
    if (LoadedMontage)
    {
        float MontageLength = LoadedMontage->GetPlayLength();
        float MontageBlendOut = MontageLength*MoveBlendOutPercent;
        int32 BlendOut = FMath::CeilToInt(MontageBlendOut * 60);
        UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
        if (!AnimInstance)
        {
            //GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("AnimInstance is invalid!"));
            return;
        }
        AnimInstance->Montage_Play(LoadedMontage, 1.0f, EMontagePlayReturnType::MontageLength, 0.0f, true);
        BlendOutFrame = gameTick.get() + BlendOut;
    }
    
}




void ACharacterRenderMachine::ReplayIdle(){

    FString MontagePath = FString(TEXT("/Game/ThirdPerson/Tremp/Montages/")) + currentAnim.BStateName.ToString() + FString(TEXT(".")) + currentAnim.BStateName.ToString();
    UAnimMontage* LoadedMontage = LoadObject<UAnimMontage>(nullptr, *MontagePath);
    if (!LoadedMontage)
    {
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Failed To Load Montage!!!")));
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Failed Path: %s"), *MontagePath));
        return;
    }


    float MontageLength = LoadedMontage->GetPlayLength();
    float MontageBlendOut = MontageLength*0.8f;
    int32 BlendOut = FMath::CeilToInt(MontageBlendOut * 60);

    UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
    if (!AnimInstance)
    {
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("AnimInstance is invalid!"));
        return;
    }

    AnimInstance->Montage_Play(LoadedMontage, 1.0f, EMontagePlayReturnType::MontageLength, 0.0f, true);
    BlendOutFrame = gameTick.get() + BlendOut;

}

void ACharacterRenderMachine::CheckNotifies(int32 gameFrame, bool _IsRollBack){
    
    //GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Check Notify Frame: %d"), gameFrame));
    
        
    for(int i = 0; i < NotifyQueue.Num(); ++i){
        uint64 tmp_frame = NotifyQueue[i].FrameToFire;
       
        if(tmp_frame + Render_Frame.get() > gameFrame){
            break;
        } else if(tmp_frame + Render_Frame.get() == gameFrame){
    
            currentNotify = NotifyQueue[i].Notify;

          


            

            if(currentNotify == NotifyType::AttackStart){
                // Spawn Proximity Hitbox
            }


            if(currentNotify == NotifyType::AttackActive){
                // Spawn HitBox
            }

            if(currentNotify == NotifyType::RMH){
                // Remove HitBox
            }


            if(currentNotify == NotifyType::SpawnProjectile){
                // SPawn Projectile
            }

        }
    }


}


bool ACharacterRenderMachine::CheckBranches(bool IsRollBack){
   
    // loops through animation Branches
    for(auto Branch : AnimationBranches){

        // if it's not None... I.E. we set the branch to have a particular Attack State that is required
        // It Checks to See if It Matches
        // If it doesn't Match Continue is triggered and it checks the next branch in the array

        if(Branch.BAttack != EAttackName::VE_None){
            if(AttackName != Branch.BAttack){
                continue;
            }
        }

        if(Branch.BCharacterState != ECharacterState::VE_None){
            if(CharacterState != Branch.BCharacterState){
                continue;
            }
        }

        if(Branch.BDamagedState != EDamagedState::VE_None){
            if(DamagedState != Branch.BDamagedState){
                continue;
            }
        }


        if(Branch.BAttackType != EAttackType
        ::VE_None){
            if(AttackType != Branch.BAttackType){
                continue;
            }
        }

        if(Branch.BMoveType != MoveName){
            continue;
        }


        if(Branch.BPlayerHealth != -100){
            if(PlayerHealth != Branch.BPlayerHealth){
                continue;
            }
        }

        if(Branch.BIsFlipped != -100){
            if(IsFlipped && Branch.BIsFlipped == 1 //
            || !IsFlipped && Branch.BIsFlipped == 0){

                continue;

            }
        }

        if(Branch.Pos_Speed != 0.0f){

            if(CharacterVelocity.Y > Branch.Pos_Speed){ 
                continue;
            }
        }


        if(Branch.Neg_Speed != 0.0f){

            if(CharacterVelocity.Y < Branch.Neg_Speed){ 
                continue;
            }
        }

        if(Branch.Pos_AirSpeed != 0.0f){
            if(CharacterVelocity.Z > Branch.Pos_AirSpeed){
                continue;
            }
        }

        if(Branch.Neg_AirSpeed != 0.0f){
            if(CharacterVelocity.Z < Branch.Neg_AirSpeed){
                continue;
            }
        }

      
        // If It passed all the checks then the animation branch has met all it's requirements
        // Set the Start Animation Frame to the current GameTick
        // and Set the Current Animation to the Current Branch
        // Return True that we have found a new animation Branch to return
    
        Start_Frame.set(gameTick.get());
        currentAnim = Branch;

        
        return true;
    }
    // Return false... we haven't found any animation Branches that match the current Character Paramaters.
    return false;

}