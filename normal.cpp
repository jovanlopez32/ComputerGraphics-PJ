#include<iostream>
#include<math.h>
#include "ClassObject.h"

Vertice Normal_Operation(Vertice v1, Vertice v2, Vertice v3);

void visibleface(Object3D array[], int end, double vsx, double vsy, double vsz){
	
	
	int i=0, cont = 0;
	Vertice *vtx = NULL;
	vtx = new Vertice[100000];
	Vertice v[3];
	int vi = 0;
	
	for( ; i <=  end; i++){
		
		for(int x=0; x < array[i].v.size(); x++, vi++){
			vtx[vi].x = array[i].v[x].x;
			vtx[vi].y = array[i].v[x].y;
			vtx[vi].z = array[i].v[x].z;
		}
		
		list<Faces>::iterator lt;
		
		for(lt = array[i].f.begin(); lt != array[i].f.end(); lt++){
			
			list<int>::iterator it;
			it = lt->intls.begin();
			while(it != lt->intls.end()){
				
				if(cont < 3){
					v[cont] = vtx[*it];
					cont++;
				}
				else{
					break;
				}
				
				it++;
			}
			
			Vertice Normal;
			
			Normal = Normal_Operation(v[0], v[1], v[2]);
			lt->vision = (Normal.x*vsx)+(Normal.y*vsy)+(Normal.z*vsz);
						
			cont = 0;
				
		}
	}
	
}

//Calculate the normal of the face.
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
