#include "dos.h"
#include "conio.h"
#include "stdio.h"
void main() {
	struct fatinfo p;
	unsigned char u;

	getfat (1,&p);	/* 0 = default  1 = A: 2 = B: 3 = C  */
	u = (unsigned char) p.fi_fatid;
	switch (u) {
		case 0xfe : printf ("5.25,160kb,1 cab, 8 Sect/pista\n");break;
		case 0xff : printf ("5.25,320kb,2 cab, 8 Sect/pista\n");break;
		case 0xfc : printf ("5.25,180kb,1 cab, 9 Sect/pista\n");break;
		case 0xfd : printf ("5.25,360kb,2 cab, 9 Sect/pista\n");break;
		case 0xf9 : printf ("5.25,1.2MB,2 cab,15 Sect/pista, o,\n");
			    printf ("3.5 ,720kb,2 cab, 9 Sect/pista\n");break;
		case 0xf0 : printf ("3.5,1.44MB,2 cab,18 Sect/pista\n");break;
		case 0xf8 : printf ("Disco duro\n");break;
		default : printf ("Error en unidad\n"); break;
	}
	getch();
}
