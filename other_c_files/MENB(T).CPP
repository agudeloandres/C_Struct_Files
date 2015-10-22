//LEONIS MENDOZA GOMEZ ******* SANTA MARTA, SEPTIEMBRE 17 DE 1997
//INGINIERIA DE SISTEMAS
//UNIVERSIDAD COOPERATIVA DE COLOMBIA
//PROGRAMA QUE MANEJA ARBOLES BINARIOS
//( PREORDEN - INORDEN - POSTORDEN)

#include <stdio.h>
#include <conio.h>
#include <C:\BORLANDC\BIN\OTROS\RUTITREE.H>
 main()
{
  nom *t,*q,*p,*avail;
  int max,n,k;
  unsigned int sw=0;

  char opcion,opcion1,inf,info;

  sw=0;
  do{
     
    clrscr();
     
     gotoxy(25,5);
     printf("<<** ARBOLES ** BINARIOS ** >>");
     gotoxy(32,6);
     printf("<<* M-E-N-U *>>");
     gotoxy(15.4,8);
     printf("**************************************************");
     gotoxy(20.4,10);
     printf("1- I-N-I-C-I-A-L-I-Z-A-C-I-O-N DE NODOS ");
     gotoxy(20.4,12);
     printf("2- C-R-E-A-C-I-O-N DE NODOS ");
     gotoxy(20,14);
     printf("3- V-I-S-U-A-L-I-Z-A-C-I-O-N ");
     gotoxy(20,16);
     printf("4- C-A-N-C-E-L-A-CI-O-N DE NODOS ");
     gotoxy(20,18);
     printf("5- SALIR");
     gotoxy(15,24);
     printf("**************************************************");
     gotoxy(15,19);
     printf("**************************************************");
     gotoxy(20.4,21);
     printf("INTRUDUZCA EL NUMERO CORRESPONDIENTE");
     gotoxy(26.4,22);
     printf(" A LA OPCION DESEADA < > ");
     gotoxy(48,22);



     do{
	opcion=getchar();
     }while(opcion<'0' && opcion>'4');

      switch (opcion){
		    case '1':if (sw==0){
		    sw=1;
		    t=0;
		    clrscr();
		    gotoxy(20,15);
		    printf(" ARBOL INICIALIZADO");
		    
		    validar(opcion);
	      }
	      else{
		  clrscr();
		  gotoxy(20,15);
		  printf(" ARBOL YA ESTA  CREADO ");
		  validar(opcion);
	     }
	     break;

	case '2': if (sw==0){
			clrscr();
			gotoxy(20,15);
			printf(" ARBOL NO INICIALIZADO ");
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
		     printf(" ARBOL NO INICIALIZADO ");
		     validar(opcion);
		   }
		   else{
		       do{

		   clrscr();
	    
	      gotoxy(26,9);
	      printf(" ***<<SUB>>MENU***");       
              gotoxy(23.5,10);
	      printf("PARA MANEJO DE ORDENAMIENTO");
	      gotoxy(26,12);
	      printf("1- P-R-E-O-R-D-E-N");
	      gotoxy(26,14);
	      printf("2- I-N-O-R-D-E-N");
	      gotoxy(26,16);
	      printf("3- P-O-S-T-O-R-D-E-N");
	      gotoxy(26,18);
	      printf("4- R-E-T-O-R-N-A-R");
	      gotoxy(26,22);
	      printf("PARA INGRESAR ALGUNA OPCION ");
	      gotoxy(18,23);
	      printf("ESCRIBA EL NUMERO CORRESPONDIENTE AQUI < > \a");
	      gotoxy(58,23);
			 do{
			    opcion1=getchar();
			 }while (opcion1<'0' && opcion1>'4');
		   switch(opcion1){
		   case '1':
			clrscr();
			gotoxy(25,8);
			printf("EL RECORRIDO EN PREORDEN ES:\n");
			preorden(t);
			validar(opcion1);
			break;

		  case '2':
			clrscr();
			gotoxy(25,8);
			printf("EL RECORRIDO  EN INORDEN ES:\n");
			inorden(t);
			validar(opcion1);
			break;
		  case '3':
			clrscr();
			gotoxy(25,8);
			printf("EL RECORRIDO EN POSTORDEN ES:\n");
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
		printf ("QUE INFORMACION QUIERE CANCELAR ?");
		 lea_info(&info);
		remover_nodo_arbol(&t,info,avail);
		  }
		break;
		default:break;
	       }
	      }while(opcion !='5');
	      clrscr();
	      gotoxy(30,10);
	      printf(" PROGRAMA  FINALIZADO  ");
	      gotoxy(37,13);
	      printf("GRACIAS");
	    }


