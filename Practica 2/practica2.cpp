#define GLUT_DISABLE_ATEXIT_HACK
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
/*
using namespace std;
#include <iostream>
*/
#define RED 0
#define GREEN 0
#define BLUE 0
#define ALPHA 1

#define ECHAP 27
void init_scene();
void render_scene();
GLvoid initGL();
GLvoid window_display();
GLvoid window_reshape(GLsizei width, GLsizei height);
GLvoid window_key(unsigned char key, int x, int y);

//function called on each frame
GLvoid window_idle();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);


	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TP 2 : Transformaciones");


	initGL();
	init_scene();

	glutDisplayFunc(&window_display);

	glutReshapeFunc(&window_reshape);

	glutKeyboardFunc(&window_key);

	//function called on each frame
	glutIdleFunc(&window_idle);

	glutMainLoop();

	return 1;
}



GLvoid initGL()
{
	GLfloat position[] = { 0.0f, 5.0f, 10.0f, 0.0 };

	//enable light : try without it
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	//light 0 "on": try without it
	glEnable(GL_LIGHT0);

	//shading model : try GL_FLAT
	glShadeModel(GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);

	//enable material : try without it
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(RED, GREEN, BLUE, ALPHA);
}

/////////////////////////////////
// Primer ejercicio
/////////////////////////////////
float angulo=0;
void rotar_tetera(){
    int r=10;
	glColor3f(1.0,1.0,0.0);
	glRotatef(angulo,0,0,1);
    glTranslatef(r,0,0);
    glutSolidTeapot(2);
    angulo+=0.5;
}
/////////////////////////////////
// Segundo ejercicio
/////////////////////////////////
float ma =8;
float mi = -8;
float val = mi;
float num = 0.2;

void pelota(){
    glColor3f(0.0,0.4,1.0);
	glTranslatef(val,0,0);
    glutSolidSphere(1,64,64);
	rotar_tetera();
	if(val>=ma)
		num = -0.2;
	if(val<=mi)
		num = 0.2;
	val += num;
}

/////////////////////////////////
//Tercer ejercicio
/////////////////////////////////
float cube=0;
void rotar_cuadrado(){
	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glRotatef(-cube,1,0,0);
    glTranslatef(0,5,0); 
	glutSolidCube(1);
    glPopMatrix();
	cube +=0.5;
}

float rto=0;
void rotar_toro(){
	int r=3;
	glColor3f(0.0,1.0,0.0);
	glRotatef(-rto,0,1,0);
	glTranslatef(r,0,0);
    glutSolidTorus(0.2,0.5,32,32);
	rto += 1;
}

void pelota_toro(){
    glColor3f(0.0,0.4,1.0);
    glTranslatef(val,0,0);
    glutSolidSphere(1,64,64);	
	rotar_cuadrado();
	rotar_tetera();
	rotar_toro();

	if(val>=ma)
		num=-0.2;
	if(val<=mi)
		num = 0.2;
	val += num;
}

/////////////////////////////////
//Cuarto ejercicio
/////////////////////////////////

// Variables de rotacion
float vs = 0.5, 
	vt = 3*vs,
	vl = 2*vt,
	vm = vs;

float rsol = 0,
	rtier = 0,
	rluna = 0,
	rmart = 0;

void sol(){
	glColor3f(1.0,1.0,0.0);
	glRotatef(rsol,0,1,0);
	glTranslatef(0,0,0);
	glutSolidSphere(4,8,8);
	rsol+=vs;
}

void tierra(){
	glColor3f(0.0,0.4,1.0);
	glRotatef(rtier,0,1,0);
	glTranslatef(10,0,0);
	glutSolidSphere(2,8,8);
	rtier+=vt;
}

void luna(){
	glColor3f(0.5,0.5,0.5);
	glRotatef(rluna,0,1,0);
	glTranslatef(4,0,0);
	glutSolidSphere(0.5,8,8);
	rluna+=vl;
}

void marte(){
	glColor3f(0.2,0.4,0.3);
	glRotatef(rmart,0,1,0);
	glTranslatef(18,0,0);
	glutSolidSphere(1.5,8,8);
	rmart+=vm;
}

void sistema_solar(){
	sol();
	
	glPushMatrix();
	tierra();
	luna();
	glPopMatrix();

	glPushMatrix();
	marte();
	glPopMatrix();
}


GLvoid window_display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-25.0f, 25.0f, -25.0f, 25.0f, -25.0f, 25.0f);

    /*Dibujar aqui*/
	//rotar_tetera();
    //pelota_toro();
	sistema_solar();

	glutSwapBuffers();

	glFlush();
}

GLvoid window_reshape(GLsizei width, GLsizei height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-25.0f, 25.0f, -25.0f, 25.0f, -25.0f, 25.0f);

	glMatrixMode(GL_MODELVIEW);
}



void init_scene()
{

}

GLvoid window_key(unsigned char key, int x, int y)
{
	switch (key) {
	case ECHAP:
		exit(1);
		break;

	default:
		printf("La touche %d non active.\n", key);
		break;
	}
}


//function called on each frame
GLvoid window_idle()
{


	glutPostRedisplay();
}