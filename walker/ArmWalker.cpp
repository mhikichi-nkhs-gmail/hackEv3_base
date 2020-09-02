#include "ArmWalker.h"
#include "Walker.h"
#include "util.h"
extern ArmWalker *gArmWalker;

ArmWalker::ArmWalker(Odometry *odo,
                    SpeedControl *scon):
    Walker(odo),
    mSpeedControl(scon)
{
    mArmAngle = gArmAngle;

    ap = 0;
    mTarget = 0.0;
    mPFactor = 0.0;
    mIFactor = 0.0;
    mDFactor = 0.0;
    kind = 1;
    stop_flag = 0;
}

void ArmWalker::setPwm(float target, float kp, float ki, float kd)
{
    mTarget = target;
    mPFactor = kp;
    mIFactor = ki;
    mDFactor = kd;

    mPid->setLimit(50);
    mPid->setTarget(mTarget);
    mPid->setKp(mPFactor);
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
}

void ArmWalker::run()
{
    if(stop_flag == 0){
        ap = (int)mPid->getOperation(mArmAngle->getValue());
        mOdo->setArmpwm(ap);
    }
}

void ArmWalker::init()
{
    gArmWalker->setPwm(mTarget,mPFactor,mIFactor,mDFactor);
}

void ArmWalker::setFlag(int f)
{
    stop_flag = f;
}