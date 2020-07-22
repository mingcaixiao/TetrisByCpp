// Tetris.cpp : 定义控制台应用程序的入口点。
//
#include<stdio.h>
#include<stdlib.h>
#include"setdisplay.h"
#include"control.h"
#include"view.h"
#include<conio.h>
#include<time.h>

int main(int argc, int argv[])
{
	srand((unsigned)time(NULL));

	char chInput = 0;
	clock_t clkStart = 0;
	clock_t clkFinish = 0;

	InitBackground();
	GetNewBrick();
	ShowGame();

	while (1)
	{
		if (_kbhit() != 0)
		{
			chInput = _getch();
		}

		clkFinish = clock();

		if (clkFinish - clkStart > 500)
		{
			OnDown();
			clkStart = clkFinish;
		}
		switch (chInput)
		{
		case'a':
			OnLeft();
			break;
		case'w':
			OnRotate();
			break;
		case's':
			OnDown();
			break;
		case'd':
			OnRight();
			break;
		case'q':
			SaveGame();
			break;
		case'l':
			LoadGame();
			break;
		default:
			break;
		}
		chInput = 0;
	}

	return 0;
}
