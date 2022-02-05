#include <gl\glut.h>
 
void DrawCoordinate()
{
  glDisable(GL_LIGHTING);
  glBegin(GL_LINES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(10.0, 0.0, 0.0);
  glEnd();
 
  glBegin(GL_LINES);
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.0, 10.0, 0.0);
  glEnd();
 
  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.0, 0.0, 10.0);
  glEnd();
 
  glEnable(GL_LIGHTING);
}
 
 
 
void RendenScene()
{
 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
 
  gluLookAt(5.0, 5.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
 
  glPushMatrix();
  DrawCoordinate();
  glutSolidTeapot(3.0);
  glPopMatrix();
 
  glFlush();
}
 
void ReShape(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  float ratio = (float)width/(float)height;
  gluPerspective(45.0, ratio, 1, 100.0);
  glMatrixMode(GL_MODELVIEW);
}
 
 
void Init()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
 
    GLfloat light_pos [] = {0.0, 0.0, 1.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
 
    GLfloat ambient [] = {1.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
 
    GLfloat diff_use [] = {0.0, 0.5, 0.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
 
    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
 
    GLfloat shininess = 50.0f;
    glMateriali(GL_FRONT, GL_SHININESS, shininess);
}
 
int main()
{
  glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Opengl Study");
 
  Init();
  glutReshapeFunc(ReShape);
  glutDisplayFunc(RendenScene);
 
  glutMainLoop();
 
}
