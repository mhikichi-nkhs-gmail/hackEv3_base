#include "BingoArea.h"

BingoArea::BingoArea()    //コンストラクタ
{
    run_body = new RunningBody();
    initCircleBlock();    //交点サークル初期化
    initStorage();   //ブロックサークル初期化
}

void BingoArea::init_CircleBlock()    //交点サークル初期化
{
    game_coordinates coordinates;
    //（交点サークルナンバー, 色, 座標）
    coordinates.x = 0.0;
    coordinates.y = 0.0;
    object_management_array[0] = new IntersectionCircle(0, RED, coordinates);    //赤
    coordinates.y = 1.0;
    object_management_array[1] = new IntersectionCircle(1, RED, coordinates);    //赤
    coordinates.y = 2.0;
    object_management_array[2] = new IntersectionCircle(2, BLUE, coordinates);    //青
    coordinates.y = 3.0;
    object_management_array[3] = new IntersectionCircle(3, BLUE, coordinates);    //青
    coordinates.x = 1.0;
    coordinates.y = 0.0;
    object_management_array[4] = new IntersectionCircle(4, RED, coordinates);    //赤
    coordinates.y = 1.0;
    object_management_array[5] = new IntersectionCircle(5, RED, coordinates);    //赤
    coordinates.y = 2.0;
    object_management_array[6] = new IntersectionCircle(6, BLUE, coordinates);    //青
    coordinates.y = 3.0;
    object_management_array[7] = new IntersectionCircle(7, BLUE, coordinates);    //青
    coordinates.x = 2.0;
    coordinates.y = 0.0;
    object_management_array[8] = new IntersectionCircle(8, YELLOW, coordinates);    //黄
    coordinates.y = 1.0;
    object_management_array[9] = new IntersectionCircle(9, YELLOW, coordinates);    //黄
    coordinates.y = 2.0;
    object_management_array[10] = new IntersectionCircle(10, GREEN, coordinates);    //緑
    coordinates.y = 3.0;
    object_management_array[11] = new IntersectionCircle(11, GREEN, coordinates);    //緑
    coordinates.x = 3.0;
    coordinates.y = 0.0;
    object_management_array[12] = new IntersectionCircle(12, YELLOW, coordinates);    //黄
    coordinates.y = 1.0;
    object_management_array[13] = new IntersectionCircle(13, YELLOW, coordinates);    //黄
    coordinates.y = 2.0;
    object_management_array[14] = new IntersectionCircle(14, GREEN, coordinates);    //緑
    coordinates.y = 3.0;
    object_management_array[15] = new IntersectionCircle(15, GREEN, coordinates);    //緑

    for(int i = 0; i < INTERSECTION_CIRCLE_COUNT; i++)
    {
        intersection_circle[i] = i;
    }
    
    int block_num;
    char block_c;
    int  block_num[84];
    block_num['A'] = 1;
    block_num['B'] = 1;
    block_num['C'] = 2;
    block_num['D'] = 2;
    block_num['E'] = 3;
    block_num['F'] = 3;
    block_num['G'] = 4;
    block_num['H'] = 4;
    block_num['J'] = 5;
    block_num['K'] = 5;
    block_num['L'] = 6;
    block_num['M'] = 6;
    block_num['P'] = 7;
    block_num['Q'] = 7;
    block_num['R'] = 8;
    block_num['S'] = 8;

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_BLUE1);
    
    i = block_num[block_c];
    if(i - INTERSECTION_CIRCLE_COUNT = 1 || 2 || 5 || 6)
    {
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, BLUE, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 1]);
    }else{
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, BLUE, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 2]);
    }

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_BLUE2);
    
    i = block_num[block_c];
    if(i - INTERSECTION_CIRCLE_COUNT = 1 || 2 || 5 || 6)
    {
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, BLUE, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 1]);
    }else{
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, BLUE, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 2]);
    }

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_RED1);
    
    i = block_num[block_c];
    if(i - INTERSECTION_CIRCLE_COUNT = 1 || 2 || 5 || 6)
    {
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, RED, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 1]);
    }else{
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, RED, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 2]);
    }  

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_RED2);
    
    i = block_num[block_c];
    if(i - INTERSECTION_CIRCLE_COUNT = 1 || 2 || 5 || 6)
    {
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, RED, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 1]);
    }else{
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, RED, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 2]);
    }

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_GREEN1);
    
    i = block_num[block_c];
    if(i - INTERSECTION_CIRCLE_COUNT = 1 || 2 || 5 || 6)
    {
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, GREEN, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 1]);
    }else{
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, GREEN, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 2]);
    }

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_GREEN2);
    
    i = block_num[block_c];
    if(i - INTERSECTION_CIRCLE_COUNT = 1 || 2 || 5 || 6)
    {
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, GREEN, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 1]);
    }else{
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, GREEN, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 2]);
    }

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW1);
    
    i = block_num[block_c];
    if(i - INTERSECTION_CIRCLE_COUNT = 1 || 2 || 5 || 6)
    {
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, YELLOW, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 1]);
    }else{
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, YELLOW, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 2]);
    }

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW2);

    i = block_num[block_c];
    if(i - INTERSECTION_CIRCLE_COUNT = 1 || 2 || 5 || 6)
    {
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, YELLOW, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 1]);
    }else{
        object_management_array[i + INTERSECTION_CIRCLE_COUNT] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, YELLOW, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 2]);
    }
        
}

void BingoArea::initStorage()    //ブロックサークル初期化
{
    //(ブロック置き場ナンバー, 座標x,y)
    game_coordinates coordinates;
    int i = 0;
    coordinates.x = 1.5;
    coordinates.y = 1.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CenterStorage(i, coordinates);    //センターブロック置き場
    //(ブロック置き場ナンバー, 色, 座標x,y)
    i++;
    coordinates.x = 0.5;
    coordinates.y = 0.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, YELLOW, coordinates);    //黄  
    i++;
    coordinates.y = 1.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, GREEN, coordinates);    //緑
    i++;
    coordinates.y = 2.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, RED, coordinates);    //赤
    i++;
    coordinates.x = 1.5;
    coordinates.y = 0.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, BLUE, coordinates);    //青
    i++;
    coordinates.y = 2.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, YELLOW, coordinates);    //黄
    i++;
    coordinates.x = 2.5;
    coordinates.y = 0.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, GREEN, coordinates);    //緑
    i++;
    coordinates.y = 1.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, RED, coordinates);    //赤
    i++;
    coordinates.y = 2.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, BLUE, coordinates);    //青

    int j = INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT;
    for(i = 0; i < STORAGE_COUNT; i++)
    {
        storage[i] = j;
        j++;
    }
}

BingoArea::gameCoordinates BingoArea::objCoordinates(object object_type, int object_num)    //コース内要素座標を問い合わせる
{
    switch(object_type)
    {
        case block:
            return object_management_array[block[object_num]]->getCoordinates();
        case storage:
            return object_management_array[storage[object_num]]->getCoordinates();    
    }
}

runInfo BingoArea::runningInformation()    //走行体情報を問い合わせる
{
    return run_body->get_runInfo();    //走行体情報を問い合わせる
}

int BingoArea::circleColor(Coordinates pass_coordinates)    //交点サークルの色を問い合わせる
{
    int i;
    gameCoordiantes g_coordinates;
    for(i = 0; i < INTERSECTION_CIRCLE_COUNT; i++)
    {
        g_coordinates = object_management_array[i]->getCoordinates();
        if(coordinatesConparison(pass_coordinates, g_coordinates) == true)    //一致したら
        {
            break;
        }
    }
    return static_cast<IntersectionCircle>object_management_array[i]->getColor();    //色を取得する
}

BingoArea::color BingoArea::blockColor(int block_num)    //ブロックの色を問い合わせる
{
    return static_cast<ColorBlock>object_management_array[block[block_num]]->getColor();
}

bool BingoArea::objSuccsesPass(object object_type, int　object_num)   //有効移動成立しているか問い合わせる
{
    switch(object_type)
    {
        case block:
            return static_cast<Block>object_management_array[block[object_num]]->getSuccsesPass();
        case storage:
            return static_cast<Block>object_management_array[storage[object_num]]->getSuccsesPass();
    }
}

gameCoordinates BingoArea::relativeCoordinates(gameCoordinates coordinates, direction direction)    //相対座標に変換する
{
    double x = coordinates.x;
    double y = coordinates.y;
    switch(direction)
    {
        case NORTH:     //走行体向きが北の場合（ｘ、ｙ）→（ｙ、3-ｘ）
             x = coordinates.y;
             y = 3 - coordinates.x;
             break;
        case SOUTH:     //走行体向きが南の場合（ｘ、ｙ）→（3-ｙ、ｘ）
            x = 3 - coordinates.y;
            y = coordinates.x;
            break;
        case WEST:      //走行体向きが西の場合（ｘ、ｙ）→（3-ｙ、3-ｘ）
            x = 3 - coordinates.y;
            y = 3 - coordinates.x;
            break;
    }
    coordinates.x = x;
    coordinates.y = y,
    return coordinates;
}

gameCoordiantes BingoArea::absoluteCoordinates(gameCoordinates coordinates, direction direction)    //絶対座標に変換する
{
    double x = coordinates.x;
    double y = coordinates.y;
    switch(direction){
        case NORTH:     //走行体向きが北の場合（ｘ、ｙ）→（3-ｙ、ｘ）
             x = 3 - coordinates.y;
             y = coordinates.x;
             break;
        case SOUTH:     //走行体向きが南の場合（ｘ、ｙ）→（ｙ、3-ｘ）
            x = coordinates.y;
            y = 3 - coordinates.x;
            break;
        case WEST:      //走行体向きが西の場合（ｘ、ｙ）→（3-ｙ、3-ｘ）
            x = 3 - coordinates.y;
            y = 3 - coordinates.x;
            break;
    }
    coordinates.x = x;
    coordinates.y = y,
    return coordinates;
}

void updateRunInfo(gameCoordiantes new_coodiantes, direction new_direction, direction old_direction)
{
    Direction absolute_direction = convertDirection(old_direction, new_direction);
    run_body->setInfo(new_coodiantes, absolute_direction);
}

BingoArea::direction convertDirection(direction run_direction, direction relative_direction)
{
    direction new_direction;
    switch(run_direction)
    {
        case NORTH:
            switch(relative_direction)
            {
                case NORTH:
                    new_direction = WEST;
                    break;
                case EAST:
                    new_direction = NORTH;
                    break;
                case SOUTH:
                    new_direction = EAST;
                    break;
                case WEST:
                    new_direction = SOUTH;
                    break;
            }
            break;
        case EAST:
            new_direction = relative_direction;
            break;
        case SOUTH:
            switch(relative_direction)
            {
                case NORTH:
                    new_direction = EAST;
                    break;
                case EAST:
                    new_direction = SOUTH;
                    break;
                case SOUTH:
                    new_direction = WEST;
                    break;
                case WEST:
                    new_direction = NORTH;
                    break;
            }
            break;
        case WEST:
            switch(relative_direction)
            {
                case NORTH:
                    new_direction = SOUTH;
                    break;
                case EAST:
                    new_direction = WEST;
                    break;
                case SOUTH:
                    new_direction = NORTH;
                    break;
                case WEST:
                    new_direction = EAST;
                    break;
            }
            break;
    }
    return new_direction;
}