#include "TXLib.h"
#include "Ball.h"
void initChars (BallChar chars[], Ball balls[], int size);
void drawHitTable (Ball balls[], const int bnum, double x1, double y1, double x2, double y2, int topsnum = 5);
void moveBalls (Ball balls[], int bnum);
void drawBalls (Ball balls[], int bnum);
void testBalls (Ball balls[], int bnum);
void initBalls (Ball balls[], int bnum);
int main()
    {
    txCreateWindow (800, 600);
    txDisableAutoPause();
    const int bnum = 6;
    Ball balls[bnum];
    initBalls (balls, bnum);
    bool paused = false;
    balls[0].setName ("John");
    balls[1].setName ("Bill");
    balls[2].setName ("Alex");
    balls[3].setName ("Ilya");
    balls[4].setName ("Ded");
    balls[5].setName ("Egor");
    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        if (GetAsyncKeyState ('P'))
            {
            if (paused == false) paused = true;
            else paused = false;
            }
        if (!paused) moveBalls (balls, bnum);
        drawBalls (balls, bnum);
        testBalls (balls, bnum);
        //getch();
        //printf ("Point a\n");
        //getch();
        drawHitTable (balls, bnum, txGetExtentX() - 250, 50, txGetExtentX() - 50, txGetExtentY()/2 - 50);
        //printf ("Point d\n");
        //getch();
        //printf ("angle == %f\n", ABall.getAngle());
        txSleep(10);
        txSetFillColor (TX_BLACK);
        txClear();
        //txClearConsole();
        }


    return 0;
    }

void drawHitTable (Ball balls[], const int bnum, double x1, double y1, double x2, double y2, int topsnum)
    {
    txSetColor (TX_WHITE, 1);
    double xsize = x2 - x1;
    double ysize = y2 - y1;
    double liney = ysize/bnum;
    txLine (x1 + 20, y1, x1 + 20, y2);
    txDrawText (x1 + 20, y1, x2, y1 + liney, "������ �� ��������");
    BallChar chars[bnum];
    initChars (chars, balls, bnum);
    SortBallsCharacteristics (chars, 0, bnum - 1);
    if (bnum < topsnum) topsnum = bnum;
    char help[16] = {};
    for (int i = 0; i < topsnum; i++)
        {
        txLine (x1, y1 + liney * (i + 1), x2, y1 + liney * (i + 1));
        sprintf (help, "%d", i + 1);
        txDrawText (x1, y1 + liney * (i + 1), x1 + 20, y1 + liney * (i + 2), help);
        txDrawText (x1 + 20, y1 + liney * (i + 1), x2, y1 + liney * (i + 2), chars[i].namech);
        }
    txLine (x1, y2, x2, y2);
    }


void initChars (BallChar chars[], Ball balls[], int size)
    {
    for (int i = 0; i < size; i++)
        {
        chars[i] = balls[i].thisChars;
        }
    }



void initBalls (Ball balls[], int bnum)
    {
    for (int i = 0; i < bnum; i++)
        {
        Ball hball ((double)(i)/(double)(bnum) * txGetExtentX(), (double)(i)/(double)(bnum) * txGetExtentY(),
                    10, (i - bnum/2) * 15, 5, RGB ((double)(i)/(double)(bnum)*255, (double)(i)/(double)(bnum)*255, (double)(i)/(double)(bnum)*255), i, i);
        balls[i] = hball;
        }
    }

void drawBalls (Ball balls[], int bnum)
    {
    for (int i = 0; i < bnum; i++)
        {
        balls[i].draw();
        }
    }

void testBalls (Ball balls[], int bnum)
    {
    for (int i = 0; i < bnum; i++)
        {
        balls[i].testWallHit();
        }
    }

void moveBalls (Ball balls[], int bnum)
    {
    for (int i = 0; i < bnum; i++)
        {
        balls[i].move(1);
        }
    }

