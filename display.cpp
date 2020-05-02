#include<iostream>
#include<sstream>
#include<fstream>
#include<list>
#include <GL/glut.h>

#include "ClassObject.h"

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
	
	for(int i = 0; i <= end; i++){
		
		cout << array[i].name << endl;
		list<Vertex>::iterator it;
		it = array[i].v.begin();
		for(it;  it!=array[0].v.end(); it++){
			it->printvertex();
		}
		
	}
 	glutSwapBuffers ();
}
