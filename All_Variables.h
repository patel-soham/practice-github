#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define GA_XL 5
#define GA_XR 80
#define GA_YT 5
#define GA_YB 30
#define Game_delay 5000000

int length;
int turn_no;
int len;
char key;
char main_menu();
void load();
void Delay();
void Snake();
void Food();
int Score_display();
void instructions();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Turn();
void Wall();
void Go_Down();
void Go_Left();
void Go_Up();
void Go_Right();
void ExitGame();


struct coordinate{
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;

coordinate Head, turn[500],food,body[30];
