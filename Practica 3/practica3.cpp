#define GLUT_DISABLE_ATEXIT_HACK
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
//#include <iostream>
#include <GL/glut.h>

//using namespace std;

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

	glutSpecialFunc(&callback_special);
	glutMouseFunc(&callback_mouse);
	glutMotionFunc(&callback_motion);

	return 1;
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
// glutperspective (45.0,1 alto/ancho de pantalla ,1,100)

// E2 gltransalate (0 0 -30) desplaza el escenario

// E3 no usar gltransalate 0,1,0 desplaza la camara glulookat()

// E4 no trabajar con glotlookat, rotar el escenario

// x = r cos angulo
// y = r sin angulo