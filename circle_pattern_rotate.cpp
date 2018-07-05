#include<iostream>
#include<graphics.h>
using namespace std;

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

void petalmidpt (int xcentre, int ycentre, int R, int type)
{
    int x=0, y=R, d=1-R;
    while(x<=y)
    {
        if(type == 1){
       putpixel(y+xcentre-xcentre*0.38, x+ycentre*1.4, WHITE);
       putpixel(-y+xcentre+xcentre*0.38, x+ycentre*1.4, WHITE);
       putpixel(y+xcentre-xcentre*0.38, -x+ycentre*1.4, WHITE);
       putpixel(-y+xcentre+xcentre*0.38, -x+ycentre*1.4, WHITE);
        }
       if(type == 2){
       putpixel(x+xcentre*0.6, y+ycentre-ycentre*0.35, WHITE);
       putpixel(-x+xcentre*0.6, y+ycentre-ycentre*0.35, WHITE);
       putpixel(x+xcentre*0.6, -y+ycentre+ycentre*0.35, WHITE);
       putpixel(-x+xcentre*0.6, -y+ycentre+ycentre*0.35, WHITE);
       }
       if(type == 3){
       putpixel(y+xcentre-xcentre*0.38, x+ycentre*0.6, WHITE);
       putpixel(-y+xcentre+xcentre*0.38, x+ycentre*0.6, WHITE);
       putpixel(y+xcentre-xcentre*0.38, -x+ycentre*0.6, WHITE);
       putpixel(-y+xcentre+xcentre*0.38, -x+ycentre*0.6, WHITE);
       }
       if(type == 4){
       putpixel(x+xcentre*1.4, y+ycentre-ycentre*0.35, WHITE);
       putpixel(-x+xcentre*1.4, y+ycentre-ycentre*0.35, WHITE);
       putpixel(x+xcentre*1.4, -y+ycentre+ycentre*0.35, WHITE);
       putpixel(-x+xcentre*1.4, -y+ycentre+ycentre*0.35, WHITE);
       }

        if(d<0)
            d+=2*x+3;
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
  int i;
  while(1)
  {
      for(i=1; i<=4; i++)
        {
            circlemidpt(90,99, 80);
            petalmidpt(90,99, 50, i);
            delay(16);
            cleardevice();
        }
  }
  getch();
  closegraph();
}
