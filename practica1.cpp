#define GLUT_DISABLE_ATEXIT_HACK	
#include <math.h>
#include <GL/glut.h>

#define KEY_ESC 27

//dibuja un simple gizmo
void displayGizmo()
{
	glBegin(GL_LINES);
	glColor3d(255,0,0);
	glVertex2d(0, 0);
	glVertex2d(1, 0);
	glColor3d(0, 255, 0);
	glVertex2d(0, 0);
	glVertex2d(0, 1);
	glEnd();
}
// FIGURAS
void cuadrado(float x,float y, float arista){
	float mitad = arista/2;

	glBegin(GL_LINE_LOOP);
	glVertex2d(x+ mitad, y+mitad);  
	glVertex2d(x-mitad, y+mitad);
	glVertex2d(x-mitad, y-mitad);  
	glVertex2d(x+mitad, y-mitad); 
	glEnd();

}
void circulo(float cx, float cy, float r) {
	float n_cortes=300;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n_cortes; i++)   {
        float angulo = 2 * 3.1415926f * float(i) / n_cortes; 
        float x = r * cos(angulo);
        float y = r * sin(angulo);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void circulos_dentro(int cant,float porcent){
	float x = 15;
	float y = 17;
	float r = 10;
	float mov = 0;
	for(int i = 0; i < cant; i++){
		circulo(x,y,r);
		mov = r * porcent/100;
		r -= mov;
		x -= mov;
	}
}
void reducir_circulo(int cant,float porcent){
	float x = -20;
	float y = -15;
	float r = 8;
	float newr=r;
	for(int i = 0; i < cant; i++){
		circulo(x,y,newr);
		newr -= r * porcent/100;
		x += r+newr;
		r = newr;
	}
}
void circulos_angulo(int cant,float porcent,float angulo){
	float x = 15;
	float y = -15;
	float r = 5;
	float newr=r;
	for(int i = 0; i < cant; i++){
		circulo(x,y,newr);
		newr= r-( r * porcent/100);
		x += cos(angulo) *(r+newr);
		y += sin(angulo)*(r+newr);
		r = newr;
	}
}

//END FIGURAS

//funcion llamada a cada imagen
void glPaint(void) {

	//El fondo de la escena al color initial
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //(R, G, B, transparencia) en este caso un fondo negro
	glLoadIdentity();
	
	
	//dibuja el gizmo
	displayGizmo();

	cuadrado(-20,20,10);
	circulo(-5,20,5);
	circulos_dentro(5,20);
	reducir_circulo(5,50);
	circulos_angulo(4,50,20);
	//doble buffer, mantener esta instruccion al fin de la funcion
	glutSwapBuffers();
}

//
//inicializacion de OpenGL
//
void init_GL(void) {
	//Color del fondo de la escena
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //(R, G, B, transparencia) en este caso un fondo negro

	//modo projeccion 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

//en el caso que la ventana cambie de tamaño
GLvoid window_redraw(GLsizei width, GLsizei height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-30.0f,  30.0f,-30.0f, 30.0f, -1.0f, 1.0f); 
	// todas la informaciones previas se aplican al la matrice del ModelView
	glMatrixMode(GL_MODELVIEW);
}

GLvoid window_key(unsigned char key, int x, int y) {
	switch (key) {
	case KEY_ESC:
		exit(0);
		break;

	default:
		break;
	}

}
//
//el programa principal
//
int main(int argc, char** argv) {

	//Inicializacion de la GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600); //tamaño de la ventana
	glutInitWindowPosition(100, 100); //posicion de la ventana
	glutCreateWindow("TP1 OpenGL : hello_world_OpenGL"); //titulo de la ventana

	init_GL(); //funcion de inicializacion de OpenGL

	glutDisplayFunc(glPaint); 
	glutReshapeFunc(&window_redraw);
	// Callback del teclado
	glutKeyboardFunc(&window_key);

	glutMainLoop(); //bucle de rendering

	return 0;
}
