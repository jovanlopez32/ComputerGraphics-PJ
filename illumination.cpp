#include<iostream>
#include<math.h>
#include "ClassObject.h"

//Ambient-Light Variables
double Ka = 1.0;
Color Ia;


//Diffuse-Light Variables
double Kd = 1.0;
Color Id;

//Specular-Light Variables
double Ks = 0.1;
Color Is;

//N
int n = 3;

using namespace std;

Vertice convertUnit(Vertice v1);
double productPoint(Vertice v1, Vertice v2);
Vertice calculateR(Vertice N, Vertice L, double NL);

void illumination(Object3D array[], int end, Vertice L, Vertice v){
	

	Color I;	double NL;	double Rv;
	
	//Ambient-Light Declaration
	Ia.r = 0.30; 	Ia.g = 0.38;		Ia.b = 0.40;
	
	//Diffuse-Light Declaration
	Id.r = 0.47; 	Id.g = 0.61;		Id.b = 0.62;
	
	//Specular-Light Declaration
	Is.r = 1.0; 	Is.g = 1.0;		Is.b = 1.0;
	
	
	L = convertUnit(L);
	v = convertUnit(v);
	
	int i = 0;
	for( ; i <= end; i++){
		
		list<Faces>::iterator it;
		for(it = array[i].f.begin(); it != array[i].f.end(); it++){
			
			//Ambient-Light
			I.r = (Ia.r * Ka);
			I.g = (Ia.g * Ka);
			I.b = (Ia.b * Ka);
			
			//Ambient-Light
			

			NL = productPoint(L, it->normal);
			
			I.r += (Id.r * Kd * NL);
			I.g += (Id.g * Kd * NL);
			I.b += (Id.b * Kd * NL);
			
			//Specular-Light
			
			Vertice R;
			
			R = calculateR(it->normal, L, NL);	
			
			R = convertUnit(R);	
			
			Rv = pow(productPoint(R, v), n);
			
			I.r += (Is.r * Ks * Rv);
			I.g += (Is.g * Ks * Rv);
			I.b += (Is.b * Ks * Rv);
			
			
			
			
			
			//cout << I.r << endl;
			//cout << I.g << endl;
			//cout << I.b << endl;
			
			it->color  = I;
			
			NL = 0;
			/*cout << it->color.r << endl;
			cout << it->color.g << endl;
			cout << it->color.b << endl;*/
		}
	}	
	
}

//Convert a vector to unitary vector
Vertice convertUnit(Vertice v1){
	
	Vertice U;	double Magnitud;
	
	U = v1;
	
	Magnitud = pow(U.x, 2) + pow(U.y, 2) + pow(U.z, 2);
	
	Magnitud = sqrt(Magnitud);
	
	U.x = U.x / Magnitud;
	U.y = U.y / Magnitud;
	U.z = U.z / Magnitud;
	
	return U;
}

double productPoint(Vertice v1, Vertice v2){
	
	double result;
	
	result = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	
	return result;
}

Vertice calculateR(Vertice N, Vertice L, double NL){
	
	Vertice r;
	
	r.x = (2 * NL * N.x) - L.x;
	r.y = (2 * NL * N.y) - L.y;
	r.z = (2 * NL * N.z) - L.z;
	
	return r;
}








