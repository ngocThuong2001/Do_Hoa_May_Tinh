#include <graphics.h>
#include <math.h>
#include <time.h>

void init()
{
    glClearColor(2.0,1.0,1.0,0.0);
    glOrtho(0,640,0,480,-1,1);
}


void BoundaryFill(int x,int y, int fillColour, int boundaryColour){
 int colour = getpixel(x,y);
 if ((colour!= fillColour)&&(colour!=boundaryColour)){
	putpixel(x,y, fillColour);
	push(x,y);
 }
}

void BoundaryFill_Stack(int x0,int y0,int fillColour,int boundaryColour){
	int x,y;
	putpixel(x0,y0, fillColour);
	top=NULL;
	push(x0,y0);
	while(top!=NULL){
	pop(&x,&y);
	BoundaryFill (x-1,y, fillColour, boundaryColour);
	BoundaryFill (x+1,y,fillColour, boundaryColour);
	BoundaryFill (x,y+1,fillColour, boundaryColour);
	BoundaryFill (x,y-1, fillColour, boundaryColour);
	}
}
void mouse(int btn, int state, int x, int y)
{
    y = 480-y;
    if(btn==GLUT_LEFT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {
            float bCol[] = {1,0,0};
            float color[] = {0,0,1};
            BoundaryFill(x0,y0,fillColour,boundaryColour);
        }
    }
}

void mydisplay(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(100,400);
        glVertex2i(300,400);
        glVertex2i(150,200);
        glVertex2i(10,300);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Boundary Fill");
    glutDisplayFunc(mydisplay);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
