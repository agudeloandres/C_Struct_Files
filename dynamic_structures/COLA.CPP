  # include <iostream.h>
  # include <conio.h>
  # include <stdio.h>
  # include <dos.h>
  # include <string.h>
  # include <c:\borlandc\bin\dinami~1\cola.h>

		   //PROGRAMA PARA MANEJO DE PILAS O STACK

  void main()
{
  char opcion;
  unsigned int sw;
  queue *base, *tope, *max,min;
  float inf;

		   //CREACION DEL MENU
				 //sw=0 cola no inicializada
				 //sw=1 cola inicializada
    sw=0;
   do{

     textcolor(15);
     textbackground(1);
     clrscr ();
     marco();
     gotoxy(10,4);
     printf("      MENU PRINCIPAL PARA EL MANEJO DE COLAS O QUEUE ");
     gotoxy(15,5);

     gotoxy(15,8);
     printf("    1.   INICIALIZAR COLA.");
     gotoxy(15,10);
     printf("    2.   CREAR COLA.");
     gotoxy(15,12);
     printf("    3.  CANCELAR NODO.");
     gotoxy(15,14);
     printf("    4.  MOSTRAR NODOS DE LA COLA.");
     gotoxy(15,16);
     printf("    5.  SALIR.");
     gotoxy(15,19);
     printf(" DIGITE OPCION :  ");

   do {
       opcion = getchar();

   } while (opcion<'0' && opcion<'5');

   switch(opcion){

	case '1' :if (sw == 0){
				sw=1;

		    //INICIALIZACION DE LA COLA

		      inicializar_Queue(&base,&tope,&max);
		      clrscr();
		      printf(" COLA INICIALIZADA.");
		      getch();
		  }
		   else	{
		      clrscr();
		      printf(" COLA YA FUE DEFINIDA.");
		      getch();
		   }
		    break;
		    //INSERTAR NODOS EN LA COLA
	case '2' :if (sw == 1){
		      clrscr();
		      printf("\n DIGITE INFORMACION DEL NODO: ");
		      scanf("%f",&inf);

		      insertar_queue( &tope,max,inf);
		      clrscr();
		      printf("\n\tNODO %.f INSERTADO.\n\n\tPULSE <ENTER> PARA CONTINUAR.",inf);
		      getch();
		  }
		   else{
		      clrscr();
		      printf("\n COLA NO INICIALIZADA ...PULSE <ENTER>...CONTINUE");
		      getch();
		   }
		    break;
		    //CANCELACION DE NODOS EN LA COLA
	case '3' :if (sw == 1){
		      clrscr();
		      printf("\n NODO DE LA COLA FUE CANCELADO !! ");
		      printf("\n CANCELACION DEL NODO POR LA BASE !");
		      getch();
		      //scanf("%f",&inf);
		      cancelar_queue(&tope,&base,&inf);

		  }
		   else{
		      clrscr();
		      printf("\n COLA NO INICIALIZADA ");
		      getch();
		   }
		    break;
	case '4' :if (sw == 1){
		      clrscr();
		      printf("\nCOLA DE NODOS:\n\n");
		      consulta_queue(&base,tope,&inf);
		      printf("\n\n PULSE <ENTER> PARA CONTINUAR.");
		      getch();
		  }
		   else{
		      clrscr();
		      printf("\n COLA NO DEFINIDA PULSE <ENTER> PARA CONTINUAR");
		      getch();
		   }
		     break;
	  default :break;
	}
  } while (opcion != '5');
		      clrscr();
		      printf("\n FIN DEL PROCESO.PULSE <ENTER> PARA SALIR.");
		      getch();
}



