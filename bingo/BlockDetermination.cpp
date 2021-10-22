#include "BlockDetermination.h"
#include "BingoSectionManager.h"

BlockDetermination::BlockDetermination()
:RouteDecision()
{
}

int BlockDetermination::routeDecision()    //ルートを決定する
{
	num = 0;
	min_cost = 999;
	double cost;
	gameCoordinates goal;
    run_info = bingo_area->runningInformation();    //走行体情報を問い合わせる
	for (int i = 1; i < BLOCK_COUNT; i++)
	{
        if (!bingo_area->objSuccsesPass(BLOCK, i))/*有効移動が成立しているか*/
        {
	        goal = bingo_area->objCoordinates(BLOCK, i);    //ブロック座標を問い合わせる
	        cost = block_list->getCost(run_info.rb_coordinates, goal);    //コストを取得する
	        if (minCompare(min_cost, cost))    //更新処理
            {
				//goal_coordinates本決まりさせなきゃいけないよ
				goal_coordinates = goal;
		        min_cost = cost;
		        num = i;
	        }
        }
	}
	printf("goal.x = %lf, y = %lf\n", goal_coordinates.x, goal_coordinates.y);
	bingo_area->updateTransportStatus(BLOCK, num);
    return num;    //取得したブロックナンバーをリターンする
}

void BlockDetermination::finishRun()
{
	bingo_manager->rdStateChange(BingoSectionManager::circle_decision);
}
