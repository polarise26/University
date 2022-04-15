#include <iostream>
#include <GL/glut.h>

void createObj(int a, int b);
void init()
{
    glClearColor(0.5, 0.5, 0.5, 0.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.01);
    createObj(0, 0);
    glFlush();
}

void createObj(int a, int b)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.8, 0.0, 0.8);
    glBegin(GL_POLYGON);
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(-1, -1);
    glVertex2f(-1,  1);
    glVertex2f( 0,  0);
    glVertex2f( 0, 0.5);
    glEnd();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(300, 10);
    glutCreateWindow("Project - Karan Taneja - 500084399");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}
