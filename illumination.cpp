#include<iostream>
#include<math.h>
#include "ClassObject.h"

using namespace std;

void convertUnit(Vertice *v);
double productOperation(Vertice V1, Vertice V2);

//Ambient
double Ka = 0.8;
Color Ia;


//Diffuse
double Kd = 0.9;
Color Id;

//Specular
double Ks = 0;
Color Is;


void illumination(Object3D array[], int end, Vertice L){
	
	Color I;	Vertice L2 = L;
	
	/*Ambient*/
	Ia.r = 0;	Ia.g = 0;	Ia.b = 0;
	/*Diffuse*/
	Id.r = 0;	Id.g = 0;	Id.b = 0;
	/*Specular*/
	Is.r = 0;	Is.g = 0;	Is.b = 0;
	
	int i;
	
	double NL;
	
	convertUnit(&L2);
	
	for(i = 0; i <= end; i++){

		list<Faces>::iterator it;
		it = array[i].f.begin();
		for(it; it != array[i].f.end(); it++){
		
			//Ambient Light
			I.r = Ia.r * Ka;
			I.g = Ia.b * Ka;
			I.b = Ia.b * Ka;
			
			NL = productOperation(it->normal, L); 
			
			//Diffuse Light
			I.r = I.r + (Id.r * Kd * NL);
			I.g = I.g + (Id.g * Kd * NL);
			I.b = I.b + (Id.b * Kd * NL);
			
			//it->color = I;
						
		}
	}
	

}

double productOperation(Vertice V1, Vertice V2){
	
 	double result;
 	
 	result = (V1.x * V2.x) + (V1.y * V2.y) + (V1.z * V2.z);
	
	return result;
}

//Convert to unitary vector.
void convertUnit(Vertice *v){
	
	double Magnitude;
	
	Magnitude = pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2);
	Magnitude = sqrt(Magnitude);
	
	v->x = v->x / Magnitude;
	v->y = v->y / Magnitude; 
	v->z = v->z / Magnitude;
	
}



