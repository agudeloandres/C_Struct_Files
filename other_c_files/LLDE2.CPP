#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include "C:\BORLANDC\BIN\DINAMI~1\LLDE.H"

// PROGRAMA PARA MANEJO DE LISTA LINEAL DOBLEMENTE ENLAZADAS (LLDE)

void main()
{
  nodo_LLDE *Ptr,*Avail;
  char opcion,op1;
  unsigned int sw;
  float inf;
  int i;


  //CREACION DEL MENU

  sw=0;

  do{
    menu();
    do{
      opcion=getch();

    }while(opcion<'0' && opcion>'4');
  switch(opcion){
	      case '1':if(sw==0){
		      sw=1;
		       Ptr=0;
		       Avail=0;
		      marco();
		      gotoxy(22,12);
		      printf("LISTA DOBLEMENTE ENLAZADA INICIALIZADA.....!!");
		      getch();


		    }
		    else{
		      marco();
		      gotoxy(21,12);
		      printf("LISTA YA CREADA....!!!");
		      getch();

			}
			break;

	      case '2':if(sw==1){
		      do{
			submenu();
		       do{
			  op1=getch();
			 }while(op1<'0' && op1>'3');
		      switch(op1){
		      case '1':  marco();
				 gotoxy(25,12);
				 printf("DIGITE INFORMACION DEL NODO A INCLUIR : ");
				 scanf("%f",&inf);
				 Crear(&Ptr,&Avail,inf);
				 break;
		      case '2':  marco();
				 gotoxy(25,12);
				 printf("DIGITE INFORMACION DEL NODO A BUSCAR : ");
				 scanf("%f",&inf);
				 Insertar(Ptr,&Avail,inf);
				 break;
			 default:break;
			}
		     }while(op1!='3');

		    }
		    else{
		      marco();
		      gotoxy(21,12);
		      printf("LISTA NO CREADA...!!!");
		      getch();

			}
			break;
       case '3':if(sw==1){

		      if(Ptr==NULL){
			 marco();
			 gotoxy(23,12);
			 printf("LISTA VACIA....!!!....UNDERFLOW");
			 getch();
		       break;
		       }
		      marco();
		      gotoxy(23,12);
		      printf("DIGITE NODO A CANCELAR = ");
		      scanf("%f",&inf);
		      Cancelar(&Ptr,&Avail,inf);
		      //printf("\n NODO CANCELADO = %2.1f",inf);
		      getch();

		    }
		    else{
		      marco();
		      gotoxy(22,12);
		      printf("LISTA NO CREADA.....!!!");
		      getch();

			}
			break;

	  case '4':if(sw==1){
		      clrscr();
		      Consulta(Ptr);
		      getch();


		     }
		     else{
			marco();
			gotoxy(22,12);
			printf("LISTA NO CREADA....!!!");
			getch();

		       }
		       break;
	  default : break;
       }

   }while(opcion!='5');
   marco();
   gotoxy(28,14);
   printf("FIN DEL PROCESO");

  }