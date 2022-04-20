#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
float x2, y2, x3, y3, x4, y4, x5, y5;
void display()
{
 glColor3f(1,0,0);
 glPointSize(7);
 glBegin(GL_POINTS);
 glVertex2f(x2,y2);
 glVertex2f(x3,y3);
 glVertex2f(x4,y4);
 glVertex2f(x5,y5);
 glEnd();
 glColor3f(0,0,0);
 glBegin(GL_LINES);
 for(float t = 0;t<1;t+=0.005)
 {
 glVertex2f(x2*pow((1-t),3) + 3*x3*pow((1-t),2)*t + 3*x4*pow((1-
t),1)*pow(t,2) + x5*pow(t,3), y2*pow((1-t),3) + 3*y3*pow((1-t),2)*t +
3*y4*pow((1-t),1)*pow(t,2) + y5*pow(t,3));
 }
 glEnd();
 glFlush();
}
int main(int argc, char** argv)
{
 printf("Enter the value of x1 : ");
 scanf("%f",&x2);
 printf("Enter the value of y1 : ");
 scanf("%f",&y2);
 printf("Enter the value of x2 : ");
 scanf("%f",&x3);
 printf("Enter the value of y2 : ");
 scanf("%f",&y3);
 printf("Enter the value of x3 : ");
 scanf("%f",&x4);
 printf("Enter the value of y3 : ");
 scanf("%f",&y4);
 printf("Enter the value of x4 : ");
 scanf("%f",&x5);
 printf("Enter the value of y4 : ");
 scanf("%f",&y5);
 glutInit(&argc, argv);
53
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(750, 750);
 glutInitWindowPosition(80, 54);
 glutCreateWindow("Bezier Curve - Karan Taneja - 500084399");
 glClearColor(1,1,1,1);
 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-50,50,-50,50);
 glMatrixMode(GL_MODELVIEW);
 glutDisplayFunc(display);
 glutMainLoop();
}
