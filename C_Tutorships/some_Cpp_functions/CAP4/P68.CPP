double lea_double () {
	double x;
	char a[15],*p;

	gets (a);
	x = strtod (a, &p);
	while (*p != '\0') {			/* Ciclo para validar a[] */
		printf ("%c",7);  		/* Aviso de error */
		printf ("Dato incorrecto..\n");
		gets (a);
		x = strtod (a,&p);
	}
	/* Dato de tipo double 	correcto */
	return (x);
}
