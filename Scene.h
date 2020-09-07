#ifndef _SCENE_H_
#define  _SCENE_H_

#include "SpeedSectionManager.h"
#include "SlalomSectionManager.h"
#include "GarageSectionManager.h"

class Scene{
    public:
        Scene();
        bool run();
        void execUndefined();
        void execStart();
        void execSpeed();
        void initSlalom();
        void execSlalom();
        void initGarage();
        void execGarage();

    private:
        enum State {
            UNDEFINED,
            START,
            SPEED,
            INIT_SLALOM,
            SLALOM,
            INIT_GARAGE,
            GARAGE,
            END
        };

        State mState;

        SpeedSectionManager *mSsm;
        SlalomSectionManager *mSlm;
        GarageSectionManager *mGsm;
};
#endif
