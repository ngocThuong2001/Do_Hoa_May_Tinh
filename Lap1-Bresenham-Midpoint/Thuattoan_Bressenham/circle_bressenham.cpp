#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

typedef struct {
	int x,y;
} Point;

Point P[10];
int n=-1;
void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
	glOrtho(-320,320,-240,240,-1,1);	
}

void draw8point(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc + y, yc + x);
		glVertex2i(xc + y, yc - x);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc - y, yc - x);
		glVertex2i(xc - y, yc + x);
		glVertex2i(xc - x, yc + y);
	glEnd();
}
void CircleBres(int xc,int yc,int R )	
{	 
   	int p ;
	int y = R ; 
	int x = 0;
	p = 3 - 2*R;
	draw8point(xc,yc,x,y);
	while (x < y) 
    	{
		if (p <0)	
            p +=4*x+6;
		else
            {	
              p += 4*(x-y)+10;
		      y--;
		    }
		x++;
        draw8point(xc,yc,x,y);
		}
}

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	CircleBres(0, 0, 200); //Tâm C(0,0) bán kính 200
	glViewport(0,0,640,480);
	glFlush();

}

void MouseEventHandler(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state ==  GLUT_UP)
		{   n++;
			P[n].x=x-300;
			P[n].y=300-y;		printf("\n n=%i x=%d y=%d",n,P[n].x,P[n].y);			
			glutPostRedisplay();
		}
}	

int main(int argc, char** argv){
	/*int mode=GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 0);
	glutCreateWindow("DEMO THUAT TOAN BRESSENHAM VE PARABOL");
	
    initGL();
	glutDisplayFunc(mydisplay);    
	glutMouseFunc(MouseEventHandler);
	glutMainLoop();
	*/
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize (600, 600); 
	glutInitWindowPosition (10, 10); 
	glutCreateWindow("Ve duong Tron");
	gluOrtho2D(-300, 300, -300, 300);
	glClearColor(0,0,0,0);
	glutDisplayFunc(mydisplay);
	glutMouseFunc(MouseEventHandler);	
	glutMainLoop();
}
