#include <stdio.h>
#include "1.h"

int handcuffstate = 0;

void handcuffs(int user)
{
    if (handcuffstate != 0)
    {
        printf("이미 수갑 효과가 적용 중입니다.\n");
        return;
    }

    handcuffstate = user;

    if (user == 1)
    {
        printf("플레이어가 수갑을 사용했습니다!\n");
        printf("딜러의 다음 턴을 스킵합니다.\n");
    }
    else
    {
        printf("딜러가 수갑을 사용했습니다!\n");
        printf("플레이어의 다음 턴을 스킵합니다.\n");
    }
}
