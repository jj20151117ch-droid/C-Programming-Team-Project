#include <stdio.h>
#include "1.h"

void cigarette(int user, int* myHP, int* enemyHP)
{
    if (user == 1)
    {
        if (*myHP < 5)
        {
            (*myHP)++;
            printf("담배를 사용했습니다! HP가 1 회복되었습니다.\n");
            printf("내 HP = %d\n", *myHP);
        }
        else
            printf("HP가 최대치입니다.\n");
    }
    else
    {
        if (*enemyHP < 5)
        {
            (*enemyHP)++;
            printf("딜러가 담배를 사용했습니다! HP가 1 회복되었습니다.\n");
            printf("상대 HP = %d\n", *enemyHP);
        }
        else
            printf("딜러의 HP가 최대치입니다.\n");
    }
}


