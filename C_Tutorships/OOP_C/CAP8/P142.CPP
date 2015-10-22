#include "iostream.h"

double F(double d) { return d+1.0; }

float F(float x) { return x+1.0; }

main() {
	int x=10.0;
	cout << F(x) << endl;
}
