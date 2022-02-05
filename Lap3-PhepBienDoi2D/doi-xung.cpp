#include <graphics.h>

int main(){
	initwindow(1000,1000);
	int x1 = 100, x2 = 140;
	int y1 = 150, y2 = 60;
	
	for (int i=0; i<100; i++){
		cleardevice();
		line(x1-i, y1-i, x2-i, y2-i);
		Sleep(50);
	}
	getch();
	return 0;
	
}
