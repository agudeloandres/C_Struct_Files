#include "stdio.h"
#include "conio.h"

void main()
{
	int buscar1 (int a[], int i);
	void unir1 (int a[], int i, int j);
	int a[21],i;
	for (i=1; i <= 20; i++)
		a[i] = 0;
	unir1 (a, buscar1 (a, 18), buscar1 (a, 1));
	unir1 (a, buscar1 (a,  4), buscar1 (a, 8));
	unir1 (a, buscar1 (a,  5), buscar1 (a,19));
	unir1 (a, buscar1 (a, 10), buscar1 (a,14));
	unir1 (a, buscar1 (a, 11), buscar1 (a,15));
	unir1 (a, buscar1 (a, 20), buscar1 (a, 2));
	unir1 (a, buscar1 (a,  3), buscar1 (a, 2));
	unir1 (a, buscar1 (a,  8), buscar1 (a,19));
	unir1 (a, buscar1 (a, 20), buscar1 (a, 7));
	unir1 (a, buscar1 (a,  8), buscar1 (a,12));
	unir1 (a, buscar1 (a, 14), buscar1 (a, 4));
	unir1 (a, buscar1 (a, 12), buscar1 (a,15));
	unir1 (a, buscar1 (a,  9), buscar1 (a,16));
	unir1 (a, buscar1 (a,  3), buscar1 (a, 6));
	unir1 (a, buscar1 (a, 10), buscar1 (a,16));
	unir1 (a, buscar1 (a, 17), buscar1 (a, 1));
	unir1 (a, buscar1 (a,  7), buscar1 (a,17));
	for (i=1; i <= 20; i++)
		printf ("%d ",a[i]);
}
int buscar1 (int a[], int i)
{
	while (a[i] > 0)
		i = a[i];
	return (i);
}

void unir1 (int a[], int i, int j)
{
	a[i] = j;
}
