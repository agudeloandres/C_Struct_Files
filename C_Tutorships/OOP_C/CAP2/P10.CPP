#include "iostream.h"
#include "conio.h"

main() {
	int i;
	double y;
	float x;
	char j;
	cin >> i >> x >> y >> j;  // Si se teclea:  1 2 3 4 <R>
	i = i + x + y;
	j = j + 'A';
	cout << x << " " << i << " " << endl;  	// Escribe: 2 6
	cout << y << " " << j << endl;			// Escribe: 3 u
	getch();
}
