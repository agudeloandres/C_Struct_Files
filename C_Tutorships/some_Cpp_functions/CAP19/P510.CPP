#include "iostream.h"
#include "math.h"   // M_PI
#include "stdio.h"
void main() {
	char *q;
	q = new char [100];
	sprintf (q,"%d %s %15.10f %p \n",0x23,"ejemplo",M_PI,q);
	/*
	.
	.   Otras Instrucciones
	.
	.
	.
	*/
	cout << q << endl;
}


