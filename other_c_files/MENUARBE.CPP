#include <stdio.h>
#include <conio.h>
#include <F:rutiarbb.h>
 main()
{
  cod *t,*q,*p,*avail;
  int max,n,k;
  unsigned int sw=0;

  char opcion,opcion1,inf,info;

  sw=0;
  do{

     clrscr();
     gotoxy (29,2);
     printf(" °°°°°°°°°°°°°°°°°°  ");
     gotoxy (30,3);
     printf (" MENÚ PRINCIPAL ");
     gotoxy (29,4);
     printf(" °°°°°°°°°°°°°°°°°°  ");
     gotoxy(31.4,10);
     printf("1- INICIALIZACION ");
     gotoxy(31.4,12);
     printf("2- CREAR NODOS ");
     gotoxy(31.4,14);
     printf("3- MOSTRAR ");
     gotoxy(31.4,16);
     printf("4- CANCELAR");
     gotoxy(31.4,18);
     printf("5- SALIR");
     gotoxy(31.4,22);
     printf("POR FAVOR DIGITE LA OPCION DESEADA :  ");
     gotoxy(68,22);




     do{
	opcion=getchar();
     }while(opcion<'0' && opcion>'4');

      switch (opcion){
		    case '1':if (sw==0){
		    sw=1;
		    t=0;
		    clrscr();
		    printf("EL ARBOL YA ESTA  INICIALIZADO\n");
		    validar(opcion);
	      }
	      else{
		  clrscr();
		  printf("EL ARBOL YA ESTA  CREADO ");
		  validar(opcion);
	     }
	     break;

	case '2': if (sw==0){
			clrscr();
			printf("EL ARBOL NO  ESTA INICIALIZADO ");
			validar(opcion);
		   }
		    else{
			 clrscr();
			 lea_info(&inf);
			 crear_arbol_busqueda(&t,inf);
		  }
		   break;

	case  '3':if (sw==0){
		     clrscr();
		     printf("EL ARBOL NO ESTA INICIALIZADO ");
		     validar(opcion);
		   }
		   else{
		       do{

	           clrscr();
		   gotoxy (30,2);
		   printf ("");
                   gotoxy (30,3);
		   printf ("     SUBMENÚ DE ORDENAMIENTO      ");
                   gotoxy (30,4);
		   printf ("");
	           gotoxy(33,12);
	           printf("1- PREORDEN");
	           gotoxy(33,14);
	           printf("2- INORDEN");
	           gotoxy(33,16);
	           printf("3- POSTORDEN");
	           gotoxy(33,18);
	           printf("4- RETORNAR");
	           gotoxy(33,22);
	           printf("POR FAVOR DIGITE LA OPCION DESEADA : ");
	           gotoxy(69,22);
			 do{
			    opcion1=getchar();
			 }while (opcion1<'0' && opcion1>'4');
		   switch(opcion1){	 
		   case '1':
			clrscr();
			gotoxy(25.5,5);
			printf("EL RECORRIDO EN PREORDEN ES:\n");
                        gotoxy(25,9);
			preorden(t);
			validar(opcion1);
			break;

		  case '2':
	                clrscr();
			gotoxy(25.5,5);
			printf("EL RECORRIDO  EN INORDEN ES:\n");
                        gotoxy(25,9);
		        inorden(t);
			validar(opcion1);
			break;
		  case '3':
	                clrscr();
			gotoxy(25.5,5);
			printf("EL RECORRIDO EN POSTORDEN ES:\n");
                        gotoxy(25,9);
			postorden(t);
			validar(opcion1);
			break;
			default:break;
		}
		 }while(opcion1!='4');
	      }
               break;
       case '4':if(t==0){
		printf ("ARBOL ESTA VACIO POR FAVOR NO  CANCELAR ");
                }

		else{
		printf ("DIGITE LA INFORMACION A CANCELAR");
		 lea_info(&info);
		remover_nodo_arbol(&t,info,avail);
	          }
		break;
		default:break;	
	       }
	      }while(opcion !='5');
              clrscr();
    
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");     
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("      \n");
    printf("      \n");
    printf("                             \n");
    printf("               \n");
    printf("                                 \n");
    printf("                  \n");
    printf("                  \n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");

	    }


