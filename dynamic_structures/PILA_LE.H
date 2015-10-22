//RUTINAS PILAENLA.H QUE CONTIENE LAS FUNCIONES PARA EL MANEJO DE
		  //LISTAS LINEAL ENLAZADAS COMO PILAS

//DEFINICION DE LA ESTRUCTURA O NODOS DE LA LISTA
typedef struct stack {
	float Info;
	stack *link;
       };
//FUNCION QUE LOCALIZA ESPACIO DISPONIBLE EN MEMORIA PARA INSERTAR NODOS

void Localizar(stack **P, stack **Avail)
{
 if(*Avail==NULL){
   *P=new stack;
 }
 else{
   *P=*Avail;
   *Avail=(*Avail)->link;
 }
 return;
}
//FUNCION PARA LIBERAR ESPACIO EN UNA STACK
void Liberar(stack *P, stack **Avail)
{
 if(P != 0){
   P->link=*Avail;
   *Avail=P;
 }
 return;
}
//FUNCION PARA INSERTAR UN NODO EN UNA stack
void Insertar(stack **tope,stack **base, float Inf,stack **Avail)
{
 stack *P;
 Localizar(&P,&(*Avail));
 P->Info=Inf;
 P->link=*tope;
 *tope=P;
 if (*base==NULL){
  * base=P;
   }
 return;
}
//FUNCION QUE BUSCA UN NODO CON INFO CONOCIDA
void Buscar(stack *tope,stack **Q,stack **P,float Inf)
{
  *P=tope;

     while(*P!=0 && (*P)->Info!=Inf){
	*Q=*P;
	(*P)=(*P)->link;

     }
 return;
}
//FUNCION PARA CANCELAR UN NODO EN UNA stack
void Cancelar(stack **tope,stack **Avail,float Inf)
{
 stack *P,*Q;
 Buscar(*tope,&Q,&P,Inf);
 if(P==NULL){
   clrscr();
   printf("NODO NO ENCONTRADO O stack VACIO  ");
 }
 else{
    if(P==*tope){
      (*tope)=(*tope)->link;
     }

      else{
	 Q->link=P->link;
	 Liberar(P,&(*Avail));
      }
    }

 return;
}


//FUNCION PARA CONSULTAR NODOS EN LA stack
void Consultar(stack *tope)
{
 int i;
 stack *P;
 P=tope;
 while(P!=NULL){
    printf("  %1.2f ",P->Info);
    P=P->link;
 }
 return;
}
