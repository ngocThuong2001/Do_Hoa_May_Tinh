#include<GL/glut.h>
#include<math.h>
#include<dos.h>
#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define pi 3.14
#include<iomanip>

using namespace std;
float xw1, yw1, xw2, yw2;
int xv1, yv1, xv2, yv2;
float tlx, tly;

void cuaso(float x1, float y1, float x2, float y2){
	xw1 = x1; 
	yw1 = y1;
	xw2 = x2;
	yw2 = y2;
}

void khungNhin(int x1, int y1, int x2, int y2){
	xv1 = x1; 
	yv1 = y1;
	xv2 = x2;
	yv2 = y2;
	
	tlx = (xv2 - xv1)/(xw2 - xw1), tly = (yv2 - yv1)/(yw2 - yw1);
}

void chuyenDen(float x, float y){
	int xm = (int) (tlx * (x-xw1) + xv1);
	int ym = (int) (tly * (yw2 - y) + yv1);
	moveto(xm, ym);
}

void veDen(float x, float y){
	int xm = (int) (tlx*(x - xwl) + xv1);
	int ym = (int) (tly*(yw2 -y) + yv1);
	lineto(xm,ym);
}

void chu(float x, float y, char *s){
	int xm = (int) (tlx * (x-xw1) + xv1);
	int ym = (int) (tly * (yw2 - y) + yv1);
	outtextxy(xm, ym, s);
}

void veOXY(){
	float x=-12, y=-0.2, dx = 0.01;
	while(x<11){
		chuyenDen(x,y);
		veDen(x, 0.2);
		x =x+1;
	}
	y=-12; x=-0.1;
	while (y<12){
		chuyenDen(x,y);
	}
}

int ktra(char *s){
	for (int i=0; i<strlen(s); i++)
		if (s[i]>'9' || s[i] < '0')
			return 0;
	return 1;
}


