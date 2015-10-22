
#define M 13 /*503*/
#define MAXIMO 5
#define MAX_DAT 5
#define LONIND sizeof (struct IND)
#define LOND   30
#define FC 4
#define PR(x) printf ("%s\n",x)

#define cerrar(x) { if (_close (x) == -1) error("_close()"); }

#define leercab(x,y) { if(_read(x,(char*)&y,2)==-1)error("leercab"); }
#define grabarcab(x,y) { if(_write(x,(char*)&y,2)==-1)error("grabarcab"); }
#define ubicarcab(x,y) {if(lseek(x,(long)2*y,SEEK_SET)==-1)\
				error("ubicarcab");}

#define leerind(x,y) { if(_read(x,(char*)&y,LONIND)==-1)error("leerind"); }
#define grabarind(x,y) { if(_write(x,(char*)&y,LONIND)==-1)error("grabarind");}
#define ubicarind(x,y) {if(lseek(x,(long) LONIND * y,SEEK_SET)==-1)\
					error("ubicarind");}

#define leerd(x,y) { if(_read(x,y,LOND)==-1)error("leerd"); }
#define grabard(x,y) { if(_write(x,y,LOND)==-1)error("grabard"); }
#define ubicard(x,y) {if(lseek(x,(long) LOND * y,SEEK_SET)==-1)\
					error("ubicard");}

struct INFO {
	int cod;
	int pos;
};

struct IND {
	int cont;
	struct INFO info [FC];
	int sig;
};

struct DATOS {
	int cod;
	char n[30];
};

hash (int cod) {
	return (cod % M);
}

error (char *q) {
	char *p;

	p = _strerror (q);
	printf ("%s",p);
	getch();
	exit (1);
}

inicia() {
	int i,id,CERO=0;
	struct IND buffer;
	char a[30];

	id = _creat ("cabezas",FA_ARCH);
	cerrar(id);
	id = _open ("cabezas",O_WRONLY);
	for (i = 0; i < M; i++)
		grabarcab (id,CERO);
	cerrar(id);

	id = _creat ("indice",FA_ARCH);
	cerrar(id);
	id = _open ("indice",O_WRONLY);
	buffer.cont = 0;
	for (i=0; i < FC; i++) {
		buffer.info [i].cod = 0;
		buffer.info [i].pos = 0;
	}
	for (i = 0; i < MAXIMO; i++) {
		buffer.sig = i + 1;
		grabarind (id,buffer);
	}
	buffer.sig = 0;
	grabarind (id,buffer);
	cerrar(id);

	id = _creat ("datos",FA_ARCH);
	cerrar(id);
	id = _open ("datos",O_WRONLY);
	for (i = 0; i < MAXIMO; i++) {
		itoa (i+1,a,10);
		grabard(id,a);
	}
	itoa (0,a,10);
	grabard (id,a);
	cerrar(id);
}

captu () {
	int cab,id,idd,k;
	int i;
	struct DATOS datos;

	cab = _open ("cabezas",O_RDWR);
	id = _open ("indice",O_RDWR);
	idd = _open ("datos",O_RDWR);
	leadatos (&datos);
	while (datos.cod != 999) {
		k = hash (datos.cod);
		if (insertar (cab,id,idd,k,&datos) == -1) {
			PR ("Ya existe");
		}
		leadatos (&datos);
	}
	cerrar (cab);
	cerrar (id);
	cerrar (idd);
}

copiar (struct IND *p, struct IND *q) {
	int m;

	p->cont = q->cont;
	for (m=0; m < FC; m++) {
		p->info [m].cod = q->info [m].cod;
		p->info [m].pos = q->info [m].pos;
	}
	p->sig = q->sig;
}

insertar (int cab,int id,int idd,int k,struct DATOS *datos) {
	int i,j,esta,d,dd,m;
	struct IND buffer,temp,r0;
	char r0d [30];

	ubicarcab (cab,k);
	leercab (cab,i);
	esta = 0;
	j = 0;
	while (i != 0 && !esta) {
		ubicarind (id,i);
		leerind (id,buffer);
		m = 0;
		while (m < buffer.cont && buffer.info [m].cod != datos->cod)
			m++;
		if (m == buffer.cont) {
			j = i;
                        copiar (&temp,&buffer);
			i = buffer.sig;
		}
		else esta = 1;
	}
	if (esta == 1)
		return (-1);

        ubicard (idd,0);
	leerd (idd,r0d);
	dd = dispd (idd,r0d);
	if (j != 0 && temp.cont < FC) {
		temp.info [temp.cont].cod = datos->cod;
		temp.info [temp.cont].pos = dd;
		temp.cont++;
                ubicarind (id,j);
		grabarind (id,temp);
	}
	else {
		ubicarind (id,0);
		leerind (id,r0);
		d = disp (id,&r0);
		buffer.cont = 1;
		buffer.info [0].cod = datos->cod;
		buffer.info [0].pos = dd;
		for (m=1; m < FC; m++) {
			buffer.info [m].cod = 0;
			buffer.info [m].pos = 0;
		}
		buffer.sig = 0;
		ubicarind (id,d);
		grabarind (id,buffer);
		if (j == 0) {
			ubicarcab (cab,k);
			grabarcab (cab,d);
		}
		else {
			temp.sig = d;
			ubicarind (id,j);
			grabarind (id,temp);
		}
                ubicarind (id,0);
		grabarind (id,r0);
	}
	ubicard (idd,dd);
	grabard (idd,datos->n);
	ubicard (idd,0);
	grabard (idd,r0d);
	return (1);
}

disp (int id,struct IND *r0) {
	int i;
	struct IND b1;

	if (r0->sig == 0)
		ampliar (id,r0);
	i = r0->sig;
	ubicarind (id,i);
	leerind (id,b1);
	r0->sig = b1.sig;
	return (i);
}

ampliar (int id,struct IND *r0) {
	long ele;
	int i;
	struct IND buffer;

	ele = filelength (id);
	ele = ele / LONIND;
	lseek (id,(long)0,SEEK_END);
	buffer.cont = 0;
	for (i=0; i< FC; i++)
		buffer.info[i].cod = buffer.info[i].pos = 0;
	for (i = 1; i < MAXIMO; i++) {
		buffer.sig = (int)ele+i;
		grabarind (id,buffer);
	}
	buffer.sig = 0;
	grabarind (id,buffer);
	r0->sig = ele;
}

dispd (int idd,char *r0) {
	int i;
	char b1[30];

	if ( (atoi (r0) ) == 0)
		ampliard (idd,r0);
	i = atoi (r0);
	ubicard(idd,i);
	leerd(idd,b1);
	strcpy (r0, b1);
	return (i);
}

ampliard (int idd,char *r0) {
	long ele;
	int i;
	char buffer[30];

	ele = filelength (idd);
	ele = ele / LOND;
	lseek (idd,(long)0,SEEK_END);
	for (i = 1; i < MAX_DAT; i++) {
		itoa ((int)ele+i,buffer,10);
		grabard (idd,buffer);
	}
	itoa (0,buffer,10);
	grabard (idd,buffer);
	itoa ( (int)ele,buffer,10);
	strcpy (r0,buffer);
}
leadatos (struct DATOS *p) {
	char a[40];

	PR ("De codigo");
	gets (a);
	p->cod = atoi (a);
	PR ("De nombre");
	gets (p->n);
}
/*
leadatos (struct DATOS *p) {
	char a[40];

	p->cod = random (32000);

	itoa (p->cod,p->n,10);
	printf ("%d %s\n",p->cod,p->n);
}
*/
/*
consul () {
	int cod,cab,id,idd,k;
	struct IND b;
	char a[30];

	cab = _open ("cabezas",O_RDWR);
	id = _open ("indice",O_RDWR);
	idd = _open ("datos",O_RDWR);

	PR("De codigo a consultar");
	gets (a);
	cod = atoi (a);
	while (cod != 9999) {
		k = hash (cod);
		if (consultar (cab,id,idd,k,cod) == -1) {
			PR ("No existe");
			getch();
		}
		PR("De codigo a consultar");
		gets (a);
		cod = atoi (a);
	}
	cerrar (cab);
	cerrar (id);
	cerrar (idd);
}
	*/
consultar (int cab,int id,int idd,int k,int cod) {
	int i,esta,m;
	struct IND buffer;
	char a[30];

	ubicarcab (cab,k);
	leercab (cab,i);
	esta = 0;
	while (i != 0 && !esta) {
		ubicarind (id,i);
		leerind (id,buffer);
		m = 0;
		while (m < buffer.cont && buffer.info [m].cod != cod)
			m++;
		if (m == buffer.cont)
			i = buffer.sig;
		else esta = 1;
	}
	if (esta == 1) {
		ubicard (idd,buffer.info [m].pos);
		leerd (idd,a);
		PR(a);
		return (1);
	}
	else return (-1);
}

listar () {
	int cod,cab,id,idd,k,i;
	struct IND b;
	char a[30];

	cab = _open ("cabezas",O_RDWR);
	id = _open ("indice",O_RDWR);
	idd = _open ("datos",O_RDWR);
	PR("El siguiente listado presenta cada lista individualmente");
	while (!eof(cab) ) {
		leercab (cab,k);
		while (k!=0) {
			ubicarind (id,k);
			leerind (id,b);
			printf ("* ");
			for (i=0; i < b.cont; i++) {
				ubicard (idd,b.info [i].pos);
				leerd (idd,a);
				printf ("%d %s\\",b.info[i].cod,a);
			}
			PR(" ");
			k = b.sig;
		}
		PR ("Ahora veamos otra lista. Oprima una tecla");
		getch();
	}
	cerrar (cab);
	cerrar (id);
	cerrar (idd);
}


retira () {
	int cod,cab,id,idd,k;
	struct IND b;
	struct DATOS datos;
	char a[30];

	cab = _open ("cabezas",O_RDWR);
	id = _open ("indice",O_RDWR);
	idd = _open ("datos",O_RDWR);

	PR("De codigo a retirar");
	gets (a);
	cod = atoi (a);
	while (cod != 999) {
		k = hash (cod);
		if (retirar (cab,id,idd,k,cod,&datos) == -1)
			PR ("No existe");
		else
			printf ("Datos retirados = %d %s\n",datos.cod,
					datos.n);
		PR("De codigo a retirar ");
		gets (a);
		cod = atoi (a);
	}
	cerrar (cab);
	cerrar (id);
	cerrar (idd);
}

retirar (int cab,int id,int idd,int k,int cod,struct DATOS *datos) {
	int i,m,j,esta,d,dd,tempk,ZERO=0,libera;
	struct IND buffer,temp,r0;
	char r0d [30];

	ubicarcab (cab,k);
	leercab (cab,i);
	esta = 0;
	j = 0;
	while (i != 0 && !esta) {
		ubicarind (id,i);
		leerind (id,buffer);
		m = 0;
		while (m < buffer.cont && buffer.info [m].cod != cod)
			m++;
		if (m == buffer.cont) {
			j = i;
                        copiar (&temp,&buffer);
			i = buffer.sig;
		}
		else esta = 1;
	}
	if (esta == 0)
		return (-1);
	ubicard (idd,buffer.info [m].pos);
	leerd (idd,datos->n);
        libera = buffer.info [m].pos;
	for ( ; m < buffer.cont-1; m++) {
		buffer.info[m].cod = buffer.info [m + 1].cod;
		buffer.info[m].pos = buffer.info [m + 1].pos;
	}
	buffer.info[m].cod = 0;
	buffer.info[m].pos = 0;
	datos->cod = cod;
	tempk = k;
	k = j;
	j = i;
        copiar (&temp,&buffer);
	i = buffer.sig;
	while ( i != 0 ) {
		ubicarind (id,i);
		leerind (id,buffer);
		temp.info [FC - 1].cod = buffer.info [0].cod;
		temp.info [FC - 1].pos = buffer.info [0].pos;
		for (m = 0; m < buffer.cont-1; m++) {
			buffer.info[m].cod = buffer.info [m + 1].cod;
			buffer.info[m].pos = buffer.info [m + 1].pos;
		}
                buffer.info[m].cod = 0;
		buffer.info[m].pos = 0;
		ubicarind (id,j);
		grabarind (id,temp);
		k = j;
		j = i;
                copiar (&temp,&buffer);
		i = buffer.sig;
	}
	buffer.cont--;
	if (buffer.cont == 0) {
		if (k != 0) {
			ubicarind (id,k);
			leerind (id,buffer);
			buffer.sig = 0;
                        ubicarind (id,k);
			grabarind (id,buffer);
		}
		else {
			ubicarcab (cab,tempk);
			grabarcab (cab,ZERO);
		}
		ubicarind (id,0);
		leerind (id,r0);
		liberar (id,&r0,j);
		ubicarind (id,0);
		grabarind (id,r0);
	}
	else {
		ubicarind (id,j);
		grabarind (id,buffer);
	}
        ubicard (idd,0);
	leerd (idd,r0d);
	liberard (idd,r0d,libera);
	ubicard (idd,0);
	grabard (idd,r0d);
	return (1);

}

liberar (int id,struct IND *r0,int i) {
	struct IND b;
	int j;

	b.cont = 0;
	for (j=0; j < FC; j++) {
		b.info [j].cod = 0;
		b.info [j].pos = 0;
	}
	b.sig = r0->sig;
	ubicarind (id,i);
	grabarind (id,b);
	r0->sig = i;
}

liberard (int idd,char *r0d,int i) {
	char b[30];

	strcpy (b,r0d);
	ubicard (idd,i);
	grabard (idd,b);
	itoa (i,r0d,10);
}
consul () {
	int cod,cab,id,idd,k;
	struct IND b;
	char a[30];

	cab = _open ("cabezas",O_RDWR);
	id = _open ("indice",O_RDWR);
	idd = _open ("datos",O_RDWR);
	while (!eof(cab) ) {
		leercab(cab,k);
		printf ("%d ",k);
	}
	PR(" ");
	getch();
	while (!eof(id) ) {
		leerind(id,b);
		printf ("%d  ",b.cont);
		for (k=0; k < FC; k++) {
			printf ("%d-%d  ",b.info[k].cod,b.info[k].pos);
		}
		printf ("%d:",b.sig);
		PR(" ");
	}
	PR(" ");getch();
	while (!eof(idd) ) {
		leerd(idd,a);
		printf ("%s\n",a);
	}
	PR(" ");
	getch();
	cerrar (cab);
	cerrar (id);
	cerrar (idd);
}
