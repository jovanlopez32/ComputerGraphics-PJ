#include<iostream>
#include<sstream>
#include<fstream>
#include<list>
#include<vector>
#include<math.h> 
#include<GL/glut.h>

#include "ClassObject.h"

#define NUMMAX 50

using namespace std;

/*Global variables for the Objects and its size*/
Object3D array[NUMMAX];
static int end;

/*Refresh period in milliseconds*/
int refreshMillis = 20;

/*Variable of the visualisation*/
float xAxis=2, yAxis=.1, zAxis=-1.75;

/*Global variables for rotate*/
double Rf[4][4];
double theta;
double alpha;
double gamma;


/*OPENGL FUNCTIONS*/
void init (void);
void display(void);
void Timer(int value) ;
void mouse(int button, int state, int x, int y);
void keyboard (unsigned char key, int x, int y);

/*MY FUNCTIONS*/
int loadFile(char *nf, Object3D  array[]);	//Read the OBJ file
void translate(Object3D array[], int size, float xt, float yt, float zt);	//Translate the points
void rotate(Object3D array[], int end, double Rf[4][4], double theta, double alpha, double gamma);
void rotateAnimation(Object3D array[], int end, double Rf[4][4], double theta, double alpha, double gamma, int opc);
void visibleface(Object3D array[], int end, double vsx, double vsy, double vsz);
void illumination(Object3D array[], int end, Vertice L, Vertice v);

int main(int argc, char **argv){
	
	/*int element;
	cout << "....:::: ATOM PROJECT ::::...." << endl;
	
	cout << endl << "1.- HYDROGEN [H] \t 2.- HELIUM [He] \t 3.- LITHIUM [Li]" << endl;
	
	cout << endl << "Enter a number according to the menu: ";
	cin >> element;
	
	switch(element){
		case 1:
				end = loadFile("2.obj", array);
				break;
		case 2:
				end = loadFile("2.obj", array);
				break;
		case 3: 
				end = loadFile("2.obj", array);
				break;
		default:
				cout << endl << "....:::: INCORRECT OPTION ::::....";
				exit(0);
				break;
	}
	*/
	end = loadFile("2.obj", array);
	
	/*Fuctions for display screen*/
	glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (750, 650); 
    glutInitWindowPosition (200, 0);
    glutCreateWindow ("ATOM PROJECT");
    init ();
	
	glutTimerFunc(0, Timer, 0);
	glutDisplayFunc(display); 
//	glutMouseFunc(mouse);
    glutMainLoop();
    
	return 0;
}


void init (void) 
{
/*  select clearing (background) color       */
    //glClearColor(0.1, 0.39, 0.88, 1.0);
    glClearColor(0.93, 0.96, 0.85, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	
	glTranslatef(0, 0, zAxis);
	//translate(array, end, xAxis, yAxis, zAxis);
	//glRotatef(190, 0, 1, 0);
	//glRotatef(30, 0.0, 1.0, 1.0);
	//rotate(array, end, Rf, 0, .0, .1);
	//for(int i = 0; i <= end; i++)
	//cout << array[i].name << " " << i << endl;
	//gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
	gluLookAt(.2, 0, 0, xAxis, yAxis, zAxis, 0, 1, 0);
}


void display(void)
{
	
	glClear (GL_COLOR_BUFFER_BIT);	//Clean the screen for the atom.
	
    //Normal Variables
	int contvertices=0;
	Vertice Nv[3];
    
    Vertice *vtx = NULL;
    vtx = new Vertice[100000];
    int vi=0;

	for(int i = 0; i <= end; i++){ //Object Layer
		
		for(int x=0; x < array[i].v.size(); x++, vi++){
			vtx[vi].x = array[i].v[x].x;
			vtx[vi].y = array[i].v[x].y;
			vtx[vi].z = array[i].v[x].z;
		}

		/*Recorremos las caras de la lista*/
		list<Faces>::iterator jt;
		jt = array[i].f.begin();
		
		for(jt; jt!=array[i].f.end(); jt++){
			
			list<int>::iterator il;		
			il 	= jt->intls.begin();

			//--- Draw the faces that are greater than zero. --------------------------
			
			//cout << jt->color.r << " " << jt->color.g << " " << jt->color.b << endl;
			
			//Check the web site coolors.co and get the rgb color and transformate with this formule: (color select) / 255;
			glColor3f (jt->color.r, jt->color.g, jt->color.b);
			
			
			glBegin(GL_QUADS);
			//glBegin(GL_LINE_LOOP);
			if(jt->vision <= 0)
			while(il != jt->intls.end()){
				glVertex3f(vtx[*il].x, vtx[*il].y, vtx[*il].z);
				il++;
			}
			glEnd();
			//-------------------------------------------------------------------------
		}
	}
	glutSwapBuffers ();	
	vtx = NULL;
}

void Timer(int value) 
{

	/*Points of the pivot*/
	double dx = 0;
	double dy = 0;
	double dz = 0;
	
	/*---Translation to the origin---*/
	dx = dx * -1;	dy = dy * -1;	dz = dz * -1;
	translate(array, end, dx, dy, dz);
	
	Vertice L, v;
	L.x = -1.2;
	L.y = 1;
	L.z = -1;
	v.x = xAxis;
	v.y = yAxis;
	v.z = zAxis;	
	/*--------------------------------------------------------------------------------*/

	
	visibleface(array, end, xAxis, yAxis, zAxis);
	illumination(array, end, L, v);
	rotateAnimation(array, end, Rf, theta, alpha, gamma, 0);
	
	/*--------------------------------------------------------------------------------*/
	
	/*---Translation to the original position---*/
	dx = dx * -1;	dy = dy * -1;	dz = dz * -1;
	translate(array, end, dx, dy, dz);
	
	/*--Redisplay the figures then of the first loop in mainloop*/
    glutPostRedisplay();
    // subsequent timer call at milliseconds
    glutTimerFunc(refreshMillis, Timer, 0);

}
