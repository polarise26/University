#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>

GLfloat x,y;
float temp_x,temp_y;
int max_d=800;
int min_d=0;
float i=100.0;
float j=0.0;

int state=1;

void timer(int);
void move_left();
void move_right();
void move_up();
void move_down();
void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void move_right(){

if(i<532){
    i++;
}
//glutPostRedisplay();
glFlush();

move_up();

}


void move_left(){

if(i>10){
    i--;
}
//glutPostRedisplay();
glFlush();
}

void move_down(){
if(j>10){
    j--;
}
//glutPostRedisplay();
glFlush();
}

void move_up(){
if(j<600){
    j++;
}
//glutPostRedisplay();
glFlush();
}


void objectCreate(int X,int Y){
    glClear(GL_COLOR_BUFFER_BIT);
      //glClearColor(1.0,1.0,1.0,0.0);
      glLineWidth(3);
    glPointSize(4);
int temp=800;
glClearColor(0.5,0.5,1,0);
//for(int i=0;i<temp;i++){
//move_right();
//glutPostRedisplay();

glColor3f (1.0, 0.0, 0.0);
        glRasterPos2f(290, 270); //define position on the screen
        char *string = "fuck you";

      while(*string){
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string++);
      }



glColor3f(0.1,0.24,0.06);
//glColor3f(1.439216,  1.858824 ,1.976471);
glBegin(GL_POLYGON);
glVertex2i(35+i,100+j);
glVertex2i(65+i,40+j);
glVertex2i(45+i,10+j);
glVertex2i(45+i,60+j);
glVertex2i(25+i,60+j);
glVertex2i(25+i,10+j);
glVertex2i(5+i,40+j);
glEnd();

//}
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(30+i,90+j);
glVertex2i(40+i,90+j);
glVertex2i(35+i,80+j);
glEnd();
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2i(25+i,80+j);
glVertex2i(35+i,80+j);
glVertex2i(30+i,70+j);
glEnd();
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2i(35+i,80+j);
glVertex2i(45+i,80+j);
glVertex2i(40+i,70+j);
glEnd();
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(20+i,70+j);
glVertex2i(30+i,70+j);
glVertex2i(25+i,60+j);
glEnd();
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(40+i,70+j);
glVertex2i(50+i,70+j);
glVertex2i(45+i,60+j);
glEnd();
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2i(15+i,60+j);
glVertex2i(25+i,60+j);
glVertex2i(20+i,50+j);
glEnd();
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2i(45+i,60+j);
glVertex2i(55+i,60+j);
glVertex2i(50+i,50+j);
glEnd();
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(10+i,50+j);
glVertex2i(20+i,50+j);
glVertex2i(15+i,40+j);
glEnd();
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(50+i,50+j);
glVertex2i(60+i,50+j);
glVertex2i(55+i,40+j);
glEnd();
glColor3f(0.0,1.0,1.0);

glBegin(GL_LINES);
glVertex2i(6.2+i,40+j);
glVertex2i(28+i,40+j);
glEnd();

glBegin(GL_LINES);
glVertex2i(42+i,40+j);
glVertex2i(64.5+i,40+j);
glEnd();
//move_right();
//move_down();
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(min_d+60,min_d+30);
glVertex2i(min_d+60,min_d+70);
glVertex2i(min_d+90,min_d+70);
glVertex2i(min_d+90,min_d+30);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(570,30);
glVertex2i(570,70);
glVertex2i(540,70);
glVertex2i(540,30);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(570,410);
glVertex2i(570,450);
glVertex2i(540,450);
glVertex2i(540,410);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(min_d+60,410);
glVertex2i(min_d+60,450);
glVertex2i(min_d+90,450);
glVertex2i(min_d+90,410);
glEnd();


glFlush();
//move_left();
//glutPostRedisplay();
}
void myDisplay(){
    glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(4.0);
    objectCreate(x,y);
    glFlush();

}

int main(int argc,char **argv){

//printf("x co-ordinate");
//scanf("%d",&x);
//printf("y co-ordinate");
//scanf("%d",&y);
glutInit(&argc,argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (max_d, max_d);
	glutInitWindowPosition (300, 10);
	glutCreateWindow ("Project Work");
glutDisplayFunc(myDisplay);
	myInit ();
	glutTimerFunc(0,timer,0);
	glutMainLoop();


}
void timer(int){
glutPostRedisplay();
glutTimerFunc(1000/60,timer,0);

/*
if(i!=400){
i+=5;
temp_x=i;


}
else if(j!=400 && i==400){
    j+=2;
    //i=i;
    //temp_y=j;
    //temp_x=i;
}
else if(i!=200 && j!=200){
    j-=2;
    i-=2;
    //i=i;
    //temp_y=j;
    //temp_x=temp_x-1;
}
*/

    switch(state){
    case 1:
        if(i<475 && j<580 ){
            i=i+5;
            //temp_y=i;
        }
        else{
            state=-1;

        }
        break;
    case -1:
        if(i>85 && j<380){
            i=i-5;
        }
        else{
            state=2;
        }
        break;
    case 2:
        if(j<380 && i<120){
            j=j+5;
        }
        else{
            state=3;
            //j=600;
        }
    case 3:
        if(i<485 && j>375){
            i=i+5;
        }
        else{
            state=4;
        }
    case 4:
        if(j>0 && i>470){
            j=j-5;
        }
        else{
        state=-1;
        }

    }

}
