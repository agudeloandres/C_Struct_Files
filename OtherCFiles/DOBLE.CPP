

#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include "a:\doble.h"


void main()
{
char opcion;
unsigned int sw;
nodo *Avail,*Ptr;
float inf;

  //CREACION DEL MENU

  sw=0;
  do{
  clrscr();
  gotoxy(25,2);
  printf("MENU PRINCIPAL LLDE");
  gotoxy(20,6);
  printf("1- INICIALIZAR LLDE");
  gotoxy(20,8);
  printf("2- INCLUIR NODO POR (PTR)");
  gotoxy(20,10);
  printf("3- INSERTAR DESPUES DE UN NODO CONOCIDO");
  gotoxy(20,12);
  printf("4- CANCELAR NODO ");
  gotoxy(20,14);
  printf("5- CONSULTAR LISTA ");
  gotoxy(20,16);
  printf("6- SALIR");
  gotoxy(20,22);
  printf(" DIGITE OPCION:  ");
  do{
      opcion=getchar();
     }while(opcion<'0' && opcion>'6');
  switch(opcion){
	  case '1':if(sw==0){
		       sw=1;
		       clrscr();

		       Ptr=NULL;
		       Avail=NULL;
		       gotoxy(30,3);
		       printf(" LLDE INICIALIZADA");
		       gotoxy(20,6);
		       printf("\n <Enter> continua..");
		       getch();
		       }
		       else{
		       clrscr();
		       printf("LLDE YA CREADA. continua.");
		       getch();
		      }
		    break;
	  case '2':if(sw==1){
		      clrscr();
		      printf("Digite Informacion del Nodo a incluir: ");
		      scanf("%f",&inf);
		      Crear(&Ptr,&Avail,inf);
		    }
		    else{
		      clrscr();
		      printf("PILA NO CREADA. <Enter> Continua");
		      getch();
		      }
		      break;
	  case '3':if(sw==1){
		      clrscr();
		      printf("Digite informacion del nodo a buscar:\n\n");
		      scanf("%f",&inf);
		      insert_des(Ptr,&Avail,inf);
		      printf("\n\n Digite 0 y <Enter> Continua");
		      do{
			  opcion=getchar();
			 }while(opcion!='0');
		    }
		    else{
		      clrscr();
		      printf("PILA NO CREADA. <Enter> Continua");
			getch();
			}
			break;
	  case '4':if(sw==1){
		      clrscr();
		      //Escribir_Pila(Base,&Tope,Max,n);
		      cancelar(inf,&(*ptr),&(*avail));
		      printf("\n\n  <Enter> Continua");
		      getch();
		      }
		     else{
			clrscr();
			printf("PILA NO CREADA. <Enter> Continua");
			getch();
			}
			break;
	     case 5:if (sw==1){
		       clrscr();
		       consulta(Ptr);
		       printf("\n\n <enter> continua");
		       getch();
		       }
		       else{
		       clrscr();
		       printf("Lista no definida");
		       getch();
		       }
		       break;
	  default : break;
       }
       }
   }while(opcion!='6');
   clrscr();
   gotoxy(28,14);
  // delete Avail;
   printf("F I N   D E L  P R O C E S O");

   }

