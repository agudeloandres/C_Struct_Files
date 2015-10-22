#include "iostream.h"

void F(int &i,float &j) {
	i++;
	j = j + 3;
}

main() {
	int j = 3;
	float k = 2.1;
	void F(int &,float &);
	F(j, k);
	cout << j << "  " << k << endl;
}


