#ifndef _SLALOM_SECTION_MANAGER_H_
#define _SLALOM_SECTION_MANAGER_H_
#include "SectionManager.h"



class SlalomSectionManager : public SectionManager
{
    public:
        SlalomSectionManager();
        void init();
        bool run();
        void adjustLength();

        using SectionManager::init;

    protected:

    private:
        #if defined(MAKE_RIGHT)
            const int _EDGE = LineTracer::LEFTEDGE;
        #else
            const int _EDGE = LineTracer::LEFTEDGE;
        #endif
        
float normal_spd=35;
float turn_spd=55;
float angle_offset=+0;
float rkp0=18,rki0=9,rkd0=3.1;
//float rkp=50,rki=10,rkd=6.5;
float rkp=30,rki=12,rkd=3.0;
float rkp2=35,rki2=25,rkd2=6.0;
//float rvkp=20,rvki=1.0,rvkd=2.1;
float rvkp=90,rvki=55.0,rvkd=9.5;
float tkp=10,tki=5,tkd=0.2;

int ONBOARD=10;
int CALIB=11;

        wParam a[100] = {
                        {0, Section::TRACER, Section::LENGTH,  48, 0,rkp0,rki0,rkd0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 55, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {0, Section::TRACER, Section::LENGTH,  45, 0,rkp0,rki0,rkd0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 60, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {CALIB, Section::TURN, Section::TURNANGLE, 0, -0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, 30, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {ONBOARD, Section::TURN, Section::TURNANGLE, 0, 0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0,turn_spd, false,Judge::UNUPDATE, 3, 0, 0.0, 0, 0, 0, 0, 0,Section::SONERSTATUS},
                        {0, Section::TRACER, Section::LENGTH,  35, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 4.8,0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {0, Section::WALKER, Section::LENGTH,  35, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 35, 0, _EDGE, Judge::UPDATE, 0, 0.2,0, 0, 0, 0, 0 , 0, Section::JNONE},
                    //１本目
                        {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0, rvkp,rvki,rvkd, 0, 0 /*setparam*/, -36, 0, 0, 0, true,Judge::UPDATE, 0,2, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -24, 0 /*setparam*/, 0, +18.0, 0, 0, true,Judge::UNUPDATE, +30+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0, rvkp,rvki,rvkd, 0, 0 /*setparam*/, +30+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,9, 0, 0, 0, 0, 0, Section::JNONE},
                    //2-3
                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, +24, 0 /*setparam*/, 0, -16.5, 0, 0, true,Judge::UNUPDATE, -20+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -20+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,14.5, 0, 0, 0, 0, 0, Section::JNONE},


                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -22, 0 /*setparam*/, 0, +13.5, 0, 0, true,Judge::UNUPDATE, +0+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {12, Section::TURN, Section::TURNANGLE, 0, -0.0,tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UNUPDATE, 25+angle_offset, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 25+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,19, 0, 0, 0, 0, 0, 0,Section::JNONE},
                    //抜けた
                        {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, rvkp,rvki,rvkd, +15, 0 /*setparam*/, 0, -19.5, 0, 0, true,Judge::UNUPDATE, -0+angle_offset, 0, 0, 0, 0, 0, 0, false,Section::JNONE},

                        //色
                        {0, Section::VIRTUAL2, Section::LENGTH,  30,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -0 ,0, 0, 0, true,Judge::UPDATE, 0,5, 0, 0, 0, 0, 0, false, Section::JNONE},
                       {0, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0,0, 0, 0, 0, 0 , 0, Section::JNONE},
                           {0, Section::WALKER, Section::BRIGHTNESS, 30, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 30, 0, false,Judge::UNUPDATE, 0, 0, 0.6, 1, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, rvkp,rvki,rvkd, -15, 0 /*setparam*/, 0, +10.0, 0, 0, true,Judge::UNUPDATE, 45+angle_offset, 0, 0, 0, 0, 0, 0, false,Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH,  30,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 45+angle_offset ,0, 0, 0, true,Judge::UPDATE, 0,4, 0, 0, 0, 0, 0, false, Section::COLORSTATUS},
                        {0, Section::VIRTUAL2, Section::LENGTH,  -40,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -180+45+angle_offset ,0, 0, 0, true,Judge::UNUPDATE, 0,-1, 0, 0, 0, 0, 0, false, Section::JNONE},
                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100,0, Section::JNONE},
                        {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UNUPDATE, -80, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
                           //ラインキャッチ
                       {0, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 13,0, 0, 0, 0, 0 , 0, Section::JNONE},

                        {12, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, +turn_spd, false,Judge::UPDATE, -38, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH,  normal_spd,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -38, 0, 0, 0, true,Judge::UPDATE, 0,3, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -20, 0 /*setparam*/, 0, +14.0, 0, 0, true,Judge::UNUPDATE, +35+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, normal_spd, normal_spd/4, false,Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::WALKER, Section::BRIGHTNESS, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, normal_spd, normal_spd/4, false,Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0,0, Section::JNONE},

                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::COLOR,  40, -0.1,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.2, 0 , false, Section::JNONE},
                        {12, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +170, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 30, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {12, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +80, 0, 0, 0, 0, 0, 0,0, Section::JNONE},

                    //    {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

                        // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
        };

        wParam b[100] = {
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        wParam *array[10]={a,b};
        wParam *wp;

};

#endif
