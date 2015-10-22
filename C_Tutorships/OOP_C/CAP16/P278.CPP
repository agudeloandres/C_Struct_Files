#include "iostream.h"

main() {
	int i;
	float f;
	cout.setf(ios::right);
	cout << "De dos numeros: el primero int y el segundo float...";
	cin >> i >> f;
	cout.setf(ios::left | ios::showpos | ios:: scientific);
	cout << i << ' ' << f;
}

