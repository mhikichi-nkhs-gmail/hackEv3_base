#ifndef _BINGO_SECTION_MANAGER_H_
#define _BINGO_SECTION_MANAGER_H_
#include "SectionManager.h"
#include "Bingo.h"
#include "etroboc_ext.h"


    

typedef struct _Param2
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
    BingoSectionManager();
    void init(int i);
    bool run();
    bool exe_run();
    void exe_number();
    bool exe_run2();

protected:
private:


    enum State {
        INIT,
        NUMBER,
        RUN      
        };

        State mState;

    int n;
    int i2=0;


    #if defined(MAKE_RIGHT)
  const int _EDGE = LineTracer::LEFTEDGE;
#else
  const int _EDGE = LineTracer::RIGHTEDGE;
#endif

     Bingo *mBingo; 

    //{-1の時終了, Section::使いたいwalker, Section::使いたいjudge, 速度, 0, pの値, dの値, iの値, 0, 0 ,
    ///*setparam*/, 直線仮想ライントレースの角度, 円仮想ライントレースの半径, 単純走行のパワー, 単純走法の曲がり具合, 線のどちらを進むか,
    //1の時現在地を更新可能, 終了角度, 終了距離,白黒割合 , 白黒計測フラグ, 色数値, 彩度数値,止まる秒数}
    
    
    //setparamの例,Virtual2->setParam(10,5, 0.2, 0.2,1,1)
    // tracer->setParam(30,0,30,0.2,0.1)
    //Virtual->setParam(20,2,0.2,0,1,1)
    //Walker->setCommand(0,10)

   wParam3 a[100] = { 
                           
                         {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 10, 0, 0.3, 1, 1 /*setparam*/, 180, 20, 0, -30, true,Judge::UNUPDATE, -90, 8, 0, 0, 0, 0,0,false},
                        {0, Section::VIRTUAL2, Section::LENGTH, 10, 0, 10, 0, 0.4, 1,1 /*setparam*/,-90 , 0, 0, -30, true,Judge::UPDATE, -40, 14, 0, 0, 0, 0,0,false},
                         {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 10, 0, 0.3, 1, 1 /*setparam*/, 180, 20, 0, -30, true,Judge::UNUPDATE, 0, 8, 0, 0, 0, 0,0,false},
                            {0, Section::VIRTUAL2, Section::LENGTH, 10, 0, 20, 0, 0.4, 1,1 /*setparam*/,0, 0, 0, -30, true,Judge::UPDATE, -40, 70, 0, 0, 0, 0,0,false},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1,1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0,0,false}};

 wParam3 b[100] ={   {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 10, 0, 0.3, 1, 1 /*setparam*/, 180,-10 , 0, -30, true,Judge::UNUPDATE, -90, -40, 0, 0, 0, 0,0,false},
                    {0, Section::VIRTUAL2, Section::LENGTH, 8, 0, 10, 0, 0.3, 1,1  /*setparam*/, -90,90, 0, -30, true,Judge::UPDATE, -40, 30, 0, 0, 0, 0,0,false},
                     {0, Section::WALKER, Section::STOP, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, -85, 0, 0, 0, true,Judge::UNUPDATE, -90, 50, 0, 0, 0, 0,50,false},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0,0,false}
     
                };

 wParam3 c[100] ={  {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 10, 0, 0.3, 1, 1 /*setparam*/, 180,-10 , 0, -30, true,Judge::UNUPDATE, -90, -40, 0, 0, 0, 0,0,false},
                    {0, Section::VIRTUAL2, Section::LENGTH, 8, 0, 10, 0, 0.3, 1,1  /*setparam*/, -90,90, 0, -30, true,Judge::UPDATE, -40, 15, 0, 0, 0, 0,0,false},
                     {0, Section::WALKER, Section::STOP, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, -85, 0, 0, 0, true,Judge::UNUPDATE, -90, 50, 0, 0, 0, 0,50,false},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 10, 0, 0.3, 1, 1 /*setparam*/, 180,-20 , 0, -30, true,Judge::UNUPDATE, -180, -40, 0, 0, 0, 0,0,false},
                    {0, Section::VIRTUAL2, Section::LENGTH, 8, 0, 10, 0, 0.3, 1,1  /*setparam*/, -180,90, 0, -30, true,Judge::UPDATE, -40, 10, 0, 0, 0, 0,0,false},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0,0,false}
     
                };
wParam3 d[100] ={  {0, Section::VIRTUAL2, Section::LENGTH, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, 180, 0, 0, -30, true,Judge::UPDATE, -40, 8, 0, 0, 0, 0,0,false},
                     {0, Section::WALKER, Section::STOP, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, -85, 0, 0, 0, true,Judge::UNUPDATE, -90, 50, 0, 0, 0, 0,50,false},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0,0,false}
     
                };
wParam3 e[100] ={
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0,0,false}
     
                };
    wParam3 f[100] ={  {0, Section::VIRTUAL2, Section::LENGTH, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, 180, 0, 0, -30, true,Judge::UPDATE, -40, -40, 0, 0, 0, 0,0,false},
                     {0, Section::WALKER, Section::STOP, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, -85, 0, 0, 0, true,Judge::UNUPDATE, -90, 50, 0, 0, 0, 0,50,false},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0,0,false}
     
                };
wParam3 g[100] ={  {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 10, 0, 0.3, 1, 1 /*setparam*/, 180,10 , 0, -30, true,Judge::UNUPDATE, 90, -40, 0, 0, 0, 0,0,false},
                    {0, Section::VIRTUAL2, Section::LENGTH, 8, 0, 10, 0, 0.3, 1,1  /*setparam*/, 90,90, 0, -30, true,Judge::UPDATE, -40, 30, 0, 0, 0, 0,0,false},
                     {0, Section::WALKER, Section::STOP, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, -85, 0, 0, 0, true,Judge::UNUPDATE, -90, 50, 0, 0, 0, 0,50,false},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0,0,false}
     
                };
wParam3 h[100] ={  {0, Section::VIRTUAL2, Section::LENGTH, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, 180, 0, 0, -30, true,Judge::UPDATE, -40, -40, 0, 0, 0, 0,0,false},
                     {0, Section::WALKER, Section::STOP, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, -85, 0, 0, 0, true,Judge::UNUPDATE, -90, 50, 0, 0, 0, 0,50,false},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0,0,false}
     
                };
wParam3 i[100] ={  {0, Section::VIRTUAL2, Section::LENGTH, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, 180, 0, 0, -30, true,Judge::UPDATE, -40, -40, 0, 0, 0, 0,0,false},
                     {0, Section::WALKER, Section::STOP, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, -85, 0, 0, 0, true,Judge::UNUPDATE, -90, 50, 0, 0, 0, 0,50,false},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0,0,false}
     
                };
              
wParam3 l[100] ={  {0, Section::VIRTUAL2, Section::LENGTH, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, 180, 0, 0, -30, true,Judge::UPDATE, -40, -40, 0, 0, 0, 0,0,false},
                     {0, Section::WALKER, Section::STOP, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, -85, 0, 0, 0, true,Judge::UNUPDATE, -90, 50, 0, 0, 0, 0,500,false},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0,0,false}
     
                };
wParam3 *array[10]={a,b,c,d,e,f,g,h,i,l};
  wParam3 *wp;


    void setWalker(Section *sc);
    void setJudge(Section *sc);
};
#endif