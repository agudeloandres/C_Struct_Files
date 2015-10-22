#include "iostream.h"
#include "fstream.h"
#include "iomanip.h"

class A {
	int i;
	float x;
public:
	void F(int *p,float *q) {
		*p = i;
		*q = x;
	}
};

ostream &formato1 (ostream &s) {
	s << setprecision (4);
	s << setw(10);
	s.setf(ios::left | ios :: showpoint);
	return s;
}

void main() {
	ifstream entra;
	entra.open ("prueba", ios::in, 0);
	A objeto;
	int i;
	float f;
	entra.read ( (char *)&objeto, sizeof (A) );
	while (!entra.eof() ) {
		objeto.F(&i,&f);
		cout << "datos = " << formato1 << i << f << endl;
        entra.read ( (char *)&objeto, sizeof (A) );
	}
	entra.close();
}


