# include <dos.h>
# include<iostream.h>
# include <string.h>
# include <stdio.h>
# include <f:getch.H>
# include <conio.h>
# include <f:cuadro.h>
# include <f:cuadr.h>

//programa para el manejo de pilas lle

void main ()
{

int opcion;
unsigned int sw;
Nodo_LLDE *ptr, *Avail;
int inf;
//creacion del menu
sw=0;
do{
textcolor(15);
clrscr();
cuadro();
textbackground(1);
textcolor(15);
gotoxy(30,5);
textcolor(350);
cprintf(" ARBOLES DE BUSQUEDA ");
textcolor(15);
gotoxy(35,2);
textcolor(350);
cprintf(" MENU PRINCIPAL ");
textcolor(350);
gotoxy(20,8);
cprintf("1  Inicializar            ");
gotoxy(20,10);
cprintf("2  Crear    ");
gotoxy(20,12);
cprintf("3  Insertar   ");
gotoxy(20,14);
cprintf("4  Cancelar  ");
gotoxy(20,16);
cprintf("5  Mostrar   ");
textcolor(11);
gotoxy(20,18);
cprintf("6  Terminar ");
gotoxy(20,20);
textcolor(15);
cprintf("DIGITE OPCION:   ");
textcolor(15);
do{
  cin>>opcion;
  }while (opcion< 0 && opcion< 6);
  switch (opcion){
     case 1: if(sw==0){
		sw=1;
		clrscr();

		//definicion de la lista lle

		ptr=0;
		Avail=0;
		cuadr();
		gotoxy(29,12);
		textcolor(350);
		cprintf(" ARBOL INICIALIZADO ");
		getch();
		}
		else {
		    clrscr();
		    cuadr();
		    gotoxy(30,12);
		    textcolor(44);
		    cprintf("ARBOL YA FUE DEFINIDO\a\a");
		    getch();
	      }
	      break;

     case 2: if (sw==1){

		clrscr();
		gotoxy(25,9);
		printf("PROCESO PARA INSERTAR NODOS");
		cuadr();
		gotoxy(25,12);
		printf("INFORMACION NODO : ");
		cin>>inf;
		Crear_LLDE(&ptr,&Avail,inf);

	      }

	      else{
		  clrscr();
		  cuadr();
		  gotoxy(25,12);
		  printf("ARBOL NO  DEFINIDO.. pulse<ENTER>\a");
		  getch();
		}
		break;
     case 3: if (sw==1){
		 clrscr();
		 cuadr();
		 gotoxy(25,12);
		printf("INSERTAR DESPUES DE ... " );
		cin>>inf;

		Insertar_nodo(ptr,&Avail,inf);

		}
		else{
		 clrscr();
		 cuadr();
		 gotoxy(30,12);
		 printf("ARBOL NO DEFINIDO\a\a");
		 getch();
		}
		break;
   case 4: if (sw==1){
		 clrscr();
		 gotoxy(10,2);
		 printf("INFORMACION DEL NODO A CANCELAR:  \a");
		 gotoxy(15,4);
		 printf("informacion   : ");
		 cin>>inf;
		 cancelar(inf,&ptr,&Avail);
	       }
	       else{
		clrscr();
		cuadr();
		gotoxy(30,12);
		printf("ARBOL NO DEFINIDO\a\a");
		getch();
		}
		break;
      case 5 : if (sw==1){
	       clrscr();
	       mostrar_nodos(ptr);
	       cuadr();
	       gotoxy(30,12);
	       printf("presione <Enter>..!:");
	       getch();
		}
		else{
		  clrscr();
		  cuadr();
		  gotoxy(30,12);
		  printf("ARBOL NO DEFINIDO\a\a");
		getch();
		 }
		 break;

      default:
	       break;
   }
   } while (opcion !=  6);
   }
