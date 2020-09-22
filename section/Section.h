#ifndef _SECTION_H_
#define _SECTION_H_

#include "LineTracer.h"
#include "SimpleWalker.h"
#include "VirtualLineTracer.h"
#include "VirtualLineTracer2.h"
#include "TailWalker.h"
#include "ArmWalker.h"

#include "Walker.h"
#include "Judge.h"
#include "LengthJudge.h"
#include "TurnAngleJudge.h"
#include "BrightnessJudge.h"
#include "ColorJudge.h"
#include "TailAngleJudge.h"
#include "ArmAngleJudge.h"
#include "Stop.h"
#include "GyroJudge.h"




class Section {
    public:
        Section();
        ~Section();
        virtual bool run();
        virtual void init();

        Walker *selectWalker(int no);
        Judge *selectJudge(int no);

        enum WALKER_NO {
            WNONE,
            WALKER,
            TRACER,
            VIRTUAL,
            VIRTUAL2,
            TAIL,
            ARM
        };
            enum JUDGE_NO {
            JNONE,
            LENGTH,
            TURNANGLE,
            BRIGHTNESS,
            COLOR,
            TAILANGLE,
            ARMANGLE,
            STOP,
            GYRO
        };

    protected:
        Walker *mWalker;
        Judge *mJudge;


    private:
        bool first;
        bool first2;


};

#endif
