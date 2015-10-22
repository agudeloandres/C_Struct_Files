#include <stdio.h>
#include <conio.h>
#include <dos.h>

int Menu( char* [], int , int , char * );
void main(){
char * Menup[]={ "  Inicializar Arbol AVL ",
		 "    Insertar Nodo       ",
		 "    Consultar Nodos     ",
		 "    Eliminar Nodos      ",
		 "    Salir a D.O.S.      ",
		};
int opcion;


clrscr();
textbackground(1);textcolor(15);clrscr();
gotoxy(28,2);printf("Programa de Base de Datos");
_setcursortype(_NOCURSOR);
opcion=Menu(Menup,5,28,"      Menu Arbol AVL      ");
//Cuadro( 12, 10, 10, 5, BLACK, BLACK );
//Cuadro( 10, 9, 10, 5, 7, 7 );
getch();
}// FIN


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


