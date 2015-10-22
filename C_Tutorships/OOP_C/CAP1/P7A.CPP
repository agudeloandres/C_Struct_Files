#include "stdio.h"
#include "stdlib.h"
main() {
	for (int i = 0,sum = 0; i < 10; i++)
		sum = sum + i;
	char a[10];
	printf ("De numero\n");
	gets (a);
	int total = atoi(a);
	printf ("%d\n",total % sum);
}