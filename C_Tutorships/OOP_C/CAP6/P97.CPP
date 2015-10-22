#include "iostream.h"

main() {
	int i;
	int &j = i;
	i = 3;
	cout << j << '\n' << i << '\n';
	j = j + 2;
	cout << j << '\n' << i << '\n';
}
