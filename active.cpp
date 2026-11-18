#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "1.h"
#include <Windows.h>

int firstbullet = 0;
int inventory[8] = { 0 };        // 플레이어의 아이템 인벤토리
int enemyinventory[8] = { 0 };   // 딜러의 아이템 인벤토리

int active()
{
    int select;
    printf("1: 나, 2: 상대\n");                                        // 1 = 자기자신에게 발사 , 2 = 상대에게 발사
    scanf("%d", &select);

    while (select != 1 && select != 2)                                 // 다른숫자 입력시 다시 입력
    {
        printf("1: 나, 2: 상대\n");
        scanf("%d", &select);
    }

    return select;
}

int fire(int bullet[], int* allbullet, int* myHP, int* enemyHP)
{
    if (firstbullet >= *allbullet)
        return 0;

    int select = active();                                            // 입력받은 값을 select로 
    int nowbullet = bullet[firstbullet];

    if (select == 1)                                                  // 나에게 발사
    {
        if (bullet[firstbullet] == 1)                                 //실탄
        {
            printf("실탄발사\n");						              //텍스트용
            printf("\n");
            Sleep(1000);

            if (sawstate == 1)
            {
                (*myHP) -= 2;
                printf("톱 효과! 피해량 2\n");
            }
            else
                (*myHP)--;

            printf("내 HP = %d\n", *myHP);                            //텍스트용
            printf("\n");
            Sleep(1000);
        }
        else                                                          //공포탄
        {
            printf("공포탄발사\n");
            printf("\n");
        }
    }
    else                                                              // 상대에게 발사
    {
        if (bullet[firstbullet] == 1)                                 //실탄
        {
            printf("실탄발사\n");						              //텍스트용
            printf("\n");
            Sleep(1000);

            if (sawstate == 1)
            {
                (*enemyHP) -= 2;
                printf("톱 효과! 피해량 2\n");
            }
            else
                (*enemyHP)--;
            printf("상대 HP = %d\n", *enemyHP);                      //텍스트용
            printf("\n");
            Sleep(1000);
        }
        else                                                         //공포탄
            printf("공포탄발사\n");						             //텍스트용
        printf("\n");
        Sleep(1000);
    }

    sawstate = 0;
    firstbullet++;

    if (select == 1 && nowbullet == 0)
        return 1;                             // 나에게 쐈는데 공포탄
    else
        return 0;                             // 그외의 경우
}


int enemyfire(int bullet[], int livebullet, int blankbullet, int* myHP, int* enemyHP)
{
    int nowbullet = bullet[firstbullet];

    // 발사 대상을 먼저 결정
    int target = enemy(livebullet, blankbullet);

    

    if (firstbullet == enemyphoneindex)
    {
        enemyphoneindex = -1;
        enemyphonebullet = -1;
    }

    if (target == 1)
    {
        printf("상대선택 : 나에게발사\n");
        Sleep(1000);

        if (nowbullet == 1)
        {
            printf("총알 : 실탄\n");
            printf("\n");
            Sleep(2000);

            if (sawstate == 2)
            {
                (*myHP) -= 2;
                printf("톱 효과! 피해량 2\n");
            }
            else
                (*myHP)--;

            printf("내 HP = %d\n", *myHP);
        }
        else
        {
            printf("총알 : 공포탄\n");
        }
    }
    else
    {
        printf("상대선택 : 본인에게발사\n");
        Sleep(500);

        if (nowbullet == 1)
        {
            printf("총알 : 실탄\n");
            Sleep(1000);

            if (sawstate == 2)
            {
                (*enemyHP) -= 2;
                printf("톱 효과! 피해량 2\n");
            }
            else
                (*enemyHP)--;

            printf("상대 HP = %d\n", *enemyHP);
        }
        else
        {
            printf("총알 : 공포탄\n");
        }
    }

    sawstate = 0;
    firstbullet++;
    // 현재 탄환 발사 후 정보 초기화
    enemyknowbullet = 0;

    if (target == 0 && nowbullet == 0)
        return 1;
    else
        return 0;
}

