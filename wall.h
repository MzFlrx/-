#ifndef _WALL_HEAD
#define _WALL_HEAD
#include<iostream>

using namespace std;

class Wall
{
public:
	enum {
		ROW = 26,
		COL = 26,
	};

	//初始化墙
	void initWall();

	//画出墙壁
	void drawWall();

	//根据所以设置二维数组里的内容
	void setWall(int x, int y, char c);

	//根据索引获取当前位置符号
	char getWall(int x, int y);
private:
	char gameArray[ROW][COL];
};



#endif // !_WALL_HEAD
