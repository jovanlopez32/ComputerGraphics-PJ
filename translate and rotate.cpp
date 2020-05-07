#include<iostream>
#include<math.h>
#include "ClassObject.h"

using namespace std;


//It get the Object3D array and its size and the changes values
void translate(Object3D array[], int size, float xt, float yt, float zt){
	
	int i=0;
	int j=0;
	
	for( ; i <= size; i++) {
		
		for(j=0; j < array[i].v.size(); j++) {
			
			array[i].v[j].x = array[i].v[j].x + xt;
			array[i].v[j].y = array[i].v[j].y + yt;
			array[i].v[j].z = array[i].v[j].z + zt;
				
		}
	}
	
	
}

Vertice Normal_Operation(Vertice v1, Vertice v2, Vertice v3){
	
	Vertice vi, vj;
	Vertice N;

	//Calculate the vertice i.
	vi.x = v2.x - v1.x;	
	vi.y = v2.y - v1.y;	
	vi.z = v2.z - v1.z;
	//Calculate the vertice j.
	vj.x = v3.x - v1.x;
	vj.y = v3.y - v1.y;
	vj.z = v3.z - v1.z;
	
	//Calculate the NORMAL
	N.x = ((vi.y*vj.z) - (vi.z*vj.y));
	N.y = ((vi.z*vj.x) - (vi.x*vj.z));
	N.z = ((vi.x*vj.y) - (vi.y*vj.x));
	
	double NOBS=0;
	
	NOBS = pow(N.x, 2) + pow(N.y, 2) + pow(N.z, 2);
	NOBS = sqrt(NOBS);

	if(NOBS != 0){
		N.x = N.x / NOBS;
		N.y = N.y / NOBS;
		N.z = N.z / NOBS;
	}
	
	/*cout << vi.x << " " << vi.y << " " << vi.z << " " << endl; 

	cout << vj.x << " " << vj.y << " " << vj.z << " " << endl; 
	
	cout << N.x << " " << N.y << " " << N.z << " " << endl; */
	
	return N;	
}




