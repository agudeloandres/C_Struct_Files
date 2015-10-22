/****************************************************************************

 Nombre: LISTA.C
 Utilidad: Muestra el uso de una lista para la gesti¢n din mica de la memoria.
 Autor: Sergio Pacho
 Fecha: 17 de septiembre de 1998
 E-mail: cworld@programando.com
 Web: http://www.programando.com/c/cworld

 Este programa es un ejemplo sobre la utilizaci¢n de una lista enlazada para
 la gesti¢n din mica de la memoria.

 Lo £nico que te pido es que no lo modifiques, y que se lo pases a todos tus
 amigos, colegas...
 Tambi‚n puedes decir que lo has conseguido en:
 http://www.programando.com/c/cworld

****************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <alloc.h>

void insertar(void);
void extraer(void);
void visualizar(void);

struct lista
{
        int num;
        struct lista *sig;
}*CAB=NULL,*AUX=NULL,*F=NULL,*P=NULL;

main() /* Rellenar, extraer y visualizar */
{
        char opc;
        do
        {
                clrscr( );
                gotoxy(30,8);
                printf("1.- Insertar");
                gotoxy(30,10);
                printf("2.- Extraer");
                gotoxy(30,12);
                printf("3.- Visualizar la lista");
                gotoxy(30,14);
                printf("4.- Salir");
                opc=getch( );
                switch(opc)
                {
                        case '1':
                                insertar( );
                                break;
                        case '2':
                                extraer( );
                                break;
                        case '3':
                                visualizar( );
                }
        }while (opc!='4');
}

/* A continuaci¢n insertaremos el elemento que
vamos a crear en la posici¢n que le corresponda,
teniendo en cuenta que la lista deber  quedar
ordenada de menor a mayor.El puntero P comprueba
si el campo num de un elemento es menor que el
campo num del elemento introducido.El puntero
F se quedar  apuntando al elemento de la posici¢n
anterior al elemento que hemos insertado */

void insertar(void)
{
        AUX=(struct lista *)malloc(sizeof(struct lista));
        clrscr( );
        printf("Introduce un n£mero: ");
        scanf("%d",&AUX->num);
        AUX->sig=NULL;
        if (CAB==NULL)
                CAB=AUX;
        else if (CAB->num > AUX->num)
        {
                AUX->sig=CAB;
                CAB=AUX;
        }
        else
        {
                P=F=CAB;
                while (P->num < AUX->num && P!=NULL)
                {
                        if (P==CAB) P=P->sig;
                        else
                        {
                                P=P->sig;
                                F=F->sig;
                        }
                }
                AUX->sig=F->sig;
                F->sig=AUX;
        }
}

void extraer(void)
{
        int var;
        if (CAB==NULL) return;
        clrscr( );
        printf("Introduce el n£mero a extraer: ");
        scanf("%d",&var);
        if (CAB->num==var)
        {
                P=CAB;
                CAB=CAB->sig;
                free(P);
        }
        else
        {
                P=F=CAB;
                while (P->num != var && P!=NULL)
                {
                        if (P==CAB) P=P->sig;
                        else
                        {
                                P=P->sig;
                                F=F->sig;
                        }
                }
                if (P==NULL) return;
                F->sig=P->sig;
                free(P);
        }
}

void visualizar(void)
{
        if (CAB==NULL) return;
        clrscr( );
        AUX=CAB;
        while (AUX!=NULL)
        {
                printf("N£mero: %d\n",AUX->num);
                AUX=AUX->sig;
        }
        getch( );
}