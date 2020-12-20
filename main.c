#include "All_Variables.h"

int main()
{
   char mm;
   l1:mm = main_menu();
   if(mm == '3')
		exit(0);
    else if(mm == '2'){
            instructions();
            goto l1;
    }

    else // mm = 1 i.e User wants to play game
    {
    system("cls");

    load();

    length=5;

    Head.x=25;

    Head.y=20;

    Head.direction=RIGHT;

    Wall();
    Score_display();

    Food(); //to generate food coordinates initially

    turn[0]=Head;

    Snake();   //initialing initial turn coordinate
    }

    return 0;

}
char main_menu(void){
    char ch;
    int i=3; // Max number of trials for input
    do{
        system("cls");
        printf("/////////////Welcome to the SNAKE GAME\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
        printf("               Main Menu\n");
        printf("1. Play\n");
        printf("2. Instructions\n");
        printf("3. Exit\n\n\n");
        printf("    Please enter choice number : ");
        scanf(" %c",&ch);
        if(ch=='1' || ch=='3' || ch=='2')
            return ch;
    }while(i--);
    system("cls");
    printf("\n\tGame exit because of consecutive invalid inputs!\n\n");
    exit(0);
}
void load(){
    int r,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=30;r++){
    for(q=0;q<=10000000;q++);//to display the character slowly
    printf("%c",177);}
    getch();
}
void instructions()
{
    system("cls");
    printf("/////////////Welcome to the SNAKE GAME\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
    printf("\t\tInstructions:\n");
    printf("\n-> Use arrow keys to navigate the snake.\n\n->Food is provided at various locations of the screen which you have to eat.\n\n->Eating the food increases the length of the snake by 1 element and also the score.\n\n-> Your GAME will finish as you hit the wall or snake's body.\n\n-> Game can be paused in middle by pressing any key and will continued by pressing any key once again\n\n-> Game can be exited by pressing esc. \n");
    printf("\n\nPress any key to return main menu...");
    getch();
}
void Wall()
{
   system("cls");
   int i;
   GotoXY(food.x,food.y);   /*displaying food*/
       printf("O");
   for(i=GA_XL;i<=GA_XR;i++)
   {
       GotoXY(i,GA_YT);
           printf("%c",176);
       GotoXY(i,GA_YB);
           printf("%c",176);
   }
   for(i=GA_YT+1;i<=GA_YB;i++)
   {
       GotoXY(GA_XL,i);
           printf("%c",176);
       GotoXY(GA_XR,i);
       printf("%c",176);
   }
}
void Food()
{
    if(Head.x==food.x&&Head.y==food.y)
    {
        length++;
        food.x=rand()%GA_XR;
        if(food.x<=GA_XL)
            food.x+=11;
        food.y=rand()%GA_YB;
        if(food.y<=GA_YT)
            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time */
    {
        food.x=rand()%GA_XR;
        if(food.x<=GA_XL)
            food.x+=11;
        food.y=rand()%GA_YB;
        if(food.y<=GA_YT)
            food.y+=11;
    }
}
void Snake()
{
    int a,i;

    do{

        Food();
        fflush(stdin);

        len=0;

        for(i=0;i<30;i++)

        {

            body[i].x=0;

            body[i].y=0;

            if(i==length)

            break;

        }

        Delay();

        Wall();
        Score_display();

        if(Head.direction==RIGHT)

            Go_Right();

        else if(Head.direction==LEFT)

            Go_Left();

        else if(Head.direction==DOWN)

            Go_Down();

        else if(Head.direction==UP)

            Go_Up();

        ExitGame();

    }while(!kbhit());

    a=getch();

    if(a==27)

    {

        system("cls");

        exit(0);

    }
    key=getch();

    if((key==RIGHT&&Head.direction!=LEFT&&Head.direction!=RIGHT)||(key==LEFT&&Head.direction!=RIGHT&&Head.direction!=LEFT)||(key==UP&&Head.direction!=DOWN&&Head.direction!=UP)||(key==DOWN&&Head.direction!=UP&&Head.direction!=DOWN))

    {

        turn_no++;

        turn[turn_no]=Head;

        Head.direction=key;

        if(key==UP)

            Head.y--;

        if(key==DOWN)

            Head.y++;

        if(key==RIGHT)

            Head.x++;

        if(key==LEFT)

            Head.x--;

        Snake();

    }

    else if(key==27)

    {

        system("cls");

        exit(0);

    }

    else

    {

        printf("\a");// for making beep sound

        Snake();

    }
}
void gotoxy(int x, int y)
{

 COORD temp;

 temp.X = x;

 temp.Y = y;

 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);

}
void GotoXY(int x, int y) // to avoid game lag issues
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }
void Delay()
{
    long double i;
    for(i=0;i<=(Game_delay);i++);// to slow down the game play
}
void Go_Up()
{
   int i;
   for(i=0;i<=(turn[turn_no].y-Head.y)&&len<length;i++)
   {
       GotoXY(Head.x,Head.y+i);
       {
           if(len==0)
               printf("^");
           else
               printf("*");
       }
       body[len].x=Head.x;
       body[len].y=Head.y+i;
       len++;
   }
   Turn();
   if(!kbhit())
       Head.y--;
}
void Go_Down()
{
    int i;
    for(i=0;i<=(Head.y-turn[turn_no].y)&&len<length;i++)
    {
        GotoXY(Head.x,Head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=Head.x;
        body[len].y=Head.y-i;
        len++;
    }
    Turn();
    if(!kbhit())
        Head.y++;
}
