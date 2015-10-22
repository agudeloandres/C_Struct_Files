#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>
# include <a:\rutpilas.h>

//PROGRMA PARA EL MANEJO DE PILAS

void main()
{
int *base, *tope, *max, *li;
unsigned int sw;
char opcion;
int n,Inf;

//CREACION DEL MENU
sw=0;
do{
  clrscr();
  gotoxy(20,2);
  printf (" MENU PRINCIPAL");
  gotoxy (20,3);
  printf ("MANEJO DE PILAS");
  gotoxy (15,5);
  printf (" 1 - CREAR PILA");
  gotoxy (15,7);
  printf (" 2 - AGREGAR NODO - PUSH");
  gotoxy (15,9);
  printf (" 3 - CANCELAR NODO- POP ");
  gotoxy (15,11);
  printf (" 4 - MOSTRAR PILA ");
  gotoxy (15,12);
  printf (" 5 - SALIR \n");
  gotoxy (15,14);
  printf ("POR FAVOR DIGITE LA OPCION DESEADA");

  do{
    opcion = getchar();
    }while (opcion<'0' && opcion >'5');
     switch (opcion){
	     case '1': if (sw==0){
			  sw=1;
			  clrscr(); 

			  //DEFINICION ESPACIO DISPONIBLE

	                   printf (" DIGITE EL MAXIMO NUMERO DE NODOS DE LA PILA");
                           do{
		             scanf  ("%d",&n);
			     }while (n<=0);
			     crear_pila (&base, &tope, n);
			     max=maximo (base,n);
			     printf ("   base=%04x:%04x",FP_SEG(base),FP_OFF(base) );
			     printf ("   tope=%04x:%04x",FP_SEG(tope),FP_OFF(tope) );
			     printf ("\n  maximo=%04x:%04x",FP_SEG(max),FP_OFF(max) );
			     printf ("\n\n DIGITE 0 Y <ENTER> CONTINUA");

			     do{
				opcion=getchar();
				}while (opcion !='0');

		       }
		       else{
			   clrscr();
			   printf("PILA YA CREADA.. DIGITE 0 Y <ENTER> CONTINUA");

			   do{
			     opcion=getchar();
			     }while (opcion !='0');
                            }
                            break;

	     case '2': if (sw==1){
                          clrscr(); 
                          printf ("\n DIGITE INFORMACION DE NODO A INCLUIR");
                          scanf  ("%d",&Inf);

		       }
		       else{
			   clrscr();
			   printf (" PILA NO CREADA ..DIGITE 0 Y <ENTER> CONTINUA");

			   do{
			      opcion=getchar();
			      }while (opcion !='0');
                       }
                       break;

	     case '3': if (sw==1){
			   clrscr();
			   Pop (&tope,base,&Inf);
			   printf("\n NODO CANCELADO =%d", Inf);
			   printf("\n\n DIGITE 0 Y <ENTER> CONTINUA");

			   do{
			      opcion=getchar();
			      }while (opcion !='0');
                        }	       
                        break;


	     case '4': if (sw==1){
			   clrscr();
			   Escribir_pila (base,&tope,max,n);
			   printf ("\n\n DIGITE 0 Y <ENTER> CONTINUA");

			   do{
			      opcion=getchar();
			      }while (opcion !='0');

		        }
			else {
			     clrscr();
			     printf ("PILA NO CREADA..DIGITE 0 Y <ENTER> CONTINUA ");

			     do{
				opcion=getchar();
				}while (opcion !='0');
			}

			break;		    
                        default: break;

       }

    }while (opcion !='5');
    clrscr();
    printf (" HA TERMINADO EL PROCESO");

}
     	     	        