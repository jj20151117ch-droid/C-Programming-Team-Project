#include <stdio.h>
#include <stdlib.h>
#include "1.h"

int enemyphoneindex = -1;
int enemyphonebullet = -1;

void phone(int bullet[], int* allbullet, int user)
{
    int count = *allbullet - firstbullet;

    if (count <= 1)
    {
        if (user == 1)
            printf("전화가 연결되었습니다. 안타깝게... 됐군...\n");
        else
            printf("딜러가 전화를 사용했습니다.\n");

        return;
    }

    int item = rand() % (count - 1) + firstbullet + 1;

    if (user == 1)
    {
        if (bullet[item] == 1)
            printf("전화 결과: %d번째 탄환은 실탄입니다!\n", item - firstbullet + 1);
        else
            printf("전화 결과: %d번째 탄환은 공포탄입니다!\n", item - firstbullet + 1);
    }
    else
    {
        enemyphoneindex = item;
        enemyphonebullet = bullet[item];

        printf("딜러가 전화를 사용했습니다.\n");
    }
}
