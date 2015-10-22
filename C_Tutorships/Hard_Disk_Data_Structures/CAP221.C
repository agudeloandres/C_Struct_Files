
#define M 13
#define MAXIMO 5
#define MAX_DAT 5
#define LONIND sizeof (struct IND)
#define LOND   30
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

struct IND {
	int cod;
	int pos;
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
	buffer.cod = buffer.pos = 0;
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
	p->cod = q->cod;
	p->pos = q->pos;
	p->sig = q->sig;
}

insertar (int cab,int id,int idd,int k,struct DATOS *datos) {
	int i,j,esta,d,dd;
	struct IND buffer,temp,r0;
	char r0d [30];

	ubicarcab (cab,k);
	leercab (cab,i);
	esta = 0;
	j = 0;
	while (i != 0 && !esta) {
		ubicarind (id,i);
		leerind (id,buffer);
		if (buffer.cod == datos->cod)
			esta = 1;
		else {
			j = i;
                        copiar (&temp,&buffer);
			i = buffer.sig;
		}
	}
	if (esta == 1)
		return (-1);
	ubicarind (id,0);
	leerind (id,r0);
	ubicard (idd,0);
	leerd (idd,r0d);
	d = disp (id,&r0);
	dd = dispd (idd,r0d);
	buffer.cod = datos->cod;
	buffer.pos = dd;
	buffer.sig = 0;
	ubicarind (id,d);
	grabarind (id,buffer);
	if (j != 0) {
		temp.sig = d;
		ubicarind (id,j);
		grabarind (id,temp);
	}
	else {
		ubicarcab (cab,k);
		grabarcab (cab,d);
	}
	ubicard (idd,dd);
	grabard (idd,datos->n);
	ubicarind (id,0);
	grabarind (id,r0);
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
	buffer.cod = buffer.pos = 0;
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
	gets(p->n);
}

/*
leadatos (struct DATOS *p) {
	char a[40];

	p->cod = random (32000);

	itoa (p->cod,p->n,10);
	printf ("%d %s\n",p->cod,p->n);
}
	*/
/*consul () {
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

consultar (int cab,int id,int idd,int k,int cod) {
	int i,esta;
	struct IND buffer;
	char a[30];

	ubicarcab (cab,k);
	leercab (cab,i);
	esta = 0;
	while (i != 0 && !esta) {
		ubicarind (id,i);
		leerind (id,buffer);
		if (buffer.cod == cod)
			esta = 1;
		else i = buffer.sig;
	}
	if (esta == 1) {
		ubicard (idd,buffer.pos);
		leerd (idd,a);
		PR(a);
		return (1);
	}
	else return (-1);
}
	*/

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
			ubicard (idd,b.pos);
			leerd (idd,a);
			printf ("%d %s\n",b.cod,a);
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
	int i,j,esta,d,dd;
	struct IND buffer,temp,r0;
	char r0d [30];

	ubicarcab (cab,k);
	leercab (cab,i);
	esta = 0;
	j = 0;
	while (i != 0 && !esta) {
		ubicarind (id,i);
		leerind (id,buffer);
		if (buffer.cod == cod)
			esta = 1;
		else {
			j = i;
                        copiar (&temp,&buffer);
			i = buffer.sig;
		}
	}
	if (esta == 0)
		return (-1);
	datos->cod = cod;
	ubicard (idd,buffer.pos);
	leerd (idd,datos->n);
	ubicarind (id,0);
	leerind (id,r0);
	ubicard (idd,0);
	leerd (idd,r0d);
	if (j == 0) {
		ubicarcab (cab,k);
		grabarcab (cab,buffer.sig);
	}
	else {
		temp.sig = buffer.sig;
		ubicarind (id,j);
		grabarind (id,temp);
	}
	liberar (id,&r0,i);
	liberard (idd,r0d,buffer.pos);

	ubicarind (id,0);
	grabarind (id,r0);
	ubicard (idd,0);
	grabard (idd,r0d);
	return (1);
}

liberar (int id,struct IND *r0,int i) {
	struct IND b;

	b.cod = b.pos = 0;
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
		printf ("%d-%d-%d  ",b.cod,b.pos,b.sig);
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