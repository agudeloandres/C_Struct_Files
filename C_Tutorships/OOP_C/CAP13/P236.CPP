#include "iostream.h"

class compleja {
	float r,i;
	friend class imaginaria;
	friend class real;
public:
	compleja (float rr=0,float ii=0) { r = rr; i = ii; }
	compleja(compleja &a) { r = a.r; i = a.i; }
	compleja &operator=(compleja &a) { r = a.r; i = a.i; return *this; }
	compleja operator+(compleja &a) {
		compleja t;
		t.r = r + a.r; t.i = i + a.i;
		return t;
	}
	float R() { return r; }
	float I() { return i; }
	operator float() { return r; }
};

class imaginaria : public compleja {
public:
	imaginaria (float i=0) : compleja (0,i) {}
	imaginaria(compleja &a) : compleja (0, a.i) {}
	imaginaria &operator=(compleja &a) { r = 0; i = a.i; return *this; }
	operator float() { return i; }
};

class real : public compleja {
public:
	real (float r=0) : compleja (r,0) {}
	real(compleja &a) : compleja (a.r,0) {}
	real &operator=(compleja &a) { r = a.r; i = 0; return *this; }
};

main() {
	compleja c = compleja (3,4);					// 1
	imaginaria k = 6;								// 2
	compleja suma = c + k;							// 3
	imaginaria i = -1;								// 4
	compleja j = compleja (4,6);					// 5
	float a = float (i);							// 6
	float b = float (j);							// 7
	cout << c.R() << ' ' << c.I() << endl;			// 8
	cout << k.R() << ' ' << k.I() << endl;			// 9
	cout << suma.R() << ' ' << suma.I() << endl;	// 10
	cout << i.R() << ' ' << i.I() << endl;			// 11
	cout << j.R() << ' ' << j.I() << endl;			// 12
	cout << a << ' ' << b << endl;					// 13
};
