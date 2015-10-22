void marco (void){      //MARCO
int q,q2,q3,q4;
clrscr();
gotoxy(0,0);
printf("É");
for (q=1;q<=78;q++){
gotoxy(q,0);
printf("Í");
}
gotoxy(79,0);
printf("»");

for (q2=2;q2<=23;q2++){
gotoxy(80,q2);
printf("º");
}
gotoxy(80,24);
printf("¼");

for(q3=79;q3>=1;q3--){
gotoxy(q3,24);
printf("Í");}

gotoxy(1,24);
printf("È");

for (q4=23;q4>=2;q4--){
gotoxy(1,q4);
printf("º");}
return;
}
//******************************


// DEFINICION DE LOS NODOS DE LA LISTA

typedef struct nodo_LLDE {

		  nodo_LLDE *Llink;
		  float info;
		  nodo_LLDE *Rlink;
		  
		  };

void Localizar(nodo_LLDE **p,nodo_LLDE **Avail)
{
  if(*Avail==0){
    *p=new nodo_LLDE;
    }
    else{
	 *p=*Avail;
	 *Avail=(*Avail)->Rlink;
	 }
   return;
 }

//FUNCION PARA GUARDAR ESPACIO DISPONIBLE
void Liberar(nodo_LLDE *p,nodo_LLDE **Avail)
{
  p->Rlink=*Avail;
  *Avail=p;
  return;
 }

// FUNCION QUE BUSCA UN NODO PARA INSERTAR OTRO DESPUES DE ESTE
void Buscar(nodo_LLDE *Ptr,nodo_LLDE **p,float inf)
{
  *p=Ptr;

  while(*p!=NULL && (*p)->info!=inf){
       *p=(*p)->Rlink;
       }
  return;
 }

//FUNCION QUE INSERTA UN NODO DESPUES DE PTR
void Crear(nodo_LLDE **Ptr,nodo_LLDE **Avail,float inf)
{
  nodo_LLDE *p;

  Localizar(&p,&(*Avail));
  p->info=inf;

  if(*Ptr==NULL){
     p->Llink=NULL; //****
     *Ptr=p;
     (*Ptr)->Rlink=NULL;
     }
     else{
	  p->Rlink=*Ptr;
	  (*Ptr)->Llink=p;
		  *Ptr=p;
	  }
  return;
 }

//FUNCION QUE INSERTA UN NODO DESPUES DE OTRO NODO CUYA INF ES CONOCIDA
void Insertar(nodo_LLDE *Ptr,nodo_LLDE **Avail,float inf)
{
  nodo_LLDE *p,*q,*x;
  char op;

  if(Ptr==NULL){
     marco();
     gotoxy(22,12);
     printf("LISTA VACIA.....!!!");
     getch();

    }
    else{
	 Buscar(Ptr,&p,inf);
	 if(p!=NULL){
	    marco();
	    gotoxy(22,12);
	    printf("DIGITE INFORMACION A INCLUIR : ");
	    scanf("%f",&inf);
	    Localizar(&q,&(*Avail));
	    q->info  = inf;
		  x  = p->Rlink;
	    q->Rlink = x;
	    p->Rlink = q;
	    q->Llink = p;
	    x->Llink = q;
	    }
	    else{
		  marco();
		  gotoxy(23,12);
		  printf("NODO NO ENCONTRADO...!!!");
		  getch();

		 }
	}
  return;
 }

//FUNCION CANCELACION
void Cancelar(nodo_LLDE **Ptr,nodo_LLDE **Avail,float inf)
{
  nodo_LLDE *p,*q,*x;
  char op;

  if(*Ptr==NULL){
     marco();
     gotoxy(23,12);
     printf("LISTA VACIA....!!!....UNDERFLOW");
     }
    else{
	 Buscar((*Ptr),&p,inf);
	 if(p==NULL){
	     marco();
	     gotoxy(22,12);
	     printf("NODO NO ENCONTRADO..!!");
	     }
	    else{
		 if((*Ptr)->Rlink==NULL){
		    inf=p->info;
		    *Ptr=NULL;
		   }  //nueva condicion
		   else{
		       if((*Ptr)->info==inf){
			  *Ptr=(*Ptr)->Rlink;
			  (*Ptr)->Llink=NULL;
			  }
			  else{
				q= p->Llink;
				x= p->Rlink;
			q->Rlink = x;
			x->Llink = q;
			}
			}
		    Liberar(p,&(*Avail));
		 }
	 }
  return;
 }


//FUNCION DE CONSULTA DE NODOS(LLDE)

void Consulta(nodo_LLDE *Ptr)
{
  nodo_LLDE *p;
  char op;

  p=Ptr;
  if(p==NULL){
     marco();
     gotoxy(22,12);
     printf("LISTA VACIA.....!!");
     }
     else{
	  marco();
	  gotoxy(22,2);
	  printf("LA LISTA ES:\n\n");
	  gotoxy(2,4);printf("NULL ");
	  while(p!=NULL){

		printf("\%2.1f <-> ",p->info);
		p=p->Rlink;
	       }
	  printf("NULL");
	 }
  return;
 }

//*****************************************
void menu (){
int i;
clrscr();
  //recuadro
  for(i=13;i<64;i++){
  gotoxy(i,1);
  putchar(205);

  }
  gotoxy(13,1);
  putchar(201);
  gotoxy(64,1);
  putchar(187);
  gotoxy(13,2);
  putchar(186);
  gotoxy(64,2);
  putchar(186);
  gotoxy(13,3);
  putchar(204);
  gotoxy(64,3);
  putchar(185);

  for(i=14;i<64;i++){
     gotoxy(i,3);
     putchar(205);

  }
  for(i=4;i<19;i++){
     gotoxy(13,i);
     putchar(186);

  }
  for(i=4;i<19;i++){
     gotoxy(64,i);
     putchar(186);

  }
  for(i=14;i<64;i++){
     gotoxy(i,18);
     putchar(205);

  }
  gotoxy(13,18);
  putchar(200);
  gotoxy(64,18);
  putchar(188);

  gotoxy(24,2);
  printf(" MENU PRINCIPAL MANEJO DE LLDE ");
  gotoxy(19,6);
  printf("1.  INICIALIZAR LISTA");
  gotoxy(19,8);
  printf("2.  INSERTAR NODO EN LA LISTA");
  gotoxy(19,10);
  printf("3.  CANCELAR NODO EN LA LISTA");
  gotoxy(19,12);
  printf("4.  CONSULTAR NODOS DE LA LISTA");
  gotoxy(19,14);
  printf("5.  SALIR");
  gotoxy(26,17);
  printf(" DIGITE OPCION DESEADA:[ ] ");
  gotoxy(50,17);
return;
}
//*********************************************

void submenu(){
 clrscr();
  int i;	//recuadro

  for(i=9;i<60;i++){
  gotoxy(i,4);
  putchar(205);

  }
  gotoxy(9,4);
  putchar(201);
  gotoxy(60,4);
  putchar(187);
  gotoxy(9,5);
  putchar(186);
  gotoxy(60,5);
  putchar(186);
  gotoxy(9,6);
  putchar(204);
  gotoxy(60,6);
  putchar(185);

  for(i=10;i<60;i++){
     gotoxy(i,6);
     putchar(205);

  }
  for(i=7;i<19;i++){
     gotoxy(9,i);
     putchar(186);

  }
  for(i=7;i<19;i++){
     gotoxy(60,i);
     putchar(186);

  }
  for(i=10;i<60;i++){
     gotoxy(i,18);
     putchar(205);

  }
  gotoxy(9,18);
  putchar(200);
  gotoxy(60,18);
  putchar(188);
   //recuadro terminado


		      gotoxy(20,5);
		      printf(" INSERCION DE NODOS ");
		      gotoxy(15,9);
		      printf("1.  CREAR NODO EN LA LISTA");
		      gotoxy(15,11);
		      printf("2.  INSERTAR NODO DESPUES DE INF CONOCIDA");
		      gotoxy(15,13);
		      printf("3.  RETORNAR AL MENU PRINCIPAL");
		      gotoxy(22,17);
		      printf(" DIGITE OPCION DESEADA:[ ] ");
		      gotoxy(46,17);
 return;
}