 #include"stdio.h"
 #include"stdlib.h"
 #include"dos.h"
 #include"conio.h"
 #include"c:\borlandc\bin\arboles\avl.h"

 void  main()
 {
    avl *T,*q,*p,*avail,*pp,*pivote;
    char opcion,opcion1;
    int inf;
    unsigned int sw=0,SW=0;
    textbackground(0);
    textcolor(15);
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
		       SW=1;
		       avail=0;
		       marco();
		       gotoxy(31,12);
		       printf("ARBOL INICIALIZADO");
		       validar();
		   }
		   else{
			marco();
			gotoxy(24,12);
			printf("ARBOL YA INICIALIZADO ");
			validar();
		   }
	  break;
	  case '2':
		   if (sw==0){
		      marco();
		      control_sw();
		    }
		    else{

			 marco();
			 gotoxy(24,12);
			 printf("DIGITE LA INFORMACION = ");
			 gotoxy(47,12);

			 lea_info(&inf);
			 SW=0;

			 Insertar_Avl(&T,inf);
		 }
	  break;
	  case '3':
		   if (sw==0){
		    marco();
		    control_sw();
		    }
		    else{
			 if(SW==0){
			 do{
			    submenu();
			    do{
			       opcion1=getchar();
			    }while (opcion1<'0' && opcion1>'4');

			    switch(opcion1){
				case '1':
					 marco();
					 gotoxy(20,2);
					 printf("RECORRIDO DE UN ARBOL EN PREORDEN");

					 gotoxy(20,8);
					 preorden(T);
					 validar();

				break;
				case '2':
					 marco();
					 gotoxy(23,2);
					 printf("RECORRIDO DE UN ARBOL EN POSTORDEN");
					 gotoxy(20,8);
					 postorden(T);
					 validar();

				break;
				case '3':
					 marco();
					 gotoxy(24,2);
					 printf("RECORRIDO DE UN ARBOL EN INORDEN");
					 gotoxy(23.5,8);
					 inorden(T);
					 validar();

				break;
				default:break;
			    }
			 }while(opcion1!='4');

			  }
			  else{
			  marco();
			  control_sw1();
			  }

		    }
	  break;
	  case '4':if(sw==0){
		     marco();
		     control_sw();
		    }

		    else{
		      if(SW==0){
		      marco();
		      gotoxy(24,12);
		      printf("DIGITE LA INFORMACION A CANCELAR = ");
		      lea_info(&inf);
		      clrscr();
		      remover_nodo_del_arbol_avl(&T,inf,avail,&SW);
		       }
		      else{
			  marco();
			  control_sw1();
		      }
		    }
	  break;
	 default:break;
       }

    }while(opcion!= '5');
   clrscr();
    T=0;
    gotoxy(30,12);
    printf("FIN DE PROCESO");
}

