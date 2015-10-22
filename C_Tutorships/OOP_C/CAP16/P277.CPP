#include "iostream.h"

main() {
	int i=2345;
	cout.setf(ios::oct);
	cout << i << endl;
	cout.unsetf(ios::oct);
	cout.setf(ios::hex);
	cout << i << endl;
}

