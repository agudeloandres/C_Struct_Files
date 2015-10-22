# include <iostream.h>
# include <conio.h>
# include <dos.h>
# include <stdio.h>
# include  <string.h>
#include "a:\rulle.h"

//programa para el manejo de pilas lle
void main ()
{
char opcion;
unsigned int sw;
estudiante *Ptr, *Avail,*P,*Q,*T;
float Inf;

//creacion del menu
sw=0;
do{
clrscr();
gotoxy(10,2);
printf("                   MENU PRINCIPAL ");
gotoxy(15,4);
printf("1- INICIALIZAR LISTA ");
gotoxy(15,6);
printf("2- CREAR LISTA ");
gotoxy(15,8);
printf("3- INSERTAR ANTES ");
gotoxy(15,10);
printf("4- CANCELAR  ");
gotoxy(15,12);
printf( "5- MOSTRAR LISTA");
gotoxy(15,14);
printf("6- TERMINAR");
gotoxy(15,16);
printf("DIGITE OPCION:  ");
do{
  opcion=getchar();
  }while (opcion<'0'&&opcion<'6');
  switch (opcion){
     case'1': if(sw==0){
		sw=1;
		clrscr();
		//definicion de la lista lle
		Ptr=0;
		Avail=0;
		printf("LISTA ENLAZADA YA DEFINIDA");
		getch();
		}
		else {
		    clrscr();
		    printf("Lista ya Definida");
		    getch();
	      }
	      break;

     case'2': if (sw==1){
		  crear_nodo_lle(&Ptr);
		}
		else{
		  clrscr();
		  printf("Lista No Definida");
		  getch();
		}
		break;
     case'3': if (sw==1){
		  captura_nodo(&Inf,&T,&Avail);
		  inserta(&Ptr,Inf,T);
		}
		else{
		 clrscr();
		 printf("Lista No Definida");
		 getch();
		}
		break;
     case'4': if (sw==1){
		 clrscr();
		 gotoxy(10,2);
		 printf("INFORMACION DEL NODO A CANCELAR:  ");
		 gotoxy(15,4);
		 printf("Codigo   : ");
		 scanf("%f",&Inf);
		 Cancelar(&Ptr,&Avail,Inf);
	       }
	       else{
		clrscr();
		printf("Lista No definida");
		getch();
		}
		break;
      case'5': if (sw==1){
	       clrscr();
	       escribir_nodos_lle(Ptr);
	       printf("\n\n<Enter> Continua:");
	       getch();
		}
		else{
		  clrscr();
		  printf("Lista No Definida");
		getch();
		 }
		 break;
      default:break;
   }
   } while (opcion != '6');
   clrscr();
   printf(" F I N  P R O C E S O ");
   }
