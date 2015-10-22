#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <C:\BORLANDC\BIN\DINAMI~1\COLAS2.H>
//PROGRAMA PARA EL MANEJO DE COLAS
void main ()
{
char opcion;
unsigned int sw;
queue *base, *tope, *max, *min;
float inf;

//CREACION DEL MENU
sw = 0;
do{
	clrscr();
	marco();
	gotoxy (10,3);
	printf ("    MENU PRINCIPAL PARA EL MANEJO DE COLAS");
	gotoxy (15,6);
	printf ("1.  Inicializar QUEUE");
	gotoxy (15,9);
	printf ("2.  Insertar nodos (INSERT)");
	gotoxy (15,12);
	printf ("3.  Cancelar nodo (REMOVE)");
	gotoxy (15,15);
	printf ("4.  Consultar nodos de la cola");
	gotoxy (15,18);
	printf ("5.  Salir");
	gotoxy (15,21);
	printf ("     Digite su opcion:  [   ]");
	gotoxy(41,21);
	do{
		opcion = getchar();
	  }while (opcion<'0' && opcion>'6');
	switch (opcion){
		case '1': if (sw == 0){
			 sw = 1;
			 inicializar_queue (&min,&max,&base,&tope);
				}
			  else{
			 clrscr();
			 printf ("COLA YA CREADA...<enter>");
			 getch();
				}
			  break;
		case '2': if (sw == 1){
		  if (tope!=max){
				  clrscr();
				  printf ("DIGITE LA INFORMACION A INSERTAR =");
				  scanf ("%f", &inf);
				  insert_queue(&tope,max,base,min,inf);
			  }
			 else{
				  printf("ERROR DE OVERFLOW");
				  getch();

			  }
				}
			  else{
			 clrscr();
				 printf ("COLA NO DEFINIDA...<enter>");
			 getch();
				}
			break;
		case '3': if (sw == 1){

				 remove_queue(&tope,&base,max,min,&inf);
				 printf ("EL NODO CANCELADO ES  %.1f ...<enter>",inf );
				 getch();
				}
			  else{
			 clrscr();
			 printf ("COLA NO DEFINIDA...<enter>");
			 getch();
				 }
				break;
		case '4': if (sw == 1){
			 clrscr();
			 consultar_queue(tope,min,base,max);
			 printf ("\n <enter>");
			 getch();
				 }
				else{
			 clrscr();
			 printf ("COLA NO DEFINIDA...<enter>");
			 getch();
				 }
				break;
		default :break;
				break;
	}
  }while (opcion != '5');
clrscr();
printf ("Fin del proceso");
getch();
}

