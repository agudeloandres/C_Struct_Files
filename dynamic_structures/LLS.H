//ARCHIVO LLS.H QUE CONTIENE LAS RUTINAS DE LLS.CPP LISTA LINEAL SECUENCIAL.

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

     marco();
     gotoxy(25,12);
     printf("LISTA LLENA......!!!!");
    getch();
    }

    else{

		marco();
		gotoxy(9,7);
		printf("DIGITE INFORMACION :   ");
		  scanf("%f",&inf);
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
  marco();
  gotoxy(4,6);
  printf("INFORMACION DEL NODO A CANCELAR: ");
  scanf("%f",&inf);
  busqueda_nodo(lo,lk,inf,&Li,&i);
  if(Li>*Lk){
    marco();
    gotoxy(25,12);
    printf("NODO NO ENCONTRADO....!!");
    getch();
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
 int i,x=8;
 Li=Lo+1;
 marco();
 gotoxy(7,6);
 printf("NODOS DE LA LISTA LINEAL SECUENCIAL\n");
 for(Li;Li<=Lk;Li++){

    gotoxy(4,x);
    printf("Lista = %7.0f   ",Li->info);
    printf("dir = %04x:%04x \n",FP_SEG(Li),FP_OFF(Li));
    x++;
    }

 return;
 }







