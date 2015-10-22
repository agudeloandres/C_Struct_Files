#include "iostream.h"
#include "conio.h"

class UNO {
	int i;
public:
	void F(int j) { i = j; }
	int H() { return i+1; }
};

class DOS {
	UNO a;
public:
	void G(int k) { a.F(k); }
	int L() { return a.H(); }
};

main() {
	DOS b;
	b.G(8);
	cout << b.L() << endl;
	getch();
}

