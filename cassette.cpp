#include <stdio.h>
#include "1.h"

void cassette(int bullet[], int* allbullet)
{
    for (int i = firstbullet; i < *allbullet; i++)
    {
        bullet[i] = !bullet[i];
    }

    // 전화로 확인한 탄환 정보도 반전
    if (enemyphoneindex >= firstbullet && enemyphoneindex < *allbullet)
    {
        enemyphonebullet = !enemyphonebullet;
    }

    // 돋보기로 확인한 현재 탄환 정보도 반전
    if (enemyknowbullet == 1)
        enemyknowbullet = 2;
    else if (enemyknowbullet == 2)
        enemyknowbullet = 1;

    printf("카세트 테이프를 사용했습니다! 남은 탄환이 모두 반전되었습니다.\n");
}
