#include "iostream.h"
#include "fstream.h"

main() {
	ifstream entra;
	entra.open ("prueba",ios::in, 0);
	cout << endl;
	char c;
	entra.get(c);
	while (!entra.eof()) {
		cout << c;
		entra.get(c);
	}
	entra.close();
}