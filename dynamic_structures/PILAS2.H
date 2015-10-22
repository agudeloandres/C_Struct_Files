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



typedef struct stack{
	float s;
};


// Rutina para inicializar pila  <stack>

void inicializar_stack (stack **base,stack **tope,stack **max)
{
int n;
clrscr();
  do{
    printf ("Digite numero nodos de la pila : ");
    scanf ("%d", &n);
  }while(n<=0);
    *base = new stack[n];
    *tope = (*base);
    *max = (*base) + n;
return;
}


// Rutina para incluir  <PUSH>

void push(stack **tope,stack *max,float inf)
{
 if (*tope == max){
  clrscr();
  printf (" Pila Llena_OverFlow.....  <enter> ");
  getch();
 }
  else{
   (*tope)++;
   (*tope)->s=inf;
  }
return;
}


// Rutina para cancelar <POP>

void pop(stack **tope,stack *base,float *inf)
{
 if (*tope == base){
   clrscr();
   printf (" Pila Vacia_UnderFlow.....  <enter> ");
   getch();
 }
  else{
    *inf = (*tope)->s;
    (*tope)--;
  }
return;
}


// Rutina para consultar la pila

void consultar_stack (stack *base,stack **tope,stack *max)
{
 int n;
 float inf;
 stack *li,*base1,*tope1,*max1;
 n=0;
  for(li=base+1;li<=(*tope);li++){
  n++;
  }
    base1=new stack[n];
    tope1=base1;
    max1=base1+n;
    while (*tope>base){
      pop(&(*tope),base,&inf);
      printf("%.1f \n",inf);
      push(&tope1,max1,inf);
    }
      while (tope1>base1){
	pop(&tope1,base1,&inf);
	push(&(*tope),max,inf);
      }
delete base1;
return;
}



