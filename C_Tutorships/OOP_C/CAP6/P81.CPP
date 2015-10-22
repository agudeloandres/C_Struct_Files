#include "iostream.h"

void F(int &i) {
	i++;
}

main() {
	void F(int &);
	int i;
	cin >> i;
	F(i);
	cout << i << endl;
}

