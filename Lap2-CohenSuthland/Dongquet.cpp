#include <conio.h>
#include <iostream>
#include <graphics.h>
#include <stdlib.h>
using namespace std;
 
struct ToaDo
{
    int x,y;
};
//==============================================
void nhapDaGiac(ToaDo p[], int v)
{
    int i;
    for(i=0;i<v; i++){
        cout<<"\nNhap toa do dinh "<<i+1<<" : ";
        cout<<"\n\tx["<<(i+1)<<"] = "; cin>>p[i].x;
        cout<<"\n\ty["<<(i+1)<<"] = "; cin>>p[i].y;
    }
    p[i].x=p[0].x;
    p[i].y=p[0].y;
}
//==============================================
void veDaGiac(ToaDo p[], int v)
{
    for(int i=0;i<v;i++)
        line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
}
//==============================================
void ScanLine(ToaDo p[], int v)
{
    int xmin,xmax,ymin,ymax,c,mang[50];
    xmin=xmax=p[0].x;
    ymin=ymax=p[0].y;
    for(int i=0;i<v;i++){ if(xmin>p[i].x) xmin=p[i].x;
        if(xmax<p[i].x) xmax=p[i].x; if(ymin>p[i].y) ymin=p[i].y;
        if(ymax<p[i].y) ymax=p[i].y;
    }
    float y;
    y=ymin+0.01;
    while(y<=ymax){ 
        int x,x1,x2,y1,y2,tg;
        c=0;    
        for(int i=0;i<v;i++){ 
            x1=p[i].x;
            y1=p[i].y;
            x2=p[i+1].x;
            y2=p[i+1].y;
            if(y2<y1){ 
                tg=x1;x1=x2;x2=tg;
                tg=y1;y1=y2;y2=tg;
            }
            
            if(y<=y2&&y>=y1){
                if(y1==y2)  x=x1; 
                else{
                    x=((y-y1)*(x2-x1))/(y2-y1); 
                    x+=x1; 
                }
                if(x<=xmax && x>=xmin)
                    mang[c++]=x;   
            }
        }
        
        for(int i=0; i<c;i+=2){
                delay(30);
                line(mang[i],y,mang[i+1],y);
        }  
        y++;
    }
}
//nhap 10 dinh:
//1.(75,250),2.(210,250),3.(250,128),4.(291,250),5.(425,250)
//6.(318,331),7.(360,460),8.(249,380),9.(140,460),10.(182,331)
//3 7 1 5 9
int main()
{
    int cl,v;
    do{
        cout<<"\n Nhap so dinh da giac:"; cin>>v;
    }while(v<3);
    ToaDo p[v];
    nhapDaGiac(p,v);
    cout<<"\nChon mau (0-15) : "; cin>>cl;
    initwindow(500,600);
    veDaGiac(p,v);
    setcolor(cl);
    ScanLine(p, v);
    getch();
}
