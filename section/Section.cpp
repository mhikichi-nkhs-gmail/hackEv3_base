#include "Section.h"
 
extern SimpleWalker *gWalker;
extern LineTracer *gTracer;
extern VirtualLineTracer *gVitual;
extern Odometry *gOdo;
extern SpeedControl *gSpeed;

Section::Section()
{
}

Section::~Section()
{
    msg_log("destruct Section");
    delete mWalker;
}


bool Section::run()
{
    //判定
    
   // if(mJudge->run()){
    //    return true;
    //}

    //走法
    mWalker->run();
    
    return false;
}

Walker *Section::selectWalker(int  no)
{
    switch(no) {
        case WALKER:
            mWalker = (Walker*)(new SimpleWalker(gOdo,gSpeed));
            break;
        case TRACER:
            mWalker = (Walker*)(new LineTracer(gOdo,gSpeed));
           break;
        case VIRTUAL:
            mWalker = (Walker*)(new VirtualLineTracer(gOdo,gSpeed));
            break;
        default:
            msg_log("selectWalker error!!");
    }

    return mWalker;
}


Judge *Section::selectJudge(int no)
{
    switch(no) {
        case LENGTH:
            mJudge = (Judge*)(new LengthJudge());
            break;
        case TURNANGLE:
            mJudge = (Judge*)(new TurnAngleJudge());
            break;
        case BRIGHTNESS:
            mJudge = (Judge*)(new BrightnessJudge());
            break;
        case COLOR:
            mJudge = (Judge*)(new ColorJudge());
            break;
        default:
            msg_log("selectJudge error!!");
    }
    
    return mJudge;
}