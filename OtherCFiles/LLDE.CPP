# include <stdio.h>
# include <conio.h>
# include <a:cuadro.h>
# include "f:archivo.h"
void main()
{
nodo_llde *p,**ptr,**avail;
float Inf,inf;
int choice;

       while((choice = menu_opcion()) != 5){

	     switch(choice){

		  case 1:
			 ptr = NULL;
			 avail = NULL;
			 gotoxy(20,15);
			 printf("lista inicializada");
			 getch();
			 break;
		  case 2:
			 clrscr();
			 printf(" informacion a insertar  :" );
			 scanf("%f",&inf);
			 crear(ptr,&(*avail),inf);
			 break;
		  case 3:
			 clrscr();
			 printf(" informacion a insertar" );
			 scanf("%f",&Inf);
			 buscar_nodo(ptr,&p,Inf);
		       //	 printf(" inserte  antes de : " );
		      //	 scanf("%f",&inf);
			 insert(ptr,&(*avail),inf);
			 break;
		     }
		}
	 }


