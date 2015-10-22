#include "iostream.h"

class Z {
	int x,y;
public:
	Z() {}
	void valor(int i,int j) { x = i;  y = j; }
	void F(int *p,int *q) { *p = x; *q = y; }
};


