


  # include <stdio.h>
  # include <conio.h>
  # include <dos.h>
 // # include <f:\gprupila.h>
  # include <dos.h>

   // programa que maneja menu de pila lls

   void main ( )
   {

   int *base, *tope, *avail, *max ;
   int n,inf,crear_pila;
   unsigned int sw;
   char opcion;

   // creacion del menu de pila lls

   sw=0;
    do{
     clrscr();
      gotoxy (35,2);
      printf ("M  E  N  U ");
      gotoxy (32,3);
      printf (" MANEJO DE PILAS");
      gotoxy (15,6);
      printf ("1_CREAR PILA");
      gotoxy (15,8);
      printf ("2_INCLUIR NODO EN UNA PILA(PUSH)");
      gotoxy (15,10);
      printf ("3_CANCELAR NODO EN UNA PILA(POP)");
      gotoxy (15,12);
      printf ("4_MOSTRAR PILA");
      gotoxy (15,14);
      printf ("5_ SALIR\n\n");
    //  gotoxy (15,20);
      printf ("DIGITE OPCION : ");
       do{
	opcion=getchar ( );
	}while ( opcion<'0' && opcion>'5');
	switch(opcion){

	 case '1': if (sw==0){
		   sw=1;
		   clrscr ( );
		   // definir el espacio disponible

		   printf("DIGITE EL MAXIMO NUMERO DE NODOS DE LA LISTA");
		    do {
		     scanf ("%d",&n);
		    }while (n<=0);
		     crear_pila (&base,&tope,n);
		     max=Maximo (base,n);
		     printf ("  BASE=%04X:%04X\n",FP_SEG(base),FP_OFF(base));
		     printf ("  TOPE=%04X:%04X\n",FP_SEG(tope),FP_OFF(tope));
		     printf ("\n MAXIMO=%04X:%04X\n",FP_SEG(max),FP_OFF(max));
		     printf ("\n  DIGITE 0 Y <ENTER> CONTONUA");
		     do{
		     opcion=getchar ( );
		     }while (opcion !='0');
		    }
		  else {
		  clrscr ( );
		  printf ("PILA YA CREADA.. DIGITE O Y <ENTER> CONTINUA");
		   do {
		    opcion=getchar();
		    }while (opcion !='0');
		  }
		  break;


	 case '2':  if (sw==1){
		     clrscr();
		      printf ("\n DIGITE INFORMACION DEL NODO A INCLUIR");
		      scanf ("%d",&inf);
		      Push(&tope,max,inf);
		    }
		  else {
		   clrscr();
		     printf ("PILA NO CREADA.. DIGITE 0 Y <ENTER> CONTINUA");
		      do{
		       opcion=getchar ( );
		      }while (opcion !='0');
		    }
		    break;


	case '3':   if (sw==1){
		     clrscr();
		      Pop (&tope,base,&inf);
		      printf ("\n NODO CANCELADO=%d",inf);
		      printf ("\n \n DIGITE 0 Y <ENTER> CONTINUA");
		       do{
			opcion=getchar ( );
		       }while (opcion!='0');

		    }
		   else{
		    clrscr();
		     printf ("PILA NO CREADA.. DIGITE 0 Y <ENTER> CONTINUA");
		      do {
		       opcion=getchar ( );
		      }while (opcion!='0');
		     }
		     break;

	case '4': if (sw==1){
		    clrscr ();
		     escribir_Pila(base,&tope,max,n);
		     printf ("\n\n DIGITE O Y <ENTER> CONTINUA");
		      do{
		       opcion=getchar ( );
		      }while (opcion !='0');
		     }
		    else {
		     clrscr();
		      printf ("PILA NO CREADA.. DIGITE 0 Y <ENTER> CONTINUA");
		       do{
			opcion=getchar ( );
		       }while (opcion !='0');
		      }
		      break;

	       default : break;

	 }
	}while (opcion != '5');
	 clrscr();
	  gotoxy(35,12);
	  printf ("FIN PROCESO");
	  delay(700);
	}