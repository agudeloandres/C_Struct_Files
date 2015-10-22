#define MANUAL 1
#define M 13
#define MAX_LLAVES 104
#define FILAS (MAX_LLAVES / M)
#define MAX_DAT 5
#define LONIND sizeof (struct IND)
#define LOND   30
#define PR(x) printf ("%s\n",x)

#define cerrar(x) { if (_close (x) == -1) error("_close()"); }


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
};

struct DATOS {
	int cod;
	char n[30];
};


error (char *q) {
	char *p;

	p = _strerror (q);
	printf ("%s",p);
	getch();
	exit (1);
}

inicia() {
	int id,i;
	struct IND buffer;
	char a[30];

	id = _creat ("indice",FA_ARCH);
	cerrar(id);
	id = _open ("indice",O_WRONLY);
	buffer.cod = -1;
	buffer.pos = 0;
	for (i=0; i < MAX_LLAVES; i++)
		grabarind (id,buffer);
	cerrar (id);

	id = _creat ("datos",FA_ARCH);
	cerrar(id);
	id = _open ("datos",O_WRONLY);
	for (i = 0; i < MAX_DAT; i++) {
		itoa (i+1,a,10);
		grabard(id,a);
	}
	itoa (0,a,10);
	grabard (id,a);
	cerrar(id);
}

#if MANUAL == 1
leadatos (struct DATOS *p) {
	char a[40];

	PR ("De codigo");
	gets (a);
	p->cod = atoi (a);
	PR ("De nombre");
	gets (p->n);
}
#elif
leadatos (struct DATOS *p) {
	char a[40];

	p->cod = random (32000);

	itoa (p->cod,p->n,10);
	printf ("%d %s\n",p->cod,p->n);
}
#endif
captu () {
	int id,idd,k;
	int i;
	struct DATOS datos;
	struct IND buffer;

	id = _open ("indice",O_RDWR);
	idd = _open ("datos",O_RDWR);
	leadatos (&datos);
#if MANUAL == 1
	while (datos.cod != 999) {
		if (insertar (id,idd,&datos) == -1) {
			PR("Ya existe. Oprima una tecla...");
		}
		leadatos (&datos);
	}
#elif
	i=0;
	while (i < 20) {
		printf ("%d ",i);
		if (insertar (id,idd,&datos) == -1) {
			PR("Ya existe. Oprima una tecla...");
		}
		leadatos (&datos);
		i++;
	}
#endif
	cerrar (id);
	cerrar (idd);
}


insertar (int id,int idd,struct DATOS *datos) {
	struct IND buffer;
	char r0d [30];
	int R,C;
	int pos;

	R = datos->cod % M;
	C = datos->cod / M;
	pos = R * FILAS + C;
	ubicarind (id,pos);
	leerind (id,buffer);
	if (buffer.cod != -1)
		return (-1); /* Ya existe */
	else {
		ubicarind (id,pos);
		buffer.cod = datos->cod;
		buffer.pos = dispd (idd,r0d);
		grabarind (id,buffer);
		ubicard (idd,buffer.pos);
		grabard (idd,datos->n);
		ubicard (idd,0);
		grabard (idd,r0d);
		return (1);
	}
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

consul () {
	int cod,id,idd,k;
	struct IND b;
	char a[30];

	id = _open ("indice",O_RDWR);
	idd = _open ("datos",O_RDWR);

	PR("De codigo a consultar");
	gets (a);
	cod = atoi (a);
	while (cod != 999) {
		if (consultar (id,idd,cod) == -1) {
			PR ("No existe");
		}
		PR("De codigo a consultar");
		gets (a);
		cod = atoi (a);
	}
	cerrar (id);
	cerrar (idd);
}

consultar (int id,int idd,int cod) {
	struct IND buffer;
	char a[30];
	int R,C,pos;

	R = cod % M;
	C = cod / M;
	pos = R * FILAS + C;
	ubicarind (id,pos);
	leerind (id,buffer);
	if (buffer.cod == -1)
		return (-1);
	else {
		ubicard (idd,buffer.pos);
		leerd (idd,a);
		printf ("%s\n",a);
		return (1);
	}
}
listar () {
	int cod,id,idd,k,i,j;
	struct IND b;
	char a[30];

	id = _open ("indice",O_RDWR);
	idd = _open ("datos",O_RDWR);
	for (i = 0; i < FILAS; i++) {
		for (j = 0; j < M; j++) {
			ubicarind (id,(j * FILAS + i) );
			leerind (id,b);
			if (b.cod != -1) {
				ubicard (idd,b.pos);
				leerd (idd,a);
				printf ("%d %s\n",b.cod,a);
			}
			else ;  /* No existe llave en esa posicion */
		}
	}
	getch();
	cerrar (id);
	cerrar (idd);
}
/*
listar () {
	int cod,id,idd,k,i,j;
	struct IND b;
	char a[30];

	id = _open ("indice",O_RDWR);
	idd = _open ("datos",O_RDWR);
	while (!eof (id)) {
		leerind (id,b);
		printf ("%d %s\n",b.cod,b.n);
		getch();
	}
	cerrar (id);
	cerrar (idd);
}*/
retira () {
	int cod,id,idd,k;
	struct IND b;
	struct DATOS datos;
	char a[30];

	id = _open ("indice",O_RDWR);
	idd = _open ("datos",O_RDWR);

	PR("De codigo a retirar");
	gets (a);
	cod = atoi (a);
	while (cod != 999) {
		if (retirar (id,idd,cod,&datos) == -1)
			PR ("No existe");
		else
			printf ("Datos retirados = %d %s\n",datos.cod,
					datos.n);
		PR("De codigo a retirar ");
		gets (a);
		cod = atoi (a);
	}
	cerrar (id);
	cerrar (idd);
}

retirar (int id,int idd,int cod,struct DATOS *datos) {
	int R,C,pos;
	struct IND buffer;
	char r0d [30],a[30];


	R = cod % M;
	C = cod / M;
	pos = R * FILAS + C;
	ubicarind (id,pos);
	leerind (id,buffer);
	if (buffer.cod == -1)
		return (-1);
	else {
		ubicard (idd,buffer.pos);
		leerd (idd,a);
		datos->cod = buffer.cod;
		strcpy (datos->n,a);
                ubicard (idd,0);
		leerd (idd,r0d);
		liberard (idd,r0d,buffer.pos);
                ubicard (idd,0);
		grabard (idd,r0d);
		buffer.cod = -1;
		buffer.pos = 0;
                ubicarind (id,pos);
		grabarind (id,buffer);
		return (1);
	}
}


liberard (int idd,char *r0d,int i) {
	char b[30];

	strcpy (b,r0d);
	ubicard (idd,i);
	grabard (idd,b);
	itoa (i,r0d,10);

}
/*
consul () {
	int cod,id,idd,k;
	struct IND b;
	char a[30];

	id = _open ("indice",O_RDWR);
	idd = _open ("datos",O_RDWR);
	while (!eof(id) ) {
		leerind(id,b);
		printf ("%d-%d   ",b.cod,b.pos);
	}
	cerrar (id);
	cerrar (idd);
}

*/
