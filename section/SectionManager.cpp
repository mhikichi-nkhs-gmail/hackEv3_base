#include "SectionManager.h"

int SectionManager::msPrevWalker=0;

SectionManager::SectionManager()
{
    // msg_log("SectionManger");
    mSectionIdx=0;
    mLastIdx=0;
    error_code=0;
}

SectionManager::~SectionManager()
{
    // msg_log("destruct SectionManager");

    for(int i=0;i<mLastIdx;i++) {
        delete mSection[i];
    }
}

bool SectionManager::run()
{
    error_code=0;
    if(mSection[mSectionIdx]==nullptr)
        return true;

    if(mSection[mSectionIdx]->run()) {
       if(mSection[mSectionIdx]->getError()!=0) {
           error_code=1;
           return true;
       } 

        mSectionIdx++;
       // printf("nextIdx %d\n",mSectionIdx);
    }

    return false;
}

void SectionManager::addSection(Section *sec)
{
    mSection[mLastIdx++]=sec;
    mSection[mLastIdx]=nullptr;
}

void SectionManager::reset()
{
    for(int i=0;i<mLastIdx;i++) {
        delete mSection[i];
    }
    mSectionIdx = 0;
    mLastIdx=0;
}
void SectionManager::setWalker(Section * sc,wsParam *wp,int n)
{
    Walker *walk = sc->selectWalker(wp[n].walk);

    switch (wp[n].walk)
    {
    case Section::VIRTUAL2:
      //  printf("create VIRTUAL2 \n");
        // syslog(LOG_NOTICE,"VIRTUAL2:%d %d",(int)wp[n].speed,(int)wp[n].kp);
        ((VirtualLineTracer2 *)walk)->setAbsTurnAngle(wp[n].absangle);
        ((VirtualLineTracer2 *)walk)->setvangle(wp[n].vangle);
        ((VirtualLineTracer2 *)walk)->setParam(wp[n].speed, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp);

        break;
    case Section::WALKER:
      //  printf("create WALKER \n");
        ((SimpleWalker *)walk)->setCommandV(wp[n].forward, wp[n].turn);

        break;
    case Section::VIRTUAL:
     //   printf("create VIRTUAL \n");

        ((VirtualLineTracer *)walk)->setRound(wp[n].round);
        ((VirtualLineTracer *)walk)->setParam(wp[n].speed, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp); //(20,2, 0.2, 0,1,1)

        break;
    case Section::TRACER:
      //   printf("create TRACER \n");
       ((LineTracer *)walk)->setParam(wp[n].speed, wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp); //(30, 0 ,  30, 0.2, 0.1 )
        ((LineTracer *)walk)->setEdgeMode(wp[n].edge);

        break;
    case Section::ARM:

        ((ArmWalker *)walk)->setPwm(wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd);

        break;
    case Section::TAIL:
        /*sprintf(buf[n],"Section %f,%f,%f,%f",wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd);
        msg_log(buf[n]);*/
        ((TailWalker *)walk)->setPwm(wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd);
        break;
    }
}

void SectionManager::setWalker(Section * sc)
{
    setWalker(sc,wp,n);
}
void SectionManager::setJudge(Section * sc)
{
    setJudge(sc,wp,n);
}

void SectionManager::setJudge(Section * sc,wsParam *wp2, int n)
{
    //printf("SM setJudge %d\n",wp2[n].judge);
    Judge *judge = sc->selectJudge(wp2[n].judge);
    
    switch (wp2[n].judge)
    {
    case Section::TURNANGLE:
      //  printf("create turn angle judge\n");
        ((TurnAngleJudge *)judge)->setupdate(wp2[n].jflag);
        ((TurnAngleJudge *)judge)->setFinishAngle(wp2[n].fangle);
        break;
    case Section::LENGTH:
      //  printf("create length judge\n");
        ((LengthJudge *)judge)->setFinLength(wp2[n].flength);
        ((LengthJudge *)judge)->setupdate(wp2[n].jflag);
        break;
    case Section::BRIGHTNESS:
        ((BrightnessJudge *)judge)->setBrightness(wp2[n].bright1, wp2[n].bright2);
        break;
    case Section::COLOR:
        ((ColorJudge *)judge)->setColor(wp2[n].color1, wp2[n].color2);
        break;
    case Section::STOP:
        ((Stop *)judge)->setCount(wp2[n].count);
        break;
    case Section::ARMANGLE:
        ((ArmAngleJudge *)judge)->setFinAngle(wp2[n].fangle);
        break;
    case Section::TAILANGLE:
        ((TailAngleJudge *)judge)->setFinAngle(wp2[n].fangle);
        break;
    case Section::SONER:
        ((SonerJudge *)judge)->setLength(wp2[n].flength,1);
        break;
    }
 }

void SectionManager::setWPointer(wsParam *ptr)
{
    wp = ptr;
}

int SectionManager::getError()
{
    return error_code;
}