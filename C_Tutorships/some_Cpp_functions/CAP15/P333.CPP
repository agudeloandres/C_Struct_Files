#include "dos.h"
#include "conio.h"
#include "stdio.h"
#include "string.h"

void main() {
	char *directorio = "c:\\turboc\\nuevo";
	union REGS r;
	struct SREGS s;

	s.ds = FP_SEG (directorio);
	r.x.dx = FP_OFF (directorio);
	r.h.ah = 0x39;
	int86x (0x21, &r, &r,&s);
	if (r.x.cflag != 0) 		/* Ocurrio un error */
		printf ("%s\n",strerror (_doserrno));
	getch();
}





