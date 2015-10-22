
typedef struct nodo{
	int inf;
	nodo *link;
};

void crear_nodo ( nodo **Ptr)
{
  nodo *x, *ptr;
  int inf;

  clrscr();
  gotoxy(10,2);
  printf("CREACION DE NODO EN LA LISTA LINEAL ENLAZADA");
  gotoxy(15,4);
  printf("infomacion    : ");
  scanf ("%d", &inf);

  x=new nodo;
  x->inf=inf;
  x->link=*Ptr;
  *Ptr=x;
  return;
}

void mostrar_nodos(nodo *Ptr)
{
  int i;
  nodo *P;

  gotoxy(15,2);
  printf("NODOS DE LA LISTA LINEAL ENLAZADA");
  gotoxy(2,4);
  printf("informacion   : ");

  i=6;
  P=Ptr;
  while (P!=0){
    gotoxy(2,i);
    printf("%d",P->inf);
    P=P->link;
    i++;
  }
  return;
}

void localiza(nodo **Avail,nodo **x)
{
  if(*Avail==0){
    *x= new nodo;
  }
  else{
    *x=*Avail;
    *Avail=(*Avail)->link;
  }
  return;
}

void liberar (nodo *P, nodo **Avail)
{
  if(P!=0){
    P->link=*Avail;
    *Avail=P;
  }
  return;
}

void captura_nodo(int *Inf,nodo **x,nodo **Avail)
{
  nodo *x1,*Avail1;
  int inf;


  //Captura de la informacion del nodo a insertar

  clrscr();
  gotoxy(10,2);
  printf("INFORMACION DEL NODO A INCLUIR: ");
  gotoxy(15,4);
  printf(" informacion    : ");
  scanf("%d",&inf);

  Avail1=*Avail;
  localiza(&Avail1,&x1);
  x1->inf=inf;
  *x=x1;
  *Avail=Avail1;
  clrscr();
  gotoxy(10,2);
  printf("INFORMACION DEL NODO A BUSCAR: ");
  gotoxy (15,4);
  printf(" informocion :  ");
  scanf("%d",&inf);
  *Inf=inf;
  return;
}

void buscar_nodo(nodo *Ptr,nodo **Q,nodo **P,int inf,unsigned int *sw)
{
  *sw=0;
  if(Ptr==0){
    *sw=1;
  }
  else{
    if(inf==Ptr->inf){
      *sw=2;
    }
    else{
      *Q=Ptr;
      *P=Ptr->link;
      while(*P!=0 && (*P)->inf != inf){
	*Q=*P;
	*P=(*P)->link;
      }
      if(*P==0){
	*sw=3;
      }
    }
   }
  return;
}


void inserta(nodo **Ptr,int inf, nodo *x)
{
  char op;
  unsigned int sw;
  nodo *P,*Q,*ptr;

  //Asignar Ptr a ptr

  ptr=*Ptr;

  buscar_nodo(ptr,&Q,&P,inf,&sw);
  if(sw==1){
    clrscr();
    printf("\n\nLista Vacia.  No Incluir. <Enter> Continua");
    getch();
    }
    else{
    if(sw==2){
      x->link=*Ptr;
      *Ptr=x;
    }
    else{
      if(sw==3){
	clrscr();
	printf("\n\nNodo no encontrado.  No incluir.  <Enter> Continua");
	getch();
	}
      else{
	Q->link=x;
	x->link=P;
      }
    }
  }
  return;
  }


void Cancelar(nodo **Ptr,nodo **Avail,int inf)
{
  char op;
  unsigned int sw;
  nodo *P,*Q,*ptr,*Avail1;

  ptr=*Ptr;
  Avail1=*Avail;

  buscar_nodo(ptr,&Q,&P,inf,&sw);
  if(sw==1){
    clrscr();
    printf("\n\nLista Vacia.  No Cancelar.  <Enter> Continua");
    getch();
    }
  else{
    if(sw==2){
      //Eliminamos nodo Ptr
      P=*Ptr;
      *Ptr=(*Ptr)->link;
      liberar(P,&Avail1);
      *Avail=Avail1;
    }
    else{
      if(sw==3){
	clrscr();
	printf("\n\nNodo no Encontrado. No Cancelar.  <Enter> Continua");
	getch();
	}
      else{

	//Eliminacion de nodo encontrado

	Q->link=P->link;
	liberar(P,&Avail1);
	*Avail=Avail1;
      }
    }
  }
  return;
}

