#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
float Cube[8][3] = {{0, 0, 0}, {25, 0, 0}, {0, 25, 0}, {0, 0, 25}, {25,
25, 0}, {25, 0, 25}, {0, 25, 25}, {25, 25, 25}};
float Tx, Ty, Tz, Sx, Sy, Sz, SHx, SHy, SHz;
float angle;
void translation()
{
 for (int i = 0; i < 8; i++)
 {
 Cube[i][0] += Tx;
 Cube[i][1] += Ty;
 Cube[i][2] += Tz;
 }
}
void rotation()
{
 for (int i = 0; i < 8; i++)
 {
 float temp = Cube[i][0];
 Cube[i][0] = (Cube[i][0] * cos(angle)) - (Cube[i][1] *
sin(angle));
 Cube[i][1] = (temp * sin(angle)) + (Cube[i][1] * cos(angle));
 }
}
void scaling()

{
 for (int i = 0; i < 8; i++)
 {
 Cube[i][0] *= Sx;
 Cube[i][1] *= Sy;
 Cube[i][2] *= Sz;
 }
}
void reflection() //Along Z-X Axis
{
 for (int i = 0; i < 8; i++)
 Cube[i][1] = -Cube[i][1];
}
void shearing()
{
 for (int i = 0; i < 8; i++)
 {
 Cube[i][0] = Cube[i][0] + SHy * Cube[i][1] + SHz * Cube[i][2];
 Cube[i][1] = Cube[i][1] + SHx * Cube[i][0] + SHz * Cube[i][2];
 Cube[i][2] = Cube[i][2] + SHx * Cube[i][0] + SHy * Cube[i][1];
 }
}
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glRotatef(20, 1.0, 0.0, 0.0);
 glRotatef(-20, 0.0, 1.0, 0.0);
 glBegin(GL_QUADS);
 glColor3f(1, 0, 0);
 glVertex3fv(Cube[6]);
 glVertex3fv(Cube[7]);
 glVertex3fv(Cube[5]);
 glVertex3fv(Cube[3]);
 glColor3f(0, 1, 1);
 glVertex3fv(Cube[2]);
 glVertex3fv(Cube[4]);
 glVertex3fv(Cube[1]);
 glVertex3fv(Cube[0]);
 glColor3f(1, 0, 1);
 glVertex3fv(Cube[6]);
 glVertex3fv(Cube[2]);
 glVertex3fv(Cube[0]);
 glVertex3fv(Cube[3]);
 glColor3f(0, 0, 1);
 glVertex3fv(Cube[7]);
 glVertex3fv(Cube[4]);
 glVertex3fv(Cube[1]);
 glVertex3fv(Cube[5]);
 glColor3f(0, 1, 0);

 glVertex3fv(Cube[6]);
 glVertex3fv(Cube[2]);
 glVertex3fv(Cube[4]);
 glVertex3fv(Cube[7]);
 glColor3f(1, 1, 0);
 glVertex3fv(Cube[3]);
 glVertex3fv(Cube[0]);
 glVertex3fv(Cube[1]);
 glVertex3fv(Cube[5]);
 glEnd();
 glFlush();
}
int main(int argc, char **argv)
{
 //Initially cube is of 25 length and center existing at (12.5, 12.5, 12.5)
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 int ch;
 printf("1> Translation");
 printf("\n2> Rotation");
 printf("\n3> Scaling");
 printf("\n4> Reflection(Along ZX)");
 printf("\n5> Shearing");
 printf("\nEnter Option: ");
 scanf("%d", &ch);
 switch(ch)
 {
 case 1:
 printf("\nEnter Translation Vectors: \n");
 printf("Translation Along X: ");
 scanf("%f", &Tx);
 printf("Translation Along Y: ");
 scanf("%f", &Ty);
 printf("Translation Along Z: ");
 scanf("%f", &Tz);
 translation();
 break;
 case 2:
 printf("\nEnter The Angle Of Rotation :");
 scanf("%f", &angle);
 angle = (angle * 22/7) / 180;
 rotation();
 break;
 case 3:
 printf("\nEnter Scale Vectors: \n");
 printf("Scaling Along X: ");
 scanf("%f", &Sx);
 printf("Scaling Along Y: ");

 scanf("%f", &Sy);
 printf("Scaling Along Z: ");
 scanf("%f", &Sz);
 scaling();
 break;
 case 4:
 reflection();
 break;
 case 5:
 printf("\nEnter Shearing Vectors: \n");
 printf("Shearing Along X: ");
 scanf("%f", &SHx);
 printf("Shearing Along Y: ");
 scanf("%f", &SHy);
 printf("Shearing Along Z: ");
 scanf("%f", &SHz);
 shearing();
 break;
 default:
 printf("Wrong Choice, Exiting!!");
 break;
 }
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(200, 200);
 glutCreateWindow("3D Tranformation");
 glEnable(GL_DEPTH_TEST);
 glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
