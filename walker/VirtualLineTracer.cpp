#include "VirtualLineTracer.h"
#include "math.h"
#define M_PI 3.14159265358979323846


VirtualLineTracer::VirtualLineTracer(Odometry *odo,
                        SpeedControl *scon)
                         : SimpleWalker(odo,scon) {
    cx=0;
    cy=0;
    ax=0;
    ay=0;
    basedistance=0;
    currentdistance=0;
    mTarget=0;
    mTargetSpeed=0;
    mPFactor=0;
    mIFactor=0;
    mDFactor=0;
    mLimit = 100;
}

void VirtualLineTracer::setParam(float speed,float kp, float ki, float kd,float angleTarget,float angleKp){

    mTargetSpeed = speed;
    
    mPFactor = kp;
    mIFactor = ki;
    mDFactor = kd;


    mPid->setTarget(fabs(mround));


    
    mPid->setKp(mPFactor); 
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
   
    mCurve = angleTarget;
    mAngleKp = angleKp;


    currentdistance = calcDistance();

    mPid->resetParam();
}

void  VirtualLineTracer::setRound(float round){
    mround = round;
}

void  VirtualLineTracer::init(){
 
        cx=mXPosition->getvalue()-mround*sin((mTurnAngle->getValue()/180)* M_PI);
        cy=mYPosition->getvalue()+mround*cos((mTurnAngle->getValue()/180)* M_PI);
    


    static char buf[100];
    //sprintf(buf,"%f,%f,%f",  cx,cy,mround );
    //msg_log(buf);

}



void VirtualLineTracer::setCenterPosition(float centerx,float centery){
    cx=centerx;
    cy=centery;
}

void VirtualLineTracer::setBaseDistance(){
    ax=mXPosition->getvalue();
    ay=mYPosition->getvalue();
      /*    static char buf[100];
    sprintf(buf,"%f,%f",  ax,ay );
    msg_log(buf);
*/
    basedistance = calcDistance();
}

float VirtualLineTracer::calcDistance(){
static char buf[100];
 //   sprintf(buf,"%f,%f", cos((mTurnAngle->getValue()/180)* M_PI),sin((mTurnAngle->getValue()/180)* M_PI));
   // msg_log(buf);

            if(mTargetSpeed<0){
        return  sqrt((ax-7*cos((mTurnAngle->getValue()/180)* M_PI)-cx)*(ax-7*cos((mTurnAngle->getValue()/180)* M_PI)-cx)+(ay-7*sin((mTurnAngle->getValue()/180)* M_PI)-cy)*(ay-7*sin((mTurnAngle->getValue()/180)* M_PI)-cy));
            
        }
        else{
           return  sqrt((ax+7*cos((mTurnAngle->getValue()/180)* M_PI)-cx)*(ax+7*cos((mTurnAngle->getValue()/180)* M_PI)-cx)+(ay+7*sin((mTurnAngle->getValue()/180)* M_PI)-cy)*(ay+7*sin((mTurnAngle->getValue()/180)* M_PI)-cy));
        }
    
        
}

float VirtualLineTracer::calcTurn(){
        

        float val1_turn =  mPid->getOperation(basedistance);
        setBias(-mForward*(1-mCurve)/(1+mCurve)*mAngleKp);
        float turn =  val1_turn+mBias;
        return turn;
}
void VirtualLineTracer::setLimit(float limit)
{
    mLimit=limit;
    mPid->setLimit(limit);
}


void VirtualLineTracer::run(){
    

    setBaseDistance();
 //      static char buf[100];
   // sprintf(buf,"%f,",);
    //msg_log(buf);
    if(mTargetSpeed>0){
        if(mround<0){
        
            mTurn = -(calcTurn());
        }
        else{
            mTurn = (calcTurn());
        }
    }
    else{
                if(mround<0){
        
            mTurn = (calcTurn());
        }
        else{
            mTurn = -(calcTurn());
        }


    }
         //  static char buf[100];
    //sprintf(buf,"%d",  mTurn );
    //msg_log(buf);


    setCommandV((int)mTargetSpeed, (int)mTurn);
    SimpleWalker::run();
}

 
void VirtualLineTracer::setBias(float curve){
     mBias = curve;

}