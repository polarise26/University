#include <GL/glut.h>
#include <stdio.h>
void display()
{
 GLint viewport[4];
 glGetIntegerv(GL_VIEWPORT, viewport);
 double aspect = (double)viewport[2] / (double)viewport[3];
 gluPerspective(60, aspect, 1, 100);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 // move back a bit
 glTranslatef( 0, 0, -35 );
 glRotatef(45,0,5,5);
 glColor3f(0,1,1);
 //glutSolidCube(5);
 //glutSolidCone(5,10,100,100);
 //glutSolidSphere(5,100,100);
 glutSolidTeapot(10);
 glutSwapBuffers();
}
int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitWindowSize(640,480);
 glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
 glutCreateWindow("3D");
 glClearColor(1,1,1,1);

 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
 glEnable(GL_COLOR_MATERIAL);
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
