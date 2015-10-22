#include "dos.h"
#include "errno.h"
#include "conio.h"
#include "string.h"
void main() {
	char directorio [64],aux [64];
	unsigned char i;
	void inicializar() ;
	void escriba (char c);
	void dir_activo (char *a);

	inicializar();	/* Inicializa la impresora */
	dir_activo (directorio);
	strcpy (aux,"c:\\");
	strcat (aux,directorio);
	i  = 0;
	while (aux [i] != '\0')  {
		escriba (aux [i]);
		i++;
	}
	escriba ('\n');
	getch();
}

void inicializar() {		/* Inicializa la impresora */
	_AH = 1;
	_DX = 0;
	geninterrupt (0x17);
}

void escriba (char c) {	/* Escribe un caracter en la impresora */
	_AH = 0;
	_AL = c;
	_DX = 0;
	geninterrupt (0x17);
}

void dir_activo (char *a) {	/* Informa el directorio actual */
		union REGS r;
		struct SREGS s;

		r.h.ah = 0x47;
		r.h.dl = 0;
		s.ds = FP_SEG (a);
		r.x.si = FP_OFF (a);
		int86x(0x21,&r,&r,&s);  /* La llamada tambien puede ser: */
					/* intdosx (&r,&r,&s);  produciendo */
					/* los mismos resultados */
}
