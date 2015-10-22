//archivo funciones.h que contiene las rutinas para el manejo de pila

//funcion que halla la direccion maxima que se puede acceder en memoria
typedef struct pila{
	       float S;
	     };
pila *Maximo(pila *base, int n)
{
 pila *max;
 int i;
 max=base;
 for(i=1;i<=n;i++){
    max++;
 }
 return max;
}

//funcion para definir una pila

void crear_pila(pila **Base,pila **Tope,int n)
{
 pila *Avail;

 //asignacion del espacio disponible

 Avail=new pila[n];

 //asignacion de condiciones iniciales

 *Base=Avail;
 *Tope=Avail;
}

//funcion push para insertar un nodo en una pila

void push(pila **Tope,pila *Max,float Inf)
{
 char op;
 (*Tope)++;
 if(*Tope>Max){
   (*Tope)--;
   clrscr();
   printf("Pila Llena .. OVERFLOW ( ENTER ) Y Continua: ");
   do{
     op=getch();
   }
   while(op<13 || op>13);
 }
 else{

   (*Tope)->S = Inf;
 }
 return;
}

//funcion Pop para cancelar un nodo de una pila

void Pop(pila **Tope,pila *Base,float *Inf)
{
 char op;
 if(*Tope==Base){
   clrscr();
   printf("Pila Vacia .. underflow.. ");
   do{
     op=getch();
   }while(op<13 || op >13);
 }
 else{
   *Inf=(*Tope)->S;
   (*Tope)--;
 }
 return;
}

//Funcion que escribe los elementos de la pila

void Escribir_Pila(pila *Base,pila **Tope,pila *Max, int n)
{
 char op;
 pila *Base1,*Tope1,*Max1,*Top;
 float Inf;
 Top=*Tope;

 //crear nueva pila para sacar elementos y guardar

 crear_pila(&Base1,&Tope1,n);
 Max1=Maximo(Base1,n);

 //impresion de la pila usando Pop u Push (StackTop)

 while(Base!=Top){
    Pop(&Top,Base,&Inf);
    *Tope=Top;
    printf("\n %3.1f",Inf);
    push(&Tope1,Max1,Inf);
 }

 //Recuperacion de la pila

 while(Base1!=Tope1){
    Pop(&Tope1,Base1,&Inf);
    push(&Top,Max,Inf);
    *Tope=Top;
 }
}
