#include "Scene.h"

#include "ev3api.h"

#include "Bingo.h"

#include "etroboc_ext.h" 

#include "HBTtask.h"

Scene::Scene():
    mState(UNDEFINED)
{
    mSsm = new SpeedSectionManager();
    mBsm = new BingoSectionManager();

}

bool Scene::run()
{
    switch(mState) {
        case UNDEFINED:
            execUndefined();
            break;
        case START:
            execStart();
            break;
        case SPEED: 
            execSpeed();
            break;
        case INIT_SPEED:
            initSpeed();
            break;
        case BINGO:
            execBingo();
            break;
        case INIT_BINGO:
            initBingo();
            break;
        case GARAGE:
            execGarage();
            break;
        case END:

            finish();

        default:
            return true;
    }
    return false;
}

void Scene::execUndefined()
{
    msg_log("Press Touch Button to start.");
 //   Bingo *mBingo = new Bingo();
 //     mBingo->get(); 

 
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);


  
    mState=START;
}
void Scene::execStart()
{
    bt = ev3_serial_open_file(EV3_SERIAL_BT);
    uint64_t c;
    c = fgetc(bt);

    if (c == 's')
    {
       msg_f("RunStart",2);
        mState = INIT_SPEED;
    }
    // とりあえず動かすだけなので、設計に基づいて書き直そう
    /*if (ev3_touch_sensor_is_pressed(EV3_PORT_1) == 1)
    {
            mState=INIT_SPEED;
    }*/
}
void Scene::execSpeed()
{
    if(mSsm->run()) //設定したパラメータで走行を終えた時にtrue
    {
        delete mSsm;
        mSsm = new SpeedSectionManager();
        msg_log("test length");
        mState = INIT_SPEED; //initSpeed()
    }
}
void Scene::initSpeed() //パラメータを設定した時true
{
    if (mSsm->init()){
        mState = SPEED; //execSpeed()
    }    
}

void Scene::execBingo()
{
    if(mBsm->run()) {
        delete mBsm;
         msg_log("test length2");
        mState = END;
    }
}

void Scene::initBingo(){

    mState = BINGO;

}
void Scene::execGarage()
{

}

void Scene::finish(){

    ETRoboc_notifyCompletedToSimulator();
}
