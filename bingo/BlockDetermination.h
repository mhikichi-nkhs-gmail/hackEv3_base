#ifndef _BLOCK_DETERMINATION_H_
#define _BLOCK_DETERMINATION_H_

#include "RouteDecision.h"

class BlockDetermination : public RouteDecision
{
public:
    BlockDetermination();    //コンストラクタ
    int routDecision();    //ルートを決定する
};