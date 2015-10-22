//ARCHIVO rlle.H QUE CONTIENE LAS FUNCIONES PARA EL MANEJO DE
		  //LISTA LINEAL DOBLEMENTE ENLAZADA
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
/////**************** MARCO DE LOS MENUS ***************************/////
 void marco2(void){
    int i;
    clrscr();
    gotoxy(10,3);
    printf("É");
    ///segundo cuadro

   //linea horizontal arriba
   for(i=5;i<=63;i++){
      printf("Í");
    }
    gotoxy(i,63);
    printf("»");
    gotoxy(10,4);
    printf("º");
    gotoxy(70,4);
    printf("º");
    gotoxy(10,5);
    printf("È");
    for(i=11;i<=69;i++){
      gotoxy(i,5);
      printf("Í");
    }
    gotoxy(i,5);
    printf("¼");
///////////////////////////////*********************************************//////////////////
   //linea horizontal arriba

    gotoxy(11,7);
    printf("É");
   for(i=15;i<=71;i++){
      printf("Í");
    }
   gotoxy(19,i);
   printf("»");
    //linea vertical izq
    for(i=8;i<=18;i++){
       gotoxy(11,i);
      printf("º\n");
    }                                                                     


   gotoxy(11,i);
   printf("È");
   //linea horizontal abajo
   for(i=12;i<=69;i++){
      gotoxy(i,19);
      printf("Í");
    }
     //linea vertical izq
    for(i=8;i<=18;i++){
      gotoxy(69,i);
      printf("º\n");
    }
     gotoxy(69,i);
     printf("¼");
}



//DEFINICION DE LA ESTRUCTURA O NODOS DE LA LISTA

typedef struct BT {
	BT *llink;
	int Info;
	BT *rlink;
       };


//FUNCION QUE LOCALIZA ESPACIO DISPONIBLE EN MEMORIA PARA INSERTAR NODOS

void Localizar(BT **P,BT **Avail)
{
 if(*Avail==NULL){
   *P=new BT;
 }
 else{
   *P=*Avail;
   *Avail=(*Avail)->rlink;
 }
 return;
}


//FUNCION PARA LIBERAR ESPACIO EN UNA LLE
void Liberar(BT *P,BT **Avail)
{
 if(P != 0){
   P->rlink=*Avail;
   *Avail=P;
 }
 return;
}
//FUNCION QUE BUSCA UN NODO CON INFO CONOCIDA
void Buscar(BT *T,BT **Q,int Inf,BT **r)
{

  *Q=T;
  *r=*Q;
     while(*r!=NULL && (*r)->Info!=Inf){
	*Q=*r;
	if((*Q)->Info>Inf){
	  *r=(*Q)->llink;
	 }
	  else{
	    *r=(*Q)->rlink;
	 }
    }
 return;
}



//FUNCION PARA INSERTAR UN NODO EN UN ARBOL B(T)
void Insertar(BT **T,int Inf,BT **Avail,BT**Q,BT**r)
{
 BT *P;
 Localizar(&P,&(*Avail));
  P->Info=Inf;
   P->llink=0;
   P->rlink=0;
   if (*T==NULL){
     *T=P;
    }
    else
    {
      Buscar(*T,&(*Q),Inf,&(*r));
      if((*r)!=NULL){
       gotoxy(15,10);
       printf("\NODO DUPLICADO !!!");
       Liberar(P,&(*Avail));
       }
       else{
	 if((*Q)->Info>Inf){
	   (*Q)->llink=P;
	  }
	  else{
	  (*Q)->rlink=P;
	  }

	}
       }

  return;
}

////////*************************RUTINAS DE ELIMINACION**************//////

//Eliminar un nodo hoja
void eliminar_hoja(BT *Q, BT *r)
{
  printf("voy aqui Una hoja Q %d s %d ",Q->Info,r->Info);
  getch();
  if(r->rlink==NULL && r->llink==NULL){
    if(Q->llink==r){
    Q->llink=NULL;
		   }
    else{
	 Q->rlink=NULL;
	   printf("\Cambie enlace de Q Una hoja Q %d s %d ",Q->Info,r->Info);
	   getch();
	}
  }
  return;
  }
//Eliminar un nodo rama que tenga una hoja
void eliminar_rama_1H(BT *Q, BT *r)
{

 if (r->rlink!=NULL && r->llink==NULL){
     printf("Una Rama Q %d s %d",Q->Info,r->Info);
     getch();
      if (r==Q->llink){
      Q->llink=r->rlink;
      }
      else{
	  Q->rlink=r->rlink;
      }
    }
  else{
      if(r->rlink==NULL && r->llink!=NULL){
	  if (r==Q->llink){
	     Q->llink=r->llink;
	     }
	     else{
		 Q->rlink=r->llink;
		 }
   }
  }
  return;
  }
//Eliminar un nodo rama que tenga dos hijos
void eliminar_rama_2H(BT *Q,BT **r)
  {
  BT *s;
  if((*r)->rlink!=NULL && (*r)->llink!=NULL){
    s=(*r)->llink;
     while(s->rlink!=NULL){
	  Q=s;
	  s=s->rlink;
	  }
    (*r)->Info=s->Info;
    printf("VOY AQUI\n q %d s %d",Q->Info,(*r)->Info);
    getch();

    eliminar_hoja(Q,s);
    eliminar_rama_1H(Q,s);
    //Liberar(s,&(*Avail));
    *r=s;
 }
 return;
 }
void Cancelar(BT **T,BT **Avail,float Inf){
     BT *Q,*r;
     if ((*T)==NULL){
	printf("NO CANCELAR");
	}
	else{
	    Buscar(*T,&Q,Inf,&r);
	    if(r==NULL){
	       gotoxy(22,12);
	       printf("NODO NO ENCONTRADO !!!");
	       getch();
	       }
	      else{
		  if((*T)->rlink==NULL && (*T)->llink==NULL){
		     *T=NULL;
		     Liberar(r,&(*Avail));
		     }
		     else{  //Si es hoja
			 eliminar_hoja(Q,r);
			 eliminar_rama_1H(Q,r);
			 eliminar_rama_2H(Q,&r);
			 Liberar(r,&(*Avail));
			 }
		  }
	     }
     return;
  }



//******************* RUTINA PARA VISITAR NODOS *********************//

void Visitar(BT *P){
     printf("\%d ",P->Info);

  return;
  }

 //*********** RUTINA PARA CONSULTAR EN PREORDEN ***********************//

void Preorden(BT *P)
{
//  BT *P;
  //  P=T;
  if(P==NULL){
    printf("");
   }
   else{


     Visitar(P);
     Preorden(P->llink);
     Preorden(P->rlink);

 }
 return;
}

 //*********** RUTINA PARA CONSULTAR EN INORDEN ***********************//

void Inorden(BT *P)
{

     if(P==NULL){
    printf("");
   }
   else{
     Inorden(P->llink);
     Visitar(P);
     Inorden(P->rlink);

 }

 return;
}
 //*********** RUTINA PARA CONSULTAR EN POSTORDEN ***********************//

void Postorden(BT *P)
{
     if(P==NULL){
    printf("");
   }
   else{
   Postorden(P->llink);
     Postorden(P->rlink);
     Visitar(P);

 }
  return;
}

///************************ MENU PRINCIPAL *******************///
void menu (void){
 clrscr();
  marco2();
  gotoxy(35,4);
  printf (" M E N U  ");
  gotoxy(18,8);
  printf ("1  INICIALIZAR ARBOL B(T)");
  gotoxy(18,10);
  printf ("2  INSERTAR INFORMACION EN EL ARBOL B(T)");
  gotoxy(18,12);
  printf ("3  ELIMINAR INFORMACION DADA EN UN ARBOL B(T)");
  gotoxy(18,14);
  printf ("4  CONSULTAR INFORMACION EN UN ARBOL B(T)");
  gotoxy(18,16);
  printf ("5  SALIR ");
  gotoxy (33,18);
  printf ("OPCION [ ]");
  gotoxy(41,18);
}

///********************* SUBMENU DE CONSULTA ****************//////
 void submenu (void){

   clrscr();
   marco2();
   gotoxy(32,4);
   printf("MENU DE CONSULTA");
   gotoxy(18,9);
   printf("1  CONSULTA EN PREORDEN ");
   gotoxy(18,11);
   printf("2  CONSULTA EN INORDEN");
   gotoxy(18,13);
   printf("3  CONSULTA EN POSTORDEN");
   gotoxy(18,15);
   printf("4  RETORNAR");
   gotoxy(30,17);
   printf("OPCION [ ]");
   gotoxy(38,17);


}

