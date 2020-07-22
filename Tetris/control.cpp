#include"control.h"
#include"stdlib.h"
#include<stdio.h>

#define GAME_ROWS 18
#define GAME_COLS 12

int g_nType = 0;//�������״
int g_nRotate = 0;
int g_nRow = 0;
int g_nCol = 0;

char g_chCurBrick[4][4] = { 0 };

char g_chGameBackground[GAME_ROWS][GAME_COLS] = { 0 };

char g_BricksPool[][4] = {
	//����
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


	//z��
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

	//��z��
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

	//L��
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

	//��L��
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

	//������
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

	//T����
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
	//����
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
//�ƶ�
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

//��ת
void Rotate()
{
	int nAddRow = 0;
	g_nRotate = rand() % 4;
	nAddRow = g_nType * 16 + g_nRotate * 4;
	//����
	for (size_t nRow = 0; nRow < 4; nRow++)
	{
		for (size_t nCol = 0; nCol < 4; nCol++)
		{
			g_chCurBrick[nRow][nCol] =
				g_BricksPool[nAddRow + nRow][nCol];
		}
	}
}

//�ж��Ƿ�����ƶ�
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
//�ж��Ƿ��ܹ���ת
int IsCanRotate()
{
	char chTempBrick[4][4] = { 0 };//�洢��һ����״
	int nNextRotate = (g_nRotate + 1) % 4;
	int nAddRow = 16 * g_nType + 4 * nNextRotate;
	//������һ����״
	for (size_t nRow = 0; nRow < 4; nRow++)
	{
		for (size_t nCol = 0; nCol < 4; nCol++)
		{
			chTempBrick[nRow][nCol] = g_BricksPool[nAddRow + nRow][nCol];
		}
	}
	//�ж���ת���Ƿ��غ�
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

void FixBrick()//�̶����鵽����
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

//�ж��Ƿ��ܹ�����,���ܹ�������
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
			FullLine();//�õݹ�ķ�������������
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

//�浵
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

//����
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


