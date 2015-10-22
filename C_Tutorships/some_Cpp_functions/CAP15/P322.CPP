
int F(void) {
	printf ("Programa cancelado por el usuario\n");
	printf ("Por favor hacer copia del archivo \'archi.txt\'\n");
	printf ("Oprima una tecla...\n");
	getch();
	return (0);  	/* 0 Aborta el programa */

			/* Un valor diferente de cero, reasume la */
			/* La ejecucion del programa */

}
