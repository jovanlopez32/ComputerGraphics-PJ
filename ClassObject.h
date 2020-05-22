#include<iostream>
#include<sstream>
#include<fstream>
#include<list>
#include<vector>

using namespace std;

typedef struct{
	float r;
	float g;
	float b;
}Color;

//Ia.r = 0.07; 	Ia.g = 0.27;		Ia.b = 0.34;
//Id.r = 0.34; 	Id.g = 0.51;		Id.b = 0.57;

class Vertice {
	//private:
	public:
		double x, y, z;
	public:
		Vertice ();
		Vertice(double a, double b, double c);
		void printvertex();
		double getX();
		double getY();
		double getZ();
		void setX(double a);
		void setY(double b);
		void setZ(double c);
};

class Faces {
	public:
		list<int> intls;
		Vertice normal;
		double vision;
		Color I;
		
	public:
		Faces(list<int> ls);
		void printfaces();
};

class Object3D {
	public:
		string name;
		vector<Vertice> v;
		list<Faces> f;
		void printEverything();
};


