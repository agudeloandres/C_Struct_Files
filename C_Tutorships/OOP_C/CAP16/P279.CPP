#include "iostream.h"

main() {
	int i=35;
	cout.setf(ios::showpos);
	cout << i << endl;
	cout.unsetf(ios::showpos);
	cout << i << endl;
}

