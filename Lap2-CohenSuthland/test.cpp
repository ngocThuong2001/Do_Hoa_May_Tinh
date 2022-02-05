#include <graphics.h>
 
#include<math.h>
int main()
{
    int x,y, r = 10;
    float t=0;
    initwindow(640,480);
 
    while(!kbhit()){
        t = t + 0.01;
        x = (int) (-r*(16 * sin(t)*sin(t)*sin(t)) + 0.5);
        y = (int) (-r*(13*cos(t)-5*cos(2*t)-2*cos(3*t)-cos(4*t)) + 0.5);
        putpixel(getmaxx()/2 + x,getmaxy()/2 + y,4);
    }
    getch();
    closegraph();
}
 
