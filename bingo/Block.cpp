#include "Block.h"

const double Block::r = 30;    //半径
const double Block::h = 30;    //半径

Block::Block(int n)    //コンストラクタ
{
    travelable_area = new TravelableArea();    //走行可能領域のインスタンス生成
    block_num = n;    //引数で受け取った番号をブロックナンバーに格納する
    b_succses_pass = false;    //有効移動成立のメンバ変数に初期値を格納する
}

bool Block::getE_move()
{
    return b_succses_pass;    //有効移動成立を表す変数をリターン
}

void Block::EffectiveMovementJudgment(int block_num)    //ブロックの有効移動判定
{
    b_succses_pass = true;    //有効移動成立
}

gameCoordinates Block::BlockCoordinates()    //ブロック座標を問い合わせる
{
    return intersection_circle[block_num]->getCoordinates();    //ブロック座標を取得する
}