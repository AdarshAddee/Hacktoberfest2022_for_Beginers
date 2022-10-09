#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main()
{
    int gmode = DETECT,gdriver,i;
    char g[] = " ";
    initgraph(&gmode,&gdriver,g);
    for(i=4 ; i<=200 ; i+=3)
    {
        circle(320,240,i);
        delay(30);
    }
    getch();
}
