#include "iostream.h"

void indicadores() {
	long ele = cout.flags();
	for (int i=0; i < 16; i++) {
		if ( (ele & 0x8000) == 0x8000)
			cout << '1';
		else cout << '0';
		ele <<= 1;
	}
	cout << endl;
}

main() {
	int indicadores();
	indicadores();
	cout.setf(ios::internal | ios::showbase | ios::scientific |
				ios::stdio);
	indicadores();
}


