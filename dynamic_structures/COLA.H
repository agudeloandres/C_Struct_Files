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

		//DEFINICION DEL TIPO DE COLA O QUEUE.

 typedef struct queue {
	    float Q;
	 };

	       //INICIALIZAR COLA

  void inicializar_Queue(queue **tope, queue **base, queue **max)
{
  int n;
  queue **min;
  do{
    clrscr ();
    printf ("\n DIGITE EL NUMERO DE NODOS: ");
    scanf ("%d",&n);
  }while (n < 1);
    (*base) = new queue[n];
    (*max) = (*base) + n;  //Direccion del maximo nodo que se puede Agregar
    (*tope) = *base;                       // a la cola
    (*min) = *base;
  return;
}
		 //INSERTAR NODOS EN UN STACK

  void insertar_queue(queue **tope, queue *max, float inf)
{
  if (*tope ==max){
	clrscr();
	printf("\n COLA LLENA OVERFLOW...PULSE <ENTER> ...CONTINUE.");
	getch();
  }
   else{
      (*tope)++;
      (*tope)->Q = inf;
   }
 return;
}

		      //RUTINA PARA CANCELAR UN NODO

  void cancelar_queue(queue **tope, queue **base, float *inf)
{
   if (*base == *tope){
	clrscr ();
	printf ("\n COLA VACIA....ERROR DE UNDERFLOW " );
	getch ();
   }
    else{
      (*base)++;
      (*inf) = (*base)->Q;
    }
   return;
}




		 //MUESTRA DE LA INFORMACION



 void consulta_queue (queue **base, queue *tope,float *inf)
{
  queue *li;
  clrscr();
  if (*base == tope) {
    printf("\n COLA VACIA");
  }
   else{
      printf("\n COLA DE LOS NODOS:\n\n");
      li = *base + 1;
     while (li <= tope){
      printf("  %.2f",li->Q);
      li++;
     }
     /*printf("\n\n\tLISTA DE NODOS:\n\n");

     while (*base != tope){
     (*base++);
     (*base)->Q = *inf;
     printf("  %.f",(*base)->Q);*/
     //printf("\n\n\tPULSE <ENTER> PARA CONTINUAR.");
     //getch();

 }
 return;
}


