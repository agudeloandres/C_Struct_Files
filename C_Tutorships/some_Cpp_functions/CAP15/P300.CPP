#include "bios.h"
#include "stdio.h"
#include "conio.h"
void main() {
	int i;

	i = biosmemory ();
	printf ("Memoria RAM = %dKb = %ld bytes\n",i,(long)i * 1024);
	getch();
}