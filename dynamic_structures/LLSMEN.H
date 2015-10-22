// DEFINICION DE LOS NODOS DE LA LISTA

typedef struct lls {

		  float info;
		  };

// FUNCION QUE CALCULA LA MAXIMA DIRECCION DE ALMACENAMIENTO PARA LA LLS

lls *Calculo_Maximo(lls *Avail,int n)
{
  lls *Max;
  int i;
  Max= Avail;
  for(i=1;i<=n;i++){
      Max++;
     }
  return Max;
  }

// FUNCION QUE ADICCIONA UN NODO EN LA LLS CON INF DADA

void crear_nodo_lls(lls **Lk,int *k,lls *Max,float inf)
{
  char op;
  int lon,i;
  lls *lk;
  lk=*Lk;
  lk++;
  if ( lk > Max){
     clrscr();
     printf("Lista Llena.. Digite <Enter> Para Continuar");
     do{
	op=getchar();
	}while(op<13 || op>13);
    }
    else{
	  clrscr();


		  printf("Digite informacion");
		  scanf("%f",&inf);

		 // for(i=0;i<=lon;i++){
		//  lk->nombre[i]=nom[i];
	     //  }
	 (*k)++;
	 lk->info=inf;
	 *Lk=lk;
       }
  return;
}

// RUTINA QUE BUSCA UN NODO EN UNA LLS

void busqueda_nodo(lls *Lo,lls *Lk,float inf,lls **Li,int *i)
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

void corrimiento_izquierdo(lls *Lo,lls *Li)
{
  lls *L1,*L2;
  L1=Lo;
  do{
     L2= L1+1;
     L1->info=L2->info;
     L1=L2;
    }while (L2 <= Li);
  return;
}

// FUNCION CORRIMIENTO A DERECHA DE NODOS

void corrimiento_derecho(lls *Lk,lls *Li)
{
 lls *L1,*L2;
 L1= Lk+1;
 L2= L1-1;
 while(L2 > Li){
      L1->info= L2->info;
      L1=L2;
      L2--;
  }
 return;
}



// FUNCION PARA CANCELAR UN NODO EN UNA LLS
void Cancelacion_nodo(lls **Lo,lls **Lk,int *k,float inf)
{
  lls *lo,*lk,*Li;
  int i;
  char op;
  lo=*Lo;
  lk=*Lk;
  printf("INFORMACION DEL NODO A CANCELAR: ");
  scanf("%f",&inf);
  busqueda_nodo(lo,lk,inf,&Li,&i);
  if(Li>*Lk){
    clrscr();
    printf("Nodo no encontrado...Presione <<ENTER>> Para Continuar");
    do{
     op=getchar();
    }while(op<13 || op>13);
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

void escribir_nodos_nodo(lls *Lo,lls *Lk)
{
 lls *Li;
 int i;
 Li=Lo+1;
 for(Li;Li<=Lk;Li++){

    printf("\n Lista = %7.0f          ",Li->info);
    printf("dir = %04x:%04x \n",FP_SEG(Li),FP_OFF(Li));
    }

 return;
 }





