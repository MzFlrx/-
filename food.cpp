#include"food.h"
#include<Windows.h>
//光标定位
void gotoxy2(HANDLE hOut1, int x, int y)
{
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(hOut1, pos);
}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE); //定义显示器句柄变量

void Food::setFood()
{
	int flag = 1;
	while (true)
	{
		foodX = rand() % (Wall::ROW - 2) + 1;
		foodY = rand() % (Wall::COL - 2) + 1;

		//如果随机的位置是蛇头或蛇身就重新生成
		if (wall.getWall(foodX, foodY) == ' ')
		{
			wall.setWall(foodX, foodY, '#');
			gotoxy2(hOut2, foodY * 2, foodX);
			cout << '#';
			break;
		}
	}
}


Food::Food(Wall& wall_t):wall(wall_t)
{
	foodX = 0;
	foodY = 0;
}