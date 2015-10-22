#include "iostream.h"
#include "fstream.h"
#include "conio.h"

class A {
	int i;
	float x;
public:
	void asignar(int *p,float *q) {
		cout << "De i:";
		cin >> i;
		cout << "De x:";
		cin >> x;
		*p = i;
		*q = x;
	}
};

void main() {
	ofstream sale;
	sale.open ("prueba", ios::out | ios:: trunc, 0);
	A objeto;
	int i;
	float f;
	do {
		objeto.asignar(&i,&f);
		if(i == 0 && f == 0.0)
			break;
		sale.write( (char *)&objeto,sizeof (A)  );
	} while (1);
	sale.close();
}


