//PROGRAMA PARA EL MANEJO DE UNA LISTA ENLAZADA CIRCULAR(Ptr)
// Ptr= Es Apuntador o cabeza del nodo y el unico elemento que se conoce de la lista.
// Avail= Es un apuntador, que es el espacio disponible.
//P,Q= son apuntadores, que contienen la direccion de memoria de un nodo.

#include<conio.h>
#include<stdlib.h>
#include <stdio.h>
#include "C:\BORLANDC\BIN\DINAMI~1\LEC.H"

void main()
{
char Opc,op;
unsigned int sw;
LEC *Ptr,*Avail;
float Inf;

//CREACION DEL MENU
sw=0;

do{
  menu();
  gotoxy(23,2);
  printf (" M E N U  P R I N C I P A L  L E C ");
  gotoxy(18,7);
  printf ("1.  INICIALIZAR LISTA ENLAZADA CIRCULAR");
  gotoxy(18,9);
  printf ("2.  INSERTAR INFORMACION EN UNA LEC");
  gotoxy(18,11);
  printf ("3.  ELIMINAR LA INFORMACION DADA ");
  gotoxy(18,13);
  printf ("4.  CONSULTAR INFORMACION EN UNA LEC");
  gotoxy(18,15);
  printf ("5.  SALIR DEL PROGRAMA");
  gotoxy (25,18);
  printf ("DIGITE OPCION : [ ]");
  gotoxy(42,18);
  do{
    Opc=getchar();
  }while(Opc<'0' && Opc>'5');
   switch(Opc){


      case '1':if(sw==0){
		 sw=1;
		  clrscr();
		   Ptr=NULL;
		    Avail=NULL;
		     marco();
		     gotoxy(25,12);
		     printf ("LISTA ENLAZADA CIRCULAR INICIALIZADA....!!!");
		     getch();
		   }
		 else{
		    marco();
		    gotoxy(25,12);
		    printf ("LISTA YA INICIALIZADA.....!!!");
		    getch();

		 }
	       break;


      case '2':if(sw==1){
		   do{
		   marco();
		   gotoxy(25,9);
		   printf("DIGITE INFORMACION: ");
		   scanf("%f",&Inf);
		   Insertar_Lec(&Ptr,Inf,&Avail);
		   gotoxy(7,13);
		     printf("DESEA INSERTAR MAS NODOS (S/N):   ");
		     do{
		      op=getchar();
		      }while(op!='s' && op!='S' && op!='n' && op!='N');
		     }while(op=='s' || op=='S');


		}
		 else{
		   marco();
		   gotoxy(25,12);
		   printf ("LEC NO INICIALIZADA.....!!!!");
		   getch();

		}
		break;

      case '3':if(sw==1){
		 marco();
		 gotoxy(25,12);
		 printf ("DIGITE INFORMACION DEL NODO A CANCELAR: ");
		 scanf ("%f", &Inf);
		   Cancelar_Lec(&Ptr,&Avail,Inf);
		   getch();
		}
		 else{
		   marco();
		    gotoxy(25,12);
		    printf ("LEC VACIA...ERROR UNDERFLOW..!!!!");
		    getch();


		 }
	       break;



      case '4':if(sw==1){
		   marco();
		   gotoxy(3,2);
		   printf("LA LISTA ES :");
		   gotoxy(2,4);
		   Consultar_Lec(Ptr);
		   getch();

		}
		 else{
		  marco();
		   gotoxy(25,12);
		   printf ("LEC NO INICIALIZADA");
		       getch();


		break;
	   default: break;
	}
       }
   }while (Opc !='5');
   clrscr();
    gotoxy(20,8);
      printf (" F I N  D E L  P R O G R A M A ");
}



