#include "iostream.h"

main() {
	int i = 31345;
	cout.setf(ios::hex | ios::uppercase | ios::showbase);
	cout << i << endl;
	cout.unsetf(ios::hex | ios::uppercase);
	cout.setf (ios::oct);
	cout << i << endl;
}

