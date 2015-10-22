#include "iostream.h"

class A {
	int x,y;
public:
	A() { x = y = 0; }
	void iniciar (int i,int j) { x = i; y = j; }
	int F(int *p) {
		*p = y;
		return x;
	}
};

main() {
	A b [5];
	A c [5];
	int j;
	for (int i = 0; i < 5; i++)
		c[i].iniciar (i,i+1);
	for (i = 0; i < 5; i++) {
		cout << b[i].F(&j) << ' ';
		cout << j << ' ';
	}
	cout << endl;
	for (i = 0; i < 5; i++) {
		cout << c[i].F(&j) << ' ';
		cout << j <<  ' ';
	}
}
