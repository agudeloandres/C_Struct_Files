# include <dos.h>
# include<iostream.h>
# include <string.h>
# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <A:funarb.h>

//programa para el manejo de arboles

void main ()
{

int c;
int opcion;
char o[80];
int op;
unsigned int sw;
B_Tree *P, *avail,*T;
int inf;
char s[80];
//creacion del menu

sw=0;
do{
textcolor(15);
clrscr();
gotoxy(35,5);
printf(" MENU PRINCIPAL ");
gotoxy(33,2);
printf(" ARBOL DE BUSQUEDA ");
gotoxy(20,8);
printf("1- Inicializar");
gotoxy(20,10);
printf("2- Insertar   ");
gotoxy(20,12);
printf("3- Cancelar  ");
gotoxy(20,14);
printf("4- Mostrar   ");
gotoxy(20,16);
printf("5- Terminar ");
gotoxy(20,18);
printf("DIGITE OPCION:   ");

do{
   gets(o);
  opcion = atoi(o);
  }while (opcion< 0 && opcion< 6);
  switch (opcion){
     case 1: if(sw==0){
		sw=1;
		clrscr();

		//definicion del arbol
		Crear_Tree(&T,&avail);
	     //	T=NULL;
	      //	avail=NULL;
  //		cuadr();
		gotoxy(29,12);
		printf(" ARBOL INICIALIZADO ");
		getch();
		}
		else {
		    clrscr();
		    gotoxy(30,12);
		    printf("ARBOL YA FUE DEFINIDO\a\a");
		    getch();
	      }
	      break;

     case 2: if (sw==1){

		clrscr();
		gotoxy(25,9);
		printf("PROCESO PARA INSERTAR NODOS");
		gotoxy(25,12);
		printf("INFORMACION NODO : ");
		scanf("%d",&inf);

		Insert_Nodo(inf,&T,&avail);

	      }

	      else{
		  clrscr();
		  gotoxy(25,12);
		  printf("ARBOL NO  DEFINIDO.. pulse<ENTER>\a");
		  getch();
		}
		break;
     case 3: if (sw==1){
		 clrscr();
		 gotoxy(25,12);
		printf("ELIMINAR NODO ... " );
		cin>>inf;
		Cancelar_Nodo_Arbol(&T,inf,&avail);
  //		inserta(*ptr,&Avail,inf);

		}
		else{
		 clrscr();
		 gotoxy(30,12);
		 printf("ARBOL NO DEFINIDO\a\a");
		 getch();
		}
		break;
   case 4: if (sw==1){
		    do{
		    clrscr();
		    printf("1. PRE_ORDEN\n");
		    printf("2. IN_ORDEN\n");
		    printf("3. POST_ORDEN\n\n");
		    printf("4. RETORNAR MENU\n");
		    printf("\nIntroduzca su opcion:\n");
		    scanf("%d",&op);
		 switch(op){
			 case 1:

			      Pre_Orden(&T);
			      getch();
			      break;

			 case 2:
			     In_Orden(&T);
			      getch();
			      break;

			 case 3:
			      Post_Orden(&T);
			      getch();
			      break;
			      }

		       }while(op != 4);
		    }
		else{
		clrscr();
		gotoxy(30,12);
		printf("ARBOL NO DEFINIDO\a\a");
		getch();
		}

      default:
	       break;
   }
   } while (opcion !=  5);
   }
