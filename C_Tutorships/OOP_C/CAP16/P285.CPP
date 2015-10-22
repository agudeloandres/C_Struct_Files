#include "iostream.h"

main() {
	int i = 100;
	cout.width(10);
	cout.flags(0x0002);
	cout << oct << i << endl;
	cout.width(10);
	cout.flags(0x0004);
	cout << hex << i << endl;
}