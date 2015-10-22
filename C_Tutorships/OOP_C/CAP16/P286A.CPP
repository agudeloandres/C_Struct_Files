#include "iostream.h"
#include "iomanip.h"

main() {
	int i;
	cout << "De un entero. !en hexa!...\n";
	cin >> hex >> i;
	cout  << setbase(8) << i << endl;
	cout << 4956 << endl;
}