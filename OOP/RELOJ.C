/****************************************************************************
 
 Nombre: RELOJ.C
 Utilidad: Es un reloj residente para entorno MS-DOS.
 Autor: Sergio Pacho
 Fecha: 4 de octubre de 1998
 E-mail: cworld@programando.com
 Web: http://www.programando.com/c/cworld
 
 Este programa es una demostraci¢n sobre como crear TSR's ( Terminate Stay
 Resident ), es decir programas que se queden residentes en memoria una vez
 haya finalizado su ejecuci¢n.No obstante le falta un peque¤o detalle.No se
 puede descargar de memoria.Si sabes como controlar en que zona de la memoria
 se carga el programa y como se puede descargar, te agradecer¡a que me lo
 dijeras.
 Una vez compilado, sal al DOS y ejec£talo.
 Este programa puede ser utilizado libremente.
 Lo £nico que te pido es que no lo modifiques, y que se lo pases a todos tus
 amigos, colegas...
 Tambi‚n puedes decir que lo has conseguido en:
 http://www.programando.com/c/cworld

****************************************************************************/

#include <dos.h>
#include <mem.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <bios.h>

#ifdef__cplusplus
        #define__CPPARGS ...
#else
        #define__CPPARGS
#endif

unsigned long far *tiempo;
unsigned long segundos;
int hor,min,seg,resto;
char hora[10];
char cad[3];
char far *p;

void interrupt otra1c(__CPPARGS); /* Esta es la int. del timer del PC */
void interrupt (*vieja1c)(__CPPARGS);

/* Funci¢n principal del TSR */
void principal(void);

void main(void)
{
        unsigned int segment, offst;

        disable(); /* Deshabilita las interrupciones */

        vieja1c=getvect(0x1c);
        setvect(0x1c,otra1c);

        enable(); /* Habilita las interrupciones hardware */

        asm{
                mov ah,34h      /* Detectamos la inactividad del DOS */
                int 21h         /* Retornar  0 si el DOS se encuentra */
                mov segment,es  /* inactivo y 1 si est  activo */
                mov offst,bx
        }

        tiempo=(char far *) MK_FP(0x0040,0x006c);
        keep(0,1000); /* Finaliza y permanece residente ( 1000 es el tama¤o */
                      /* del archivo .EXE creado.Siempre es mejor poner un poco */
                      /* m s... ) El tama¤o no se expresa en bytes.Divide el */
                      /* tama¤o entre 16 y eso es lo que tendr s que poner en la */
                      /* funci¢n keep(). */
}

void interrupt otra1c(__CPPARGS)
{
        vieja1c();
        principal();
}

/* Funci¢n principal del TSR */

void principal(void)
{
        int x,y;
        disable();
        *(char far *) MK_FP(0x40,0x1a)=*(char far *) MK_FP(0x40,0x1c); /* Limpia el buffer de teclado */
        tiempo=(unsigned long far *) MK_FP(0x0040,0x006c); /* Contamos los clicks del timer */
        segundos=*tiempo * 10/182; /* 18'2 clicks = 1 segundo */
        hor=segundos/3600;
        resto=segundos%3600;
        min=resto/60;
        seg=resto%60;
        itoa(hor,cad,10);
        if (hor<10) strcpy(hora,"0");
        else strcpy(hora,"\0");
        strcat(hora,cad);
        strcat(hora,":");
        itoa(min,cad,10);
        if (min<10) strcat(hora,"0");
        strcat(hora,"\0");
        strcat(hora,cad);
        strcat(hora,":");
        itoa(seg,cad,10);
        if (seg<10) strcat(hora,"0");
        strcat(hora,cad);
        p=(char far *) MK_FP(0xB800,0x0000);
        for (x=0;hora[x]!='\0';x++)
        {
                *(p+160*24+140+2*x) = hora[x];
                *(p+160*24+140+2*x+1) = 7;
        }
        enable();
}