#include <GL\glut.h>
#include <graphics.h>
GLuint g_sun;
GLuint g_earth;
GLuint g_moon;
 
GLuint g_angle_day = 0;
GLuint g_angle_year = 0;
GLuint gl_angle_moon = 0;
 
GLuint MakeSphere(const float& radius)
{
  GLuint boxDisplay;
  boxDisplay = glGenLists(1);         
  glNewList(boxDisplay,GL_COMPILE);
  glutSolidSphere(radius, 64,16);
  glEndList();
  return boxDisplay;
}
 
void RendenScene()
{
 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
 
  gluLookAt(5.0, 5.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
 
  GLfloat mat_ambien[] = {1.0, 1.0, 0.0f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien);
  GLfloat diff[] = {05, 0.5, 0.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
  glCallList(g_sun);
 
  glRotatef(g_angle_year, 0.0f, 1.0f, 0.0f);
  glTranslated(8.0, 0.0, 0.0);
  glRotatef (g_angle_day, 0.0f, 1.0f, 0.0f);
 
  GLfloat mat_ambien2[] = {0.0, 0.0, 1.0f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien2);
  GLfloat diff2[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff2);
  glCallList(g_earth);
 
  glPushMatrix();
  glRotatef (gl_angle_moon, 0.0f, 1.0f, 0.0f);
  glTranslated(2.0, 0.0, 0.0);
 
  GLfloat mat_ambien3[] = {0.7, 0.7, 0.7f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien3);
  GLfloat diff3[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff3);
 
  glCallList(g_moon);
  glPopMatrix();
 
  glPopMatrix();
 
  Sleep(83);
  
  gl_angle_moon = (gl_angle_moon + 13);
  if (gl_angle_moon >= 360)
  {
    gl_angle_moon = 0;
  }
 
  g_angle_day = (g_angle_day + 360);
  if (g_angle_day >= 360)
  {
    g_angle_day = 0;
  }
 
  g_angle_year = (g_angle_year + 1);
  if (g_angle_year >= 360)
  {
    g_angle_year = 0;
  }
 
  glutSwapBuffers();
  glFlush();
 
  glutPostRedisplay();
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
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glEnable(GL_DEPTH_TEST);
 
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
 
  GLfloat light_pos [] = {1.0, 1.0, 1.0, 0.0};
  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
 
  GLfloat ambient[] = {1.0, 1.0, 0.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
 
  GLfloat diff_use[] = {0.5, 0.5, 0.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
 
  GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
 
  GLfloat shininess = 50.0f;
  glMateriali(GL_FRONT, GL_SHININESS, shininess);
 
  g_sun = MakeSphere(2.0);
  g_earth = MakeSphere(1.0);
  g_moon = MakeSphere(0.2);
}
 
int main(int argc, char **argv)
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
