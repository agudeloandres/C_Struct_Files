#include "iostream.h"
#include "string.h"
#include "iomanip.h"

main() {
	int i=123;
	long ele=24478;
	char a[] = "sept/9/92";
	char *p = new char [20];
	strcpy (p,"10:08:08");
	cout.width(8);				// 1
	cout.setf(ios::left);       // 2
	cout << ele;                // 3
	cout.unsetf(ios::left);     // 4
	cout.setf(ios::right);      // 5
	cout.width(8);              // 6
	cout << i;                  // 7
	cout.width(11);             // 8
	cout << a;                  // 9
	cout.unsetf(ios::right);    // 10
	cout.setf(ios::left);       // 11
	cout.width(11);             // 12
	cout << p;                  // 13
	cout << "ok";               // 14
	cout << endl;
}


