// DEFINICION DE LOS NODOS DE LA LISTA

typedef struct nodo {
		  int info;
		  };

// FUNCION QUE CALCULA LA MAXIMA DIRECCION DE ALMACENAMIENTO PARA LA LLS

nodo *Calculo_Maximo(nodo *Avail,int n)
{
  nodo *max;
  int i;
  max= Avail;
  for(i=0;i<=n;i++){
      max++;
     }
  return max;
  }

// FUNCION QUE ADICCIONA UN NODO EN LA LLS CON INF DADA

void crear_nodo_lls(nodo **Lk,int *k,nodo *Max,int Inf)
{
  char op;
  nodo *lk;
  lk=*Lk;
  lk++;
  if ( lk > Max){
     clrscr();
     printf("Lista Llena.. DIgite 0 y <Enter> Continua");
     do{
	op=getchar();
	}while(op != '0');
    }
    else{
	 (*k)++;
	 lk->info=Inf;
	 *Lk=lk;
       }
  return;
}

// RUTINA QUE BUSCA UN NODO EN UNA LLS

void busqueda_nodo(nodo *Lo,nodo *Lk,int inf,nodo **Li,int *i)
{
// los valores de la busqueda se devuelven en Li e i
 *Li=Lo+1;
 *i=1;
 while(*Li <= Lk && (*Li)->info != inf){
      (*Li)++;
      (*i)++;
 }
 if ( (*Li)->info != inf){
       (*Li)= Lk+1;
   }
 return;
}

// RUTINAS QUE REALIZAN LOS CORRIMIENTOS DE NODOS PARA INSERTAR NUEVOS

// FUNCION CORRIMIENTO A IZQUIERDA DE NODOS

void corrimiento_izquierdo(nodo *Lo,nodo *Li)
{
  nodo *L1,*L2;
  L1=Lo;
  do{
     L2= L1+1;
     L1->info=L2->info;
     L1=L2;
    }while (L2 <= Li);
  return;
}

// FUNCION CORRIMIENTO A DERECHA DE NODOS

void corrimiento_derecho(nodo *Lk,nodo *Li)
{
 nodo *L1,*L2;
 L1= Lk+1;
 L2= L1-1;
 while(L2 > Li){
      L1->info= L2->info;
      L1=L2;
      L2--;
  }
 return;
}

// FUNCION PARA INSERTAR NODO EN UNA LLS

void insertar_nodo(nodo **Lo,nodo **Lk,int *k, nodo *Max,nodo *Min,int Inf, int Inf1)
{
  nodo *Li,*lo,*lk;
  int i;
  char op;

  lo=*Lo;
  lk=*Lk;

  // Inf: informacion del nodo a buscar  Inf1: informacion a incluir

  busqueda_nodo(lo,lk,Inf,&Li,&i);

  if(Li>*Lk){
     clrscr();
     printf("No Insertar -Nodo no encontrado.. Digite 0 y <Enter> Continua");
     do{
	op=getchar();
	}while(op != '0');
    }
    else{
	if(i<*k-i){
	   if(lo==Min){
	     if(lk==Max){
	     clrscr();
	     printf("Lita Llena No Insertar ... Digite 0 y <Enter> Continua");
	     do{
		op=getchar();
		}while(op != '0');
	    }
	    else{
	       corrimiento_derecho(lk,Li);
	       (*Lk)++;
	       Li++;
	       Li->info=Inf1;
	       (*k)++;
	    }
	  }
	  else{
	      corrimiento_izquierdo(lo,Li);
	     (*Lo)--;
	     Li->info=Inf1;
	     (*k)++;
	   }
	}
	else{
	    if(*Lk==Max){
	       if(*Lo==Min){
		    clrscr();
		    printf("Lista Llena No Insertar ... Digite 0 y <Enter> Continua");
		    do{
		       op=getchar();
		       }while(op != '0');
		 }
		 else{
		    corrimiento_izquierdo(lo,Li);
		    (*Lo)--;
		    Li->info=Inf1;
		    (*k)++;
		  }
	       }
	       else{
		     corrimiento_derecho(lk,Li);
		     (*Lk)++;
		     Li++;
		     Li->info=Inf1;
		     (*k)++;
		   }
	      }
   }
   return;
}

// FUNCION PARA CANCELAR UN NODO EN UNA LLS
void Cancelacion_nodo(nodo **Lo,nodo **Lk,int *k,int inf)
{
  nodo *lo,*lk,*Li;
  int i;
  char op;
  lo=*Lo;
  lk=*Lk;
  busqueda_nodo(lo,lk,inf,&Li,&i);
  if(Li>*Lk){
    clrscr();
    printf("Nodo no encontrado...Digite 0 y <Enter> Continua");
    do{
       op=getchar();
       }while(op != '0');
  }
  else{
       if(i<*k-1){
	  Li--;
	  corrimiento_derecho(Li,lo);
	  (*k)--;
	  (*Lo)++;
       }
       else{
	    corrimiento_izquierdo(Li,lk);
	    (*Lk)--;
	    (*k)--;
	   }
      }
  return;
 }

// FUNCION PARA MOSTRAR EL CONTENIDO DE TODOS LOS NODOS DE LA LLS

void escribir_nodos_lls(nodo *Lo,nodo *Lk)
{
 nodo *Li;
 char op;

 Li=Lo+1;
 for(Li;Li<=Lk;Li++){
    printf("\n Nodo= %d",Li->info);
    printf("  direccion = %04x:%04x \n",FP_SEG(Li),FP_OFF(Li));
    }
 return;
 }
