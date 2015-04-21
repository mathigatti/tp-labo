# include <iostream>
# include "correpocoyo.h"

using namespace std;

int main () {
	CorrePocoyo<int> carrera;
	carrera.nuevoCorredor(1);
	carrera.nuevoCorredor(2);
	carrera.nuevoCorredor(3);
	carrera.nuevoCorredor(4);
	carrera.nuevoCorredor(5);
	cout << carrera << endl;
	
	CorrePocoyo<int> carrera2;
	carrera2.nuevoCorredor(666);
	carrera2.nuevoCorredor(999);
	cout << carrera2 << endl;
	
	CorrePocoyo<int> carrera3;
	carrera3.nuevoCorredor(666);
	carrera3.nuevoCorredor(999);
	cout << carrera3 << endl;
	
	cout << "La carrera 1 es igual a la 2?: " << (carrera == carrera2) << endl;
	cout << "La carrera 2 es igual a la 3?: " << (carrera3 == carrera2) << endl;
	
	return 0;
}
