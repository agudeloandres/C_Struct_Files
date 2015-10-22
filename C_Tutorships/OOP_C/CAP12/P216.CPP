#include "iostream.h"
#include "conio.h"
#include "string.h"

class base {
	char *p;
public:
	base (char *q) {
		p = new char [30];
		strcpy (p,q);
	}
	char *G() { return p; }
	~base() {
		cout << "destruyendo " << p << endl;
		delete p;
	}
};

class A : public base {
	int x;
public:
	A (char *q) :  base (q) { x = 0; }
	int F() { return x; }
	void suma (int i) { x = x + i; }
	~A() {}
};

class B : public base {
	int y;
public:
	B (char *q) : base (q) { y = 0; }
	int F() { return y; }
	void suma (int i) { y = y + i; }
	~B() {}
};

class C : public base {
	int z;
public:
	C (char *q) :  base (q) { z = 0; }
	int F() { return z; }
	void suma (int i) { z = z + i; }
	~C() {}
};

main() {
	A b("tipo A");
	B c("tipo B");
	C d("tipo C");
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
			case 'A': case 'a': b.suma (i); break;
			case 'B': case 'b': c.suma (i); break;
			case 'C': case 'c': d.suma (i); break;
		}
        cout << "A cual objeto desea sumar? (D para fin)\n";
		car = getche();cout << endl;
	}
	cout << b.G() << " = ";
	cout << b.F() << endl;
	cout << c.G() << " = ";
	cout << c.F() << endl;
	cout << d.G() << " = ";
	cout << d.F() << endl;
}

