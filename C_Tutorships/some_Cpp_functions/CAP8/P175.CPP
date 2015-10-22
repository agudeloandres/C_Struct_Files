#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x) printf ("%s\n",x)
#define PR(x) printf ("%d\n",x)

struct DATOS {
	int i;
	char a[30];
};

void main() {
	int id,i;
	char *p;

	if ( (i = _chmod ("prueba",0,0)) == -1) {
		p = strerror (errno);
		PRS(p);
		getch();
		exit (1);
	}
	if (i == FA_ARCH)
		if ((i = _chmod ("prueba",1,FA_HIDDEN) ) == -1) {
			p = strerror (errno);
			PRS(p);
			getch();
			exit (1);
		}
	getch();
}
