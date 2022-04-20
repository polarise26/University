#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1; // 0001
const int RIGHT = 2; // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8; // 1000
int x_max, y_max, x_min, y_min;
float x3[10], x4[10], y3[10], y4[10], newx3, newy3, newx4, newy4, n;
int assigning(int x, int y)
{
 // initialized as being inside
 int area = INSIDE;
 if (x < x_min) // to the left of rectangle
 area = LEFT;
 else if (x > x_max) // to the right of rectangle
 area = RIGHT;
 else if (y < y_min) // below the rectangle
 area = BOTTOM;
 else if (y > y_max) // above the rectangle
 area = TOP;
 return area;
}
void cohen(int x3, int x4, int y3, int y4)
{
 int area1 = assigning(x3,y3);
 int area2 = assigning(x4,y4);
 bool accept = false;
 while (true)
 {
 if ((area1 == 0) && (area2 == 0))
 {

 accept = true;
 break;
 }
 else if (area1 & area2)
 {
 break;
 }
 else
 {
 int temp;
 float x, y;
 if (area1 != 0)
 temp = area1;
 else
 temp = area2;
 if (temp & TOP)
 {
 x = x3 + (x4 - x3) * (y_max - y3) / (y4 - y3);
 y = y_max;
 }
 else if (temp & BOTTOM)
 {
 x = x3 + (x4 - x3) * (y_min - y3) / (y4 - y3);
 y = y_min;
 }
 else if (temp & RIGHT)
 {
 y = y3 + (y4 - y3) * (x_max - x3) / (x4 - x3);
 x = x_max;
 }
 else if (temp & LEFT)
 {
 y = y3 + (y4 - y3) * (x_min - x3) / (x4 - x3);
 x = x_min;
 }
 if (temp == area1)
 {
 newx3 = x;
 newy3 = y;
 area1 = assigning(newx3, newy3);
 }
 else {
 newx4 = x;
 newy4 = y;
 area2 = assigning(newx4, newy4);
 }
 }
 }
 if (accept)
 {
 glBegin(GL_LINES);
 glColor3f(0,0,1);
 glVertex2f(newx3,newy3);
 glVertex2f(newx4,newy4);
 glEnd();
 glFlush();
 }
}
void ClipWindow()
{
 glBegin(GL_LINES);
 glColor3f(0,0,1);
 glVertex2f(x_min,y_min);
 glVertex2f(x_max,y_min);
 glVertex2f(x_max,y_min);
 glVertex2f(x_max,y_max);
 glVertex2f(x_max,y_max);
 glVertex2f(x_min,y_max);
 glVertex2f(x_min,y_max);
 glVertex2f(x_min,y_min);
 glEnd();
 for(int i=0;i<n;i++)
 {
 glBegin(GL_LINES);
 glColor3f(0.87,0.87,0.87);
 glVertex2f(x3[i],y3[i]);
 glVertex2f(x4[i],y4[i]);
 glEnd();
 glFlush();
 cohen(x3[i],x4[i],y3[i],y4[i]);
 }
}
int main(int argc, char **argv)
{
 printf("Enter Coordinates of window: \n");
 printf("x_min: ");
 scanf("%d",&x_min);
 printf("y_min: ");
 scanf("%d",&y_min);
 printf("x_max: ");
 scanf("%d",&x_max);
 printf("y_max: ");
 scanf("%d",&y_max);
 printf("\nEnter the number of lines: ");
 scanf("%f",&n);
 for(int i=0;i<n;i++)
 {
 printf("\nLine %d: \n", i+1);
 printf("Enter Line Endpoints: \n");
 scanf("%f %f %f %f", &x3[i], &y3[i], &x4[i], &y4[i]);
 }
 glutInit(&argc, argv);

 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(200, 200);
 glutCreateWindow("Cohen LineClip - Karan Taneja - 500084399");
 glClearColor(1,1,1,0);
 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0,50,0,50);
 glMatrixMode(GL_MODELVIEW);
 glutDisplayFunc(ClipWindow);
 glutMainLoop();
 return 0;
}
