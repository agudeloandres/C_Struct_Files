#include "dos.h"
#include "errno.h"
#include "stdio.h"
#include "conio.h"

void main() {
	int renombrar (char *antiguo, char *nuevo);
	char *antiguo = "c:\\turboc\\work\\cap15\\set4.c";
	char *nuevo = "c:\\turboc\\work\\cap15\\set5.c";

	if (renombrar (antiguo, nuevo) == 0)
		printf ("Operacion correcta...\n");
	else printf ("Ocurrio un error\n");
	getch();
}



int renombrar (char *antiguo, char *nuevo) {
	union REGS r;
	struct SREGS s;

	r.h.ah = 0x56;

	s.ds = FP_SEG (antiguo);
	r.x.dx = FP_OFF (antiguo);

	s.es = FP_SEG (nuevo);
	r.x.di = FP_OFF (nuevo);

	intdosx(&r, &r, &s);
	if (r.x.cflag != 0) {		/* error */
		printf ("%s\n",strerror (_doserrno) );
		getch();
		return (-2);
	}
	return (0);
}







