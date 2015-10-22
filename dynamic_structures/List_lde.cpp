#include <ctype.h>
#include<stdio.h>        //Lista doblemente Enlazada ordenada Ascendemente
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define ListaVacia (listaD->princ == NULL)

typedef struct datos elemento;    //tipo elemento
typedef elemento * pelemento;     // tipo puntero a un elemento
struct datos                      // estructura de un elemento de la lista
{
 pelemento siguiente;
 char clave[12];
 pelemento anterior;
};

typedef struct lista ListDob;
struct lista
{
 pelemento princ;                //principio de la lista
 pelemento final;               //final de la lista
};

//Funciones

void error (void)
{
 printf("error : insuficiente espacio de memoria");
 exit(1);
}

pelemento NuevoElemento()
{
 pelemento q = (pelemento )malloc(sizeof(elemento));
 if (!q) error();
 return (q);
}

void insertar(ListDob *, char []);
void borrar(ListDob *, char []);
void visualizar_lista(ListDob);
void menu (void);
void marco (void);

main ()
{
 ListDob listaD;
 char opcion,clave[12],opc;
 int i;
 listaD.princ = listaD.final = NULL;
 while (1)
 {
  do
  {
   system ("cls");
   menu();
   opcion = getchar();
  }
  while (opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4');
  system ("cls");
  switch (opcion)
  {
    case '1':


      marco();
      gotoxy(25,9);printf("INTRODUZCA EL CODIGO : ");
      gets(clave);
      insertar(&listaD,clave);
      break;
    case '2':
      marco();
      gotoxy(25,12);printf("INTRODUZCA CODIGO A ELIMINAR : ");
      gets(clave);
      borrar(&listaD,clave);
      break;
      
    case '3':
      marco();
      visualizar_lista(listaD);
      gotoxy(25,23);printf("Pulse una tecla para continuar ");getch();
      break;
    case '4':
      exit(0);
  }
 }
}

//a¤adir un dato a la lista
void insertar (ListDob *listaD,char clave [])
{
 pelemento q,pactual,panterior;

 //Generar un elemento
 q = NuevoElemento();
 strcpy(q->clave,clave);
 q->anterior = q->siguiente = NULL;

 if (ListaVacia)
 {
  listaD->princ = listaD->final = q;
  return;
 }

//buscar la posicion donde hay que insertar pelemento
pactual = panterior = listaD->princ;
while (pactual != NULL && strcmp(clave, pactual->clave) > 0)
{
 panterior = pactual;
 pactual = pactual->siguiente;
}
if (panterior == pactual)
{
 q->siguiente = listaD->princ;
 listaD->princ = pactual->anterior = q;
}
else
{
 q->anterior = panterior;
 q->siguiente = pactual;
 panterior ->siguiente = q;
 if (pactual) pactual->anterior = q;
		       //pactual sera NULL cuando se inserta al final
}
}


//Encontrar una determinada clave y borrar el elemento
void borrar(ListDob *listaD,char clave[])
{
 pelemento panterior,pactual;

 if (ListaVacia){
  marco();
  gotoxy(25,12);
  printf("\LISTA VACIA......ERROR UNDERFLOW....!!!");
  getch();
  return;}

  //Entrar en la lista y encontrar el elemento a borrar
  panterior = pactual = listaD->princ;
  while (pactual != NULL && strcmp(clave,pactual->clave) != 0)
  {
   panterior = pactual;
   pactual = pactual->siguiente;
  }
  //Si el dato no se encuentra retornar
  if (pactual == NULL)
  {
   marco();
   gotoxy(25,10);
   printf("%s NO ESTA EN LA LISTA ",clave);
   gotoxy(25,23);printf("Pulse una tecla para continuar");getch();
   return;
  }
  //Si el dato se encuentra borrar el elemento
  if (panterior == pactual)         //el elemento esta al principio
  {
   listaD->princ = listaD->princ->siguiente;
   if (listaD->princ) listaD->princ->anterior = NULL;
   //Si principio es igual a NULL habia un solo elemento
  }
  else                       //borrar un elemento que no este al principio
  {
   //Modificar el enlace siguiente
   panterior->siguiente = pactual->siguiente;
   //Modificar el enlace anterior excepto para el ultimo
   if (pactual->siguiente)
     panterior->siguiente->anterior = pactual->anterior;
  }
  free(pactual);
}

//Visualizar el contenido de la lista

void visualizar_lista(ListDob listaD)
{

 marco();
 pelemento pactual = listaD.princ;
 printf("\NULL ");
 while (pactual != NULL)
 {

   printf("\%s <-> ",pactual->clave);
   pactual = pactual->siguiente;

 }
printf("NULL");
}


//Menu

void menu()
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

 gotoxy(25,2);printf("LISTA LINEAL DOBLEMENTE ENLAZADA");
 gotoxy(18,9);printf(" 1. INTRODUCIR UN NUEVO ELEMENTO");
 gotoxy(18,11);printf(" 2. BORRAR UN ELEMENTO");
 gotoxy(18,13);printf(" 3. VISUALIZAR LA LISTA");
 gotoxy(18,15);printf(" 4. SALIR");

 gotoxy(35,18);printf("OPCION [ ]" );
 gotoxy(43,18);
}

//****************************************
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
