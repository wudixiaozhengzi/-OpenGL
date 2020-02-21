#include "pch.h"
#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

IMAGE mm;
void initGame();
void playChess();
int judge(int a,int b);

int flag = 0;	//标记轮到谁下棋
int board[20][20] = { 0 };//0表示没有下棋的状态

int main()
{
	initGame();
	playChess();
	while (1);//防止闪屏
	return 0;
}

void initGame() 
{
	initgraph(600,500);		//设置窗口大小
	loadimage(&mm, "3.jpg", 600, 500);
	putimage(0, 0, &mm);
	mciSendString("open 1.mp3 alias music", 0, 0, 0);//alias重命名
	mciSendString("play music repeat", 0, 0, 0);
	//绘制棋盘
	//画一直线，从(0,100)到(500,200)
	//特别注意的是端点，(100,100)这个点会被画上颜色，但(500,200)不会画上颜色
	//以下所有的矩形（或者说两点）描述方式，总是前一个点取得到，但后一个点取不到
	setlinecolor(BLACK);
	for (int i = 1; i < 20; i++)
	{
		line(0, i*25, 500, i*25);
		line(i*25, 0, i*25, 500);
	}
	setlinestyle(PS_SOLID,2);//设置为实线，宽度为2
	line(500,0,500,500);
	//在指定位置输出字符串
	outtextxy(510, 60, "玩家1：黑棋");
	outtextxy(510, 100, "玩家2：白棋");
}

void playChess()
{
	int x = 0, y = 0;
	int a = 0, b = 0;
	MOUSEMSG m;//定义鼠标信息

	//在 Windows 下，句柄是一个窗口的标识，得到句柄后，可以使用 Windows SDK 中的各种命令实现对窗口的控制。
	// 获得窗口句柄
	HWND hwnd= GetHWnd();
	// 使用 API 函数修改窗口名称
	SetWindowText(hwnd, TEXT("五子棋1.1"));

	while (1)
	{
		m = GetMouseMsg();//获取鼠标信息

		//鼠标的x坐标 - 附近交点的坐标（i*25）< 一个格子中间距离25/2取整
		//鼠标的x坐标 - 附近交点的坐标（j*25）< 一个格子中间距离25/2取整
		for (int i = 1; i < 20; i++)
		{
			for (int j = 1; j < 20; j++)
			{
				if (abs(m.x - i * 25) < 12 && abs(m.y - j * 25) < 12)
				{
					a = i;
					b = j;
					x = i * 25;
					y = j * 25;
				}
			}
		}
		if (m.uMsg == WM_LBUTTONDOWN)
		{//uMsg指定鼠标消息类型。L左 button按钮 down下
			if (board[a][b] != 0)
			{
				MessageBox(hwnd, "这里已有棋子", "五子棋", MB_OK);
				continue;
			}
			if (flag % 2 == 0)
			{
					setfillcolor(BLACK);//设置填充颜色
					solidcircle(x, y, 10);//画一个半径为10填充圆
					board[a][b] = 1;
			}
			else
			{
					setfillcolor(WHITE);//设置填充颜色
					solidcircle(x, y, 10);//画一个半径为10填充圆
					board[a][b] = 2;
			}
			flag++;
		}
		if (judge(a, b))
		{
			if (1 == flag % 2)
			{
				MessageBox(hwnd,"玩家1胜利","游戏结束",MB_OK);
				return;
			}
			else
			{
				MessageBox(hwnd, "玩家2胜利", "游戏结束", MB_OK);
				return;
			}
		}
	}
}

int judge(int a, int b)
{
	int i, j;
	int t = 2 - flag % 2;
	for (i = a - 4, j = b; i <= a; i++)//横向判输赢
	{
		if (i >= 1 && i < 16 && t == board[i][j] && t == board[i + 1][j] && t == board[i + 2][j] && t == board[i + 3][j] && t == board[i + 4][j])//受限于20*20棋盘大小
			return 1;
	}
	for (i = a, j = b - 4; j <= b; j++)
	{
		if (j >= 1 && j < 16 && t == board[i][j] && t == board[i][j + 1] && t == board[i][j + 2] && t == board[i][j + 3] && t == board[i][j + 4])
			return 1;
	}
	for (i = a-4, j = b - 4; j <= b; i++,j++)//斜下
	{
		if (i >= 1 && i < 16 && j >= 1 && j < 16 && t == board[i][j] && t == board[i+1][j + 1] && t == board[i+2][j + 2] && t == board[i+3][j + 3] && t == board[i+4][j + 4])
			return 1;
	}
	for (i = a - 4, j = b + 4; j >= b; i++, j--)
	{
		if (i >= 1 && i < 16 && j >= 1 && j < 16 && t == board[i][j] && t == board[i+1][j - 1] && t == board[i+2][j - 2] && t == board[i+3][j - 3] && t == board[i+4][j - 4])
			return 1;
	}
	return 0;
}