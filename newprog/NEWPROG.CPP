#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <alloc.h>
#include <conio.h>
#include <iostream.h>
#include "C:\BORLANDC\BIN\PETER\newprog.h"

void mantener(struct nodo **);
void insertar(struct nodo **,struct nodo *,struct nodo *,int,char *,char *,int,int,int);
void retirar_p(struct nodo **,struct nodo **);
void con1(struct nodo **);
void con2(struct nodo **);
void con3(struct nodo **);
void con4(struct nodo **);
void con5(struct nodo **);
void visual(struct nodo **);
void final();

main()
{

 struct nodo *cab,*dato;
 int np=0,az,w,h=0;
 cab=NULL;
 ini:
 textbackground(11);
 textcolor(15);
 clrscr();

 while (h==0)
 {
 clrscr();
 graphics(8,70,2,21);
 gotoxy(20,4);
 cout<<"        MENU DE LISTA DINAMICA\n\n";
 gotoxy(20,8);
 cout<<"1  Insertar  Nodo\n\n";
 gotoxy(20,10);
 cout<<"2  Eliminar Nodo\n\n";
 gotoxy(20,12);
 cout<<"3  Consultas de la lista\n\n";
 gotoxy(20,14);
 cout<<"4  Visualizar lista\n\n";
 gotoxy(20,16);
 cout<<"5  Salida\n\n";
 gotoxy(20,18);
 cout<<"Digite Opcion [ ]";
 do{
 gotoxy(35,18);
 cin>>w;
 }while((w<1)||(w>5));
 switch(w)
  {
   case 1:
	   clrscr();
	   mantener(&cab);
	   break;

   case 2:
	   clrscr();
	   retirar_p(&cab,dato);
	   break;

   case 3:
	   clrscr();
	   consulta(&cab);
	   break;
   case 4:
	   clrscr();
	   visual(&cab);
	   break;

   case 5:

	   h=1;
	   exit(0);

   default: goto ini;


  }

 }
 getch();
 return 0;
}
