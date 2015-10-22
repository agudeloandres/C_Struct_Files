//PROGRAMA PARA EL MANEJO DE UNA LISTA LINEAL ENLAZADA LLE(Ptr) COMO PILA
// Ptr= Es Apuntador o cabeza del nodo y el unico elemento que se conoce de la lista.
// Avail= Es un apuntador, que es el espacio disponible.
//P,Q= son apuntadores, que contienen la direccion de memoria de un nodo.

#include<conio.h>
#include <stdio.h>
#include "C:\BORLANDC\BIN\DINAMI~1\PILA_LE.H"

void main()
{
char Opc,op;
unsigned int sw;
stack *tope,*base,*Avail;
float Inf;

//CREACION DEL MENU
sw=0;

do{
  clrscr();
  gotoxy(35,6);
  printf (" M E N U  ");
  gotoxy(18,8);
  printf ("1  INICIALIZAR LLE COMO PILA");
  gotoxy(18,10);
  printf ("2  INSERTAR INFORMACION EN LA LLE COMO PILA");
  gotoxy(18,12);
  printf ("3  ELIMINAR INFORMACION DADA EN UNA LLE COMO PILA");
  gotoxy(18,14);
  printf ("4  CONSULTAR INFORMACION EN UNA LLE COMO PILA");
  gotoxy(18,16);
  printf ("5  SALIR ");
  gotoxy (18,18);
  printf ("DIGITE OPCION: ");
  do{
    Opc=getchar();
  }while(Opc<'0' && Opc>'5');
   switch(Opc){
       case '1':if(sw==0){
		 sw=1;
		  clrscr();
		   tope=NULL;
		    Avail=NULL;
		     gotoxy(10,11);
		     printf ("LISTA LINEAL ENLAZADA COMO PILA INICIALIZADA....");
		     gotoxy(12,13);
		     printf("DIGITE 0 y <<ENTER>> PARA CONTINUAR  ");
		      do{
		       Opc=getchar();
			}while (Opc!='0');
		}
		 else{
		   clrscr();
		    printf ("LISTA YA INICIALIZADA DIGITE 0 y <<ENTER>> PARA CONTINUAR ");
		     do{
		      Opc=getchar();
		      }while (Opc!='0');
		 }
	       break;


      case '2':if(sw==1){
		  do{
		  clrscr();
		  gotoxy(4,6);
		  printf("DIGITE INFORMACION:  ");
		      scanf("%f",&Inf);
		      Insertar(&tope,&Avail,Inf,&base);
		      gotoxy(4,8);
		      printf("DESEA INSERTAR MAS INFORMACION (S/N):   ");
		      do{
			op=getchar();
		      }while(op!='s' && op!='S' && op!='n' && op!='N');
		      }while(op=='s'|| op=='S');
		       gotoxy(6,10);
		       printf("DIGITE 0 Y <<ENTER>> PARA CONTINUAR  ");
			do{
			 Opc=getchar();
			  }while (Opc!='0');
			 }
			 else{
		  clrscr();
		   printf ("LLE NO CREADA... DIGITE 0 Y <<ENTER>> PARA CONTINUAR  ");
		    do{
		     Opc=getchar();
		     }while (Opc!='0');
		}
		break;

      case '3':if(sw==1){
		clrscr();
		 gotoxy(4,6);
		 printf ("\n  DIGITE INFORMACION DEL NODO A CANCELAR: ");
		  scanf ("%f", &Inf);
		   Cancelar(&tope,&Avail,Inf);
		    gotoxy(4,8);
		    printf("DIGITE 0 Y <<ENTER>> PARA CONTINUAR  ");
		     do{
		      Opc=getchar();
		       }while (Opc!='0');

		}
		 else{
		   clrscr();
		    printf ("LLE NO CREADA...DIGITE 0 Y <<ENTER>> PARA CONTINUAR  ");
		     do{
		      Opc=getchar();
		      }while (Opc!='0');

		 }
	       break;
	case '4':if(sw==1){
		  clrscr();
		   gotoxy(4,6);
		   printf("\n\nLISTA LINEAL ENLAZADA\n");
		   Consultar(tope);
		    gotoxy(15,10);
		     printf ("\n DIGITE 0 Y <<ENTER>> PARA CONTINUAR  ");
		      do{
		       Opc=getchar();
		       }while (Opc!='0');
		}
		 else{
		  clrscr();
		   printf ("LLE NO CREADA...DIGITE 0 Y <<ENTER>> PARA CONTINUAR  ");
		       do{
			 Opc=getchar();
		       }while (Opc!='0');

		break;
	   default: break;
	}
       }
   }while (Opc !='5');
   clrscr();
    gotoxy(20,8);
      printf (" FIN DEL PROGRAMA.... ");
  getch();
}



