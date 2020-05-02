#include<iostream>
#include<sstream>
#include<fstream>
#include<list>
#include <GL/glut.h>

#include "ClassObject.h"
#define NUMMAX 50

/*Global variables for the Objects*/
Object3D array[NUMMAX];
/*Number of objects*/
int end;



using namespace std;

int loadFile(char *nf, Object3D  array[]);
void init (void);
void display(void);

int main(int argc, char **argv){
	/*Fuctions for display screen*/
	glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (400, 400); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("OBJ READER");
    init ();
    
	end = loadFile("four_figs.obj", array);
	//cube.vertices[cube.faces[i].vert[j]].x
	
	glScalef(0.5,0.5,0.5);
	glutDisplayFunc(display); 
	
    glutMainLoop();
	return 0;
}

/*
cout << array[0].name << endl;
	list<Vertex>::iterator it;
	it = array[0].v.begin();
	for(it;  it!=array[0].v.end(); it++){
		it->printvertex();
	}
	
	cout << array[1].name << endl;
	list<Vertex>::iterator it2;
	it2 = array[1].v.begin();
	for(it2;  it2!=array[1].v.end(); it2++){
		it2->printvertex();
	}
*/

void init (void) 
{
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    glRotatef (30.0, 1.0, 1.0, 1.0);
    //gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

void display(void)
{
/*  clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix();
    glColor3f (1.0, 1.0, 1.0);
    //glBegin(GL_POLYGON);
    //glBegin(GL_POINTS);
	//cube.vertices[cube.faces[i].vert[j]].x
	int vi = 0; 	//Cursor del array
	Vertice *vtx = NULL;
	/*Hacemos el arreglo de vertices dinamico*/
	vtx = new Vertice[10000];
	/*Recorremos todos los objetos del archivo*/
	for(int i = 0; i <= end; i++){
		
		//cout << array[i].name << endl;
		
		/*Vaciamos la lista de vertices del objeto a un array para hacer mas facil su manipulacion*/
		
		list<Vertice>::iterator it;
		it = array[i].v.begin();
		for(it, vi;  it!=array[i].v.end(); it++, vi++){
			vtx[vi].setX(it->getX());
			vtx[vi].setY(it->getY());
			vtx[vi].setZ(it->getZ());
			//cout << vtx[vi].getX() << " " << vtx[vi].getY() << " " << vtx[vi].getZ() << endl;
		}
		//limpiamos la lista de vertices de nuestro objeto para asi ahorrar memoria
		array[i].v.clear();
		/*Recorremos las caras de la lista*/
		list<Faces>::iterator jt;
		jt = array[i].f.begin();
		for(jt; jt!=array[i].f.end(); jt++){
			
			list<int>::iterator il;
			il = jt->intls.begin();
			glBegin(GL_LINE_LOOP);
			while(il != jt->intls.end()){
				glVertex3f(vtx[*il].getX(), vtx[*il].getY(), vtx[*il].getZ());
				il++;
			}
			glEnd();
		}
		glPopMatrix();
		glutSwapBuffers ();
	}
 	
}




