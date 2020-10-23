#ifndef _JUDGE_H_
#define _JUDGE_H_

#include "HsvHue.h" 
#include "HsvSatu.h"
#include "Brightness.h"
#include "Length.h"
#include "TurnAngle.h"
#include "TailAngle.h"
#include "ArmAngle.h"
#include "GyroAngle.h"

class Judge{
    public:
    Judge();
    virtual bool run();
    virtual void init();

    enum  JUDGE_MODE{ UPDATE,
          UNUPDATE};

    protected:
    HsvHue *mHsvHue;
    HsvSatu *mHsvSatu;
    Brightness *mBrightness;
    Length *mLength;
    TurnAngle *mTurnAngle;
    TailAngle *mTailAngle;
    ArmAngle *mArmAngle;
    GyroAngle *mGyroAngle;

};


#endif