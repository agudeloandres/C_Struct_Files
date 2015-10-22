#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <f:\program.h>
//programa para el manejo de pilas//

void main()
{

char opcion;
unsigned int sw;
estudiante *Ptr, *Avail,*P,*Q,*T;
float Inf;

//creacion del menú

sw=0;
do{
clrscr();
gotoxy(10,2);
printf("*** M E N U PRINCIPAL ** MANEJO DE LISTAS LINEALES ENLAZADAS ***");
gotoxy(15,4);
printf("1- Definir Listas Lineales Enlazadas");
gotoxy(15,6);
printf("2- Crear Listas Enlazadas");
gotoxy(15,8);
printf("3- Inserta Antes Del Nodo Con INF Dada");
gotoxy(15,10);
printf("4- Cancelar Antes Del Nodo Con INF Dada");
gotoxy(15,12);
printf("5- Mostrar Nodos De Lista");
gotoxy(15,14);
printf("6- SALIR");
gotoxy(15,16);
printf("7- Digite Opción");
do{

	opcion=getchar();
         }while (opcion'0'&& opcion<'6');
         switch (opcion){
	  case '1': if (sw==0){
	  	sw=1;
		clrscr();


		//Definicion de la LLE//

		Ptr=0;
		Avail=0;
		printf("LISTA LINEAL ENLAZADA YA DEFINIDA...Digite 0 y <Enter> continua");
		do{
		   opcion=getchar();
		   }while (opcion!= '0');
		   }
		   else {
		   clrscr();
		   printf("LISTA YA DEFINIDA...Digite 0 y <Enter> continua"';
		   do {
		   opcion=getchar();
		   } while (opcion != '0');
		  }
		break;

	  case '2': if (sw==1){
	  	crear_nodo_lle(&Ptr);
		}
	  	else{
	  	clrscr();
	  	printf("Lista NO defenida...Digite 0 y <Enter> continua");
	  	do{
	  	opcion getchar();  
		} while (opcion != '0');
		  
	  	}
	  	break;


	  case '3':if (sw==1){
	  	captura_nodo(&Inf,&T,&Avail);
	  	inserta(&Ptr,Inf,T);
	  	}
	  	else{
	  	clrscr();
	  	printf("Lista NO defenida...Digite 0 y <Enter> continua");
	  	do{
	  	opcion getchar(); 
		} while (opcion != '0');
		   
	  	}
	  	break;

	  case '4': if (sw==1){
		clrscr();
		gotoxy(10,2)
		printf("INFORMACION DEL NODO A CANCELAR");
		gotoxy(15,4);
		printf("Codigo    :  ");
		scanf("%f",&inf);
		Cancelar(&Ptr,&Avail,Inf);
                    
		}
	  	else{
	  	clrscr();
	  	printf("Lista NO defenida...Digite 0 y <Enter> continua");
	  	do{
	  	opcion getchar();  
		} while (opcion != '0');
		   }
	  	}
		break;

	  case '5':if (sw==1){
		clrscr();
		escribir_nodos_lle(Ptr);
		printf("\n\n Digite 0 y <Enter> Continua");
		do{
	  	opcion getchar();  
		} while (opcion != '0');
		}
		else{
	  	clrscr();
	  	printf("Lista NO defenida...Digite 0 y <Enter> continua");
	  	do{
	  	opcion getchar();  
		} while (opcion != '0');
		   }
	  	}
		break;
		default : break;
		}
		}while (opcion != '6');
		clrscr();
		Printf("Fin Del Proceso);
		    }