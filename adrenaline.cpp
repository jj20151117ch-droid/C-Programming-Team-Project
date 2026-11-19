
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
        // 딜러가 가진 아이템 개수 확인
        for (int i = 0; i < 8; i++)
            count += enemyinventory[i];

        if (count == 0)
        {
            printf("훔칠 아이템이 없습니다.\n");
            return 0;
        }

        // 딜러의 아이템 목록 출력
        printf("\n===== 훔칠 아이템 선택 =====\n");

        for (int i = 0; i < 8; i++)
        {
            if (enemyinventory[i] > 0)
                printf("%d. %s (%d개)\n",
                    i + 1, itemname[i], enemyinventory[i]);
        }

        printf("0. 취소\n");

        while (1)
        {
            printf("훔칠 아이템 번호를 선택하세요: ");
            scanf_s("%d", &item);

            if (item == 0)
            {
                printf("아드레날린 사용을 취소했습니다.\n");
                return 0;
            }

            if (item < 1 || item > 8)
            {
                printf("잘못된 번호입니다.\n");
                continue;
            }

            item--;

            if (enemyinventory[item] <= 0)
            {
                printf("딜러가 보유하지 않은 아이템입니다.\n");
                continue;
            }

            break;
        }

        enemyinventory[item]--;
        inventory[item]++;

        printf("아드레날린을 사용했습니다! 딜러의 [%s]을(를) 훔쳤습니다.\n",
            itemname[item]);
    }
    else
    {
        // 딜러는 기존처럼 무작위로 선택
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

        printf("딜러가 아드레날린을 사용했습니다! 플레이어의 [%s]을(를) 훔쳤습니다.\n",
            itemname[item]);
    }

    return 1;
}
