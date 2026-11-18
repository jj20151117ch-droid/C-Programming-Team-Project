#include <stdio.h>
#include "1.h"

int enemyknowbullet = 0; // 딜러가 확인한 탄환 정보

void magnifier(int bullet[], int* allbullet, int user)
{
    if (firstbullet >= *allbullet)
    {
        printf("확인할 탄환이 없습니다.\n");
        return;
    }

    if (bullet[firstbullet] == 1)
    {
        if (user == 1)
            printf("돋보기 결과: 실탄입니다!\n");
        else
            printf("딜러가 돋보기로 탄환을 확인했습니다.\n");

        if (user == 2)
            enemyknowbullet = 1;
    }
    else
    {
        if (user == 1)
            printf("돋보기 결과: 공포탄입니다!\n");
        else
            printf("딜러가 돋보기로 탄환을 확인했습니다.\n");

        if (user == 2)
            enemyknowbullet = 2;
    }
}
