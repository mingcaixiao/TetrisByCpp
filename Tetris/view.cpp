
#include"view.h"
#include"control.h"


void ShowBrick()
{
	for (size_t nRow = 0; nRow < 4; nRow++)
	{
		for (size_t nCol = 0; nCol < 4; nCol++)
		{
			if (g_chCurBrick[nRow][nCol] == 1)
			{
				WriteChar(nRow + g_nRow, nCol + g_nCol, "■",
					SetConsoleColor(COLOR_BLUE, COLOR_WHITE));
			}
		}
	}
}
void ShowBackground()
{
	for (size_t nRow = 0; nRow < GAME_ROWS; nRow++)
	{
		for (size_t nCol = 0; nCol < GAME_COLS; nCol++)
		{
			if (g_chGameBackground[nRow][nCol] == 1)
			{
				WriteChar(nRow, nCol, "■",
					SetConsoleColor(COLOR_PURPLE, COLOR_WHITE));
			}
			else
			{
				WriteChar(nRow, nCol, "□",
					SetConsoleColor(COLOR_PURPLE, COLOR_WHITE));
			}
		}
	}
}

void OnLeft()
{
	if (IsCanMove(g_nRow,g_nCol-1))
	{
		MoveLeft();
		ShowGame();
	}
}

void OnRight()
{
	if (IsCanMove(g_nRow,g_nCol+1))
	{
		MoveRight();
		ShowGame();
	}
}

void OnRotate()
{
	if (IsCanRotate())
	{
		Rotate();
		ShowGame();
	}
}

void ShowGame()
{
	system("cls");
	ShowBackground();
	ShowBrick();
}

void OnDown()
{
	if (IsCanMove(g_nRow + 1, g_nCol))
	{
		MoveDown();
		ShowGame();
	}
	else
	{
		//1.固定方块到背景
		FixBrick();

		//2.获取一个新方块
		GetNewBrick();
		//3.消行
		FullLine();
		ShowGame();
	}
}