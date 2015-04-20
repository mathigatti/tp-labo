# include <iostream>
# include "correpocoyo.h"

using namespace std;

int main () {
	CorrePocoyo<int> carrera;
	carrera.nuevoCorredor(8);
	carrera.nuevoCorredor(3);
	carrera.nuevoCorredor(55);
	carrera.nuevoCorredor(0);
	cout << carrera << endl;
	CorrePocoyo<int> carrera2;
	carrera.nuevoCorredor(8);
	carrera.nuevoCorredor(3);
	cout << (carrera == carrera2) << endl;
	return 0;
}
