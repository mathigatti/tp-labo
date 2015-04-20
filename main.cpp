# include <iostream>
# include "correpocoyo.h"

using namespace std;

int main () {
	CorrePocoyo<int> carrera;
	carrera.nuevoCorredor(8);
	cout << carrera.dameCorredorEnPos(1);
	return 0;
}
