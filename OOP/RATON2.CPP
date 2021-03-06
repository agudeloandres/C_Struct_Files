/* Programaci�n b�sica del rat�n */
/* Por Crist�bal Tello, para la Web del Programador */
/* Vis�tala, <http://www.casarramona.com/mt/programador/index.htm> */

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

int MirarPuntero(void);
int MostrarPuntero(void);
int BotonPulsado(void);
int CorHTexto(void);
int CorVTexto(void);

void main(void)
{
 if(!MirarPuntero())
 {
	clrscr();
	printf("No tienes instalado el raton\n\n");
	exit(1);
 }
 clrscr();
 _setcursortype(_NOCURSOR);
 gotoxy(27,1);printf("Programacion basica del raton");
 MostrarPuntero();
 do
 {
	gotoxy(3,3);printf("Fila:   : %2d",CorVTexto());

gotoxy(3,4);printf("Columna : %2d",CorHTexto());
	switch(BotonPulsado())
	{
	  case 0: gotoxy(32,11);printf("Ningun boton pulsado   ");break;
	  case 1:
		 {
			gotoxy(32,11);printf("Boton izquierdo pulsado   ");
			sound(1000);delay(50);nosound();
			break;
		 }
	  case 2:
		 {
			gotoxy(32,11);printf("Boton derecho pulsado   ");
			sound(800);delay(50);nosound();
			break;
		 }
	}
 }while (!kbhit());
 _setcursortype(_NORMALCURSOR);

} //FIN



int MirarPuntero(void)
{
 asm xor ax, ax
 asm int 33h
 asm cmp ax, -1
 asm je  Existe_Raton
 return 0;
 Existe_Raton:
 return 1;
}

int MostrarPuntero(void)
{
 asm mov ax, 01h
 asm int 33h
 return 1;
}

int BotonPulsado()
{
 asm mov ax, 03h
 asm int 33h
 return _BX;
}

int CorHTexto(void)
{
 asm mov ax, 03h
 asm int 33h
 return (_CX/8)+1;
}

int CorVTexto(void)
{
 asm mov ax, 03h
 asm int 33h
 return (_DX/8)+1;
}

