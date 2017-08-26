//˵��: ���˫����Ӧwindows�Դ�ɨ���е�˫�����
   
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <list>
#include <cstdio>
   
using namespace std;
//��������ת������
#define X(v) (v) % WIDTH
#define Y(v) (v) / WIDTH
//����ϵͳת��
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
int MINE_CNT = 40;  //������
int CELL_CNT;
//��һ�����ӵ�x, yƫ��
int OFFSETX = 3;
int OFFSETY = 3;
int flagCnt;        //�����
int mineLeft;       //����ʣ��
int unkwLeft;       //δ֪ʣ��
int liveLeft;       //����ʣ��
COORD tmPos;        //��ʱ����
COORD mnPos;        //����(ʣ��)����
COORD lvPos;        //��������
bool bGameStart, bGameStop;     //��Ϸ��ʼ.�������
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
//���ܸ������Ƚ�
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
//���������ǰn��Ԫ��
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
//��ʱ
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
//ʣ������(����ʾ, ��ʵ��)
void setMinesLeft()
{
    char buf[5] = {0};
    sprintf(buf, "%2d\0", MINE_CNT - flagCnt);
    writeChar(buf, mnPos);
}
//ʣ������
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
        sprintf(buf, "��\0");
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
            fillAttr((WORD)pCell->val, 2, cellCrd);  //������ɫ
            break;
        }
        break;
    }
    writeChar(buf, cellCrd);
}
//��ʼ����Ϣ��
void initInfoBar()
{
    char buf[50] = {0};
    sprintf(buf, "����: %2d   ����: %2d   ��ʱ: 000\0", liveLeft, MINE_CNT);
    COORD crd = {(80 - strlen(buf)) / 2, SCREENY(HEIGHT) + 1};      //ˮƽ����
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
    SetConsoleTitle("ɨ�׿���̨��   F2: ����; F3: �м�; F4: �߼�");
    clearScreen();
    CELL_CNT = HEIGHT * WIDTH;
    OFFSETX = (80 - WIDTH * 2) / 2; //ˮƽ����
    int* idxs = new int[CELL_CNT];  //��������
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
    liveLeft = MINE_CNT / 20 + 1;   //ÿ��ʮ���׼�һ����
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
        showTip("��ϲ��, ��Ӯ��! ", FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        bGameStop = true;
    }
}
   
void gameOver(int x, int y)
{
    setLivesLeft(-1);
    if (liveLeft == 0)
    {
        showAll();
        showTip("��Ϸ����, ����������!", FOREGROUND_RED | FOREGROUND_INTENSITY);
        bGameStop = true;
    }
    else
    {
        COORD crd = {SCREENX(x), SCREENY(y)};
        WORD attr = FOREGROUND_WHITE;
        for (int i=0; i<6; i++)      //������˸
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
    //��˫������ʾ�����ָ���������, �Ҹø�����Χ�ı�������ڸ�����
    if (pCell->mtype == NUMBER && pCell->state == DISPLAY 
        && aroundMarks(x, y) == pCell->val)
    {
        showAround(x, y);
    }
}
   
void onCellLClick(int x, int y)
{
    Cell* pCell = &cells[y][x];
    //���ֻ��δ֪����������
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
    //�һ���δ֪, ��Ǹ���������
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
    case VK_F2:     //����
        HEIGHT   = 9;
        WIDTH    = 9;
        MINE_CNT = 10;
        initGame();
        break;
    case VK_F3:     //�м�
        HEIGHT   = 16;
        WIDTH    = 16;
        MINE_CNT = 40;
        initGame();
        break;
    case VK_F4:     //�߼�
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
    SetConsoleCursorInfo(hOut, &cci);   //���ع��
    SetConsoleActiveScreenBuffer(hOut);
    initGame();
    //�����¼�
    for (;;)
    {
        DWORD nEvts;
        GetNumberOfConsoleInputEvents(hIn, &nEvts);
        if (nEvts > 0)
        {
            INPUT_RECORD inpRec;
            ReadConsoleInput(hIn, &inpRec, 1, &nEvts);
            bool bClked = false;    //�Ƿ��кϷ�����¼�����
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
                        break;  //�����˫�����ٴ�����
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
            if (inpRec.EventType == KEY_EVENT)  //�����¼�
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

