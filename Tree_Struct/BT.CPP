//PROGRAMA PARA EL MANEJO DE UN ARBOL B(T) BINARIO DE BUSQUEDA
// T= Es Apuntador o cabeza del nodo y el unico elemento que se conoce del arbol.
// Avail= Es un apuntador, que es el espacio disponible.
//P,Q,r= son apuntadores, que contienen la direccion de memoria de un nodo.

#include<conio.h>
#include <stdio.h>
#include<stdlib.h>
#include <c:\borlandc\bin\arboles\bt.h>


void main()
{
char *Opc=NULL,op,o,*op1=NULL;
unsigned int sw,sw2=0;
BT *T,*Avail,*Q,*r,*P;
int Inf,men,submen,op2,Opc2;

//CREACION DEL MENU
sw=0;

men:
do{
    menu();

   gets(Opc);
    Opc2=atoi(Opc);

   switch(Opc2){


      case 1:if(sw==0){
		 sw=1;
		  clrscr();
		   T=NULL;
		    Avail=NULL;
		     gotoxy(10,11);
		     marco();
		     gotoxy(22,12);
		     printf ("ARBOL INICIALIZADO !!! ");
		     getch();
		}
		 else{
		   clrscr();
		    marco();
		    gotoxy(22,12);
		    printf ("ARBOL YA INICIALIZADO !!!");
		    getch();
		 }
	       break;


      case 2:if(sw==1){
		  sw2=1;
		  do{
		  clrscr();
		  marco();
		  gotoxy(4,6);
		  printf("DIGITE INFORMACION:  ");
		      scanf("%d",&Inf);
		      Insertar(&T,Inf,&Avail,&Q,&r);
		      gotoxy(4,8);
		      printf("DESEA INSERTAR MAS INFORMACION (S/N):   ");
		      do{
			op=getchar();
		      }while(op!='s' && op!='S' && op!='n' && op!='N');
		      }while(op=='s'|| op=='S');

		    }
			 else{
		  clrscr();
		   marco();
		   gotoxy(27,12);
		   printf ("ARBOL NO CREADO !!! ");
		   getch();
		}
		break;

      case 3:if(sw==1){
		 if(sw2==1){
		  clrscr();
		  marco();
		  gotoxy(4,6);
		  printf ("  DIGITE INFORMACION DEL NODO A CANCELAR: ");
		  scanf ("%d", &Inf);
		  Cancelar(&T,&Avail,Inf);
		  }
		  else{
		    marco();
		    gotoxy(22,12);printf("ERROR DE UNDERFLOW !!!....ARBOL VACIO !!");
		    getch();
		   }

		}
		 else{
		   clrscr();
		    marco();
		    gotoxy(25,12);
		    printf ("ARBOL NO CREADO !!!");
		    getch();
		 }
	       break;
	case 4:if(sw==1){
		   if(T==NULL){
		      marco();
		      gotoxy(22,12);printf("ERROR DE UNDERFLOW !!!...ARBOL VACIO !!");
		      getch();
		    }
		    else{
		  clrscr();
		   P=T;
		   submen:
		   do{

		     submenu();
		     gets(op1);op2=atoi(op1);

		     switch(op2){

		    case 1:
		      marco();
		      gotoxy(15,5);
		      printf("ARBOL B(T) : ");
		      Preorden(P);
		      getch();
		      goto submen;
		     case 2:
			marco();
			gotoxy(15,5);
			printf("ARBOL B(T) : ");
			Inorden(P);
			getch();
			goto submen;
		     case 3:
		       marco();
		       gotoxy(15,5);
		       printf("ARBOL B(T) : ");
		       Postorden(P);
		       getch();
		       goto submen;
		     case 4:

		       goto men;

		       default:break;
		     }

		     }while(o !=4);
		   } //Fin else

		   }
		   else {
		   marco();
		   gotoxy(25,12);
		   printf("ARBOL NO CREADO !!!");
		   getch();
		   }

	    } //Fin del Switch

   }while (Opc2 != 5);
   clrscr();

} //Final



