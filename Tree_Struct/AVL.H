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

typedef struct arbol_avl{
	       arbol_avl *llink;
	       int fb;
	       int info;
	       arbol_avl *rlink;
	       }avl;


//FUNCION PARA VALIDAR

 void validar()
 {
   gotoxy(20.5,21);
   printf("PRESIONE CUALQUIER TECLA PARA CONTINUAR" );
   getch();
 }


 void control_sw()
 {

   marco();
   gotoxy(29.5,12);
   printf("ARBOL NO INICIALIZADO");
   validar();
 }
 void control_sw1()
 {  marco();
    gotoxy(34.5,12);
    printf("ARBOL VACIO");
    validar();


   }



//funcion para leer informacion

 void lea_info(int *inf)
 {
   int infs;
       scanf("%d",&infs);
    *inf=infs;
 }


//INSERCION DE UN NODO EN UN ARBOL AVL

void una_rot_a_la_derecha(avl *p, avl *q)
{
  p->llink=q->rlink;
  q->rlink=p;
  p->fb=0;
  q->fb=0;
}
void una_rot_a_la_izquierda(avl *p,avl *q)
{
  p->rlink=q->llink;
  q->llink=p;
  p->fb=0;
  q->fb=0;
}
void doble_rot_a_la_derecha(avl **p,avl **q)
{ avl *r;
  r=(*q)->rlink;
  (*q)->rlink=r->llink;
  r->llink=*q;
  (*p)->llink=r->rlink;
  r->rlink=*p;
 switch( r->fb){
      case 0:(*p)->fb=0;
	     (*q)->fb=0;
      break;
      case 1:(*p)->fb=-1;
	     (*q)->fb=0;
      break;
      case -1:(*p)->fb=0;
	      (*q)->fb=1;
      break;
      default:break;
 }
 r->fb=0;
 *q=r;
}
void doble_rot_a_la_izquierda(avl **p,avl **q)
{ avl *r;

  r=(*q)->llink;
  (*q)->llink=r->rlink;
  r->rlink=*q;
  (*p)->rlink=r->llink;
  r->llink=*p;
  switch(r->fb){
	case 0:(*p)->fb=0;
	       (*q)->fb=0;
       break;
       case 1: (*p)->fb=0;
	       (*q)->fb=-1;
       break;
       case -1: (*p)->fb=1;
	       (*q)->fb=0;
       break;
       default:break;

 }
  r->fb=0;
 *q=r;
}

void Insertar_Avl(avl **r,int inf)
{
  unsigned int sw=0,SW=0;
 avl *x,*pivote,*pp,*p,*q;

/***********************************/

 x=new avl;     //Localiza espacio en memoria para el nodo
 x->info=inf;  //Consigue nuevo registro y lo configura con el dato a insertar
 x->llink=0;
 x->rlink=0;
 x->fb=0;

/***************************************/

 if (*r==0){  //si es la primera vez que se llama el procedimiento, el registro
     *r=x;   //conseguido es la raiz
     sw=1;

 }
 if (sw==0){
 p=*r;  //Asigna valores iniciales a las  variables que se utilizan para buscar el
 q=0;  /*sitio donde se insertara nuevo registro y determinar pivote y su padre
	 inicialmente  PIVOTE sera la raiz y pp sera cero (0)*/
 pivote=*r;
 pp=0;

/*****************************************/

 while (p!=0){
    if (p->info==inf){
       marco();
       gotoxy(19,12);

       printf("          NODO DUPLICADO !!!");
       validar();

       //Controla que no vaya a quedar datos repetidos

       sw=1;

    }

/********************************************/


    if(p->fb!=0){
       pivote=p; //determinar valor de PIVOTE y de su padre.
       pp=q;
   q=p;
   }
    q=p;

/*******************************************/

   if(p->info>inf){
      p=p->llink; //Actualiza Q
   }             //    y
   else{
      p=p->rlink; //avanza con P
   }
 }  //FIN WHILE

/*********************************************/
 if (sw==0){

 if (q->info>inf){
     q->llink=x; //Inserta X como hijo izquierdo o como hijo derecho de q
 }
 else{
     q->rlink=x;
 }

/**********************************************/

 if(pivote->info>inf){
    pivote->fb++;   //Recalcula factor de balance
    q=pivote->llink;// de PIVOTE
 }
 else{
   pivote->fb--;
   q=pivote->rlink;
 }
 p=q;

/********************************/

 while(p!=x){  //Recalcula factores de balance de todos los registro en la
   if(p->info>inf){ //trayectoria desde PIVOTE  hasta el registro insertado X
      p->fb=1;

      p=p->llink;
   }
   else{
      p->fb=-1;
      p=p->rlink;
   }
 } // FIN WHILE

/****************************************/

 if(abs(pivote->fb)<2){ //Si el arbol siguio balanceado retorna al programa
    marco();           //llamante
    gotoxy(27.5,12);
    printf("EL ARBOL ESTA BALANCEADO");
    validar();
    SW=1;
     //programa llamante.
  }
if(SW==0){
/********************************************/

if(pivote->fb==2){ //Determina que tipo de rotacion hay que efectuar y llamar
  if(q->fb==1){  //el procedimiento correspondiente
  una_rot_a_la_derecha(pivote,q);

    marco();
    gotoxy(22.5,13);printf("   FB (P)= +2  || FB (Q)= +1");
    gotoxy(20.5,11);printf("ROTACION A LA DERECHA SOBRE EL PIVOTE (P)");
    validar();

  }
  else{
  doble_rot_a_la_derecha(&pivote,&q);

    marco();
    gotoxy(22.5,7);printf("    FB (P)= +2  ||  FB (Q)= -1");
    gotoxy(22.5,9);printf("        DOBLE ROTACION :");
    gotoxy(20.5,11);printf("ROTACION A LA IZQUIERDA SOBRE EL HIJO DE P (Q)");
    gotoxy(20.5,13);printf("ROTACION A LA DERECHA SOBRE EL PIVOTE (P)");
    validar();

  }
 } //FIN IF PIVOTE
 else{
 if(q->fb==-1){
   una_rot_a_la_izquierda(pivote,q);

   marco();
   gotoxy(22.5,13);printf("   FB (P)= -2  ||  FB (Q)= -1");
   gotoxy(20.5,11);printf("ROTACION A LA IZQUIERDA SOBRE EL PIVOTE (P)");
   validar();

 }
 else{
   doble_rot_a_la_izquierda(&pivote,&q);

   marco();
   gotoxy(22.5,7);printf("     FB (P)= -2  ||  FB (Q)= +1");
   gotoxy(22.5,9);printf("           DOBLE ROTACION : ");
   gotoxy(20.5,11);printf("ROTACION A LA DERECHA SOBRE EL HIJO DE P (Q)");
   gotoxy(20.5,13);printf("ROTACION A LA IZQUIERDA SOBRE EL PIVOTE (P)");
   validar();

 }
} //FIN ELSE

/***********************************************/

 if(pp==0){  //Si el registro desbalanceado
   *r=q;  //era la raiz actualiza la nueva raiz y regresa.
   sw=1;

  }
 if(sw==0){
/************************************************/


 if(pivote==pp->llink){ //Pega la nueva raiz del arbol rebalanceado
    pp->llink=q;// al registro Q.
  }
  else{
  pp->rlink=q;
  }
} // fin sw==0
} //FIN SW==0
}
}
}  // FIN RUTINA



 void liberar_avl(avl *p,avl **avail)
 {
    p->rlink=*avail;
    *avail=p;
 }
 //FUNCION PARA BUSCAR UN NODO PARA CANCELAR EN UN ARBOL
 void buscar_nodo_arbol_avl(avl *t,avl **p,avl **q,int inf)
 {
   *q=t;
   *p=*q;
   while(*p!=0 && inf!=(*p)->info){
     *q=*p;
      if (inf<(*p)->info){
	 *p=(*p)->llink;
      }
      else{
	   *p=(*p)->rlink;
      }
   }
 }

 //************FUNCION PARA ELIMINAR UN NODO HOJA DE UN ARBOL****************

 void eliminar_hoja_avl(avl *q,avl *p,avl **avail)
 {
    if(p==q->llink){
       q->llink=0;
       if(q->fb!=0){
	  q->fb=0;
       }else{
	 q->fb=-1;
       }
    }
    else{
	  q->rlink=0;
	  if(q->fb!=0){
	     q->fb=0;
	  }else{
	  q->fb=1;
	  }
    }
    liberar_avl(p,&(*avail));
 }


  //*********FUNCION PARA ELIMINAR UN NODO RAMA DE UN ARBOL************

 void eliminar_nodo_rama_avl(avl *q,avl *p,avl *avail)
 {    avl *k,*W,*F;
     k=q->rlink;
     W=q->llink;
     if(q->llink==0 && q->rlink==k && k->llink==0 && k->rlink==0){
	q->info=k->info;
	p=k;
	eliminar_hoja_avl(q,p,&avail);
     }

     else{
     if(q->llink!=0 && q->llink==W && W->llink==0 && W->rlink==0){
	   q->info=W->info;
	   p=W;
	   eliminar_hoja_avl(q,p,&avail);
     }
     else{


      if(p->llink==0 && p==q->llink){
	  q->llink=p->rlink;

      }
      else{
	 if(p->rlink==0 && p==q->llink){
	    q->llink=p->llink;
	 }
	 else{
	  if(p->rlink==0 && p==q->rlink){
	     q->rlink=p->llink;
	  }
	  else{
	    q->rlink=p->rlink;

	  }
	 }
      }
     }
    }
    liberar_avl(p,&avail);
 }
//FUNCION PARA REMOVER UN NODO DEL ARBOL
 void remover_nodo_del_arbol_avl(avl **t,int inf,avl *avail,unsigned int *SW)
 {
  avl *s,*p,*q;
   if(*t==0){
      marco();
      gotoxy(34.5,12);
      printf("ARBOL VACIO");
      validar();
      *SW=1;
   }
   else{

	   if((*t)->llink==0 && (*t)->rlink==0 && (*t)->info==inf && (*t)->fb==0){
	       marco();
	       gotoxy(19,12);
	       printf("EL NODO ELIMINADO ES EL UNICO DEL ARBOL");
	       validar();
	       *SW=1;
	       p=*t;
	       *t=0;

	       liberar_avl(p,&avail);
	 }
	 else{
	    buscar_nodo_arbol_avl(*t,&p,&q,inf);
	    if(p->info!=inf){
	       marco();
	       gotoxy(19,8);
	       printf("LA INFORMACION NO SE ENCUENTRA EN EL ARBOL");
	       validar();
	    }
	    else{
		 if(p->llink==0 && p->rlink==0){
		    eliminar_hoja_avl(q,p,&avail);
		 }
		 else{
		      if(p->llink==0 && p->rlink!=0){
			 eliminar_nodo_rama_avl(q,p,avail);
		      }
		      else{
			   if(p->llink!=0 && p->rlink==0){
			      eliminar_nodo_rama_avl(q,p,avail);
			   }
			   else{
				//busqueda de s
				q=p;
				s=p->llink;
				while(s->rlink!=0){
				      q=s;
				      s=s->rlink;
				}
				p->info=s->info;
				p=s;
				if(p->rlink==0 && p->llink==0){
				    eliminar_hoja_avl(q,p,&avail);
				}
				else{
				     eliminar_nodo_rama_avl(q,p,avail);
				}
			   }
		      }
		 }
	    }
       }
   }


 }


 //funcion para visitar
void visitar(avl *p)
{
   printf("%d ",p->info);
}
 //RECORRIDO DE UN ARBOL EN PRE IN Y POSTORDEN
void preorden(avl *V)
{
  if(V!=0){
    visitar(V);
    preorden(V->llink);
    preorden(V->rlink);
  }
}

void inorden(avl *Q)
{
  if(Q!=0){
    inorden(Q->llink);
    visitar(Q);
    inorden(Q->rlink);
  }
}

void postorden(avl *Z)
{
  if(Z!=0){
    postorden(Z->llink);
    postorden(Z->rlink);
    visitar(Z);
  }
}

void menu (void){
 clrscr();
  marco2();
  gotoxy(35,4);
  printf (" M E N U  ");
  gotoxy(18,8);
  printf ("1  INICIALIZAR ARBOL AVL");
  gotoxy(18,10);
  printf ("2  INSERTAR INFORMACION EN EL ARBOL AVL");
  gotoxy(18,12);
  printf ("3  CONSULTAR INFORMACION EN UN ARBOL AVL");
  gotoxy(18,14);
  printf ("4  ELIMINAR INFORMACION DADA EN UN ARBOL AVL");
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
   printf("2  CONSULTA EN POSTORDEN");
   gotoxy(18,13);
   printf("3  CONSULTA EN INORDEN");
   gotoxy(18,15);
   printf("4  RETORNAR");
   gotoxy(30,17);
   printf("OPCION [ ]");
   gotoxy(38,17);


}

