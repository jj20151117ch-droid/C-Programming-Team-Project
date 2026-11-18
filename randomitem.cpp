#include <stdio.h>
#include <stdlib.h>
#include "1.h"

int randomitem(void)
{
    return rand() % 8;
}

// 라운드 시작 시 인벤토리 초기화
void resetitem(void)
{
    for (int i = 0; i < 8; i++)
    {
        inventory[i] = 0;
        enemyinventory[i] = 0;
    }
}

// 플레이어 아이템 지급

void giveitem(void)
{
    const char* itemname[8] =
    {
        "수갑", "맥주", "담배", "돋보기",
        "톱", "아드레날린", "카세트 테이프", "전화"
    };

    for (int i = 0; i < round; i++)
    {
        int count = 0;

        for (int j = 0; j < 8; j++)
            count += inventory[j];

        if (count >= 8)
        {
            printf("아이템 보유 한도에 도달했습니다.\n");
            break;
        }

        int item = randomitem();
        inventory[item]++;

        printf("아이템 획득: %s\n", itemname[item]);
    }
}
// 딜러 아이템 지급
void enemygiveitem(void)
{
    const char* itemname[8] =
    {
        "수갑", "맥주", "담배", "돋보기",
        "톱", "아드레날린", "카세트 테이프", "전화"
    };

    for (int i = 0; i < round; i++)
    {
        int count = 0;

        for (int j = 0; j < 8; j++)
            count += enemyinventory[j];

        if (count >= 8)
            break;

        int item = randomitem();
        enemyinventory[item]++;

        printf("딜러가 아이템을 획득했습니다: %s\n", itemname[item]);
    }
}

