#include "ColorStatusJudge.h"

#include "math.h"
ColorStatusJudge::ColorStatusJudge()
{
    color[0]=0; //red
    color[1]=0; //green
    color[2]=0; //blue
    color[3]=0; //yellow
}

float ColorStatusJudge::status()
{

    float hue = mHsvHue->getValue();
    float sat = mHsvSatu->getValue();

    if (sat>0.4) {
        if(subhue(hue,GREEN_H)<30) {
            color[1]++;
        } 
        if(subhue(hue,RED_H)<30) {
            color[0]++;
        } 
         if(subhue(hue,BLUE_H)<30) {
            color[2]++;
        } 
         if(subhue(hue,YELLOW_H)<30) {
            color[3]++;
        }         

    }
    color_id=-1;
    int max_col=0;
    for(int i=0;i<4;i++) {
        if(max_col<color[i]) {
            color_id=i;
            max_col=color[i];
        }
    }
    
    printf("hue %f sat %f color_id %d (r %d g %d b %d y %d) \n",hue,sat,color_id, color[0],color[1],color[2],color[3]);
    return color_id;
}

float ColorStatusJudge::subhue(float h1, float h2)
{
    float diff =  h1 - h2;
    if(fabs(diff)>180) {
        diff = 360- fabs(diff);
    }   
    return fabs(diff);
}
