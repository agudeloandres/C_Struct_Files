//LEONIS MENDOZA GOMEZ ******* SANTA MARTA, SEPTIEMBRE DE 1997
//INGINIERIA DE SISTEMAS
//UNIVERSIDAD COOPERATIVA DE COLOMBIA
//PROGRAMA QUE MANEJA ARBOLES BINARIOS
//( PREORDEN - INORDEN - POSTORDEN)
#include<stdio.h>
#include<conio.h>
#include<f:\arbolito.h>

 void  main()
{
   nom *T,*q,*p,*avail;
   char opcion,opcion1,inf;

  //s *tope,*base;
   unsigned int sw=0;
    do{

       menu ();
       do{
	  opcion=getchar();
       }while(opcion<'0' && opcion>'5');

       switch (opcion){
	  case '1':
		   if (sw==0){
		       T=0;
		       sw=1;
		       clrscr();
		       gotoxy(31,12);
		       printf("ARBOL INICIALIZADO");
		       validar(opcion);
		   }
		   else{
			clrscr();
			gotoxy(24,12);
			printf("ARBOL YA CREADO ");
			validar(opcion);
		   }
	  break;
	  case '2':
		   if (sw==0){
		      control_sw();
		    }
		    else{
			 clrscr();
			 gotoxy(24,12);
			 printf("DIGITE LA INFORMACION = ");
			 gotoxy(47,12);

			 lea_info(&inf);
			 clrscr();
			 gotoxy(24,12);
			 printf("EL CARACTER ES = %c",inf);
			 validar(opcion);

			 crear_arbol_busqueda(&T,inf);

		    }
	  break;
	  case '3':
		   if (sw==0){
		    control_sw();
		    }
		    else{
			 do{
			    submenu();
			    do{
			       opcion1=getchar();
			    }while (opcion1<'0' && opcion1>'4');
			    switch(opcion1){
				case '1':
					 clrscr();
					 gotoxy(23.5,2);
					 printf("RECORRIDO DE UN ARBOL EN PREORDEN");
					 preorden(T);

				break;
				case '2':
					 clrscr();
					 gotoxy(23,2);
					 printf("RECORRIDO DE UN ARBOL EN POSTORDEN");

					 postorden(T);
				break;
				case '3':
					 clrscr();
					 gotoxy(24,2);
					 printf("RECORRIDO DE UN ARBOL EN INORDEN");
					 inorden(T);
				break;
				default:break;
			    }
			 }while(opcion1!='4');
		    }
		  break;
	  case '4':if(sw==0){
		     control_sw();
		    }
		    else{
		      clrscr();
		      gotoxy(24,12);
		      printf("DIGITE LA INFORMACION A CANCELAR = ");
		      lea_info(&inf);
		      clrscr();
		      remover_nodo_del_arbol(&T,inf,avail);//,&sw);
		      }
	  break;
	 default:break;
       }
    }while(opcion!='5');
   clrscr();
    gotoxy(30,12);
    printf("FIN DE PROCESO");
}
