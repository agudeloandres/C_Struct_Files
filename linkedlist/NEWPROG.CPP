#include <stdlib.h>
#include <graphics.h>
#include <a:presenta.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <alloc.h>
#include <conio.h>
#include <iostream.h>
#include <a:newprog.h>

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


 while (h==0)
 {
 textcolor(15);
 textbackground(1);
 clrscr();
 graphics(8,70,2,21);
 gotoxy(20,4);
 cout<<"**************** MENU ****************\n\n";
 gotoxy(20,8);
 cout<<"1)INSERTAR\n\n";
 gotoxy(20,10);
 cout<<"2)ELIMINAR\n\n";
 gotoxy(20,12);
 cout<<"3)CONSULTAS\n\n";
 gotoxy(20,14);
 cout<<"4)VISUALIZAR LISTA\n\n";
 gotoxy(20,16);
 cout<<"5)SALIR\n\n";
 gotoxy(20,18);
 cout<<"DIGITE OPCION [ ]";
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
	   final();
	   h=1;
	   break;

   default:
	   cout<<"MESSAGE ERROR! DON'T DO IT";
	   break;
  }

 }
 getch();
 return 0;
}
