#include<iostream>
#include<math.h>
#include "ClassObject.h"

using namespace std;

void RfMatrix(double Rf[4][4], double theta, double gamma, double alpha);	//Multiplication of the points with the RotateMatrix (RfMatrix)
double *multiplication(double matriz[4][4], double array[4]);	//Multiplication of an array with a matrix


void rotate(Object3D array[], int end, double Rf[4][4], double theta, double alpha, double gamma){
	
	int counter = 0;
	
	//theta = 0;	alpha = 0;	gamma = 0.1;
	
	RfMatrix(Rf, theta, gamma, alpha);
	
	double newarray[4];
	double *array2;
	for(int i=0; i<=end; i++){
	
		while(counter < array[i].v.size()){
			
			newarray[0] = array[i].v[counter].x;
			newarray[1] = array[i].v[counter].y;
			newarray[2] = array[i].v[counter].z;
			newarray[3] = 1;
			
			array2 = multiplication(Rf, newarray);
			
			array[i].v[counter].x = array2[0];
			array[i].v[counter].y = array2[1];
			array[i].v[counter].z = array2[2];
			
			counter++;	
		}
		counter = 0;
	}
	
}

void rotateAnimation(Object3D array[], int end, double Rf[4][4], double theta, double alpha, double gamma, int opc){
	
	int counter = 0;
	
	theta = 0;	alpha = 0.;	gamma = 0.1;
	
	/*if(opc == 0){	theta = 0;	alpha = 0;	gamma = 0.1;	}
	else
	if(opc == 1){	theta = 0;	alpha = 0;	gamma = 0.1;	}
	else
	if(opc == 2){	theta = 0;	alpha = 0;	gamma = 0.1;	}
	else
	if(opc == 3){	theta = 0;	alpha = 0;	gamma = 0.1;	}*/
	
	
	RfMatrix(Rf, theta, gamma, alpha);
	
	double newarray[4];
	double *array2;
	
	while(counter < array[0].v.size()){
		
		newarray[0] = array[0].v[counter].x;
		newarray[1] = array[0].v[counter].y;
		newarray[2] = array[0].v[counter].z;
		newarray[3] = 1;
		
		array2 = multiplication(Rf, newarray);
		
		array[0].v[counter].x = array2[0];
		array[0].v[counter].y = array2[1];
		array[0].v[counter].z = array2[2];
		
		counter++;	
	}
	counter = 0;
	
	theta = -0.1;	alpha = 0.;	gamma = 0;
	RfMatrix(Rf, theta, gamma, alpha);
	while(counter < array[4].v.size()){
		
		newarray[0] = array[4].v[counter].x;
		newarray[1] = array[4].v[counter].y;
		newarray[2] = array[4].v[counter].z;
		newarray[3] = 1;
		
		array2 = multiplication(Rf, newarray);
		
		array[4].v[counter].x = array2[0];
		array[4].v[counter].y = array2[1];
		array[4].v[counter].z = array2[2];
		
		counter++;	
	}
	
	
}



//Rotate the point of the vertice.
void RfMatrix(double Rf[4][4], double theta, double gamma, double alpha){
	
	Rf[0][0] = (cos(alpha)*cos(gamma))+(sin(alpha)*sin(theta)*sin(gamma)); 
	Rf[0][1] = (cos(alpha)*-sin(gamma))+(cos(gamma)*sin(alpha)*sin(theta));
	Rf[0][2] = sin(alpha)*cos(theta); 
	Rf[0][3] = 0;
	
	Rf[1][0] = cos(theta)*sin(gamma); 
	Rf[1][1] = cos(gamma)*cos(theta);
	Rf[1][2] = -sin(theta); 
	Rf[1][3] = 0;
	
	Rf[2][0] = (-sin(alpha)*cos(gamma))+(cos(alpha)*sin(theta)*sin(gamma)); 
	Rf[2][1] = (sin(alpha)*sin(gamma))+(cos(alpha)*sin(theta)*cos(gamma));
	Rf[2][2] = cos(alpha)*cos(theta); Rf[2][3] = 0;
	
	Rf[3][0] = 0; 
	Rf[3][1] = 0;
	Rf[3][2] = 0; 
	Rf[3][3] = 1;	
	
}


double *multiplication(double matriz[4][4], double array[4]){
	
	double mf[4];
	
	mf[0] = (matriz[0][0]*array[0] + matriz[0][1]*array[1]+matriz[0][2]*array[2]+matriz[0][3]*array[3]) ;
	mf[1] = (matriz[1][0]*array[0] + matriz[1][1]*array[1]+matriz[1][2]*array[2]+matriz[1][3]*array[3]) ;
	mf[2] = (matriz[2][0]*array[0] + matriz[2][1]*array[1]+matriz[2][2]*array[2]+matriz[2][3]*array[3]) ;
	mf[3] = (matriz[3][0]*array[0] + matriz[3][1]*array[1]+matriz[3][2]*array[2]+matriz[3][3]*array[3]) ;
	
	return mf;
}
