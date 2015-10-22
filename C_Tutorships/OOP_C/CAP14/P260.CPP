#include "iostream.h"

class V {
	V *q;
public:
	virtual int m() { return 0;}
	virtual void T() { q->T(); }
	virtual void s() { q->s(); }
	V(V *h) { q = h; }
};

class P : public V {
	int m() { return 10;}
	P (V *v) : V(v) {}
};

class B : public V {
	int m() { return 3;}
	B (V *v) : V(v) {}
};

class S : public V {
	V *b,*p,*c;
public:
	S():V(0) {
		c = b = new B(this);
		p = new P(this);
	}
	~S() {delete b; delete p;}
	void T() { c = p;}
	void s() { c = b;}
	V *operator->() { return c;}
};

main() {
	S a;
	cout << a->m() << endl;
	a->T();
	cout << a->m() << endl;
	a->s();
	cout << a->m() << endl;
}
