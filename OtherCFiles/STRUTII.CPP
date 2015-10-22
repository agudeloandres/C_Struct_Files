# include <dos.h>
# include<iostream.h>
# include <string.h>
# include <stdio.h>
# include <conio.h>
# include <f:cuadro.h>
# include <f:cuadr.h>
# include <a:submenu.h>
# include <a:TREE.h>
# include <dos.h>
# include <stdlib.h>

//programa para el manejo de arboles

void main ()
{

int opcion;
char o[80];
int op;
unsigned int sw;
B_Tree *T,*Avail,*P;
int inf,s,i;
//creacion del menu
sw=0;
do{
textcolor(15);
clrscr();
cuadro();
textbackground(1);
textcolor(15);
gotoxy(35,5);
textcolor(350);
cprintf(" MENU PRINCIPAL ");
textcolor(15);
gotoxy(33,2);
textcolor(350);
cprintf(" ARBOL DE BUSQUEDA ");
textcolor(350);
gotoxy(20,8);cprintf("1  Inicializar            ");
gotoxy(20,10);
cprintf("2  Insertar    ");
gotoxy(20,12);
cprintf("3  Cancelar   ");
gotoxy(20,14);
cprintf("4  Mostrar  ");
textcolor(11);
gotoxy(20,16);
cprintf("5  Terminar ");
gotoxy(50,22);
cprintf(" pallares guerrero william ");
gotoxy(52,23);
cprintf(" ingenieria de sistemas");
gotoxy(20,20);
textcolor(15);
cprintf("DIGITE OPCION:   ");
textcolor(15);
textcolor(11);

do{
   gets(o);
  opcion = atoi(o);
  }while (opcion< 0 && opcion< 6);
  switch (opcion){
     case 1: if(sw==0){
		sw=1;
		clrscr();

		//definicion de la lista lle

	       //	T=0;
	      //	Avail=0;
		cuadr();
		gotoxy(29,12);
		textcolor(350);
		cprintf(" ARBOL INICIALIZADO ");
                Crear_Tree(&P,&Avail);
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
	       //	Crear_LLDE(&ptr,&Avail,inf);
	   	Insert_Nodo(&T,&Avail,inf);
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
		printf("RUTINA NO TERMINADA ... " );
	       //	cin>>inf;

	       //	Insertar_nodo(ptr,&Avail,inf);

		}
		else{
		 clrscr();
		 cuadr();
		 gotoxy(30,12);
		 printf("ARBOL NO DEFINIDO\a\a");
		 getch();
		}
		break;
      case 4 : if (sw==1){
		s = rectan();

	       switch(s){
		      case 1:/*
			gotoxy(42,11);
			textcolor(450);
			cprintf(" PRE_ODEN ");
			gotoxy(24,14);
			textcolor(450);
			cprintf("  Mostrar");
			delay(500);
			gotoxy(42,13);
			printf("          ");
			gotoxy(42,15);
			printf("           ");
			*/
			Visitar(P);
			//Pre_Orden(&P);
			printf(" %d");
                        getch();
			break;
		      case 2:
			gotoxy(42,13);
			textcolor(425);
			cprintf("IN_ORDEN ");
			delay(500);
			gotoxy(42,11);
			printf("          ");
			delay(500);
			gotoxy(42,15);
			printf("           ");

		       In_Orden(&P);
			getch();
			break;
			case 3:
			gotoxy(42,15);
			textcolor(425);
			cprintf(" POSTORDEN   ");
			gotoxy(42,11);
			printf("          ");
			delay(500);
			gotoxy(42,13);
			printf("           ");
			delay(500);
			Post_Orden(&P);
			getch();
			break;
		      }



	      // clreol();
	       //getch();
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
   } while (opcion !=  5);
   }
