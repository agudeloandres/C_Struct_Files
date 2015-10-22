#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x) printf ("%s\n",x)
#define PR(x) printf ("%d\n",x)

void main() {
	int id,i;
	char *q;
	struct ftime p;

	if ( (id = _open ("prueba",O_RDONLY)) == -1) {
		q = strerror (errno);
		PRS(q);
		getch();
		exit (1);
	}
	p.ft_tsec = 0;
	p.ft_min =  0;
	p.ft_hour = 12;
	p.ft_day =  31;
	p.ft_month = 12;
	p.ft_year =  11;   /* 1991 - 1980 */
	i = setftime (id,&p);
	if ( i == -1){
		q = strerror (errno);
		PRS(q);
		getch();
		exit (1);
	}
	getch();
	_close (id);
}
