#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <c:\borlandc\bin\dinami~1\pilas2.h>
//PROGRAMA PARA EL MANEJO DE PILAS
void main ()
{
char opcion;
unsigned int sw;
stack *base, *tope, *max;
float inf;

//CREACION DEL MENU
sw = 0;
do{
	clrscr();
        marco();
	gotoxy (10,3);
	textbackground(BLUE);
	textcolor(YELLOW);
	printf ("         MENU PRINCIPAL PARA EL MANEJO DE PILAS");
	gotoxy (15,6);
	printf ("   1.  Inicializar STACK");
	gotoxy (15,9);
	printf ("   2.  Insertar nodo (PUSH)");
	gotoxy (15,12);
	printf ("   3.  Cancelar nodo (POP)");
	gotoxy (15,15);
	printf ("   4.  Consultar nodos de la pila");
	gotoxy (15,18);
	printf ("   5.  Salir");
	gotoxy (15,21);
	printf ("   Digite su opcion:     ");
	gotoxy(39,21);
	do{
		opcion = getchar();
	  }while (opcion<'0' && opcion>'6');
	switch (opcion){
		case '1': if (sw == 0){
			 sw = 1;
			 inicializar_stack (&base,&tope,&max);


				}
			  else{
			 clrscr();
			 printf ("PILA YA CREADA...<enter>");
			 getch();
				}
			  break;
		case '2': if (sw == 1){
			 clrscr();
			 printf ("DIGITE LA INFORMACION A INSERTAR =");
			 scanf ("%f", &inf);
			 push(&tope,max,inf);
				}
			  else{
			 clrscr();
			 textcolor(RED+BLINK);
			 printf ("PILA NO DEFINIDA...<enter>");
			 getch();
				}
			break;
		case '3': if (sw == 1){
			 clrscr();
			 gotoxy (10,2);
			 pop(&tope,base,&inf);
			 printf ("EL NODO %.1f CANCELADO ES ...<enter>",inf);
			 getch();
				 }
				else{
			 clrscr();
			 textcolor(RED+BLINK);
			 printf ("PILA NO DEFINIDA...<enter>");
			 getch();
				 }
				break;
		case '4': if (sw == 1){
			 clrscr();
			 consultar_stack (base,&tope,max);
			 printf ("\n <enter>");
			 getch();
				 }
				else{
			 clrscr();
			 printf ("PILA NO DEFINIDA...<enter>");
			 getch();
				 }
				break;
		default :
				break;
	}
  }while (opcion != '5');
clrscr();
printf ("Fin del proceso");
getch();
}

