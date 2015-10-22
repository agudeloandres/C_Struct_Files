#include "dos.h"
#include "errno.h"
#include "conio.h"
#include "stdio.h"
#include "stdlib.h"


/******** Esta es la definicion de  la estructura  **************/
/******** Se  encuentra en dos.h   ******************************/
/*
struct	fcb	{
	char	fcb_drive;
	char	fcb_name[8];
	char	fcb_ext[3];
	short	fcb_curblk;
	short	fcb_recsize;
	long	fcb_filsize;
	short	fcb_date;
	char	fcb_resv[10];
	char	fcb_currec;
	long	fcb_random;		
};
*/

/******** Fin de la estructura     *******************************/


void main() {
	char s[] = "a:a.txt", *p;
	struct fcb archivo, *q;

	q = &archivo;
	p = parsfnm (s, q, 0);
	if (p == NULL) {
		printf ("%s\n",strerror (errno) );
		getch();
		exit (1);
	}
	printf ("Drive = %c\nNombre = %s\nExtension = %s\n",
		q->fcb_drive + 'a'-1, q->fcb_name, q->fcb_ext);
	getch();
}


