#include <stdio.h>
#include "1.h"
#include <Windows.h>

int enemy(int livebullet, int blankbullet)
{
    // 전화로 확인한 탄환이 현재 탄환이라면 저장된 정보 사용
    if (firstbullet == enemyphoneindex)
        return enemyphonebullet;

    // 돋보기로 확인한 현재 탄환 정보 사용
    if (enemyknowbullet == 1)
        return 1;

    if (enemyknowbullet == 2)
        return 0;

    // 기존 판단 로직
    if (livebullet >= blankbullet)
        return 1;
    else
        return 0;
}
void bulletcount(int bullet[], int allbullet, int firstbullet, int* livebullet, int* blankbullet)
{
	*livebullet = 0;
	*blankbullet = 0;                                         

	for (int i = firstbullet; i < allbullet; i++)            
		if (bullet[i] == 1)
			(*livebullet)++;                                 
		else
			(*blankbullet)++;
}
