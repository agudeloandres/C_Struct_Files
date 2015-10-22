//ARCHIVO rlle.H QUE CONTIENE LAS FUNCIONES PARA EL MANEJO DE
		  //LISTA LINEAL ENLAZADA



//DEFINICION DE LA ESTRUCTURA O NODOS DE LA LISTA

typedef struct LLE {
	float Info;
	LLE *link;
       };


//FUNCION QUE LOCALIZA ESPACIO DISPONIBLE EN MEMORIA PARA INSERTAR NODOS

void Localizar(LLE **P,LLE **Avail)
{
 if(*Avail==NULL){
   *P=new LLE;
 }
 else{
   *P=*Avail;
   *Avail=(*Avail)->link;
 }
 return;
}


//FUNCION PARA LIBERAR ESPACIO EN UNA LLE
void Liberar(LLE *P, LLE **Avail)
{
 if(P != 0){
   P->link=*Avail;
   *Avail=P;
 }
 return;
}


//FUNCION PARA INSERTAR UN NODO EN UNA LLE
void Insertar_Lle(LLE **Ptr,float Inf,LLE **Avail)
{
 LLE *P;
 Localizar(&P,&(*Avail));
 P->Info=Inf;
 P->link=*Ptr;
 *Ptr=P;
 return;
}


//FUNCION QUE BUSCA UN NODO CON INFO CONOCIDA
void Buscar_Nodo(LLE *Ptr, LLE **Q,LLE **P,float Inf)
{
  *P=Ptr; 

     while(*P!=0 && (*P)->Info!=Inf){
	*Q=*P;
	(*P)=(*P)->link;
     }
 return;
}


//FUNCION PARA CANCELAR UN NODO EN UNA LLE
void Cancelar_Lle(LLE **Ptr,LLE **Avail,float Inf)
{
 LLE *P,*Q;
 Buscar_Nodo(*Ptr,&Q,&P,Inf);
 if(P==NULL){
   clrscr();
   printf("NODO NO ENCONTRADO O LISTA ENLAZADA VACIA  ");
 }
 else{
    if(P==*Ptr){
      (*Ptr)=(*Ptr)->link;
     }     

      else{
	 Q->link=P->link;
	 Liberar(P,&(*Avail));
      }
    }
 
 return;
}     
  

//FUNCION PARA CONSULTAR O VER NODOS EN LA LLE
void Consultar_Lle(LLE *Ptr)
{
 int i;
 LLE *P;
 P=Ptr;
 while(P!=NULL){
    printf("  %1.2f ",P->Info);
    P=P->link;
 }
 return;
}
