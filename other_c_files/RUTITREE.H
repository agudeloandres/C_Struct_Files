// finicion del registro para el arbol

typedef struct  nodo_enhebrado{
		nod_enhebrado *llink:
		int ltag:4;
		int rtag:4:
		float info;
		nodo_enhebrado *rlink;
		}      

//FUNCION PARA VALIDAR

 void validar(char opcion)
 {
   gotoxy(17,8);
   printf("POR FAVOR DIGITE 0 Y <ENTER> PARA CONTINUAR :\n" );
   //gotoxy(53,2);
  do{
     opcion=getchar();
  }while(opcion != '0');
 }


void control_sw()
{
  char op;
  clrscr();
  printf(" EL ARBOL AUN NO  ESTA INICIALIZADO ");
  validar(op);
}
//  funcion para leer informacion

void lea_info(char *inf)
{
 char infs,c;
    do{
     scanf("%c",&infs);
    }while(infs<'A'|| infs>'Z');
  *inf=infs;
}

//funcion para visitar

void visitar(nom *p)
{
 char op;

  //gotoxy(23.5,4);
  printf("%c ",p->info);

//  validar(op);

}

 //funcion para crear arbol
void crear_arbol_busqueda(nom **t,char inf)
{
 nom *p,*q,*r;
 char op,info;
      p=new nom;
      p->llink=0;
      p->rlink=0;
      p->info=inf;
      if(*t==0){
	*t=p;
	clrscr();
	printf("EL NODO YA ESTA  INICIALIZADO\n");
	validar(op);
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
       *P=new nodo_enhebrado;
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

 void buscar_nodo_arbol(nom *t,nom **p,nom **q,char inf)
 {
   char c;

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
     if(inf==(*p)->info){
       clrscr();
       gotoxy(24,12);
       printf("LA INFORMACION <%c> SE ENCUENTRA EN EL  ARBOL \n",(*p)->info);
	validar(c);
    }
  else{

     clrscr();
     gotoxy(24,12);
     printf("LA INFORMACION NO SE ENCUENTRA EN EL ARBOL");
     validar(c);
  }


  }

 //FUNCION PARA ELIMINAR UN NODO RAMA O RAIZ DE UN ARBOL


 void eliminar_nodo_rama(nom *q,nom *p,nom *avail)
 {
    if(p->llink==0 && p==q->llink){
      q->llink=p->rlink;
      }
      else{   //l
	 if (p->rlink==0 && p==q->llink){
	      q->llink=p->llink;
	      }
	      else{                 //r
	      if(p->rlink==0 && p==q->llink){
			    //l
		 q->rlink=p->rlink;
		 }
		 else{
		  q->rlink=p->rlink;
		 }
	      }
	 }

     liberar(p,&avail) ;
     }
 // FUNCION PARA ELIMINAR NODO CON UN HIJO
 void eliminar_nodo_hijo (nom *q,nom *p,nom **avail)
 { 											

 char op; 
 

 if (p->llink==0 && p==q->llink){
     q->llink=p->rlink;
     }
     else{
     if(p->rlink==0 && p==p->llink){
       q->llink=p->llink;
       }
       else{
       if (p->rlink==0 && p==q->rlink){
	   q->rlink=p->llink;
	   }
	   else{
	   q->rlink=p->rlink;
	   }
	}
	   
       }
       liberar (p,&(*avail));
  }

 //FUNCION PARA ELIMINAR UN NODO HOJA DE UN ARBOL
void eliminar_hoja(nom *q,nom *p,nom **avail)
  {
   
   char op;
   
      if(p==q->llink){
	   q->llink=0;
	    clrscr();
	    gotoxy(25.5,12);
	    printf("EL NODO ELIMINADO ES UNA HOJA IZQUIERDA\n");
	    validar(op);
	}
	else{
	    clrscr();
	    gotoxy(25.5,12);
	    printf("EL NODO ELIMINADO ES UNA HOJA DERECHA\n");
	    validar(op);
	  q->rlink=0;
	}
      liberar(p,&(*avail));
      }



 
//FUNCION PARA REMOVER UN NODO DEL ARBOL
				   
void remover_nodo_arbol(nom **t,char inf,nom *avail)
{
  nom *s,*p,*q;
   char op;
      if(*t==0){
      gotoxy(34.5,12);
      printf("EL ARBOL ESTA  VACIO");
      validar(op);
    }
    else{
      if((*t)->llink==0 && (*t)->rlink==0 && (*t)->info==inf){
	   gotoxy(19,12);
	   printf("EL NODO ELIMINADO ES EL UNICO DEL ARBOL");
	   validar(op);

	p=*t;
	*t=0;
	liberar(p,&avail);
      }
      else{
	   buscar_nodo_arbol(*t,&p,&q,inf);
	 if(p->llink==0 && p->rlink==0){
	    eliminar_hoja(q,p,&avail);
	 }
	 else{                //p->llink
	  if(p->llink==0 && p->rlink!=0){
	     eliminar_nodo_rama(q,p,avail);
	  }
	  else{
	    if (p->llink!=0 && p->rlink==0){
		eliminar_nodo_rama(q,p,avail);
	    }
	    else{
	     //busqueda de s
		q=p;
		s=p->llink;
		while(s->rlink != 0){
		    q=s;
		    s=s->rlink;
		}
		p->info=s->info;
		p=s;
		if (p->rlink==0 && p->llink==0){
		 
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
   

 //RECORRIDO DE UN ARBOL EN PRE IN Y POSTORDEN
 void preorden(nom *t)
 {
  if(t!=0){
  visitar(t);
  preorden(t->llink);
  preorden(t->rlink);
  }
 }

 void inorden(nom *t)
 {
  if(t!=0){
    inorden(t->llink);
    visitar(t);
    inorden(t->rlink);
  }
 }
void postorden(nom *t)
 {
  if(t!=0){
    postorden(t->llink);
    postorden(t->rlink);
    visitar(t);
  }
 }
