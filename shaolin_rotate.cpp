#include<iostream>
#include<graphics.h>
using namespace std;

void circlemidpt(int xc, int yc, int r)
{
    int x=0;
    int y=r;
    int d=1-r;
    while(x<=y)
    {
        putpixel(x+xc,y+yc,WHITE);
        putpixel(-x+xc,y+yc,WHITE);
        putpixel(x+xc,-y+yc,WHITE);
        putpixel(-x+xc,-y+yc,WHITE);
        putpixel(y+xc,x+yc,WHITE);
        putpixel(-y+xc,x+yc,WHITE);
        putpixel(y+xc,-x+yc,WHITE);
        putpixel(-y+xc,-x+yc,WHITE);

        if(d<0)
        {
            d+=2*x+3;
        }
        else{
            d+=2*(x-y)+5;
            y--;
        }
        x++;
    }
}

void shaolin(int xc, int yc, int r, int type)
{
    r=r/2;
    int x=0;
    int y=r;
    int d=1-r;
    while(x<=y)
    {
        if(type==1){
            putpixel(-y+xc,x+yc-r,WHITE);
            putpixel(-x+xc,-y+yc-r,WHITE);
            putpixel(-x+xc,y+yc-r,WHITE);
            putpixel(-y+xc,-x+yc-r,WHITE);

            putpixel(x+xc,y+yc+r,WHITE);
            putpixel(x+xc,-y+yc+r,WHITE);
            putpixel(y+xc,x+yc+r,WHITE);
            putpixel(y+xc,-x+yc+r,WHITE);
        }
        if(type==2){
            putpixel(x+xc-r,y+yc,WHITE);
            putpixel(y+xc-r,x+yc,WHITE);
            putpixel(-x+xc-r,y+yc,WHITE);
            putpixel(-y+xc-r,x+yc,WHITE);

            putpixel(-x+xc+r,-y+yc,WHITE);
            putpixel(-y+xc+r,-x+yc,WHITE);
            putpixel(x+xc+r,-y+yc,WHITE);
            putpixel(y+xc+r,-x+yc,WHITE);
        }

        if(d<0)
        {
            d+=2*x+3;
        }
        else{
            d+=2*(x-y)+5;
            y--;
        }
        x++;
    }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    while(1)
    { for(int i=1; i<=2; i++)
    {
        shaolin(70,90,50,i);
        circlemidpt(70,90,50);
        delay(50);
        cleardevice();
    }
    }
    getch();
    closegraph();
    return 0;
}
