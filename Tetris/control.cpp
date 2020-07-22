#include"control.h"
#include"stdlib.h"
#include<stdio.h>

#define GAME_ROWS 18
#define GAME_COLS 12

int g_nType = 0;//方块的形状
int g_nRotate = 0;
int g_nRow = 0;
int g_nCol = 0;

char g_chCurBrick[4][4] = { 0 };

char g_chGameBackground[GAME_ROWS][GAME_COLS] = { 0 };

char g_BricksPool[][4] = {
	//长条
	1, 1, 1, 1,
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 0, 0, 0,

	1, 1, 1, 1,
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 0, 0, 0,


	//z形
	1, 1, 0, 0,
	0, 1, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	0, 1, 0, 0,
	1, 1, 0, 0,
	1, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 0, 0,
	0, 1, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	0, 1, 0, 0,
	1, 1, 0, 0,
	1, 0, 0, 0,
	0, 0, 0, 0,

	//反z形
	0,1,1,0,
	1,1,0,0,
	0,0,0,0,
	0,0,0,0,

	1,0,0,0,
	1,1,0,0,
	0,1,0,0,
	0,0,0,0,

	0, 1, 1, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	

	1, 0, 0, 0,
	1, 1, 0, 0,
	0, 1, 0, 0,
	0, 0, 0, 0,

	//L形
	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,

	1, 1, 1, 0,
	1, 0, 0, 0,
	0, 0, 0, 0,
	0,0,0,0,

	1,1,0,0,
	0,1,0,0,
	0,1,0,0,
	0,0,0,0,

	0,0,0,1,
	0,1,1,1,
	0,0,0,0,
	0,0,0,0,

	//反L形
	0,1,0,0,
	0,1,0,0,
	1,1,0,0,
	0,0,0,0,

	1,0,0,0,
	1,1,1,0,
	0,0,0,0,
	0,0,0,0,

	1,1,0,0,
	1,0,0,0,
	1,0,0,0,
	0,0,0,0,

	1,1,1,0,
	0,0,1,0,
	0,0,0,0,
	0,0,0,0,

	//正方形
	1,1,0,0,
	1,1,0,0,
	0,0,0,0,
	0,0,0,0,

	1, 1, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	//T字形
	0,1,0,0,
	1,1,1,0,
	0,0,0,0,
	0,0,0,0,

	1,0,0,0,
	1,1,0,0,
	1,0,0,0,
	0,0,0,0,

	1,1,1,0,
	0,1,0,0,
	0,0,0,0,
	0,0,0,0,

	0,1,0,0,
	1,1,0,0,
	0,1,0,0,
	0,0,0,0,
};
void GetNewBrick()
{
	int nAddRow = 0;
	g_nType = rand()%7;
	g_nRotate = rand() % 4;

	nAddRow = g_nType * 16 + g_nRotate * 4;
	//坐标
	g_nRow = 0;
	g_nCol = GAME_COLS / 2 - 1;
	for (size_t nRow = 0; nRow < 4; nRow++)
	{
		for (size_t nCol = 0; nCol < 4; nCol++)
		{
			g_chCurBrick[nRow][nCol] =
				g_BricksPool[nAddRow + nRow][nCol];
		}
	}
}


void InitBackground()
{
	for (size_t nRow = 0; nRow < GAME_ROWS; nRow++)
	{
		for (size_t nCol = 0; nCol < GAME_COLS; nCol++)
		{
			if (nRow == GAME_ROWS - 1 || nCol == 0 || nCol == GAME_COLS - 1)
			{
				g_chGameBackground[nRow][nCol] = 1;
			}
		}
	}
}
//移动
void MoveLeft()
{
	g_nCol--;
}

void MoveRight()
{
	g_nCol++;
}

void MoveDown()
{
	g_nRow++;
}

//旋转
void Rotate()
{
	int nAddRow = 0;
	g_nRotate = rand() % 4;
	nAddRow = g_nType * 16 + g_nRotate * 4;
	//坐标
	for (size_t nRow = 0; nRow < 4; nRow++)
	{
		for (size_t nCol = 0; nCol < 4; nCol++)
		{
			g_chCurBrick[nRow][nCol] =
				g_BricksPool[nAddRow + nRow][nCol];
		}
	}
}

//判断是否可以移动
int IsCanMove(int nRow, int nCol)
{
	for (size_t nIndexRow = 0; nIndexRow < 4; nIndexRow++)
	{
		for (size_t nIndexCol = 0; nIndexCol < 4; nIndexCol++)
		{
			if (g_chCurBrick[nIndexRow][nIndexCol] == 1)
			{
				if (g_chGameBackground[nRow + nIndexRow][nCol+nIndexCol]==1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
//判断是否能够旋转
int IsCanRotate()
{
	char chTempBrick[4][4] = { 0 };//存储下一个形状
	int nNextRotate = (g_nRotate + 1) % 4;
	int nAddRow = 16 * g_nType + 4 * nNextRotate;
	//复制下一个形状
	for (size_t nRow = 0; nRow < 4; nRow++)
	{
		for (size_t nCol = 0; nCol < 4; nCol++)
		{
			chTempBrick[nRow][nCol] = g_BricksPool[nAddRow + nRow][nCol];
		}
	}
	//判断旋转后是否重合
	for (size_t nIndexRow = 0; nIndexRow < 4; nIndexRow++)
	{
		for (size_t nIndexCol = 0; nIndexCol < 4; nIndexCol++)
		{
			if (chTempBrick[nIndexRow][nIndexCol] == 1)
			{
				if (g_chGameBackground[g_nRow + nIndexRow][g_nCol + nIndexCol] == 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

void FixBrick()//固定方块到背景
{
	for (size_t nIndexRow = 0; nIndexRow <4; nIndexRow++)
	{
		for (size_t nIndexCol = 0; nIndexCol < 4; nIndexCol++)
		{
			if (g_chCurBrick[nIndexRow][nIndexCol] == 1)
			{
				g_chGameBackground[g_nRow + nIndexRow][g_nCol + nIndexCol] = 1;
			}
		}
	}
}

//判断是否能够消行,若能够就消行
void FullLine()
{
	for ( size_t nRow = GAME_ROWS - 2; nRow >= 1; nRow--)
	{    
		bool bLineFull = true;
		for (size_t nCol = 0; nCol < GAME_COLS; nCol++)
		{
			if (g_chGameBackground[nRow][nCol] == 0)
				bLineFull = false;
		}
		if (bLineFull)
		{
			DeleteFullLine(nRow);
			FullLine();//用递归的方法解决多层消行
		}
	}
}
void DeleteFullLine(int nRow)
{
	for (size_t nMoveRow = nRow; nMoveRow >=1; nMoveRow--)
	{
		for (size_t nCol = 0; nCol < GAME_COLS; nCol++)
		{
			g_chGameBackground[nMoveRow][nCol] = g_chGameBackground[nMoveRow-1][nCol];
		}
	}
}

//存档
void SaveGame()
{
	FILE *pFile;
	pFile = fopen("data.txt", "wb");
	fwrite(&g_nCol,4,1,pFile);
	fwrite(&g_nRow, 4, 1, pFile);
	fwrite(&g_nRotate, 4, 1, pFile);
	fwrite(&g_nType, 4, 1, pFile);
	fwrite(g_chGameBackground, 1, GAME_ROWS*GAME_COLS, pFile);
	fwrite(g_chCurBrick, 1, 16, pFile);
	fclose(pFile);
}

//读档
void LoadGame()
{
	FILE *pFile;
	pFile = fopen("data.txt", "rb");
	fread(&g_nCol, 4, 1, pFile);
	fread(&g_nRow, 4, 1, pFile);
	fread(&g_nRotate, 4, 1, pFile);
	fread(&g_nType, 4, 1, pFile);
	fread(g_chGameBackground, 1, GAME_ROWS*GAME_COLS, pFile);
	fread(g_chCurBrick, 1, 16, pFile);
	fclose(pFile);
}


