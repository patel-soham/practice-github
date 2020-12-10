#include "Extern_variable.h"
void ExitGame()
{
    int i,check=0;
    for(i=4;i<length;i++)   //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //check's value increases as the coordinates of Head is equal to any other body coordinate
        }
        if(i==length||check!=0)
            break;
    }
    if(Head.x<=GA_XL||Head.x>=GA_XR||Head.y<=GA_YT||Head.y>=GA_YB||check!=0)
    {

            system("cls");
            printf("GAME OVER!!!\nPress any key to quit the game\n");
            exit(0);

    }
}
