#include "iostream.h"
#include "iomanip.h"

main() {
	int i=45;
	float f=0.482213;
	cout << setfill('z') << setprecision(2);
	cout << setw(10) << i;
	cout << setw(10) << f << endl;
}