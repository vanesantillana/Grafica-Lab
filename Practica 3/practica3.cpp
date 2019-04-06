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
// funciones de practica 3
GLvoid callback_special(int key, int x, int y);
GLvoid callback_mouse(int button, int state, int x, int y);
GLvoid callback_motion(int x, int y);

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

	glutSpecialFunc(&callback_special);
	glutMouseFunc(&callback_mouse);
	glutMotionFunc(&callback_motion);

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
	float x = r * cos(angulo);
    float y = r * sin(angulo);
	//glVertex3d(1,0,0);
	glColor3f(1.0,1.0,0.0);    
    glTranslatef(x,y,0);
	glutSolidTeapot(2);
    angulo+=0.03;
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
	//glOrtho(-25.0f, 25.0f, -25.0f, 25.0f, -25.0f, 25.0f);
	gluPerspective(45, 1, 1, 100);
	//glTranslated(0,0,-30);
	gluLookAt(0,0,30,0,0,0,0,1,0); //(traslacion, posicion,camara en y)
// seguir las coordenadas de la tierra
    /*Dibujar aqui*/
	//rotar_tetera();
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

///////////////////////////////////////////////////////////////////////////////
//(1)
///////////////////////////////////////////////////////////////////////////////
GLvoid callback_special(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		glutPostRedisplay();			// et on demande le r�affichage.
		break;

	case GLUT_KEY_DOWN:
		glutPostRedisplay();			// et on demande le r�affichage.
		break;

	case GLUT_KEY_LEFT:					
		glutPostRedisplay();			// et on demande le r�affichage.
		break;

	case GLUT_KEY_RIGHT:				
		glutPostRedisplay();			// et on demande le r�affichage.
		break;
	}
}



///////////////////////////////////////////////////////////////////////////////
//(2)
///////////////////////////////////////////////////////////////////////////////
GLvoid callback_mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
	}
}

///////////////////////////////////////////////////////////////////////////////
//(3)
///////////////////////////////////////////////////////////////////////////////
GLvoid callback_motion(int x, int y)
{

	glutPostRedisplay();						
}

// E1 gllanide
// glutperspective (45.0,1,1,100) alto/ancho de pantalla

// E2 gltransalate (0 0 -30) desplaza el escenario

// E3 no usar gltransalate 0,1,0 desplaza la camara glulookat()

// E4 no trabajar con glotlookat, rotar el escenario

// x = r cos angulo
// y = r sin angulo