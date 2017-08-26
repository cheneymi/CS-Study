//说明: 左键双击对应windows自带扫雷中的双键点击
   
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <list>
#include <cstdio>
   
using namespace std;
//数组索引转成坐标
#define X(v) (v) % WIDTH
#define Y(v) (v) / WIDTH
//坐标系统转换
#define BOARDX(x) ((x) - OFFSETX) / 2
#define BOARDY(y) (y) - OFFSETY
#define SCREENX(x) 2 * (x) + OFFSETX
#define SCREENY(y) (y) + OFFSETY
#define BACKGROUND_WHITE (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED)
#define FOREGROUND_WHITE (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
   
typedef enum {
    UNKNOWN,
    DISPLAY,
    MARKED
} State;
   
typedef enum {
    NUMBER,
    EMPTY,
    MINE
} MType;
   
typedef struct {
    State state;
    MType mtype;
    int val;
} Cell;
   
typedef bool (* CmpProc)(Cell& cell, void* pData);
   
int HEIGHT   = 16;
int WIDTH    = 16;
int MINE_CNT = 40;  //地雷数
int CELL_CNT;
//第一个格子的x, y偏移
int OFFSETX = 3;
int OFFSETY = 3;
int flagCnt;        //标记数
int mineLeft;       //地雷剩余
int unkwLeft;       //未知剩余
int liveLeft;       //生命剩余
COORD tmPos;        //计时坐标
COORD mnPos;        //地雷(剩余)坐标
COORD lvPos;        //生命坐标
bool bGameStart, bGameStop;     //游戏开始.结束标记
DWORD dwStart;
HANDLE hOut, hIn;
Cell cells[16][30];
   
void writeChar(LPCSTR pChar, COORD wrtCrd)
{
    DWORD wtn;
    WriteConsoleOutputCharacter(hOut, pChar, strlen(pChar), wrtCrd, &wtn);
}
   
void fillChar(TCHAR cChar, DWORD len, COORD wrtCrd)
{
    DWORD wtn;
    FillConsoleOutputCharacter(hOut, cChar, len, wrtCrd, &wtn);
}
   
void fillAttr(WORD attr, DWORD len, COORD wrtCrd)
{
    DWORD wtn;
    FillConsoleOutputAttribute(hOut, attr, len, wrtCrd, &wtn);
}
   
bool isCell(int x, int y)
{
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}
   
bool isMine(int x, int y)
{
    return isCell(x, y) && cells[y][x].mtype == MINE;
}
   
bool cmpState(Cell& cell, void* pData)
{
    return cell.state == *(State*)pData;
}
   
bool cmpMtype(Cell& cell, void* pData)
{
    return cell.mtype == *(MType*)pData;
}
//四周格子作比较
int aroundCmp(int x, int y, CmpProc cmp, void* pData)
{
    int nRet = 0;
    for (int y0=y-1; y0<=y+1; y0++)
    {
        for (int x0=x-1; x0<=x+1; x0++)
        {
            if (isCell(x0, y0) 
                && !(x0 == x && y0 == y))       //not self
            {
                nRet += cmp(cells[y0][x0], pData);
            }
        }
    }
    return nRet;
}
   
int aroundMines(int x, int y)
{
    int val = MINE;
    return aroundCmp(x, y, cmpMtype, &val);
}
   
int aroundMarks(int x, int y)
{
    int val = MARKED;
    return aroundCmp(x, y, cmpState, &val);
}
//扰乱数组的前n个元素
void ruffle(int* arr, int len, int n)
{
    for (int i=0; i<n; i++)
    {
        int j = rand() % len;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
//计时
void setElapsedTime()
{
    if (bGameStart && !bGameStop)
    {
        DWORD dwDelt = (GetTickCount() - dwStart) / 1000;
        if (dwDelt < 1000)
        {
            char buf[5] = {0};
            sprintf(buf, "%.3d\0", dwDelt);
            writeChar(buf, tmPos);
        }   
    }
}
//剩余雷数(仅显示, 非实际)
void setMinesLeft()
{
    char buf[5] = {0};
    sprintf(buf, "%2d\0", MINE_CNT - flagCnt);
    writeChar(buf, mnPos);
}
//剩余生命
void setLivesLeft(int delt = 0)
{
    char buf[5] = {0};
    liveLeft += delt;
    sprintf(buf, "%2d\0", liveLeft);
    writeChar(buf, lvPos);
}
   
void drawCell(int x, int y)
{
    Cell* pCell = &cells[y][x];
    COORD cellCrd = {SCREENX(x), SCREENY(y)};
    char buf[3] = {0};
    switch (pCell->state)
    {
    case UNKNOWN:
        sprintf(buf, "□\0");
        break;
    case MARKED:
        sprintf(buf, " P\0");   
        break;
    case DISPLAY:
        switch (pCell->mtype)
        {
        case MINE:
            sprintf(buf, " *\0");
            break;
        case EMPTY:
            sprintf(buf, "  \0");
            break;
        case NUMBER:
            sprintf(buf, " %d\0", pCell->val);
            fillAttr((WORD)pCell->val, 2, cellCrd);  //数字着色
            break;
        }
        break;
    }
    writeChar(buf, cellCrd);
}
//初始化信息栏
void initInfoBar()
{
    char buf[50] = {0};
    sprintf(buf, "生命: %2d   地雷: %2d   用时: 000\0", liveLeft, MINE_CNT);
    COORD crd = {(80 - strlen(buf)) / 2, SCREENY(HEIGHT) + 1};      //水平居中
    writeChar(buf, crd);
    crd.X += 6;     lvPos = crd;
    crd.X += 11;    mnPos = crd;
    crd.X += 11;    tmPos = crd;
}
   
void clearScreen()
{
    COORD crd = {0, 0};
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);
    fillChar(' ', csbi.dwSize.X * csbi.dwSize.Y, crd);
    fillAttr(FOREGROUND_WHITE, csbi.dwSize.X * csbi.dwSize.Y, crd);
}
   
void initGame()
{
    srand((unsigned)time(NULL));
    SetConsoleTitle("扫雷控制台版   F2: 初级; F3: 中级; F4: 高级");
    clearScreen();
    CELL_CNT = HEIGHT * WIDTH;
    OFFSETX = (80 - WIDTH * 2) / 2; //水平居中
    int* idxs = new int[CELL_CNT];  //地雷索引
    int i, x, y;
    //init cells and indexs
    for (i=0; i<CELL_CNT; i++)
    {
        cells[Y(i)][X(i)].mtype = EMPTY;
        cells[Y(i)][X(i)].state = UNKNOWN;
        idxs[i] = i;
    }
    ruffle(idxs, CELL_CNT, MINE_CNT);
    //fill mines
    for (i=0; i<MINE_CNT; i++)
    {
        cells[Y(idxs[i])][X(idxs[i])].mtype = MINE;
    }
    //fill nums && print the game
    for (y=0; y<HEIGHT; y++)
    {
        for (x=0; x<WIDTH; x++)
        {
            if (!isMine(x, y))
            {
                cells[y][x].val = aroundMines(x, y);
                cells[y][x].mtype = cells[y][x].val > 0 ? NUMBER : EMPTY;
            }
            drawCell(x, y);
        }
    }
    delete[] idxs;
   
    bGameStart = false;
    bGameStop  = false;
    mineLeft = MINE_CNT;
    unkwLeft = CELL_CNT;
    liveLeft = MINE_CNT / 20 + 1;   //每二十个雷加一条命
    flagCnt  = 0;
    initInfoBar();
}
   
void showAll()
{
    for (int i=0; i<CELL_CNT; i++)
    {
        cells[Y(i)][X(i)].state = DISPLAY;
        drawCell(X(i), Y(i));
    }
}
   
void showTip(const char* tipMsg, WORD attr = FOREGROUND_WHITE)
{
    COORD tipCrd = {(80 - strlen(tipMsg)) / 2, 1};
    writeChar(tipMsg, tipCrd);
    fillAttr(attr, strlen(tipMsg), tipCrd);
}
   
void gameWin()
{
    if (!bGameStop)
    {
        showTip("恭喜你, 你赢了! ", FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        bGameStop = true;
    }
}
   
void gameOver(int x, int y)
{
    setLivesLeft(-1);
    if (liveLeft == 0)
    {
        showAll();
        showTip("游戏结束, 请重新来过!", FOREGROUND_RED | FOREGROUND_INTENSITY);
        bGameStop = true;
    }
    else
    {
        COORD crd = {SCREENX(x), SCREENY(y)};
        WORD attr = FOREGROUND_WHITE;
        for (int i=0; i<6; i++)      //触雷闪烁
        {
            attr = FOREGROUND_WHITE ^ FOREGROUND_RED ^ attr;
            fillAttr(attr, 2, crd);
            Sleep(100);
        }
    }
}
   
void showAround(int x, int y)
{   
    list<COORD> lst;
    COORD crd = {x, y};
    lst.push_back(crd);
    while (!lst.empty())
    {
        crd = lst.front();
        lst.pop_front();
        x = crd.X;
        y = crd.Y;
        for (int x0=x-1; x0<=x+1; x0++)
        {
            for (int y0=y-1; y0<=y+1; y0++)
            {
                if (!isCell(x0, y0) || (x0 == x && y0 == y))
                {
                    continue;
                }
                Cell* pCell = &cells[y0][x0];
                if (pCell->state == UNKNOWN)
                {
                    if (pCell->mtype == MINE)
                    {
                        gameOver(x0, y0);
                        break;
                    }
                    else if (pCell->mtype == EMPTY)
                    {
                        crd.X = x0;
                        crd.Y = y0;
                        lst.push_back(crd);
                    }
                    unkwLeft--;
                    pCell->state = DISPLAY;
                    drawCell(x0, y0);
                }
            }   //end for
        }   //end for
    }
}
   
void onCellLDBLClick(int x, int y)
{
    Cell* pCell = &cells[y][x];
    //左双击对显示的数字格子起作用, 且该格子周围的标记数等于该数字
    if (pCell->mtype == NUMBER && pCell->state == DISPLAY 
        && aroundMarks(x, y) == pCell->val)
    {
        showAround(x, y);
    }
}
   
void onCellLClick(int x, int y)
{
    Cell* pCell = &cells[y][x];
    //左击只对未知格子起作用
    if (pCell->state == UNKNOWN)
    {
        if (pCell->mtype == MINE)
        {
            gameOver(x, y);
        }
        else
        {
            pCell->state = DISPLAY;
            unkwLeft--;
            drawCell(x, y);
            if (pCell->mtype == EMPTY)
            {
                showAround(x, y);
            }
        }
    }   
}
   
void onCellRClick(int x, int y)
{
    Cell* pCell = &cells[y][x];
    //右击对未知, 标记格子起作用
    if (pCell->state != DISPLAY)
    {
        if (pCell->state == UNKNOWN)
        {
            pCell->state = MARKED;
            mineLeft -= pCell->mtype == MINE ? 1 : 0;
            unkwLeft--;
            flagCnt++;
        }
        else
        {
            pCell->state = UNKNOWN;
            mineLeft += pCell->mtype == MINE ? 1 : 0;
            unkwLeft++;
            flagCnt--;
        }
        drawCell(x, y);
        setMinesLeft();
    }
}
   
void onKeyDown(WORD keyCode)
{
    switch (keyCode)
    {
    case VK_F2:     //初级
        HEIGHT   = 9;
        WIDTH    = 9;
        MINE_CNT = 10;
        initGame();
        break;
    case VK_F3:     //中级
        HEIGHT   = 16;
        WIDTH    = 16;
        MINE_CNT = 40;
        initGame();
        break;
    case VK_F4:     //高级
        HEIGHT   = 16;
        WIDTH    = 30;
        MINE_CNT = 99;
        initGame();
        break;
    case VK_F12:
        if (liveLeft < 99)
        {
            setLivesLeft(1);
        }
        break;
    default:
        break;
    }
}
   
void afterMouseEvent()
{
    if (!bGameStart)
    {
        bGameStart = true;
        dwStart = GetTickCount();
    }
    if (mineLeft == 0 && unkwLeft == 0)
    {
        gameWin();
    }
}
   
int main(int argc, char* argv[])
{
    hIn  = GetStdHandle(STD_INPUT_HANDLE);
    hOut = CreateConsoleScreenBuffer(
            GENERIC_WRITE,
            0,
            NULL,
            CONSOLE_TEXTMODE_BUFFER,
            NULL
            );
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cci);   //隐藏光标
    SetConsoleActiveScreenBuffer(hOut);
    initGame();
    //监听事件
    for (;;)
    {
        DWORD nEvts;
        GetNumberOfConsoleInputEvents(hIn, &nEvts);
        if (nEvts > 0)
        {
            INPUT_RECORD inpRec;
            ReadConsoleInput(hIn, &inpRec, 1, &nEvts);
            bool bClked = false;    //是否有合法鼠标事件发生
            if (!bGameStop && inpRec.EventType == MOUSE_EVENT)
            {
                int x = BOARDX(inpRec.Event.MouseEvent.dwMousePosition.X);
                int y = BOARDY(inpRec.Event.MouseEvent.dwMousePosition.Y);
                if (!isCell(x, y))
                {
                    continue;
                }
                bClked = true;
                switch (inpRec.Event.MouseEvent.dwButtonState)
                {
                case FROM_LEFT_1ST_BUTTON_PRESSED:
                    if (inpRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
                    {
                        onCellLDBLClick(x, y);
                        break;  //处理过双击不再处理单击
                    }
                    onCellLClick(x, y);
                    break;
                case RIGHTMOST_BUTTON_PRESSED:
                    onCellRClick(x, y);
                    break;
                default:
                    bClked = false;
                    break;
                }
                if (bClked)
                {
                    afterMouseEvent();
                }
            }
            if (inpRec.EventType == KEY_EVENT)  //按键事件
            {
                onKeyDown(inpRec.Event.KeyEvent.wVirtualKeyCode);
                Sleep(100);
            }
            FlushConsoleInputBuffer(hIn);
        }
        setElapsedTime();
        Sleep(50);
    }
    return 0;
}

