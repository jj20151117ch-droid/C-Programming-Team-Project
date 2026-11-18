
#include <stdio.h>
#include "1.h"

// 인벤토리 출력 함수
void showitem(void)
{
    printf("\n===== ITEM INVENTORY =====\n");

    if (inventory[0] > 0)
        printf("1. 수갑 (%d개)\n", inventory[0]);

    if (inventory[1] > 0)
        printf("2. 맥주 (%d개)\n", inventory[1]);

    if (inventory[2] > 0)
        printf("3. 담배 (%d개)\n", inventory[2]);

    if (inventory[3] > 0)
        printf("4. 돋보기 (%d개)\n", inventory[3]);

    if (inventory[4] > 0)
        printf("5. 톱 (%d개)\n", inventory[4]);

    if (inventory[5] > 0)
        printf("6. 아드레날린 (%d개)\n", inventory[5]);

    if (inventory[6] > 0)
        printf("7. 카세트 테이프 (%d개)\n", inventory[6]);

    if (inventory[7] > 0)
        printf("8. 전화 (%d개)\n", inventory[7]);
}

