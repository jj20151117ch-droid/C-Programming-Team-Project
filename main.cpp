#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "1.h"
#include <Windows.h>

int round = 1;

int main()
{
    srand((unsigned)time(NULL));                                  

    int bullet[10];
    int allbullet, livebullet, blankbullet;
    int myHP, enemyHP;

    round = 1;

    while (round <= 3)
    {
        printf("\n========== %d 라운드 ==========\n", round);

        handcuffstate = 0;

        HP(&myHP, &enemyHP);

        resetitem();

        Setbullet(&allbullet, &livebullet, &blankbullet);
        bulletsuffle(bullet, allbullet, livebullet);

        giveitem();
        enemygiveitem();
                         

        printf("실탄 수 = %d, 공포탄 수 = %d\n", livebullet, blankbullet);  
        Sleep(1000);

        firstbullet = 0;

        while (myHP > 0 && enemyHP > 0)
        {
            if (firstbullet >= allbullet)
            {
                Setbullet(&allbullet, &livebullet, &blankbullet);
                bulletsuffle(bullet, allbullet, livebullet);
                firstbullet = 0;

                giveitem();
                enemygiveitem();

                printf("실탄 수 = %d, 공포탄 수 = %d\n", livebullet, blankbullet);
            }
            turn(bullet, &allbullet, &myHP, &enemyHP, livebullet, blankbullet);   
        }

        if (myHP <= 0)
        {
            round = 1;
            T = 1;
            printf("\n게임 재시작\n");                                     
            continue;                                                  
        }

        if (enemyHP <= 0 && round <= 2)
        {
            round++;
            continue;
        }
        else if (enemyHP <= 0 && round == 3)
        {
            printf("\n게임 클리어!\n");
            break;
        }
    }



}
