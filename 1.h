#pragma once                //같은 헤더 파일에서 여러 번 #include 하더라도 한 번만 처리하도록 해주는 역할

extern int round;           //round라는 전역변수가 있는것을 알리는거 (선언하는거아님)
extern int firstbullet;
extern int T;
extern int nowbullet;
extern int inventory[8];         //아이템 인벤토리 배열
extern int enemyinventory[8];   // 딜러의 아이템 인벤토리
extern int handcuffstate;       // 수갑 효과가 적용 중인지 확인하는 변수
extern int sawstate;            // 톱 효과가 적용 중인지 확인하는 변수
extern int enemyknowbullet;     // 딜러가 확인한 탄환 정보
extern int enemyphoneindex;     // 전화로 확인한 탄환의 위치
extern int enemyphonebullet;    // 전화로 확인한 탄환의 종류


int Setbullet(int* allbullet, int* livebullet, int* blankbullet);                                         //함수 선언
void bulletsuffle(int bullet[], int allbullet, int livebullet);
void HP(int* myHP, int* enemyHP);
int fire(int bullet[], int* allbullet, int* myHP, int* enemyHP);
int active();
void turn(int bullet[], int* allbullet, int* myHP, int* enemyHP, int livebullet, int blankbullet);
void myturn(int bullet[], int* allbullet, int* myHP, int* enemyHP);
void enemyturn(int bullet[], int* allbullet, int* myHP, int* enemyHP, int livebullet, int blankbullet);
void bulletcount(int bullet[], int allbullet, int firstbullet, int* livebullet, int* blankbullet);
int enemy(int livebullet, int blankbullet);
int enemyfire(int bullet[], int livebullet, int blankbullet, int* myHP, int* enemyHP);

// 아이템 관리 함수
void resetitem(void);
void giveitem(void);
void enemygiveitem(void);
int randomitem(void);
void useitem(int bullet[], int* allbullet, int* myHP, int* enemyHP);
void showitem(void);
void enemyuseitem(int bullet[], int* allbullet, int* myHP, int* enemyHP);

// 아이템 효과 함수
void handcuffs(int user);
int beer(int bullet[], int* allbullet);
void cigarette(int user, int* myHP, int* enemyHP);
void magnifier(int bullet[], int* allbullet, int user);
void saw(int user);
int adrenaline(int user);
void cassette(int bullet[], int* allbullet);
void phone(int bullet[], int* allbullet, int user);
