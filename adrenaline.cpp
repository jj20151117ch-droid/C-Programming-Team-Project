#include <stdio.h>
#include <stdlib.h>
#include "1.h"

int adrenaline(int user)
{
    int item;
    int count = 0;

    const char* itemname[8] =
    {
        "수갑",
        "맥주",
        "담배",
        "돋보기",
        "톱",
        "아드레날린",
        "카세트 테이프",
        "전화"
    };

    if (user == 1)
    {
        for (int i = 0; i < 8; i++)
            count += enemyinventory[i];

        if (count == 0)
        {
            printf("훔칠 아이템이 없습니다.\n");
            return 0;
        }

        do
        {
            item = rand() % 8;
        } while (enemyinventory[item] <= 0);

        enemyinventory[item]--;
        inventory[item]++;

        printf("아드레날린을 사용했습니다! 딜러의 [%s]을(를) 훔쳤습니다.\n", itemname[item]);
    }
    else
    {
        for (int i = 0; i < 8; i++)
            count += inventory[i];

        if (count == 0)
        {
            printf("훔칠 아이템이 없습니다.\n");
            return 0;
        }

        do
        {
            item = rand() % 8;
        } while (inventory[item] <= 0);

        inventory[item]--;
        enemyinventory[item]++;

        printf("딜러가 아드레날린을 사용했습니다! 플레이어의 [%s]을(를) 훔쳤습니다.\n", itemname[item]);
    }

    return 1;
}
