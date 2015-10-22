#include "iostream.h"
#include "math.h"

void F(int *p) {
	*p = abs(*p);
}

void F(float *p) {
	*p = fabs(*p);
}

void F(double *p) {
	*p = fabs(*p);
}

main() {
	void F(int *);
	void F(float *);
	void F(double *);

	int i;
	float f;
	double d;
	cout << "De un entero\n";
	cin >> i;
	cout << "De un real\n";
	cin >> f;
	cout << "De un double\n";
	cin >> d;
	F(&i);
	F(&f);
	F(&d);
	cout << i << endl;
	cout << f << endl;
	cout << d << endl;
}

