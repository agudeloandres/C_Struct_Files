
// Antes de compilar y ejecutar este programa,
// actualize la tabla de codificacion de paises
// de acuerdo con la version del DOS que usted
// este utilizando. Gracias

#include "dos.h"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

char *paises[] = {  |<------ Coloque el codigo de cada pais aqui
	"Australia       0",
	"Belgica         0",
	"Dinamarca       0",
	"Finlandia       0",
	"Francia         0",
	"Alemania        0",
	"Israel          0",
	"Italia          0",
	"Holanda         0",
	"Noruega         0",
	"Espana          0",
	"Suecia          0",
	"Suiza           0",
	"Gran Bretana    0",
	"Estados Unidos  0"
};

void main() {
	struct COUNTRY *pais,*P;
	int i,j;
	pais = (struct COUNTRY *)malloc (sizeof (COUNTRY));
	for (i = 0; i < 15; i++) {
		clrscr();
		j = atoi (paises [i]+16);
		P = country (j, pais);
		if (P == NULL) {
			printf ("Error al llamar la funcion\n");
			getch();
			exit (1);
		}
		printf ("******%.14s(%d)*******\n",paises [i],j);
		printf ("FORMATO DE LA FECHA\n");
		switch (pais->co_date) {
			case 0 : printf ("Mes, Dia, Ano\n"); break;
			case 1 : printf ("Dia, Mes, Ano\n"); break;
			case 2 : printf ("Ano, Mes, Dia\n"); break;
			default : printf ("Error en estilo de fecha\n");
		}
		printf ("SIMBOLO DE LA MONEDA\n");
		printf ("%s\n",pais->co_curr);
		printf ("SEPARADOR DE MILES\n");
		printf ("%s\n",pais->co_thsep);
		printf ("SEPARADOR DE DECIMALES\n");
		printf ("%s\n",pais->co_desep);
		printf ("SEPARADOR DE FECHA\n");
		printf ("%s\n",pais->co_dtsep);
		printf ("SEPARADOR DE HORA\n");
		printf ("%s\n",pais->co_tmsep);
		printf ("ESTILO ACTUAL\n");
		printf ("%c\n",pais->co_currstyle);
		printf ("DIGITOS SIGNIFICATIVOS EN MONEDA\n");
		printf ("%c\n",pais->co_digits);
		printf ("FORMATO DE HORA\n");
		printf ("%c\n",pais->co_time);
		printf ("CASE MAP\n");
		printf ("%ld\n",pais->co_case);
		printf ("SEPARADOR DE DATOS\n");
		printf ("%s\n",pais->co_dasep);
		getch();
	}
	free(pais);
	getch();
}