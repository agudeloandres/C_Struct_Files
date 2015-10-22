//ARCHIVO RUPILA.H QUE CONTIENE LAS RUTINAS PARA EL MANEJO DE PILAS

//FUNCION QUE HALLA LA DIRECCION MAXMA QUE SE PUEDE ACCEDER EN MEMORIA

typedef struct stack{
	float s;
};

stack *maximo (stack *base, int n)
{
stack *max;
int i;
max=base;
for(i=1; i<=n; i++){
      max++;
}
return max;

}

//===========================================================================
//FUNCION PARA DEFINIR UNA PILA

void crear_pila(stack**base, stack**tope, int n)
{
stack *avail;


//ASIGNACION DEL ESPACIO DISPONIBLE

avail=new stack[n];

//ASIGNACION DE CONDICIONES INICIALES

*base = avail;
*tope = avail;
}
//============================================================================
//FUNCION PUSH PARA INSETAR UN NODO EN UNA PILA

void push(stack**tope, stack*max, float inf)
{
char op;

(*tope)++;
if (*tope>max){
(*tope)--;
 clrscr();
 printf("PILA LLENA...  OVERFLOW... DIGITE 0 Y <ENTER> CONTINUA");
 do{
 op=getchar();
} while(op!='0');
}
else{
 (*tope)->s=inf;
}
return;
}
//=============================================================================

//FUNCION POP PARA CANCELAR O MENOVER UN NODO DE UNA PILA

void pop(stack**tope, stack*base, float *inf)
{
char op;

if(*tope < base){

clrscr();
printf("PILA VACIA... UNDERFLOW...  DIGITE 0 Y <ENTER> CONTINUA");
do{
  op=getchar();
} while (op!='0');
}
else{
 *inf= (*tope)->s;
 (*tope)--;
}
return;
}
//=============================================================================

//FUNCION QUE ESCRIBE LOS ELEMENTOS DE LA PILA

void escribir_pila(stack *base, stack**tope, stack *max, int n)
{
char op;
stack *base1, *tope1, *max1,*top;
float inf;
top=*tope;

//CREAR NUEVA PILA PARA SACAR ELEMENTOS Y GUARDAR

crear_pila(&base1, &tope1,n);
max1=maximo(base1,n);

//IMPRESION DE LA PILA USANDO POP U PUSH (STACK TOP)

while(base!=top){
    pop(&top, base, &inf);
    *tope=top;
    printf("\n %f",inf);
    push(&tope1,max1, inf);
}

//RECUPERACION DE LA PILA

while (base1!=tope1){
     pop(&tope1, base1, &inf);
     push(&top, max,inf);
     *tope=top;
}
}
//=============================================================================