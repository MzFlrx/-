#pragma once

#include<iostream>
#include"wall.h"
#include"food.h"
using namespace std;

class Snake
{
	//节点
	struct Point
	{
		//数据域
		int x;
		int y;

		//指针域
		Point* next;
	};

	

	Point* pHead; //头

	Wall& wall;

	Food& food;

	bool isRool;//判断是否循环的标志
public:
	enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };

	Snake(Wall& wall_t,Food& food);
	//初始化蛇
	void initSnake();

	//销毁节点
	void destroyPoint();

	//添加节点
	void addPoint(int x,int y); 

	//删除尾节点
	void deletePoint();

	//移动操作
	//返回值代表移动是否成功
	bool move(char key);

	//设定难度
	//获取刷屏时间
	int getSleepTime();
	//获取蛇身段
	int countList();

	//获取分数
	int getScore();
};