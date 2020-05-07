#include<iostream>
#include<sstream>
#include<fstream>
#include<list>
#include<vector>
using namespace std;

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

class TrajectoryDDA {
	public:
	int dx, dy, steps, k;
	float xInc, yInc, x, y;
};

