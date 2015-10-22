#include "iostream.h"

class B {
	int i;
public:
	B(int);
	int F();
	void G(int);
	~B();
};

B::B(int j) { i = j;}

int B::F() { return i; }

void B::G(int k) {
	i++;
	i += k;
}

B::~B() { cout << "Destruyendo...\n"; }

main() {}

