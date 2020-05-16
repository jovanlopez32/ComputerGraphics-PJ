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





