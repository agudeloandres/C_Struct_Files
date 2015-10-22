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

main ()
{
 ListDob listaD;
 char opcion,clave[12];
 listaD.princ = listaD.final = NULL;
 while (1)
 {
  do
  {
   system ("cls");
   menu();
   opcion = toupper(getche());
  }
  while (opcion != 'I' && opcion != 'B' && opcion != 'V' && opcion != 'S');
  system ("cls");
  switch (opcion)
  {
    case 'I':
      clrscr();
      printf("\n Introduzca codigo a a¤adir : ");
      gets(clave);
      insertar(&listaD,clave);
      break;
    case 'B':
      clrscr();
      printf("\n Introduzca codigo a borrar : ");
      gets(clave);
      borrar(&listaD,clave);
      break;
    case 'V':
      visualizar_lista(listaD);
      gotoxy(25,23);printf("Pulse una tecla para continuar ");getch();
      break;
    case 'S':
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

 if (ListaVacia)
  return;

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
   printf("%s no esta en la lista ",clave);
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
 pelemento pactual = listaD.princ;
 while (pactual != NULL)
 {
   printf("%s \n",pactual->clave);
   pactual = pactual->siguiente;
 }
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
 gotoxy(18,7);printf(" Introducir un nuevo elemento (I)");
 gotoxy(18,9);printf(" Borrar un elemento (B)");
 gotoxy(18,11);printf(" Visualizar la lista (V)");
 gotoxy(18,13);printf(" Salir (S)");

 gotoxy(22,16);printf("Elija la opcion deseada [ ]" );
 gotoxy(47,16);
}