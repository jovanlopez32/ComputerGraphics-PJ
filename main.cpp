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
int refreshMillis = 50;

/*Variable of the visualisation*/
float xAxis=0, yAxis=0, zAxis=-2;


/*OPENGL FUNCTIONS*/
void init (void);
void display(void);
void Timer(int value) ;
void mouse(int button, int state, int x, int y);
void keyboard (unsigned char key, int x, int y);

/*MY FUNCTIONS*/
int loadFile(char *nf, Object3D  array[]);
Vertice Normal_Operation(Vertice v1, Vertice v2, Vertice v3);
void translate(Object3D array[], int size, float xt, float yt, float zt);


int main(int argc, char **argv){
	/*Fuctions for display screen*/
	glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1000, 600); 
    glutInitWindowPosition (200, 0);
    glutCreateWindow ("EVEREST HOME");
    init ();
    
	end = loadFile("2.obj", array);
	
//  glutMouseFunc(mouse);
//	glutKeyboardFunc(keyboard);
//	glutTimerFunc(0, Timer, 0);
	glutDisplayFunc(display); 
//	glutMouseFunc(mouse);
    glutMainLoop();
    
	return 0;
}


void init (void) 
{
/*  select clearing (background) color       */
    glClearColor(0.1, 0.39, 0.88, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 2, -1, 1, 1, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void display(void)
{
	
	static int h = 0;
	if(h==0){
		translate(array, end, xAxis, yAxis, zAxis);
		h++;	
	}
	
	/*  color of the all pixels  */
    glColor3f (1.0, 1.0, 1.0);
	
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
			
			list<int>::iterator il;		/*iterador para calcular la normal*/
			list<int>::iterator il2;	/*iterador para sabe si imprimir la cara*/
			il 	= jt->intls.begin();
			il2 = jt->intls.begin();
			
			
			
			while(il != jt->intls.end()){
				
				//Get the three vertices for caculate the normal.
				if(contvertices < 3){
					Nv[contvertices] = vtx[*il];
					contvertices++;
				}
				else{
					break;
				}
				il++;
			}
			
			double vision;	//Variable of decision the draw face of the object
			Vertice Normal;	//Is the Normal of the previus face
			
			Normal = Normal_Operation(Nv[0], Nv[1], Nv[2]);
			
			vision = (Normal.x*0) + (Normal.y*0) + (Normal.z*-2);
			
			contvertices = 0;
			
			//cout << vision << endl;
			//--- Draw the faces that are greater than zero. --------------------------
			glBegin(GL_LINE_LOOP);
			if(vision > 0)
					while(il2 != jt->intls.end()){
					glVertex3f(vtx[*il2].x, vtx[*il2].y, vtx[*il2].z);
					il2++;
				}
			glEnd();
			//-------------------------------------------------------------------------
		}
		
		glutSwapBuffers ();	
	}
	vtx = NULL;
	glFlush();
}

void keyboard (unsigned char key, int x, int y)
{
	key = 'n';
   switch (key)
   {
   		//Flecha Arriba 
      	case 'w': 
		  		yAxis = yAxis + .1;
                break;
        //Flecha Abajo
      	case 's': 
		  		yAxis = yAxis - .1;
                break;
        //Flecha Derecha
      	case 'd': 
		  		
                break;
        //Flecha Izquierda
        case 'a': 
				break;

      	default: break;
   }
   //glTranslatef(xAxis, yAxis, zAxis);
   
   	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) 
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN){
         	glutTimerFunc(refreshMillis, Timer, 0);
		 }
         break;
      case GLUT_MIDDLE_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}

void Timer(int value) 
{
   //Post a paint request to activate display()
   glutPostRedisplay();
   //subsequent timer call at milliseconds
   glutTimerFunc(refreshMillis, Timer, 0);
}



