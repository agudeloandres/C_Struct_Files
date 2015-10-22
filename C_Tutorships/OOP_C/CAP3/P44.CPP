#include "iostream.h"

inline int F() {
	cout << "De dato\n";
	int i;
	cin >> i;
	return i;
}

main() {
	int i,j,k;
	i = F();
	j = F();
	k = F();
	cout << i << ' ' << j << ' ' << k << endl;
}
