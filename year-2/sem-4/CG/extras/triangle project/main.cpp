#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <dos.h>

float change_X = 0, change_Y = 1;
float x = 3, y = 4;
float theta = 0;

float approx(float x)
{
    if (x > 0.75)
        return 1;
    else if (x < -0.75)
        return -1;
    else
        return 0;
}

void circularMvmt()
{
    if (y > 50 && x < 140)
    {
        change_X = 1;
        change_Y = 0;
        theta = -90;
    }
    if (y > 50 && x > 140)
    {
        change_X = 0;
        change_Y = -1;
        theta = 180;
    }
    if (y < 5 && x > 10)
    {
        change_X = -1;
        change_Y = 0;
        theta = 90;
    }
    if (y < 5 && x < 10)
    {
        change_X = 0;
        change_Y = 1;
        theta = 0;
    }

    x += change_X * 0.1;
    y += change_Y * 0.1;
}

void randomMvmnt()
{
    srand(time(0));

    if (y > 50 && x < 10)
    {
        if (rand() % 2 == 0)
        {
            change_X = 1;
            change_Y = 0;
            theta = -90;
        }
        else
        {
            change_X = 0;
            change_Y = -1;
            theta = 180;
        }
    }
    if (y > 50 && x > 140)
    {
        if (rand() % 2 == 0)
        {
            change_X = 0;
            change_Y = -1;
            theta = 180;
        }
        else
        {
            change_X = -1;
            change_Y = 0;
            theta = 90;
        }
    }
    if (y < 5 && x > 140)
    {
        if (rand() % 2 == 0)
        {
            change_X = -1;
            change_Y = 0;
            theta = 90;
        }
        else
        {
            change_X = 0;
            change_Y = 1;
            theta = 0;
        }
    }
    if (y < 5 && x < 10)
    {
        if (rand() % 2 == 0)
        {
            change_X = 0;
            change_Y = 1;
            theta = 0;
        }
        else
        {
            change_X = 1;
            change_Y = 0;
            theta = -90;
        }
    }

    x += change_X * 0.05;
    y += change_Y * 0.05;
}

// xnew = xold * cosTh - yold * sinTh
// xnew = xold * sinTh + yold * cosTh

void Animation()
{
    glBegin(GL_POLYGON);

    glColor3f(1, 0, 0);
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (17) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (17) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (13) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (13) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (13) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (13) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(0, 0, 1);

    glBegin(GL_POLYGON);
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (13) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (13) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (13) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (13) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (13) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (13) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-4) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (-4) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (13) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (13) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((4) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (4) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(0, 0, 1);

    glBegin(GL_POLYGON);
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-4) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (-4) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(0, 0, 1);

    glBegin(GL_POLYGON);
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((4) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (4) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2f((-6) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (-6) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-4) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (-4) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2f((6) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (6) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((4) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (4) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(0, 0, 1);

    glBegin(GL_POLYGON);
    glVertex2f((-6) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (-6) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-4) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (-4) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(0, 0, 1);

    glBegin(GL_POLYGON);
    glVertex2f((6) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (6) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((4) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (4) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2f((-6) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (-6) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-8) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (-8) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-4) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (-4) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2f((6) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (6) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((8) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (8) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((4) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (4) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-4) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (-4) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((4) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (4) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(0, 0, 1);

    glBegin(GL_POLYGON);
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-8) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (-8) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-12) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (-12) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(0, 0, 1);

    glBegin(GL_POLYGON);
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((8) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (8) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((12) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (12) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-12) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (-12) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (-17) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (-17) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((12) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (12) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (-17) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (-17) * approx(cos(theta * 11 / 630)) + y);
    glEnd();

    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);

    randomMvmnt();
    // circularMvmt();

    glutPostRedisplay();
}

void bgDesign()
{
    glColor3f(1, 0.1, 1);

    glBegin(GL_TRIANGLES);
    glVertex2f(-25, -25);
    glVertex2f(0, -25);
    glVertex2f(-25, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(175, 75);
    glVertex2f(175, 50);
    glVertex2f(150, 75);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0, 75);
    glVertex2f(-25, 75);
    glVertex2f(-25, 50);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(150, -25);
    glVertex2f(175, -0);
    glVertex2f(175, -25);
    glEnd();
}

void obstacles()
{
    glColor3f(0.25, 0.5, 1);

    glBegin(GL_POLYGON);
    glVertex2f(-10, -10);
    glVertex2f(-5, -10);
    glVertex2f(-5, 10);
    glVertex2f(-10, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0, 60);
    glVertex2f(20, 60);
    glVertex2f(20, 65);
    glVertex2f(0, 65);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(160, 60);
    glVertex2f(155, 60);
    glVertex2f(155, 40);
    glVertex2f(160, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(150, -10);
    glVertex2f(130, -10);
    glVertex2f(130, -15);
    glVertex2f(150, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(160, -10);
    glVertex2f(155, -10);
    glVertex2f(155, 10);
    glVertex2f(160, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0, -10);
    glVertex2f(20, -10);
    glVertex2f(20, -15);
    glVertex2f(0, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-10, 60);
    glVertex2f(-5, 60);
    glVertex2f(-5, 40);
    glVertex2f(-10, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(150, 60);
    glVertex2f(130, 60);
    glVertex2f(130, 65);
    glVertex2f(150, 65);
    glEnd();
}

void Setup()
{
    bgDesign();
    obstacles();
    Animation();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 400);
    glutInitWindowPosition(550, 300);
    glutCreateWindow("CG Lab Project - Karan Taneja - 500084399");

    glClearColor(0.4, 1, 0.4, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-25, 175, -25, 75);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(Setup);
    glutMainLoop();

    return 0;
}
