// 贪吃蛇.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"wall.h"
#include"snake.h"
#include"food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>
using namespace std;

//光标定位
void gotoxy1(HANDLE hOut1, int x, int y)
{
    COORD pos;
    pos.X = x; //横坐标
    pos.Y = y; //纵坐标
    SetConsoleCursorPosition(hOut1, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); //定义显示器句柄变量

int main() 
{
    //添加随机数种子
    srand((unsigned int)time(NULL));
    char preKey = NULL;

    Wall wall;
    wall.initWall();
    wall.drawWall();
    Food food(wall);
    food.setFood();

    Snake snake(wall,food);
    snake.initSnake();

    //是否死亡表示
    bool isDead = false;

    /*snake.move('w');
    snake.move('w');
    snake.move('a'); */

    gotoxy1(hOut, 0, Wall::ROW+1);
    cout << "得分：" << snake.getScore() << "分" << endl;

    while (!isDead)
    {
        //接受用户输入
        char key = _getch();
        //第一次按了左键，才不能激活游戏
        if (preKey == NULL && key == snake.LEFT)
        {
            continue;
        }

        do
        {
            if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
            {
                //判断本次按键是否与上次按键冲突
                if ((key == snake.LEFT && preKey == snake.RIGHT) ||
                    (key == snake.UP && preKey == snake.DOWN) ||
                    (key == snake.RIGHT && preKey == snake.LEFT) ||
                    (key == snake.DOWN && preKey == snake.UP)
                    )
                {
                    key = preKey;
                }
                else
                {
                    preKey = key;
                }

                
                if (snake.move(key) == true)
                {
                    ////移动成功
                    //system("cls");
                    //wall.drawWall();
                    gotoxy1(hOut, 0, Wall::ROW);
                    cout << "得分：" << snake.getScore() << "分" << endl;
                    Sleep(snake.getSleepTime());
                }
                else
                {
                    isDead = true;
                    break;
                }
            }
            else
            {
                //强制将错误按键变为上一次移动方向
                key = preKey;
            }
        } while (!_kbhit());

       
    }

    



//    //测试
//    wall.setWall(5, 4, '=');
//    wall.setWall(5, 5, '=');
//    wall.setWall(5, 6, '@');
//
//    wall.drawWall();
//
//    cout << wall.getWall(0, 0) << endl;
//    cout << wall.getWall(5, 4) << endl;
//    cout << wall.getWall(5, 6) << endl;
//    cout << wall.getWall(1, 1) << endl;
}

