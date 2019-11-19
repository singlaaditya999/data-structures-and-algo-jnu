#include<graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    initwindow(&gd,&gm);
    circle(300,300,50);
    closegraph();
    getch();
}

