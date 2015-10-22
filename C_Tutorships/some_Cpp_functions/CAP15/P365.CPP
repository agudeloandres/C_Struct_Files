#include "dos.h"
#include "time.h"
#include "stdio.h"
#include "conio.h"

void main() {
	clock_t i,j;

	i = clock ();
	sleep(5);
	j = clock ();
	printf ("Tiempo transcurrido desde el inicio del programa = %lf \
segundos\n", (j - i) / CLK_TCK );
	getch();

}




