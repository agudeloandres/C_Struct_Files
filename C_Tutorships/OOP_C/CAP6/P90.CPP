#include "iostream.h"

int x,y;

int &F(int &y) {
	y = 3;
	return x;
}

main() {
	int &F(int &);
	F(y) = 100;
	cout << x << endl;
	cout << y << endl;
}
