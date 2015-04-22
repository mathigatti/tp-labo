# include <iostream>
#include <string>
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
	
	CorrePocoyo<int> carrera3 = CorrePocoyo<int>(carrera2);
	
	CorrePocoyo<string> carrera4;
	carrera4.nuevoCorredor("Roberto");
	carrera4.nuevoCorredor("Fulanito");
	carrera4.nuevoCorredor("Pepe", "Fulanito");
	cout << carrera4 << endl;
	
	cout << "La carrera 1 es igual a la 2?: " << (carrera == carrera2) << endl;
	cout << "La carrera 2 es igual a la 3?: " << (carrera3 == carrera2) << endl;
	cout << "Primer corredor de la carrera 3: " << carrera3.damePrimero() << endl;
	cout << "Posición de Fulanito: " << carrera4.damePosicion("Fulanito") << endl;
	cout << "Posición de Pepe: " << carrera4.damePosicion("Pepe") << endl;
	carrera2.nuevoCorredor(555);
	cout << "La carrera 2 es igual a la 3?: " << (carrera3 == carrera2) << endl;
	cout << carrera4 << endl;
	return 0;
}
