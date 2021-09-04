#ifndef _BINGO_SECTION_MANAGER_H_
#define _BINGO_SECTION_MANAGER_H_

#include "SectionManager.h"
#include "RouteDecision.h"
#include "etroboc_ext.h"

typedef struct _Param2    //パラメータの構造体
{
    int flag;
    Section::WALKER_NO walk;
    Section::JUDGE_NO judge;
    float speed;
    float target;
    float kp;
    float ki;
    float kd;
    float angleTarget;
    float anglekp;

    float absangle;
    float round;

    float forward;
    float turn;

    bool _EDGE; //true=left,false=right


    Judge::JUDGE_MODE jflag;

    float fangle;
    float flength;
    float bright1;
    float bright2;
    float color1;
    float color2;
    float count;
    bool vangle;

} wParam3;

class BingoSectionManager : public SectionManager
{
public:
    BingoSectionManager();    //コンストラクタ
    bool run();    //走行する
    bool exe_run();
    void exe_number();
    void stateChange(Routedecision *routeDecision);    //状態遷移
    void init();    //初期化
    //void s_addSection();    //区間の追加
    void running();    //実行する
    static RouteDecision *circle_decision;
    static RouteDecision *block_decision;
private:
    enum State
    {
       INIT,
       RUN
    };
    wParam3 *wp;
    State mState;    //状態の変数
    int n;
    int i2 = 0;
    RouteDecision *rdState;

    #if defined(MAKE_RIGHT)
    const int _EDGE = LineTracer::LEFTEDGE;
    #else
    const int _EDGE = LineTracer::RIGHTEDGE;
    #endif

    ingo *mBingo; 

    //{-1の時終了, Section::使いたいwalker, Section::使いたいjudge, 速度, 0, pの値, dの値, iの値, 0, 0 ,
    ///*setparam*/, 直線仮想ライントレースの角度, 円仮想ライントレースの半径, 単純走行のパワー, 単純走法の曲がり具合, 線のどちらを進むか,
    //1の時現在地を更新可能, 終了角度, 終了距離,白黒割合 , 白黒計測フラグ, 色数値, 彩度数値,止まる秒数}
    
    
    //setparamの例,Virtual2->setParam(10,5, 0.2, 0.2,1,1)
    // tracer->setParam(30,0,30,0.2,0.1)
    //Virtual->setParam(20,2,0.2,0,1,1)
    //Walker->setCommand(0,10)
    int ho=0;
   
    void setWalker(Section *sc);
    void setJudge(Section *sc);
};

#endif