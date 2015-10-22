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


typedef struct queue{
	float q;
	};

//LIBRERIA RUTCOLA.H
//RUTINA PARA INICIALIZAR UNA COLA
void inicializar_queue(queue**min, queue**max, queue**base, queue**tope)
{ 
int n;
clrscr();
do{
   printf("DIGITE EL NUMERO DE NODOS DE LA COLA = ");
   scanf("%d", &n);
} while(n<=0);
(*base)= new queue[n];
(*min)=(*base);
(*max)=(*base)+n;
(*tope)=(*base);
return;
}


//RUTINA PARA HACER INSERT EN UNA COLA
void insert_queue(queue**tope, queue*max, queue*base, queue*min, float inf)
{
clrscr();
if (*tope+1 != base){
   if (*tope<max){
      (*tope)++;
    }
   else{
      (*tope)=min+1;
    }
   (*tope)->q=inf;
 }
else{
      printf ("COLA LLENA ERROR DE OVERFLOW...");
      getch();
 } 
return;
}


//RUTINA PARA HACER REMOVE EN UNA COLA
void remove_queue(queue**tope, queue**base, queue*max, queue*min, float *inf)
{
clrscr();
if ((*base)!=(*tope)){      
    if ((*base)<max){
       (*base)++;
    }
    else{
       (*base)=min+1;
    }
    (*inf)=(*base)->q;
    if ((*base)==(*tope)){
	(*base)=min;
	(*tope)=min;
    }
}
else{
     printf("COLA VACIA ERROR DE UNDERFLOW...");
}
return;
}


//RUTINA PARA CONSULTAR NODOS EN UNA COLA
void consultar_queue(queue*tope, queue*min, queue*base, queue*max)
{
clrscr();
float inf;
queue *com;
if (tope!=min){
   com=base;
   while (com!=tope){
	  if (com>=max){
	      com=min;
	  }
	  com++;
	  inf=com->q;
	  printf("%.1f - ", inf);
    }
 }
else{
    printf ("COLA VACIA ERROR DE UNDERFLOW...<enter>");
}
return;
}
        

    	  
