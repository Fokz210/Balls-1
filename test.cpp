
#include "TXLib.h"
#include "Ball.h"

int main()
    {
    srand(time(0));
    txCreateWindow (800, 600);
    BallChar test[10] = {};
    /*test[0].hitnumch = 3;
    test[1].hitnumch = 6;
    test[2].hitnumch = 3;
    test[3].hitnumch = 1;
    test[4].hitnumch = 6;
    test[5].hitnumch = 7;
    test[6].hitnumch = 4;
    test[7].hitnumch = 8;
    test[8].hitnumch = 5;
    test[9].hitnumch = 3;//*/
    for (int j = 0; j < 10; j++)
        {
        test[j].hitnumch = rand()%10;
        }           //*/
    printchars (test, 0, 9);
    SortBallsCharacteristics (test, 0, 9);
    printchars (test, 0, 9);
    return 0;
    }
