#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "1.h"
#include <Windows.h>

int Setbullet(int* allbullet, int* livebullet, int* blankbullet)
{
    if (round == 1)
        goto ONE;
    else if (round == 2)
        goto TWO;
    else
        goto THREE;

ONE:
    *allbullet = rand() % 4 + 2;                    
    if (*allbullet == 5)
        *livebullet = rand() % 2 + 2;                
    else
        *livebullet = rand() % (*allbullet - 1) + 1;  
    *blankbullet = *allbullet - *livebullet;
    goto END;

TWO:
    *allbullet = rand() % 5 + 4;                    
    if (*allbullet == 4)
        *livebullet = rand() % (*allbullet - 1) + 1; 
    else if (*allbullet == 5)
        *livebullet = rand() % 2 + 2;               
    else if (*allbullet == 6)
        *livebullet = rand() % 3 + 2;               
    else if (*allbullet == 7)
        *livebullet = rand() % 4 + 2;              
    else
        *livebullet = rand() % 3 + 3;               
    *blankbullet = *allbullet - *livebullet;
    goto END;

THREE:
    *allbullet = rand() % 6 + 5;                   
    if (*allbullet == 5)
        *livebullet = rand() % 2 + 2;               
    else if (*allbullet == 6)
        *livebullet = rand() % 3 + 2;               
    else if (*allbullet == 7)
        *livebullet = rand() % 4 + 2;               
    else if (*allbullet == 8)
        *livebullet = rand() % 3 + 3;               
    else if (*allbullet == 9)
        *livebullet = rand() % 3 + 4;               
    else
        *livebullet = rand() % 3 + 4;              
    *blankbullet = *allbullet - *livebullet;
    goto END;

END:
    return 0;
}

