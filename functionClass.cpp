
#include"ClassObject.h";

/*------------------------- Constructors ------------------------*/
Vertice::Vertice(){
	
}
Vertice::Vertice(double a, double b, double c){
	x = a;
	y = b;
	z = c;
}

Faces::Faces(list<int> ls){
	intls = ls;
}

/*----------------------------------- Methods -----------------------*/

void Vertice::printvertex(){
	cout << x << " " << y << " " << z << endl;
}

double Vertice::getX(){
	return x;
}
double Vertice::getY(){
	return y;
}
double Vertice::getZ(){
	return z;
}

void Vertice::setX(double a){
	x = a;
}
void Vertice::setY(double b){
	y = b;
}
void Vertice::setZ(double c){
	z = c;
}

void Faces::printfaces(){
	list<int>::iterator it;
	it = intls.begin();
	for(it; it != intls.end(); it++){
		cout << " " << *it;
	}
	cout << endl;
}

void Object3D::printEverything(){
	/*print name of object*/
	cout << name << endl;
	/*printf the vertex*/
	int i=0;
	for(int i; i < v.size(); i++){
		v[i].printvertex();
	}

	/*print the faces*/
	list<Faces>::iterator itF;
	for(itF = f.begin(); itF != f.end(); itF++){
		itF->printfaces();
	}
	
}
