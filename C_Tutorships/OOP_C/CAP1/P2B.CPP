#include "iostream.h"

struct X {
	int a;
	char b[5];
};

typedef struct X X;

class W {
	X x;
public:
	W();
	int F() { return x.a; }
	char G(int i) { return x.b[i]; }
};

main() {}

