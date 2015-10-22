//ARCHIVO lle.H QUE CONTIENE LAS FUNCIONES PARA EL MANEJO DE
		  //LISTA LINEAL ENLAZADA

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
//******************************

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
   marco();
   gotoxy(25,12);
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

    printf("\%1.1f -> ",P->Info);
    P=P->link;
 }
 printf("NULL");
 return;
}

//****************************************************

void menu()     //CUADRO DEL MENU
{
 clrscr();
     int k,y,p;

     gotoxy(20,1); printf("É\n");
     gotoxy(60,1);printf("»\n");
     gotoxy(20,3);printf("È\n");
     gotoxy(60,3);printf("¼\n");
     gotoxy(15,6); printf("É\n");
     gotoxy(65,6);printf("»\n");
     gotoxy(15,21);printf("È\n");
     gotoxy(65,21);printf("¼\n");

//CUADRITO DONDE ESTA EL TITULO

    for (k=21; k<= 59; k ++){
   gotoxy (k,y);
   gotoxy(21,1);printf("Í\n");
   gotoxy (k,3);printf("Í\n");
   gotoxy(k,1);printf("Í\n");
   gotoxy (k,3);printf("Í\n");
   gotoxy (20,2);printf("º\n");
   gotoxy (60,2);printf("º\n");

    }


   for (p=6; p<=20; p++)
  {
     gotoxy(15,6); printf("É\n");
     gotoxy(65,6);printf("»\n");
     gotoxy(15,21);printf("È\n");
     gotoxy(65,21);printf("¼\n");
     gotoxy (15,p);printf("º\n");
     gotoxy (65,p);printf("º\n");
     }
      for (p=16; p<=64; p++)
  {
     gotoxy(p,6);printf("Í\n");
     gotoxy (p,21);printf("Í\n");

    }
return;
}
