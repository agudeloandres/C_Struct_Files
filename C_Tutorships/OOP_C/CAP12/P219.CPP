#include "iostream.h"

class A {
public:
	A() { cout << "Construye base" << endl; }
	~A() { cout << "Destruye base" << endl; }
};

class B : public  A {
public:
	B() { cout << "Construye B" << endl; }
	~B() { cout << "Destruye B" << endl; }
};

class C : public A {
public:
	C() { cout << "Construye C" << endl; }
	~C() { cout << "Destruye C" << endl; }
};

main() {
	B a;
	C b;
}


