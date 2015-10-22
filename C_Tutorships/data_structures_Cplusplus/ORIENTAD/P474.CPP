#include "stdio.h"
#include "conio.h"

void main()
{
	void unir2 (int a[], int i, int j);
	int buscar1 (int a[], int i);
	int a[21],i;
	for (i=1; i <= 20; i++)
		a[i] = -1 ;
	unir2 (a, buscar1 (a, 18), buscar1 (a, 1));
	unir2 (a, buscar1 (a,  4), buscar1 (a, 8));
	unir2 (a, buscar1 (a,  5), buscar1 (a,19));
	unir2 (a, buscar1 (a, 10), buscar1 (a,14));
	unir2 (a, buscar1 (a, 11), buscar1 (a,15));
	unir2 (a, buscar1 (a, 20), buscar1 (a, 2));
	unir2 (a, buscar1 (a,  3), buscar1 (a, 2));
	unir2 (a, buscar1 (a,  8), buscar1 (a,19));
	unir2 (a, buscar1 (a, 20), buscar1 (a, 7));
	unir2 (a, buscar1 (a,  8), buscar1 (a,12));
	unir2 (a, buscar1 (a, 14), buscar1 (a, 4));
	unir2 (a, buscar1 (a, 12), buscar1 (a,15));
	unir2 (a, buscar1 (a,  9), buscar1 (a,16));
	unir2 (a, buscar1 (a,  3), buscar1 (a, 6));
	unir2 (a, buscar1 (a, 10), buscar1 (a,16));
	unir2 (a, buscar1 (a, 17), buscar1 (a, 1));
	unir2 (a, buscar1 (a,  7), buscar1 (a,17));
	printf ("\n");
	for (i=1; i <= 20; i++)
		printf ("%d ",a[i]);
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
int buscar1 (int a[], int i)
{
	while (a[i] > 0)
		i = a[i];
	return (i);
}
