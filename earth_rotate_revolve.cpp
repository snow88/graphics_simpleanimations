#include<iostream>
#include<graphics.h>

using namespace std;

void verticalline(int x1, int y1, int y2)
{
    for(int i=y1; i>=y2; i--)
        putpixel(x1, i, WHITE);
}

void circlemidpt (int xcentre, int ycentre, int R)
{
    int x=0, y=R, d=1-R;
    while(x<=y)
    {
        putpixel(x+xcentre, y+ycentre, WHITE);
        putpixel(-x+xcentre, y+ycentre, WHITE);
        putpixel(x+xcentre, -y+ycentre, WHITE);
        putpixel(-x+xcentre, -y+ycentre, WHITE);
        putpixel(y+xcentre, x+ycentre, WHITE);
        putpixel(-y+xcentre, x+ycentre, WHITE);
        putpixel(y+xcentre, -x+ycentre, WHITE);
        putpixel(-y+xcentre, -x+ycentre, WHITE);

        if(d<0)
            d+=2*x+3;
        else{
            d+=2*(x-y)+5;
            y--;
        }
        x++;
    }
}

void pattern(int xc, int yc, int r, int type)
{
    if(type==1)
    {
        verticalline(xc, yc+r, yc-r);
        verticalline(xc+r*0.25, yc+r*0.9, yc-r*0.9);
        verticalline(xc-r*0.25, yc+r*0.9, yc-r*0.9);
        verticalline(xc+r*0.5, yc+r*0.8, yc-r*0.8);
        verticalline(xc-r*0.5, yc+r*0.8, yc-r*0.8);
        verticalline(xc+r*0.75, yc+r*0.6, yc-r*0.6);
        verticalline(xc-r*0.75, yc+r*0.6, yc-r*0.6);
    }

    if(type==2)
    {
        verticalline(xc+r*0.12, yc+r*0.95, yc-r*0.95);
        verticalline(xc-r*0.12, yc+r*0.95, yc-r*0.95);
        verticalline(xc+r*0.37, yc+r*0.85, yc-r*0.85);
        verticalline(xc-r*0.37, yc+r*0.85, yc-r*0.85);
        verticalline(xc+r*0.62, yc+r*0.7, yc-r*0.7);
        verticalline(xc-r*0.62, yc+r*0.7, yc-r*0.7);
        verticalline(xc+r*0.87, yc+r*0.5, yc-r*0.5);
        verticalline(xc-r*0.87, yc+r*0.5, yc-r*0.5);
    }
    if(type==3)
    {
        verticalline(xc, yc+r, yc-r);
        verticalline(xc+r*0.5, yc+r*0.8, yc-r*0.8);
        verticalline(xc-r*0.5, yc+r*0.8, yc-r*0.8);
    }


}


void ellipse(int xc, int yc, int a, int b)
{
    int x=a, y=0, d=(b*b/4)-a*b*b+a*a;
    while( b*b*abs(x)>= a*a*abs(y))
    {
        putpixel(x+xc,y+yc,WHITE);
        putpixel(-x+xc,y+yc,WHITE);
        putpixel(-x+xc,-y+yc,WHITE);
        putpixel(x+xc,-y+yc,WHITE);

        if(d<0)
            d+=2*a*a*y+3*a*a;
        else{
            d+=2*b*b-2*x*b*b+2*a*a*y+3*a*a;
            x--;
        }
        y++;
    }
    d=b*b*(x-1)*(x-1)+a*a*(y+0.5)*(y+0.5)-a*a*b*b;
    while(x>=0)
    {
        putpixel(x+xc,y+yc,WHITE);
        putpixel(-x+xc,y+yc,WHITE);
        putpixel(-x+xc,-y+yc,WHITE);
        putpixel(x+xc,-y+yc,WHITE);

        if (d<0)
        {
            d+=3*b*b-2*x*b*b+2*a*a+2*y*a*a;
            y++;
        }
        else
            d+=3*b*b-2*x*b*b;
        x--;
    }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    ellipse(300, 250, 150, 80);
    int i=0;
    while(1)
    {
        for(i=1; i<=8; i++)
        {
            ellipse(300, 250, 150, 80);
            if(i==1)
           {
                circlemidpt(300, 170, 30);
                pattern(300, 170, 30, 1);
            }
            if(i==2){
                circlemidpt(370, 185, 30);
                pattern(370, 185, 30, 3);
            }
            if(i==3){
                circlemidpt(450, 250, 30);
                pattern(450, 250, 30, 2);
            }
            if(i==4){
                circlemidpt(370, 315, 30);
                pattern(370, 315, 30, 3);
            }
            if(i==5){
                circlemidpt(300, 330, 30);
                pattern(300, 330, 30, 1);
            }
            if(i==6){
                circlemidpt(230, 315, 30);
                pattern(230, 315, 30, 3);
            }
            if(i==7){
                circlemidpt(150, 250, 30);
                pattern(150, 250, 30, 2);
            }
            if(i==8){
                circlemidpt(230, 185, 30);
                pattern(230, 185, 30, 3);
            }
            delay(60);
            cleardevice();
        }
    }
    getch();
    closegraph();
    return 0;
}
