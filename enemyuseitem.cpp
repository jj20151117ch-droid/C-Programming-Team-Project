
#include <stdio.h>
#include <stdlib.h>
#include "1.h"

void enemyuseitem(int bullet[], int* allbullet, int* myHP, int* enemyHP)
{
    int maxHP = 5;

    int magnifierused = 0;

    while (1)
    {
        // 1. 담배 우선 사용
        if (enemyinventory[2] > 0 && *enemyHP < maxHP)
        {
            printf("딜러가 담배를 사용했습니다!\n");
            cigarette(2, myHP, enemyHP);
            enemyinventory[2]--;
            continue;
        }

        // 2. 돋보기 사용
        if (enemyinventory[3] > 0 &&
            enemyknowbullet == 0 &&
            magnifierused == 0 &&
            (*allbullet - firstbullet) > 1)
        {
            printf("딜러가 돋보기를 사용했습니다!\n");
            magnifier(bullet, allbullet, 2);
            enemyinventory[3]--;
            magnifierused = 1;
            continue;
        }

        // 3. 현재 남은 탄환 개수 확인
        int livebullet = 0;
        int blankbullet = 0;

        bulletcount(bullet, *allbullet, firstbullet,
            &livebullet, &blankbullet);

        // 4. 실탄이고 플레이어에게 발사한다면 톱 사용
        if (enemyknowbullet == 1 &&
            enemy(livebullet, blankbullet) == 1 &&
            enemyinventory[4] > 0 &&
            sawstate != 2)
        {
            printf("딜러가 톱을 사용했습니다!\n");
            saw(2);
            enemyinventory[4]--;
            continue;
        }

        // 5. 남은 아이템 개수 확인
        int count = 0;

        for (int i = 0; i < 8; i++)
            count += enemyinventory[i];

        if (count == 0)
            break;

        // 6. 남은 아이템 중 무작위로 하나 선택
        int item;

        // 사용할 수 있는 아이템 개수 확인
        int available = 0;

        for (int i = 0; i < 8; i++)
        {
            if (enemyinventory[i] > 0)
            {
                // 돋보기로 실탄을 확인했으면 맥주는 제외
                if (i == 1 && enemyknowbullet == 1)
                    continue;

                available++;
            }
        }

        // 사용할 아이템이 없으면 아이템 사용 종료
        if (available == 0)
            break;

        // 사용 가능한 아이템 중 랜덤 선택
        do
        {
            item = rand() % 8;

        } while (enemyinventory[item] <= 0 ||
            (item == 1 && enemyknowbullet == 1) ||
            (item == 3 && magnifierused == 1));

       

        switch (item)
        {
        case 0:
            handcuffs(2);
            break;

        case 1:
            if (beer(bullet, allbullet) == 0)
                return;
            break;

        case 2:
            cigarette(2, myHP, enemyHP);
            break;

        case 3:
            magnifier(bullet, allbullet, 2);
            break;

        case 4:
            saw(2);
            break;

        case 5:
            enemyinventory[item]--;

            if (adrenaline(2) == 0)
            {
                enemyinventory[item]++;
                return;
            }

            continue;

        case 6:
            cassette(bullet, allbullet);
            break;

        case 7:
            phone(bullet, allbullet, 2);
            break;
        }

        enemyinventory[item]--;

        // 아이템을 사용했으므로 다시 처음부터 검사
        continue;
    }
}

