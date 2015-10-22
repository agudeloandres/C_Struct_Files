#include "iostream.h"

main() {
	float f = 34.45645,g = 0.3433423;
	cout.precision(2);
	cout.width(10);
	cout << f;
	cout.width(10);
	cout <<  g << endl;
}