
#define ubicar(id,x) lseek (id,(long)x * LON,SEEK_SET)
#define leer(id,x)  _read (id,(char *)&x,LON)
#define grabar(id,x)  _write (id,(char *)&x,LON)

void actualizar(char * prueba) {
		/*      Actualiza cualquier registro del archivo "prueba".
		/* 	Recuerde que el primer registro del archivo es el 0
			el segundo el 1, el tercero el 2, y asi
			sucesivamente */
	int n,id,n_r,c;
	DATOS r;
	char *p;

	if ( (id = _open (prueba,O_RDWR) ) == -1) {
		p = strerror (errno);
		PRS (p);
		getch(); exit(1);
	}
	n_r = n_registros(id);
	printf ("Numero de registros del archivo = %d\n",n_r);
	PRS("Lea el numero del registro a actualizar.");
	PRS("Recuerde que el primer registro en el 0.");
	PRS("El segundo es el 1, el tercero es el 2.");
	PRS("El cuarto es el 3 y asi sucesivamente.");
	n = lea_entero();
	while (n < n_r) {
		if (ubicar (id,n) == -1) {
			p = _strerror ("Error _lseek ()");
			PRS (p);
			getch(); exit(1);
		}
		if (leer (id,r) == -1) {
			p = _strerror ("Error _read ()");
			PRS (p);
			getch(); exit(1);
		}
		PRS("Los datos actuales son:");
		printf ("%d %s\n",r.i,r.a);
		PRS("Desea modificarlos?(s/n)");
		c = getch();
		if (c == 's' || c == 'S') {
			lea_reg (&r);
			if (ubicar(id,n) == -1) {
				p = _strerror ("Error _lssek ()");
				PRS (p);
				getch(); exit(1);
			}
			if (grabar (id,r) == -1) {
				p = _strerror ("Error _write()");
				PRS (p);
				getch(); exit(1);
			}
		}
		PRS("Lea el numero del registro a actualizar");
		n = lea_entero();
	}
	if ( _close (id) == -1) {
		p = strerror(errno);
		PRS (p);
		getch(); exit(1);
	}
}

int n_registros(int id) { /* Calcula el numero de registros del archivo */
	long i;

	i = lseek (id,(long)0,SEEK_END);
	return ((int) i / LON);
}
