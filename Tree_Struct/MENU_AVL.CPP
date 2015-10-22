 #include"stdio.h"
 #include"stdlib.h"
 #include"dos.h"
 #include"conio.h"
 #include"c:\borlandc\bin\arboles\avl.h"

 void  main()
 {
    int Menu( char* [], int , int , char * );
    char * Menup[]={ "  Inicializar Arbol AVL ",
		 "    Insertar Nodo       ",
		 "    Consultar Nodos     ",
		 "    Eliminar Nodos      ",
		 "    Salir a D.O.S.      ",
		};

    avl *T,*q,*p,*avail,*pp,*pivote;
    char opcion1;
    int opcion;
    int inf;
    unsigned int sw=0,SW=0;
    /*clrscr();
    textbackground(0);
    textcolor(15);*/
    int Fin= 0;
    while(Fin==0){
    textbackground(BLUE);
    textcolor( WHITE );
    clrscr();
     _setcursortype(_NOCURSOR);
    opcion=Menu(Menup,5,28,"      Menu Arbol AVL      ");
    window(1,1,80,25);
    //do{
      // menu ();
       //do{
	 // opcion=getchar();
       //}while(opcion<'0' && opcion>'5');
       switch (opcion){
	  case 0:
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
	  case 1:
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
	  case 2:
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
	  case 3:if(sw==0){
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
	 case 4: Fin=1;
         }
	 //default:break;
       }

    //}while(opcion!= '5');
   clrscr();
    T=0;
    gotoxy(30,12);
    printf("FIN DE PROCESO");
    }
    //Funciones

    //**********Funciones de menu ***********//
void Cuadro( int x, int y, int Ancho, int Alto, int Fondo, int Texto ){
	int i;
	window( x, y, x+Ancho-1, y+Alto-1 );
	textcolor( Texto );
	textbackground( Fondo );
	clrscr();

	gotoxy(1,1);
	printf("%c", 218);

	gotoxy(1,Alto);
	printf("%c", 192);

	gotoxy(Ancho,1);
	printf("%c", 191);

	gotoxy(Ancho, Alto);
	printf("%c", 217);

	for( i= 2; i<Alto; ++i ){
	  gotoxy( 1, i );
	  printf("%c", 179);
	  gotoxy( Ancho, i );
	  printf("%c", 179);
	}
	for( i= 2; i<Ancho; ++i ){
	  gotoxy( i, 1 );
	  printf("%c", 196);
	  gotoxy( i, Alto );
	  printf("%c", 196);
	}
 }



 int Menu( char* Lista[], int n, int Ancho, char *Titulo ){

	int TRes= CYAN;
	int TnRes= BLACK;
	int FRes= BLACK;
	int FnRes= LIGHTGRAY;
	int TitColor= WHITE;
	int BandColor= BLACK;

	int i;
	int x= 40-Ancho/2;
	int y= 10 ;/*12-(n/2+1);*/
	int Eleccion=0;

	Cuadro( x+1, y+1, Ancho, n+2, BLACK, BLACK );
	Cuadro( x, y-1, Ancho, n+3, FnRes, FnRes );
	textcolor( TitColor );
	gotoxy( 1, 1 );
	cprintf("%s", Titulo);
	Cuadro( x, y, Ancho, n+2, FnRes, BandColor );
	window( x+1, y+1, x+Ancho, y+n );
	textcolor( TnRes );
	for( i= 0; i< n; ++i ){
	  gotoxy( 1, i+1 );
	  cprintf("%s", Lista[i] );
	}
	textbackground(FRes);
	textcolor(TRes);
	gotoxy( 1, Eleccion+1 );
	cprintf( "%s", Lista[Eleccion] );

	while(1){
	  int Caracter;
	  gotoxy( Ancho-2, Eleccion+1 );
	  Caracter= getch();
	  if( Caracter==13 )
		 return Eleccion;
	  if( Caracter==0 ){
		 Caracter= getch();
		 if( Caracter==72 && Eleccion ){
	 textbackground( FnRes );
	 textcolor( TnRes );
	 gotoxy( 1, Eleccion+1 );
	 cprintf( "%s", Lista[Eleccion] );
	 --Eleccion;
	 textbackground( FRes );
	 textcolor( TRes );
	 gotoxy( 1, Eleccion+1 );
	 cprintf( "%s", Lista[Eleccion] );
		 }
		 if( Caracter==80 && Eleccion<n-1 ){
	 textbackground( FnRes );
	 textcolor( TnRes );
	 gotoxy( 1, Eleccion+1 );
	 cprintf( "%s", Lista[Eleccion] );
	 ++Eleccion;
	 textbackground( FRes );
	 textcolor( TRes );
	 gotoxy( 1, Eleccion+1 );
	 cprintf( "%s", Lista[Eleccion] );
		 }
	  }
	}
 }


