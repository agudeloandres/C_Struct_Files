// finicion del registro para el arbol

 typedef struct nomina{
		      nomina *llink;
		      char info;
		      nomina *rlink;
		      }nom;

//FUNCION PARA VALIDAR

 void validar()
 {
   gotoxy(20.5,14);
   printf("PRESIONE CUALQUIER TECLA PARA CONTINUAR" );
   getch();
 }


 void control_sw()
 {

   clrscr();
   gotoxy(29.5,12);
   printf("ARBOL NO INICIALIZADO");
   validar();
 }
 void control_sw1()
 {  clrscr();
    gotoxy(34.5,12);
    printf("ARBOL VACIO");
    validar();


   }


//FUNCION PARA EL MENU



  void menu()
 {
     clrscr();
     gotoxy(28,7);
     printf("MENU DE ARBOLES BINARIOS");
     gotoxy(31.4,10);
     printf("1- INICIALIZACION ");
     gotoxy(31.4,12);
     printf("2- CREAR NODOS ");
     gotoxy(31.4,14);
     printf("3- MOSTRAR");
     gotoxy(31.4,16);
     printf("4- CANCELAR");
     gotoxy(31.4,18);
     printf("5- SALIR");
     gotoxy(31.4,22);
     printf("DIGITE OPCION  < >");
     gotoxy(47,22);

 }

//FUNCION PARA EL SUBMENU

 void submenu()
 {
	      clrscr();
	      gotoxy(29,9);
	      printf(" SUB MENU PARA MANEJO");
	      gotoxy(31.5,10);
	      printf(" DE ORDENAMIENTO");
	      gotoxy(33,12);
	      printf("1- PREORDEN");
	      gotoxy(33,14);
	      printf("2- POSTORDEN");
	      gotoxy(33,16);
	      printf("3- INORDEN");
	      gotoxy(33,18);
	      printf("4- RETORNAR");
	      gotoxy(33,22);
	      printf("DIGITE OPCION ( )");
	      gotoxy(48,22);
 }
//funcion para leer informacion

 void lea_info(char *inf)
 {
   char infs;
    do{
       scanf("%c",&infs);
    }while(infs<'A'|| infs>'Z');
    *inf=infs;
 }

//funcion para visitar
void visitar(nom *p)
 {
   printf("%c ",p->info);
  }

 //funcion para crear arbol
 void crear_arbol_busqueda(nom **t,char inf)
 {
   nom *p,*q,*r;
  // char info;
    p=new nom;
    p->llink=0;
    p->rlink=0;
    p->info=inf;
    if(*t==0){
	*t=p;
	clrscr();
	gotoxy(31.5,12);
	printf("NODO INICIALIZADO");
	validar();
    }
    else{
	q=*t;
	while (q!=0 && inf!=q->info){
		r=q;
		if (q->info>inf){
		   q=q->llink;
		}
		 else{
		   q=q->rlink;
		 }
	 }
	 if(r->info>inf){
	    r->llink=p;
	 }
	 else {
	  r->rlink=p;
	 }
    }
 }

 // FUNCION PARA LOCALIZAR EL ESPACIO DISPONIBLE

 void localizar(nom **P,nom **avail)
   {
     if(*avail==0){
       *P=new nom;
     }
     else{
      *P=*avail;
      *avail=(*avail)->rlink;
     }
   }

 //FUNCION PARA LIBERAR Y MANDAR EL NODO AL ESPACIO DISPONIBLE

 void liberar(nom *p,nom **avail)
 {
    p->rlink=*avail;
    *avail=p;
 }
 //FUNCIN PARA BUSCAR UN NODO PARA CANCELAR EN UN ARBOL
 void buscar_nodo_arbol(nom *t,nom **p,nom **q,char inf)
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

 void eliminar_hoja(nom *q,nom *p,nom **avail)
 {
    if(p==q->llink){
       q->llink=0;
    }
    else{
	  q->rlink=0;
    }
    liberar(p,&(*avail));
 }


  //*********FUNCION PARA ELIMINAR UN NODO RAMA DE UN ARBOL************

 void eliminar_nodo_rama(nom *q,nom *p,nom *avail)
 {
   nom *k,*W,*F;
     k=q->rlink;
     W=q->llink;
     if(q->llink==0 && q->rlink==k && k->llink==0 && k->rlink==0){
	q->info=k->info;
	p=k;
	eliminar_hoja(q,p,&avail);
     }
     else{
	  if(q->llink==0 && q->rlink==k && k->llink==0 && k->rlink!=0){
	     q->info=k->info;
	     q->rlink=k->rlink;
	     p=k;
	  }
	  else{
	       if(q->llink!=0 && q->llink==W && W->llink!=0 && W->rlink==0){
		 q->info=W->info;
		 q->llink=W->llink;
		 p=W;
	       }
	       else{
		   if(q->llink!=0 && q->llink==W && W->llink==0 && W->rlink!=0){
		      F=W->rlink;
		      q->info=F->info;
		      p=F;
		      eliminar_hoja(W,p,&avail);
		   }
		   else{
			if(q->llink!=0 && q->llink==W && W->llink==0 && W->rlink==0){
			   q->info=W->info;
			   p=W;
			   eliminar_hoja(q,p,&avail);
			}
			else{
			      if(q->llink==0 && q->rlink==k && k->llink!=0 && k->rlink==0){
				F=k->llink;
				q->info=F->info;
				p=F;
				eliminar_hoja(k,F,&avail);
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
		   }
	       }
	  }
     }
     liberar(p,&avail) ;
 }
//FUNCION PARA REMOVER UN NODO DEL ARBOL
 void remover_nodo_del_arbol(nom **t,char inf,nom *avail,unsigned int *SW)
 {
  // unsigned int sw1=0;
  nom *s,*p,*q;
   if(*t==0){
      gotoxy(34.5,12);
      printf("ARBOL VACIO");
      validar();
      *SW=1;
   }
   else{
      // if((*t)->info==inf){
	   if((*t)->llink==0 && (*t)->rlink==0 && (*t)->info==inf){
	       gotoxy(19,12);
	       printf("EL NODO ELIMINADO ES EL UNICO DEL ARBOL");
	       validar();
	      // sw1=1;
	       *SW=1;
	       p=*t;
	       *t=0;
	       liberar(p,&avail);
	/*   }
	   else{

	    //	p=*t;
		buscar_nodo_arbol(*t,&p,&q,inf);
		eliminar_raiz(q,p,avail);
	   }*/
	 }
	 else{
	    buscar_nodo_arbol(*t,&p,&q,inf);
	    if(p->info!=inf){ //&& sw1==0){
	       gotoxy(19,8);
	       printf("LA INFORMACION NO SE ENCUENTRA EN EL ARBOL");
	       validar();
	    }
	    else{
		 if(p->llink==0 && p->rlink==0){
		    eliminar_hoja(q,p,&avail);
		 }
		 else{
		      if(p->llink==0 && p->rlink!=0){
			 eliminar_nodo_rama(q,p,avail);
		      }
		      else{
			   if(p->llink!=0 && p->rlink==0){
			      eliminar_nodo_rama(q,p,avail);
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
				    eliminar_hoja(q,p,&avail);
				}
				else{
				     eliminar_nodo_rama(q,p,avail);
				}
			   }
		      }
		 }
	    }
       }
   }
 }
 //RECORRIDO DE UN ARBOL EN PRE IN Y POSTORDEN
void preorden(nom *V)
 {

  if(V!=0){
  visitar(V);
  preorden(V->llink);
  preorden(V->rlink);
  }
 }

 void inorden(nom *Q)
 {
  if(Q!=0){
    inorden(Q->llink);
    visitar(Q);
    inorden(Q->rlink);
  }
 }

 void postorden(nom *Z)
 {
  if(Z!=0){
    postorden(Z->llink);
    postorden(Z->rlink);
    visitar(Z);
  }
 }
