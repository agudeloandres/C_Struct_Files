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
	long f = 0x68c9; // 0110 1000 1100 1001
	cout.flags(f);
	indicadores();
}


