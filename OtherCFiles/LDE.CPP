                                   
// PROGRAMA PARA EL MANEJO DE DOBLES COLAS

#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <a:\rlde.h>

void main()
{
char opcion,opcion1,opcion2,opcion3;
unsigned int sw;
int *tope, *base, *lo, *max,*max1;
int n, inf;

//CREACIÓN DEL MENÚ

sw=0;
do{
   clrscr();
   gotoxy (30,2);
   printf ("");
   gotoxy (30,3);
   printf (" MENÚ PRINCIPAL ");
   gotoxy (30,4);
   printf ("");
   gotoxy (15,8);
   printf ("1.- CREAR DOBLE COLA");
   gotoxy (15,10);
   printf ("2.- INSERTAR NODO EN LA DOBLE COLA");
   gotoxy (15,12);
   printf ("3.- CANCELAR NODO EN LA DOBLE COLA");
   gotoxy (15,14);
   printf ("4.- MOSTRAR DOBLE COLA");
   gotoxy (15,16);
   printf ("5.- SALIR");
   gotoxy (15,19);
   printf ("POR FAVOR DIGITE LA OPCION DESEADA :  ");


   do{
     opcion=getchar ();
     }while(opcion<'0' && opcion <'5');
     switch (opcion){

     case '1': if(sw==0){
		  sw=1;
		  clrscr();
		  //DEFINICIÓN DE ESPACIO DISPONIBLE
                  gotoxy(10,5);
		  printf ("DIGIE EL MÁXIMO NÚMERO DE NODOS DE LA LISTA :  ");
		  do{
                    scanf ("%d",&n);
                    
		    }while (n<=0);
		    
		    Crear_DQ(&base,&tope,&lo,n);
		    max=maximo (lo,n);
                    gotoxy(10,7);
		    printf ("\n Lo   =%04X:%04X",FP_SEG(lo),FP_OFF(lo));
		    printf ("\n Base =%04X:%04X",FP_SEG(base),FP_OFF(base));
		    printf ("\n Tope =%04X:%04X",FP_SEG(tope),FP_OFF(tope));
		    printf ("\n Max  =%04X:%04X",FP_SEG(max),FP_OFF(max));
                    gotoxy(10,12);
		    printf ("DIGITE 0 Y <ENTER> CONTINUA :  ");
                    
		    do{
		      opcion= getchar();
		      }while (opcion!='0');
               }
	       else{
		   clrscr();
                   gotoxy(10,10);
		   printf ("PILA YA CREADA...  DIGITE 0 Y <ENTER> CONTINUA :  ");
		   do{
		     opcion=getchar ();
		     }while (opcion!='0');
	       }	      
	       break;

     case '2':if(sw==1){
                 do{
		 clrscr();
		 gotoxy(15,6);
		 printf ("1.- INSERTAR NODO POR TOPE");
		 gotoxy(15,8);
		 printf ("2.- INSERTAR NODO POR BASE");
		 gotoxy(15,10);
		 printf ("3.- RETORNAR MENU PRINCIPAL");
		 gotoxy(15,13);
		 printf ("POR FAVOR DIGITE LA OPCION :  ");
                 
		 do{
		   opcion1=getchar();
		 }while (opcion1<='0' && opcion1>'3');
		 switch(opcion1){
                 case '1':    clrscr();
                              gotoxy(10,5);
			      printf ("DIGITE INFORMACION DEL NODO A  INCLUIR :  ");
			      scanf("%d",&inf);
			      
			      Insertt(lo,base,&tope,n,inf);
			
				 
		           
			   break;


		 case '2': 
			     clrscr();
                             gotoxy(10,5);
			     printf ("DIGITE INFORMACION DEL NODO A INCLUIR :  ");
			     scanf ("%d",&inf);
			     Insertb(lo,&base,tope,n,inf);
			     break;

		   default:break;
		   }

		   }while (opcion1!='3');
		 }
		 else{
		      clrscr();
                      gotoxy(10,10);
		      printf("DQ NO CREADA ... DIGITE 0 Y <ENTER> CONTINUA :  ");   
		      do{
			 opcion=getchar();
			}while (opcion!='0');
		 }
     break;
     case '3': if (sw==1){
                   do{
		   clrscr();
		   gotoxy(15,6);
		   printf ("1.- REMOVER O CANCELAR POR TOPE");
		   gotoxy(15,8);
		   printf ("2.- REMOVER O CANCELAR POR BASE");
		   gotoxy(15,10);
		   printf ("3.- RETORNAR AL MENÚ PRINCIPAL ");
		   gotoxy(15,13);
		   printf ("POR FAVOR DIGITE LA OPCION DESEADA :  ");
                   
		   do{
		     opcion2=getchar();
		   }while(opcion2<='0' && opcion2>'3');
		   switch (opcion2){

		   case '1': 
		   
			     Removet(lo,base,&tope,n,&inf);
			    // Removet(lo,base,&tope,n,inf);

			    
			     break;

		   case '2': 

				
			     Removeb(&base,tope,lo,n,&inf);

			     
			     
			     break;
		       default:break;
		       }
		       }while (opcion2!='3');
		      }
		       else{
		      clrscr();
                      gotoxy(10,10);
		      printf("DQ NO CREADA ... DIGITE 0 Y <ENTER> CONTINUA :  ");
		      do{
			 opcion=getchar();
			}while (opcion!='0');
		      }
                      break;
		   case '4': if (sw==1){
                                 do{
				 clrscr();
		          	 gotoxy(15,6);
		   		 printf ("1.- MOSTRAR POR TOPE");
		   		 gotoxy(15,8);
		   		 printf ("2.- MOSTRAR POR BASE");
		   		 gotoxy(15,10);
			         printf ("3.- RETORNE AL MENU PRINCIPAL ");
		    		 gotoxy(15,13);
		   		 printf ("POR FAVOR DIGITE LA OPCION DESEADA :  ");
                   
		   		 do{
		     		    opcion3=getchar();
		   		 }while(opcion3<='0' && opcion3>'3');
		   		  switch (opcion3){

			case '1': 

				 //ribir_por_tope(lo,&base,&tope,max,n);
				//Removet(lo,base,&tope,n,inf);
                                /*gotoxy(10,10);
				printf ("DIGITE 0 Y <ENTER> CONTINUA :  ");
				do{
				  opcion3=getchar();
				}while (opcion3!='0');*/
			     
			     break;

		   case '2': 
				clrscr();
				 //escribir_por_base(lo,&base,tope,max,n);
				//Removeb(&base,tope,lo,n,inf);
				gotoxy(10,10);
				printf ("DIGITE 0 Y <ENTER> CONTINUA :  ");
				do{
				  opcion3=getchar();
				}while (opcion3!='0');


			     break;
		       default:break;
		       }
		       }while (opcion3!='3');
		      }
		       else{
		      clrscr();
                      gotoxy(10,10);
		      printf("DQ NO CREADA ... DIGITE 0 Y <ENTER> CONTINUA :  ");
		      do{
			 opcion=getchar();
			}while (opcion!='0');
		      }
			       
			     break;
		       default:break;
		       }
		       }while (opcion!='5');
			clrscr();
			gotoxy(35,10);
			printf("FIN DEL PROCESO");
		       }
