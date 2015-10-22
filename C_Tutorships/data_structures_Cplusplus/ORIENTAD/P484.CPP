#include "stdio.h"
#include "conio.h"

void main()
{
	void unir2 (int a[], int i, int j);
	int buscar2 (int a[], int i);
	int a[21],i;
	for (i=1; i <= 20; i++)
		a[i] = -1;
	unir2 (a, buscar2 (a, 18), buscar2 (a,12));
	unir2 (a, buscar2 (a,  6), buscar2 (a,10));
	unir2 (a, buscar2 (a,  8), buscar2 (a, 2));
	unir2 (a, buscar2 (a, 11), buscar2 (a, 5));
	unir2 (a, buscar2 (a, 16), buscar2 (a,14));
	unir2 (a, buscar2 (a,  9), buscar2 (a, 1));
	unir2 (a, buscar2 (a,  3), buscar2 (a,13));
	unir2 (a, buscar2 (a,  7), buscar2 (a,19));
	unir2 (a, buscar2 (a,  8), buscar2 (a,18));
	unir2 (a, buscar2 (a, 17), buscar2 (a, 4));
	unir2 (a, buscar2 (a,  9), buscar2 (a,11));
	unir2 (a, buscar2 (a,  3), buscar2 (a, 9));
	unir2 (a, buscar2 (a, 16), buscar2 (a, 6));
	unir2 (a, buscar2 (a, 16), buscar2 (a,17));
	unir2 (a, buscar2 (a,  3), buscar2 (a, 8));
	unir2 (a, buscar2 (a, 19), buscar2 (a,15));
	printf ("\n");
	for (i=1; i <= 19; i++)
		printf ("%d:%d\n", i,a[i]);
	getch();
}


void unir2 (int a[], int i, int j)
{
	int k;

	k = a[i] + a[j];
	if (a[i] < a[j]) {
		a[j] = i;
		a[i] = k;
	}
	else {
		a[i] = j;
		a[j] = k;
	}
}

int buscar2 (int a[], int i)
{
	int k,j,temp;

	j = i;
	while (a[j] > 0)
		j = a[j];
	k = i;
	while (k != j) {
		temp = a[k];
		a[k] = j;
		k = temp;
	}
	return (j);
}


