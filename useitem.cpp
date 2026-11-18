
#include <stdio.h>
#include <string.h>
#include "1.h"

void useitem(int bullet[], int* allbullet, int* myHP, int* enemyHP)
{
    int item;
    int count = 0;
    int choice;
    int used;
    char input[20];

    for (int i = 0; i < 8; i++)
    {
        count += inventory[i];
    }

    if (count == 0)
        return;

    printf("아이템을 확인하려면 '인벤'을 입력하세요. 사용하지 않으려면 N을 입력하세요: ");
    scanf_s("%19s", input, (unsigned)sizeof(input));

    if (strcmp(input, "인벤") != 0)
        return;

    while (1)
    {
        showitem();

        printf("\n아이템을 사용하시겠습니까? (1. 예 / 2. 아니오): ");
        scanf_s("%d", &choice);

        while (choice != 1 && choice != 2)
        {
            printf("잘못된 입력입니다. 다시 입력하세요: ");
            scanf_s("%d", &choice);
        }

        if (choice == 2)
            return;

        printf("사용할 아이템 번호를 입력하세요: ");
        scanf_s("%d", &item);

        if (item < 1 || item > 8)
        {
            printf("잘못된 번호입니다.\n");
            continue;
        }

        item--;

        if (inventory[item] <= 0)
        {
            printf("보유하지 않은 아이템입니다.\n");
            continue;
        }

        used = 1;

        switch (item)
        {
        case 0: handcuffs(1); break;
        case 1:
            if (beer(bullet, allbullet) == 0)
                used = 0;
            break;
        case 2: cigarette(1, myHP, enemyHP); break;
        case 3: magnifier(bullet, allbullet, 1); break;
        case 4: saw(1); break;
        case 5:
            if (adrenaline(1) == 0)
                used = 0;
            break;
        case 6: cassette(bullet, allbullet); break;
        case 7: phone(bullet, allbullet, 1); break;
        }

        if (used == 1)
            inventory[item]--;
        else
            printf("아이템이 소모되지 않았습니다.\n");

        count = 0;

        for (int i = 0; i < 8; i++)
        {
            count += inventory[i];
        }

        if (count == 0)
        {
            printf("사용할 아이템이 더 이상 없습니다.\n");
            return;
        }

        printf("\n아이템을 더 사용하시겠습니까? (1. 예 / 2. 아니오): ");
        scanf_s("%d", &choice);

        while (choice != 1 && choice != 2)
        {
            printf("잘못된 입력입니다. 다시 입력하세요: ");
            scanf_s("%d", &choice);
        }

        if (choice == 2)
            return;
    }
}

