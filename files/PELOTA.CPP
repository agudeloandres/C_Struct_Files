/****************************************************************************
 
 Nombre: PELOTA.C
 Utilidad: Muestra la utilizaci�n de los cursores, la tecla INTRO y ESC.
 Autor: Sergio Pacho
 Fecha: 27 de septiembre de 1998
 E-mail: cworld@programando.com
 Web: http://www.programando.com/c/cworld

 Este programa es una sencilla demostraci�n de como utilizar los cursores
 para desplazar un objeto por la pantalla.
 Lo �nico que te pido es que no lo modifiques, y que se lo pases a todos tus
 amigos, colegas...
 Tambi�n puedes decir que lo has conseguido en:
 http://www.programando.com/c/cworld

****************************************************************************/

#include <dos.h>
#include <graphics.h>

char t;

void main(void)
{
	int tarj,modo,x=320,y=240,c=1;
	unsigned int segment, offst;
	detectgraph(&tarj,&modo);
	initgraph(&tarj,&modo,"c:\\tc\\bgi");
	setcolor(0);
	setfillstyle(1,c);
	do
	{
		t=inport(0x60); /* Leemos la entrada del teclado */
		switch (t)
		{
			case 28: /* Si se ha pulsado INTRO */
				if (c<15) c++;
				else c=1;
				setfillstyle(1,c); /* Cambiamos el color del c�rculo */
				break;
			case 72: /* Cursor arriba */
				y--; break;
			case 75:
				x--; break; /* Cursor izquierda */
			case 77:
				x++; break; /* Cursor derecha */
			case 80:
				y++; break; /* Cursor abajo */
		}
		fillellipse(x,y,40,40); /* dibujamos el c�rculo */

		/* Esta es una forma pr ctica de borrar la pantalla sin excesivos
			parpadeos */
		*(char far *) MK_FP(0x40,0x1a)=*(char far *) MK_FP(0x40,0x1c);
        }while(t!=1); /* Mientras no se pulse ESC */
}