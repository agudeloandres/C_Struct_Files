# include <f:cuadro.h>
# include <f:cuadr.h>
# include <f:submenu.h>
#include <stdio.h>
#include <conio.h>
#include <a:rut.h>
 main()
{
  B_TREE *t,*q,*p,*avail;

  unsigned int sw=0;

  char opcion,opcion1;

  float inf,info;

  sw=0;
  do{
     textcolor(15);
clrscr();
cuadro();
textbackground(1);
textcolor(15);
gotoxy(35,5);
textcolor(350);
cprintf(" MENU PRINCIPAL ");
textcolor(15);
gotoxy(33,2);
textcolor(350);
cprintf(" ARBOL DE BUSQUEDA ");
textcolor(350);
gotoxy(20,8);
cprintf("1  Inicializar            ");
gotoxy(20,10);
cprintf("2  Insertar    ");
gotoxy(20,12);
cprintf("3  Mostrar   ");
gotoxy(20,14);
cprintf("4  Eliminar  ");
textcolor(11);
gotoxy(20,16);
cprintf("5  Terminar ");
gotoxy(50,22);
cprintf(" pallares guerrero william ");
gotoxy(52,23);
cprintf(" ingenieria de sistemas");
gotoxy(20,20);
textcolor(15);
cprintf("DIGITE OPCION:   ");
textcolor(15);
textcolor(11);

     do{
	opcion=getchar();
     }while(opcion<'0' && opcion>'4');

      switch (opcion){
	case '1':if (sw==0){
		 sw=1;
		 t=0;
		 clrscr();
		 cuadr();
		 gotoxy(29,12);
		 textcolor(350);
		 cprintf(" ARBOL INICIALIZADO ");
		 menssege();
		 }
		 else{
		 clrscr();
		 gotoxy(17,13);
		 printf("ERROR  EL ARBOL NO  ESTA INICIALIZADO ");
		 menssege();
		 }
		 break;

	case '2': if (sw==0){
			clrscr();
			gotoxy(17,13);
			printf("ERROR  EL ARBOL NO  ESTA INICIALIZADO ");
			menssege();
		   }
		    else{
			 clrscr();
			 insertar(&inf);
			 crear_arbol_busqueda(&t,inf);

		  }
		   break;

	case  '3':if (sw==0){
		     clrscr();
		     gotoxy(17,13);
		     printf("ERROR  EL ARBOL NO  ESTA INICIALIZADO ");
		     menssege();
		   }
		   else{
		       do{

		   clrscr();
		   gotoxy (30,10);
		   printf ("      ORDENAMIENTO     ");
		   gotoxy(33,12);
		   printf("1- PREORDEN");
		   gotoxy(33,14);
		   printf("2- INORDEN");
		   gotoxy(33,16);
		   printf("3- POSTORDEN");
		   gotoxy(33,18);
		   printf("4- RETORNAR");
		   gotoxy(33,22);
		   printf(" DIGITE LA OPCION : ");
		   gotoxy(53,22);
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
			menssege();
			break;

		  case '2':
			clrscr();
			gotoxy(25.5,5);
			printf("EL RECORRIDO  EN INORDEN ES:\n");
			gotoxy(25,9);
			inorden(t);
			menssege();
			break;
		  case '3':
			clrscr();
			gotoxy(25.5,5);
			printf("EL RECORRIDO EN POSTORDEN ES:\n");
			gotoxy(25,9);
			postorden(t);
			menssege();
			break;
			default:break;
		}
		 }while(opcion1!='4');
	      }
	       break;
       case '4':if (sw==0){
		     clrscr();
		     gotoxy(17,13);
		     printf("ERROR  EL ARBOL NO  ESTA INICIALIZADO ");
		     menssege();
		   }
		   else{
		if(t==0){
		clrscr();
		gotoxy(17,14);
		printf ("ARBOL VACIO NO  CANCELAR ");
		getch();
		}

		else{
		printf ("DIGITE EL ELEMENTO A CANCELAR");
		 cancelar(&info);
		 remover_nodo_arbol(&t,info,avail);
		  }
		}
		break;
		default:break;
	       }
	      }while(opcion !='5');
	      clrscr();

	    }



