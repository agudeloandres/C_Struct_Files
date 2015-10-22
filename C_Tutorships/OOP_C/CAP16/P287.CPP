#include "iostream.h"
#include "iomanip.h"

main() {
	long ele = 0xac2;   	// 0000 1010 1100 0010
	cout << setiosflags(ele);
	int i = -284;
	float x = 42.31;
	cout << i << ' ' << x << endl;
}