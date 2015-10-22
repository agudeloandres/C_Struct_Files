

// Programa para el manejo de dobles colas

#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <f:\rutdqu.h>

void main()
{
char opcion;
unsigned int sw;
int *tope, *base, *lo, *max, *li;
int n, inf;

//Menú
sw=0;
do{
   clrscr();
   gotoxy (20,2);
   printf ("MENÚ PRINCIPAL")
   gotoxy (15,4);
   printf ("1-CREAR DOBLE COLA");
   gotoxy (15,6);
   printf ("2-INSERTAR NODO EN LA DOBLE COLA");
   gotoxy (15,8);
   printf ("3-CANCELAR NODO EN LA DOBLE COLA");
   gotoxy (15,10);
   printf ("4-MOSTRAR DOBLE COLA");
   gotoxy (15,12);
   printf ("5-SALIR");
   gotoxy (15,14);
   printf (" DIGITE OPCION");

   do{
     opcion=getchar ();
     }while(opcion<'0' && opcion <'5');
     switch (opcion){

     case '1': if(sw==0){
     sw=1;
     clrscr();
     //Espacio diponible
     printf ("DIGIE EL MÁXIMO NÚMERO DE NODOS DE LA LISTA");
     do{
     scanf ("%d",&n);
     }while (n<=0);
     //Crear_DQ (&lo,&base,&tope,n);max=maximo (lo,n);
     printf ("lo=%04x:%04x",FP_SEG(lo),FP_OFF(lo));
     printf ("base=%04x:%04x",FP_SEG(base),FP_OFF(base));
     printf ("tope=%04x:%04x",FP_SEG(tope),FP_OFF(tope));
     printf ("max=%04x:%04x",FP_SEG(max),FP_OFF(max));
     printf ("\n\n DIGITE 0 Y <ENTER> CONTINUA ");
     do{
     opcion= getchar();
     }while (opcion!='0');
     }
     else{
		   clrscr();
		   printf ("PILA YA CREADA...  DIGITE 0 Y <ENTER> CONTINUA ");
		   do{
		     opcion=getchar ();
		     }while (opcion!='0');
	       }	      
	       break;

     case '2': do{                 
                 clrscr();
		 gotoxy(15,4);
		 printf ("1- INSERTAR NODO POR TOPE");
		 gotoxy(15,5);
		 printf ("2- INSERTAR NODO POR BASE");
		 gotoxy(15,6);
		 printf ("3- RETORNAR MENU PRINCIPAL");
		 gotoxy(15,8);
		 printf ("POR FAVOR DIGITE LA OPCION ");
		 do{
		   opcion=getchar();
		 }while (opcion<='0' && opcion>'3');
		 switch(opcion){

		 case '1': if (sw==1){
                 
			      clrscr();
			      printf ("\n DIGITE INFORMACION DEL NODO A  INCLUIR");
			      scanf  ("%d",&inf);
			    //  Insertt(lo,base,tope,inf);
		           }
			   else{
			       clrscr();
			       printf ("PILA NO CREADA..DIGITE 0 Y <ENTER> CONTINUA");
			       do{
				 opcion=getchar();
			       }while (opcion!='0');
			   }
			   break;


		 case '2': if(sw==1){
			     clrscr();
			     printf ("\n DIGITE INFORMACION DEL NODO A INCLUIR");
			     scanf ("%d",&inf);
			     //Insertb(lo,base,tope,inf);
			   }   
			   else{
			       clrscr();
			       printf("PILA NO CREADA...DIGITE 0 Y <ENTER> CONTINUA");
			       do{
				 opcion =getchar();
			       }while (opcion !='0');
			   }
			   break;

		   default:break;
		   }

		   }while (opcion!='3');
		    return;

     case '3': if (sw==1){
		   clrscr();
		   gotoxy(15,4);
		   printf ("1- REMOVER O CANCELAR POR TOPE");
		   gotoxy(15,5);
		   printf ("2- REMOVER O CANCELAR POR BASE");
		   gotoxy(15,6);
		   printf ("3- RETORNAR AL MENÚ PRINCIPAL ");
		   gotoxy(15,14);
		   printf ("POR FAVOR DIGITE LA OPCION DESEADA");
		   do{
		     opcion=getchar();
		   }while(opcion<='0' && opcion>'3');
		   switch (opcion){

		   case '1': if (sw==1){
				clrscr();
				Removet(lo,base,tope,inf);
				printf ("\n NODO CANCELADO = %d",inf);
				printf ("\n \n DIGITE 0 Y <ENTER> CONTINUA");
				do{
				  opcion=getchar();
				}while (opcion!='0');
			     }
			     else{
				 clrscr();
				 printf ("PILA NO CREADA... DIGITE 0 Y <ENTER> CONTINUA");
				 do{
				   opcion=getchar();
				 }while (opcion!='0');
			     }
			     break;

		   case '2': if (sw==1){
				clrscr();
				Removeb(lo,base,tope,inf);
				printf ("\n NODO CANCELADO =%d",inf);
				printf ("\n\n DIGITE 0 Y <ENTER> CONTINUA");
				do{
				  opcion=getchar();
				}while (opcion!='0');

			     }
                             else{
				  clrscr();
				  printf ("PILA NO CREADA... DIGITE 0 Y <ENTER> CONTINUA");
				 do{
				   opcion=getchar();
				 }while (opcion!='0');
			     }
			     break;
		       default:break;
		       }
		       }while (opcion!='3');
		        return;

		   case '4': if (sw==1){
				clrscr();
				Escribir_DQ(lo, base, &tope, max);
				printf ("\n\n DIGITE 0 Y <ENTER> CONTINUA");
				do{
				  opcion=getchar();
				}while (opcion!='0');

			     }
                             else{
				  clrscr();
				  printf ("PILA NO CREADA... DIGITE 0 Y <ENTER> CONTINUA");
				 do{
				   opcion=getchar();
				 }while (opcion!='0');
			     }
			     break;
		       default:break;
		       }
		       }while (opcion!='5');
			clrscr();
			printf("FIN DEL PROCESO");
		       }