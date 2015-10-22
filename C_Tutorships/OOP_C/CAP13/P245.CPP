#include "iostream.h"
#include "conio.h"

class base {
	int total;
public:
	base (int ii=0) { total = ii;}
	int Fbase() { return total; }
	void sumabase(int i) { total = total + i; }
	~base() {}
};

class A : virtual public base {
	int x;
public:
	A (int i=0) :  base (i) { x = 0; }
	int FA() { return x; }
	void sumaA (int i) { x = x + i; sumabase(i); }
	~A() {}
};

class B : virtual public base {
	int y;
public:
	B (int i=0) : base (i) { y = 0; }
	int FB() { return y; }
	void sumaB (int i) { y = y + i; sumabase(i); }
	~B() {}
};

class C : virtual public base {
	int z;
public:
	C (int i=0) :  base (i) { z = 0; }
	int FC() { return z; }
	void sumaC (int i) { z = z + i; sumabase(i); }
	~C() {}
};

class D : public A, public B, public C {
public:
	D() : A(0),B(0),C(0) {}
};

main() {
	D b;
	int i;
	char car;
	cout << "A cual objeto desea sumar? (D para fin)\n";
	car = getche();cout << endl;
	while (car != 'D' && car != 'd') {
		while (car != 'A' && car != 'B' && car != 'C' &&
				car != 'a' && car != 'b' && car != 'c')
					car = getche();
		cout << "De entero a sumar...\n";
		cin >> i;
		switch(car) {
			case 'A': case 'a': b.sumaA (i);  break;
			case 'B': case 'b': b.sumaB (i); break;
			case 'C': case 'c': b.sumaC (i); break;
		}
        cout << "A cual objeto desea sumar? (D para fin)\n";
		car = getche();cout << endl;
	}
	cout << "total=" << b.Fbase() << endl;
	cout << "A    =" <<  b.FA() << endl;
	cout << "B    =" <<  b.FB() << endl;
	cout << "C    =" <<  b.FC() << endl;
}

