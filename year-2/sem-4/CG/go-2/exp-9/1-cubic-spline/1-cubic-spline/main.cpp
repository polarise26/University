#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
void display()
{
 glColor3f(0,0,0);
 glBegin(GL_POINTS);
 for(float x = -50;x<50;x+=0.0005)
 {
 glVertex2f(x,2*pow(x,3) + 3*pow(x,2) - 5*x + 11);
 }
 glEnd();
 glFlush();
}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(750, 750);
 glutInitWindowPosition(80, 54);
 glutCreateWindow("Curves");
 glClearColor(1,1,1,1);
 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-50,50,-50,50);
 glMatrixMode(GL_MODELVIEW);
 glutDisplayFunc(display);
 glutMainLoop();
}
