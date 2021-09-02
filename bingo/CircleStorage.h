#ifndef _CIRCLE_STORAGE_H_
#define _CIRCLE_STORAGE_H_

#include "BlockStorage.h"

typedef struct gameCoordinates    //ゲーム内座標
{
    double x;
    double y;
} gameCoordinates;

class CircleStorage : public BlockStorage
{
public:
    CircleStorage(int n, Color color, gameCoordinates c_coordinates);    //コンストラクタ
    Color getColor();    //色を取得する
private:
    enum Color     //色
    {
        blue,    //青
        red,    //赤
        green    //緑
        yellow    //黄
    };
    Color color;    //色情報
    static const double r = 110;    //半径
    bool power_block_move;    //パワーブロック有効移動成立
    static const int dot_r = 30;    //点線半径
}

#endif