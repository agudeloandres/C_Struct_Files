
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>

char* Tipos[]={"EDUCATIVO", "CONTABLE", "ENTRETENIMIENTO", "MEDICO"};


class Software{
  public:
	 char Referencia[16];
	 char Nombre[16];
	 char Autor[16];
	 int Area;
	 long int Precio;
	 int Fecha;
	 Software *Siguiente;

	 void Leer();
	 void Ver();

};



void LeerCadena(char *Buffer, int Cuantos){
  char Buff2[256];
  Buff2[0]= Cuantos;
  cgets(Buff2);
  strcpy(Buffer, Buff2+2);
  printf("\n");
}


void Software::Leer(){
  window(1,3,80,25);
  textcolor(LIGHTGRAY);
  textbackground(BLACK);
  clrscr();
  printf("Referencia del software : ");
  LeerCadena(Referencia, 9);
  printf("Nombre  : ");
  LeerCadena(Nombre, 15);
  printf("Autor   : ");
  LeerCadena(Autor, 15);
  printf("Presione el d¡gito que indica el  rea de desempe¤o...");
  printf("\n\r      Educativo---------> 0");
  printf("\n\r      Contable----------> 1");
  printf("\n\r      Entretenimiento---> 2");
  printf("\n\r      M‚dico------------> 3");
  printf("\n\r   Opci¢n: ");
  int Tecla;
  while((Tecla= getch()-48)<0 || Tecla>3);
  Area= Tecla;
  printf("%d", Area);
  printf("\n\rPrecio de venta     : ");
  scanf("%ld", &Precio);
  do{
         printf("A¤o de fabricaci¢n  : ");
	 scanf("%d", &Fecha);
	 if(Fecha<1)
                cprintf("Ingrese una valor positivo para el a¤o!\n\r");
  }while(Fecha<1);
  window(1,1,80,25);
}




void Software::Ver(){
  gotoxy(1, wherey());
  cprintf("%s", Referencia);
  gotoxy(11, wherey());
  cprintf("%s", Nombre);
  gotoxy(26, wherey());
  cprintf(" %s", Autor);
  gotoxy(42, wherey());
  cprintf(" %s", Tipos[Area]);
  gotoxy(58, wherey());
  cprintf(" %ld", Precio);
  gotoxy(69, wherey());
  cprintf(" %d", Fecha);
}

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


class ListaSoftware{
	 Software *Inicio;

  public:
	 ListaSoftware(){	Inicio= 0; }  //CONSTRUCTOR
	 void Ingresar();
	 void Eliminar();
	 void Listar();
	 void Consulta1();
	 void Consulta2();
	 void Consulta3();
	 void Consulta4();
	 void Consulta5();
}ListaSoftware;


void ListaSoftware::Consulta1(){
  textbackground(BLACK);//fondo 0...15
  textcolor(LIGHTGRAY); //texto
  clrscr();
  if(Inicio==0){
	 textcolor(WHITE);
	 cprintf("LA LISTA ESTA VACIA. ELIJA PRIMERO <INGRESAR> !!!");
	 cprintf("\n\rPresione cualquier tecla para continuar...");
	 getch();
	 return;
  }
  printf("Indicar cu ntos softwares hay por cada  rea de desempe¤o.\n\n");
  int n[4]={ 0, 0, 0, 0 };
  Software *Actual= Inicio;
  while(Actual){
	 ++n[Actual->Area];
	 Actual= Actual->Siguiente;
  }
  printf("\nEDUCATIVO:       %d", n[0]);
  printf("\nCONTABLE :       %d", n[1]);
  printf("\nENTRETENIMIENTO: %d", n[2]);
  printf("\nMEDICO:          %d", n[3]);
  printf("\n\nPresione la barra espaceadora para continuar...");
  while(getch()!=' ');
}


void ListaSoftware::Consulta2(){
  textbackground(BLACK);
  textcolor(LIGHTGRAY);
  clrscr();
  if(Inicio==0){
	 textcolor(WHITE);
	 cprintf("LA LISTA ESTA VACIA. ELIJA PRIMERO <INGRESAR> !!!");
	 cprintf("\n\rPresione cualquier tecla para continuar...");
	 getch();
	 return;
  }
  printf("Indicar cu ntos y cu les softwares hay por un autor espec¡fico.\n\n");
  char Autor[17];
  printf("Autor: ");
  LeerCadena(Autor, 15);
  int n= 0;
  Software *Actual= Inicio;
  while(Actual){
	 if(!strcmpi(Actual->Autor, Autor)){
		printf("\n%s", Actual->Nombre);
		++n;
	 }
	 Actual= Actual->Siguiente;
  }
  printf("\n\n%d softwares encontrados del autor %s.", n, Autor);
  printf("\n\nPresione la barra espaceadora para continuar...");
  while(getch()!=' ');
}


void ListaSoftware::Consulta3(){
  textbackground(BLACK);
  textcolor(LIGHTGRAY);
  clrscr();
  if(Inicio==0){
	 textcolor(WHITE);
	 cprintf("LA LISTA ESTA VACIA. ELIJA PRIMERO <INGRESAR> !!!");
	 cprintf("\n\rPresione cualquier tecla para continuar...");
	 getch();
	 return;
  }
  printf("Indicar cu ntos suman los precios por cada  rea de desempe¤o.\n\n");
  long int n[4]={ 0, 0, 0, 0 };
  Software *Actual= Inicio;
  while(Actual){
	 n[Actual->Area]+= Actual->Precio;
	 Actual= Actual->Siguiente;
  }
  printf("\nEDUCATIVO:       %d", n[0]);
  printf("\nCONTABLE :       %d", n[1]);
  printf("\nENTRETENIMIENTO: %d", n[2]);
  printf("\nMEDICO:          %d", n[3]);
  printf("\n\nPresione la barra espaceadora para continuar...");
  while(getch()!=' ');
}



void ListaSoftware::Consulta4(){
  textbackground(BLACK);
  textcolor(LIGHTGRAY);
  clrscr();
  if(Inicio==0){
	 textcolor(WHITE);
	 cprintf("LA LISTA ESTA VACIA. ELIJA PRIMERO <INGRESAR> !!!");
	 cprintf("\n\rPresione cualquier tecla para continuar...");
	 getch();
	 return;
  }
  printf("Indicar cu ntos y cu les softwares se fabricaron despu‚s de 1990.\n\n");
  int n= 0;
  Software *Actual= Inicio;
  while(Actual){
	 if(Actual->Fecha>1990){
		printf("\n%s", Actual->Nombre);
		++n;
	 }
	 Actual= Actual->Siguiente;
  }
  printf("\n\n%d softwares encontrados fabricados despu‚s del 1990.", n);
  printf("\n\nPresione la barra espaceadora para continuar...");
  while(getch()!=' ');
}



void ListaSoftware::Consulta5(){
  textbackground(BLACK);
  textcolor(LIGHTGRAY);
  clrscr();
  if(Inicio==0){
	 textcolor(WHITE);
	 cprintf("LA LISTA ESTA VACIA. ELIJA PRIMERO <INGRESAR> !!!");
	 cprintf("\n\rPresione cualquier tecla para continuar...");
	 getch();
	 return;
  }
  printf("Indicar cu l es el software m s costoso por  rea.\n\n");
  for(int i= 0; i<4; ++i){
	 printf("\n%s: ", Tipos[i]);
	 long int MaxPrecio=-1;
	 Software *Mayor= 0;
	 Software *Actual= Inicio;
	 while(Actual){
		if(Actual->Area==i && Actual->Precio>MaxPrecio){
		  MaxPrecio= Actual->Precio;
		  Mayor= Actual;
		}
		Actual= Actual->Siguiente;
	 }
	 if(Mayor)
		printf("%s (Autor: %s)", Mayor->Nombre, Mayor->Autor);
	 else
		printf("NO HAY SOFTWARES DE ESTA CATEGORIA.");
  }
  printf("\n\nPresione la barra espaceadora para continuar...");
  while(getch()!=' ');
}


void ListaSoftware::Ingresar(){
  void Centrar(char*, int);
  textbackground(BLACK);
  clrscr();
  textcolor(BLUE);
  textbackground(LIGHTGRAY);
  clreol();
  Centrar("Ingrese los datos referentes al nuevo software...", 1);
  printf("\n\n");
  textcolor(LIGHTGRAY);
  textbackground(BLACK);

  //crear el nodo...
  Software *Nuevo= new Software;
  Nuevo->Siguiente= 0;
  Nuevo->Leer();
  //Inserción en la lista...
  if(Inicio==0)
	 Inicio= Nuevo;
  else{
	 Software *Actual= Inicio, *Anterior;
	 while(Actual){
		if(strcmpi(Nuevo->Nombre, Actual->Nombre)<0)
		  break;
		Anterior= Actual;
		Actual= Actual->Siguiente;
	 }
	 Nuevo->Siguiente= Actual;
	 if(Actual==Inicio)
		Inicio= Nuevo;
	 else
		Anterior->Siguiente= Nuevo;
  }
}



void ListaSoftware::Eliminar(){
  void Centrar(char*, int);
  textbackground(BLACK);
  clrscr();
  if(Inicio==0){
	 textcolor(WHITE);
	 cprintf("LA LISTA ESTA VACIA. ELIJA PRIMERO <INGRESAR> !!!");
	 cprintf("\n\rPresione cualquier tecla para continuar...");
	 getch();
	 return;
  }

  textcolor(BLUE);
  textbackground(LIGHTGRAY);
  clreol();
  Centrar("Ingrese la referencia referente al software a eliminar...", 1);
  printf("\n\n");
  textcolor(LIGHTGRAY);
  textbackground(BLACK);

  //lectura de la referencia a borrar
  cprintf("\n\n\rReferencia: ");
  char Ref[12];
  LeerCadena(Ref, 9);
  //búsqueda del registro
  Software *Actual= Inicio, *Anterior;
  while(Actual){
	 if(strcmpi(Actual->Referencia, Ref)==0)
		break;
	 Anterior= Actual;
	 Actual= Actual->Siguiente;
  }

  if(Actual==0){
			cprintf("\n\n\rNo se encontr¢ el registro de referencia %s", Ref);
	 cprintf("\n\rPresione la barra espaceadora...");
	 while(getch()!=' ');
	 return;
  }

  if(Actual==Inicio)
	 Inicio= Actual->Siguiente;
  else
	 Anterior->Siguiente= Actual->Siguiente;
  delete Actual;
  printf("\nEliminado el registro de referencia %s", Ref);
  printf("\nPresione la barra espaceadora...");
  while(getch()!=' ');
}



void ListaSoftware::Listar(){
  void Centrar(char*, int);
  textbackground(BLACK);
  clrscr();
  if(Inicio==0){
	 textcolor(WHITE);
	 cprintf("LA LISTA ESTA VACIA. ELIJA PRIMERO <INGRESAR> !!!");
	 cprintf("\n\rPresione cualquier tecla para continuar...");
	 getch();
	 return;
  }

  textcolor(WHITE);
  textbackground(BLUE);
  clreol();
  Centrar("Lista de registros...", 1);
  textcolor(BLUE);
  textbackground(LIGHTGRAY);
  gotoxy(1,2);
  clreol();
  gotoxy(1, 2); cprintf("Ref.");
  gotoxy(11,2); cprintf("Nombre");
  gotoxy(27,2); cprintf("Autor");
  gotoxy(43,2); cprintf("Area");
  gotoxy(59,2); cprintf("Precio");
  gotoxy(70,2); cprintf("Fecha fab.");
  printf("\n");

  textcolor(LIGHTGRAY);
  textbackground(BLACK);
  Software *Actual= Inicio;
  int Cuantos= 0;
  while(Actual){
	 Actual->Ver();
	 printf("\n\r");
	 Actual= Actual->Siguiente;
	 ++Cuantos;
	 if(Cuantos%22==0 && Actual!=0){
	     printf("\nPresione una tecla para ver los dem s registros...");
		getch();
		clrscr();
	 }
  }

  printf("\nFin de la lista. Presione la barra espaceadora para continuar...");
  while(getch()!=' ');
}

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			//Rutinas de presentación...
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


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

	Cuadro( x+2, y, Ancho, n+3, BLACK, BLACK );
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
	textbackground( FRes );
	textcolor( TRes );
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


 void Centrar( char *Texto, int y ){
	gotoxy( 40-strlen(Texto)/2, y );
	cprintf("%s", Texto );
 }




 void Present(){
	textcolor(WHITE);
	textbackground(BLACK);
	clrscr();
	Centrar("CATALOGO DE SOFTWARE UTILIZANDO LISTAS LIGADAS", 2);
	textcolor(LIGHTGRAY);
      Centrar("ISMEL CERCHAR", 7);
	Centrar("LUIS EDUARDO GONZALEZ", 9);
	Centrar("JAIR VESGA", 11);
	Centrar("Universidad Cooperativa de Colombia", 20);
	Centrar("Santa Marta, abril de 1999", 22);
	_setcursortype(_NOCURSOR);
	getch();
	_setcursortype(_NORMALCURSOR);
 }



 main(){
	char *Lista[]={
			 " Ingresar un elemento a la lista  ",
			 " Eliminar un elemento             ",
			 " Ver la lista de software         ",
			 " Consultar:# Software por  rea    ",
			 " Consultar:Software del autor X   ",
			 " Consultar:Precio total por  rea  ",
			 " Consultar:A¤o > 1990             ",
			 " Consultar:Software m s costoso   ",
			 " Autores...                       ",
			 " Salir                            "
		  };

	int Fin= 0;
	while(Fin==0){
	  int Eleccion;
	  textbackground(BLUE);
	  textcolor( WHITE );
	  clrscr();
	  Centrar("CATALOGO DE SOFTWARE UTILIZANDO LISTAS LIGADAS", 2 );
	  _setcursortype(_NOCURSOR);
	  Eleccion= Menu( Lista, 10, 36,"              Opciones            " );
	  window(1,1,80,25);
	  _setcursortype(_NORMALCURSOR);
	  switch(Eleccion){
		 case 0:
			ListaSoftware.Ingresar();
			break;
		 case 1:
			ListaSoftware.Eliminar();
			break;
		 case 2:
			ListaSoftware.Listar();
			break;
		 case 3:
			ListaSoftware.Consulta1();
			break;
		 case 4:
			ListaSoftware.Consulta2();
			break;
		 case 5:
			ListaSoftware.Consulta3();
			break;
		 case 6:
			ListaSoftware.Consulta4();
			break;
		 case 7:
			ListaSoftware.Consulta5();
			break;
		 case 8:
			Present();
			break;
		 case 9:
			Fin= 1;
	  }
	}
	return 0;
 }
