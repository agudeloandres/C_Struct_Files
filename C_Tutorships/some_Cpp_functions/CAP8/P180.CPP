#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#define PRS(x) printf ("%s\n",x)
#define PR(x) printf ("%d\n",x)

main() {
	int id,i;
	char *q;
	struct ftime p;

	if ( (id = _open ("prueba",O_RDONLY)) == -1) {
		q = strerror (errno);
		PRS(q);
		getch();
		exit (1);
	}
	i = getftime (id,&p);
	if ( i == -1) {
		q = strerror (errno);
		PRS(q);
		getch();
		exit (1);
	}
	printf ("Segundos = %u\n",p.ft_tsec);
	printf ("Minutos  = %u\n",p.ft_min);
	printf ("Horas    = %u\n",p.ft_hour);
	printf ("Dia      = %u\n",p.ft_day);
	printf ("Mes      = %u\n",p.ft_month);
	printf ("Ano      = %u\n",p.ft_year + 1980); /* Para
				que nos informe el ano correcto */
	getch();
	_close (id);
}
