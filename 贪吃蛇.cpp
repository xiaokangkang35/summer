#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>

#define SNAKESIZE 100 //蛇身体的最大节数
#define MAPWIDTH 118 //宽度
#define MAPHEIGHT 29 //高度

//食物坐标
struct {
    int x;
    int y;
}food;

//蛇的相关属性
struct {
    int speed;//蛇的速度
    int len;//蛇的长度
    int x[SNAKESIZE];
    int y[SNAKESIZE];
}snake;

int key = 72;

//用来判断蛇是否吃掉了食物
int changeFlag = 0;

//记录玩家的得分
int sorce = 0;
//光标指向指定位置
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//游戏边框及游戏初始画面
void drawMap()
{
    //上下边框
    for(int i = 0;i <= MAPWIDTH;i += 2)
    {
        gotoxy(i,0);
        printf("*");
        gotoxy(i,MAPHEIGHT);
        printf("*");
    }
    //左右边框
    for(int i = 0; i < MAPHEIGHT; i++)
    {
        gotoxy(0,i);
        printf("*");
        gotoxy(MAPWIDTH,i);
        printf("*");
    }

    //食物的随机生成
    while(1)
    {
        srand((unsigned int)time(NULL));
        food.x = rand() % (MAPWIDTH - 4) + 2;
        food.y = rand() % (MAPHEIGHT - 2) + 1;
        if(food.x % 2 == 0)
            break; 
    }
    //打印食物
    gotoxy(food.x,food.y);
    printf("@");
    //初始化蛇的属性
    snake.len = 3;
    snake.speed = 200;
    //屏幕中心生成蛇头
    snake.y[0] = MAPHEIGHT / 2;
    snake.x[0] = MAPWIDTH / 2 + 1;//x的坐标为偶数
    //蛇头的打印
    gotoxy(snake.x[0],snake.y[0]);
    printf("*");

    for(int i = 1;i < snake.len;i++)
    {
        snake.x[i] = snake.x[i - 1] + 2;
		snake.y[i] = snake.y[i - 1];
		gotoxy(snake.x[i], snake.y[i]);
		printf("*");
    }
    gotoxy(MAPWIDTH - 2, 0);
	return;
}

//按键操作
void keyDown()
{
    int pre_key = key;//前一个按键的方向
    if(_kbhit())
    {
        fflush(stdin);
        key = _getch();
        key = _getch();
    }
    
    if(changeFlag == 0)
    {
        gotoxy(snake.x[snake.len-1],snake.y[snake.len-1]);
        printf(" ");
    }

    for(int i = snake.len - 1; i > 0; i--)
    {
        snake.x[i] = snake.x[i-1];
        snake.y[i] = snake.y[i-1];
    }

    if (pre_key == 72 && key == 80)
		key = 72;
	if (pre_key == 80 && key == 72)
		key = 80;
	if (pre_key == 75 && key == 77)
		key = 75;
	if (pre_key == 77 && key == 75)
		key = 77;
    //判断蛇头移动方向
    switch(key)
    {
        case 75:
            snake.x[0] -= 2;//往左
            break;
        case 77:
            snake.x[0] += 2;//往右
		break;
        case 72:
		    snake.y[0]--;//往上
		    break;
	    case 80:
		    snake.y[0]++;//往下
		    break;
    }
    gotoxy(snake.x[0],snake.y[0]);
    printf("*");
    gotoxy(MAPWIDTH - 2, 0);
    changeFlag = 0;
    return;
}

//食物的生成
void createFood()
{
    if (snake.x[0] == food.x && snake.y[0] == food.y)//蛇头碰到食物
    {
        while (1)
		{
			int flag = 1;
			srand((unsigned int)time(NULL));
			food.x = rand() % (MAPWIDTH - 4) + 2;
			food.y = rand() % (MAPHEIGHT - 2) + 1;
            for (int i = 0; i < snake.len; i++)
			{
				if (snake.x[i] == food.x && snake.y[i] == food.y)
				{
					flag = 0;
					break;
				}
			}
			//随机生成的食物不能横坐标为奇数，也不能在蛇身，否则重新生成
			if (flag && food.x % 2 == 0)
				break;
		}
        gotoxy(food.x,food.y);
        printf("@");

        snake.len++;
        sorce += 10;
        snake.speed -= 5;
        changeFlag = 1;
    }
    return;
}


//判断蛇运动是否合法
bool snakeStatus()
{
	//蛇头碰到上下边界，游戏结束
	if (snake.y[0] == 0 || snake.y[0] == MAPHEIGHT)
		return false;
	//蛇头碰到左右边界，游戏结束
	if (snake.x[0] == 0 || snake.x[0] == MAPWIDTH)
		return false;
	//蛇头碰到蛇身，游戏结束
	for (int i = 1; i < snake.len; i++)
	{
		if (snake.x[i] == snake.x[0] && snake.y[i] == snake.y[0])
			return false;
	}
	return true;
}

int main()
{
	drawMap();
	while (1)
	{
		keyDown();
		if (!snakeStatus())
			break;
		createFood();
		Sleep(snake.speed);
	}
 
	gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2);
	printf("Game Over!\n");
	gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2 + 1);
	printf("本次游戏得分为：%d\n", sorce);
	Sleep(5000);
	return 0;
}