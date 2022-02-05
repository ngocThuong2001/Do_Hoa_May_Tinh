#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>

GLfloat T = 0;
void Spin()
{
	T = T + 0.6;
	if(T>360)
		T =0;
	glutPostRedisplay();
	
}

void Draw()
{
	GLfloat Pos[] = {0,1,0,1};
	GLfloat Col[] = {1,0,0,1};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, Pos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Col);
	
	
	gluLookAt(0,1,3,0,0,0,0,1,0);
	
	glRotatef(T,0,1,0);
	
	//Face table
	glPushMatrix();
		glScalef(1,0.05,1);
		glutSolidCube(1);
	glPopMatrix();
	
	//Leg table
	glPushMatrix();
		glTranslatef(-0.5,-0.5,0.5); //A(-0.5,-0.5,0.5)
		glScalef(0.05,1,0.05);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.5,-0.5,-0.5); //B(-0.5,-0.5,0.5)
		glScalef(0.05,1,0.05);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.5,-0.5,0.5); //C(-0.5,-0.5,0.5)
		glScalef(0.05,1,0.05);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.5,-0.5,-0.5); //D(-0.5,-0.5,0.5)
		glScalef(0.05,1,0.05);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0.23,0.05); 
		glutSolidTeapot(0.18);
	glPopMatrix();
	
	glutSwapBuffers();
}

void MyInit()
{
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1,1,-1,1,2,10);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Table & TeaPot");
	MyInit();
	glutDisplayFunc(Draw);
	glutIdleFunc(Spin);
	glutMainLoop();
	return 0;
}


