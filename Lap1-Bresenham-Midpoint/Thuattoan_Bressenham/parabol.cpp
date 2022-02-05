#pragma hdrstop
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//---------------------------------------------------------------------------

#pragma argsused

int goal(int wx)
{
 int i;

 int zufallsZahl;

 srand ( time(NULL) );
 zufallsZahl = rand() % 10 + 1;

 gotoxy(60 + zufallsZahl,24);
 printf("%c", 219);

 gotoxy(60 + zufallsZahl,25);
 printf("%c", 219);

 gotoxy(60 + zufallsZahl + 1, 25);
 printf("%c", 219);

 gotoxy(60 + zufallsZahl + 2, 25);
 printf("%c", 219);

 gotoxy(60 + zufallsZahl + 3, 25);
 printf("%c", 219);

 gotoxy(60 + zufallsZahl + 3, 24);
 printf("%c", 219);

 if(wx == 60 + zufallsZahl || wx == 60 + zufallsZahl + 1 || wx == 60 + zufallsZahl + 2 || wx == 60 + zufallsZahl + 3)
 {
  return(1);
 }
 else
 {
  return(0);
 }
}

int collision(int x, int y, int pHausX, int pHausY)
{
 int i;


 for(i=0;i<=5;i++)
 {
  if(x == pHausX+i && y < pHausY)
  {
       gotoxy(10,10);
       printf("Fail");
       return(-1);
  }
 }

 return(0);
}

int wurf(double v0, double alpha, int *pHausX, int *pHausY, int *pXw )
{
 double x,y;
 double xw;
 double tx;
 double pi = 3.14159;

 alpha = alpha * (2 * pi / 360);

 xw = ((v0*v0) * sin(2*alpha)) / 9.81;

 *pXw = xw;


 for(x=0; x<=xw; x++)
 {
    tx = x / (v0 * cos(alpha));
    y = -0.5 * 9.81 * (tx*tx) + v0 * sin(alpha) *tx;
    if(collision(x,(int)y, *pHausX, *pHausY) == 0)
    {
     if((int)y > 0)
     {
      if(y<25)
      {
       if(x<=80) //Abfrage falls größer als Bildschirm
       {
        gotoxy((int)x,25-(int)y);
        printf("*");
       }
      }
     }
    }
    else
    {
      return(-1);
    }
  }
 return(0);
}

void haus(int x, int w, int *pHausX, int *pHausY)
{
 int zufallsZahl;
 int y,i;

 srand ( time(NULL) );
 zufallsZahl = rand() % 10 + 1;

 *pHausX = x+zufallsZahl;
 *pHausY = zufallsZahl;

 for(y=0;y<zufallsZahl;y++)
 {
  gotoxy(x+zufallsZahl,25-y);
  for(i=0;i<=w;i++)
  {
   printf("%c", 219);
  }
 }
}

int main(int argc, char* argv[])
{

 int hausX = 0;
 int hausY = 0;
 int still;
 int xw;
 int *pXw = &xw;
 still = 1;

 do{

 clrscr();
 haus(30,5, &hausX, &hausY);

 gotoxy(1,1);
 printf("Haus X:%d", hausX);
 printf("Haus Y:%d", hausY);

 if(wurf(25,45, &hausX, &hausY, &pXw) == -1)
 {

  gotoxy(1,1);
  printf("Du hast das Hindernis getroffen... Du Luschen");
  printf("Noch mal? Ja(1) Nein(0)");
  scanf("%i", &still);
  clrscr();

 }
 else
 {

 gotoxy(1,1);
 printf("Wow... Du hast das Haus mal stehen gelassen.");
 if(goal(63) == 1)
  {

   getch();
   clrscr();
   gotoxy(1, 1);
   printf("Sieg!!!");
   getch();

  }
 getch();

 }

 }while(still == 1);

 printf("Lass dich hier nie mehr blicken.");
 getch();

 return 0;

 }
