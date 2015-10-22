#include "iostream.h"

class A {
	int x,y;
public:
	A(int i=0,int j=0) : x(i),y(j) {}
	A &operator--() {
		x--;
		y--;
		return *this;
	}
	int operator!() {
		if (!x && !y)
			return 1;
		else return 0;
	}
	A &operator-() {
		x = -x;
		y = -y;
		return *this;
	}
	A &operator~() {
		x = ~x;
		y = ~y;
		return *this;
	}
	void F(int &p,int &q) { p = x; q = y; }
};

main() {
	A b(1,1),c(2,3);
	int i,j;
	b--;
	if (!b)
		cout << "Las variables x,y de b son 0\n";
	c = ~c;
	--b;
	b--;
	b = -b;
	-c;
	b.F(i,j);
	cout << i << ' ' << j << endl;
	c.F(i,j);
	cout << i << ' ' << j << endl;
}
