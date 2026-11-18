#include <stdio.h>
#include "1.h"
#include <Windows.h>

int T = 1;

void turn(int bullet[], int* allbullet, int* myHP, int* enemyHP, int livebullet, int blankbullet)
{
	if (T == 1)
		myturn(bullet, allbullet, myHP, enemyHP);                                     
	else
		enemyturn(bullet, allbullet, myHP, enemyHP, livebullet, blankbullet);         

}


void myturn(int bullet[], int* allbullet, int* myHP, int* enemyHP)
{
    printf("내턴\n");

    if (handcuffstate == 2)
    {
        handcuffstate = 0;
        T = 0;
        printf("수갑 효과로 플레이어의 턴이 스킵되었습니다!\n");
        return;
    }

    // 아이템 사용
    useitem(bullet, allbullet, myHP, enemyHP);

    if (fire(bullet, allbullet, myHP, enemyHP) == 0)
        T = 0;
}

void enemyturn(int bullet[], int* allbullet, int* myHP, int* enemyHP, int livebullet, int blankbullet)
{
    

    bulletcount(bullet, *allbullet, firstbullet, &livebullet, &blankbullet);

    printf("상대턴\n");

    if (handcuffstate == 1)
    {
        handcuffstate = 0;
        T = 1;
        printf("수갑 효과로 상대의 턴이 스킵되었습니다!\n");
        return;
    }

    enemyuseitem(bullet, allbullet, myHP, enemyHP);

    // 아이템 사용 후 탄환 개수 다시 계산
    bulletcount(bullet, *allbullet, firstbullet, &livebullet, &blankbullet);

    if (enemyfire(bullet, livebullet, blankbullet, myHP, enemyHP) == 0)
        T = 1;
}
