#include <stdio.h>
#include "1.h"

int sawstate = 0;

void saw(int user)
{
    sawstate = user;

    if (user == 1)
        printf("톱을 사용했습니다! 다음 발사의 피해량이 증가합니다.\n");
    else
        printf("딜러가 톱을 사용했습니다! 다음 발사의 피해량이 증가합니다.\n");
}
