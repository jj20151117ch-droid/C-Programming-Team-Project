
#include <stdio.h>
#include "1.h"

int beer(int bullet[], int* allbullet)
{
    if (*allbullet - firstbullet <= 1)
    {
        printf("탄환이 1발 이하로 남아 있어 맥주를 사용할 수 없습니다.\n");
        return 0;
    }

    if (bullet[firstbullet] == 1)
        printf("맥주를 사용했습니다! 실탄을 배출했습니다.\n");
    else
        printf("맥주를 사용했습니다! 공포탄을 배출했습니다.\n");

    firstbullet++;

    return 1;
}

