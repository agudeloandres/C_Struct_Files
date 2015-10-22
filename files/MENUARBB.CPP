#include <STDIO.H>
#include <CONIO.H>
//#include <a:\accarbol.h>

void main()
{

int nom, *t, *q, *p;
int s, *tope;
int max, n, k;


unsigned int sw;
char opcion, opcion1, inf;
sw=0;


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
   printf ("1.- INICIALIZAR ARBOL");
   gotoxy (15,10);
   printf ("2.- CREAR ARBOL  ");
   gotoxy (15,12);
   printf ("3.- SUBMENU DE RECORRIDOS ");
   gotoxy (15,14);
   printf ("4.- CANCELAR");
   gotoxy (15,16);
   printf ("5.- SALIR ");
   gotoxy (15,19);
   printf ("POR FAVOR DIGITE LA OPCION DESEADA :  ");



     do{
       opcion=getchar();
       }while(opcion<'0'&& opcion>'5');

	  switch(opcion){
	    case '1': if (sw==0){
			  sw=1;

			  t=0;
			  clrscr();
			  printf("ARBOL INICIALIZADO  <DIGITE (0) Y ENTER)");
			  //validar (opcion);

			  }
			  else{
			  clrscr();
			  printf ("ARBOL YA CRREADO <DIGITE (0) Y ENTER\n");
			  //validar(opcion);

			  }
			break;
	    case '2': if (sw==0){
	                  clrscr();
			  printf("ARBOL NO INICIALIZADO <DIGITE (0) Y ENTER)");
                          //validar (opcion);
			  }
			  else{
			  clrscr();
			  gotoxy (24,12);
			  //lea_info(&inf);
			  //validar (opcion);
			  //crear_arbol_busqueda(t,inf);
			  //validar (opcion);
			  }

			break;
	    case '3' : if (sw==0){		  
                         
			  do{
                          clrscr();
                          gotoxy (30,2);
                          printf ("");
                          gotoxy (30,3);
			  printf ("    SUBMENÚ     ");
                          gotoxy (30,4);
                          printf ("");
                          gotoxy (15,8);
                          printf ("1.- RECORRIDO DEL ARBOL EN PREORDEN");
                          gotoxy (15,10);
                          printf ("2.- RECORRIDO DEL ARBOL EN POSTODEN ");
                          gotoxy (15,12);
                          printf ("3.- RECORRIDO DEL ARBOL EN INORDEN ");
                          gotoxy (15,14);
			  printf ("4.- RETORNAR AL MENÚ PRINCIPAL");
			  gotoxy (15,16);
			  printf ("POR FAVOR DIGITE LA OPCION DESEADA :  ");

			  do{
			     opcion1=getchar();
		 	     }while(opcion1<'0' && opcion>'4');
			     switch (opcion1){
			     case '1' :
				       clrscr();
				       gotoxy(24,2);
				       //preorden(t);
				       //validar(opcion1);

				       
				      break;
			     case '2' :
				       clrscr();
				       gotoxy(24,12);
				       //postorden(t);
				       //validar (opcion1);
				      
				       break;

			     case '3' :
				       clrscr();
				       gotoxy(24,12);
				       //inorden(t);
				       //validar (opcion1);
				       
				   // break;
			      
			 // }		
		

			  default:break;

                          }
			 }while(opcion1!= '4');
			  }
			break;
			default:break;
			}
			}while (opcion!='4');
                        clrscr();
			gotoxy(30,12);
			printf ("FIN DEL PROCESO");
		       
			
                        }
		
 			   
				       	        












