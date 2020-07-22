
#define GAME_ROWS 18
#define GAME_COLS 12

extern int g_nType;
extern int g_nRotate;
extern int g_nRow;
extern int g_nCol;


extern char g_chCurBrick[4][4];

extern char g_chGameBackground[GAME_ROWS][GAME_COLS];

void InitBackground();

void GetNewBrick();

void MoveLeft();

void MoveRight();

void MoveDown();

void Rotate();

int IsCanMove(int,int);

int IsCanRotate();

void  FixBrick();

void FullLine();

void DeleteFullLine(int nRow);

void SaveGame();

void LoadGame();
