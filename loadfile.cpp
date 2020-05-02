#include<iostream>
#include<sstream>
#include<fstream>
#include<list>

#include "ClassObject.h"

int loadFile(char *nf, Object3D  array[]){
	
	ifstream myFile;	//File variable
	
	myFile.open(nf);	//Open the file
	
	//If it doesn't open the file, we show a error message
	if(!myFile.is_open()){
		cout << "Can't read the file " << nf << " please check the name file or the directory." << endl;
		exit(1);
	}
	
	string mytext;	//We created a string for read the text file
	string subtext;	//This string is for get some text file parts
	int i=-1;
	Object3D object;
	while(getline(myFile, mytext)){
		//
		subtext = mytext.substr(0,2);
		
		if(subtext == "o "){
			//
			if(i>-1){
				array[i] = object;
				object.v.clear();
				object.f.clear();
				object.name.clear();
			}
			subtext = mytext.substr(2, mytext.size()-2);
			object.name = subtext;
			i++;
		}
		if(subtext == "v "){
			double x, y, z;
			subtext = mytext.substr(2, mytext.size()-2);
			stringstream ss(subtext);
			ss >> x;
			ss >> y;
			ss >> z;
			//cout << x << "\t\t" << y << "\t\t" << z << "\t" << endl;
			//We use this variable for set in the list
			Vertice Vtest(x,y,z);
			
			//Save the vertex in the list of object
			object.v.push_back(Vtest);
			x = 0;
			y = 0;
			z = 0;
		}
		if(subtext == "f "){
			list<int> lsTest;
			int tmp;
			subtext = mytext.substr(2, mytext.size()-2);
			stringstream ss(subtext);
			while(ss){
				ss >> tmp;			//Se ingresa el valor obtenido en la variable temporal
				lsTest.push_back(tmp-1);		
			}
			lsTest.pop_back(); //Elimina el ultimo componente de la lista ya que se repetia dos veces
			
			object.f.push_back(lsTest);
		}
	}
	array[i] = object;
	return i;
}
