#pragma once

#include<iostream>
#include"wall.h"
#include"food.h"
using namespace std;

class Snake
{
	//�ڵ�
	struct Point
	{
		//������
		int x;
		int y;

		//ָ����
		Point* next;
	};

	

	Point* pHead; //ͷ

	Wall& wall;

	Food& food;

	bool isRool;//�ж��Ƿ�ѭ���ı�־
public:
	enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };

	Snake(Wall& wall_t,Food& food);
	//��ʼ����
	void initSnake();

	//���ٽڵ�
	void destroyPoint();

	//��ӽڵ�
	void addPoint(int x,int y); 

	//ɾ��β�ڵ�
	void deletePoint();

	//�ƶ�����
	//����ֵ�����ƶ��Ƿ�ɹ�
	bool move(char key);

	//�趨�Ѷ�
	//��ȡˢ��ʱ��
	int getSleepTime();
	//��ȡ�����
	int countList();

	//��ȡ����
	int getScore();
};