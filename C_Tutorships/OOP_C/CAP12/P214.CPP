#include "iostream.h"
#include "stdlib.h"

class base {
	int x,y;
public:
	base (int i=0,int j=0): x(i),y(j) {}
	int F() { return x+y; }
	void G() { x++; y++; }
};

class derivada : public base {
	int z;
public:
	derivada(int j,int k) : base(j,k), z(j+k)  {}
};

main() {
	derivada a ( random(11), random(11) );
	a.G();
	cout << a.F() << endl;
}
