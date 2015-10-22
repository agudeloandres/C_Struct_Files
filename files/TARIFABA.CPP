
#include <stdio.h>
#include <conio.h>
#define tarifa_basica 500000
main(){
  textbackground(27);
  textcolor(1);
  // textcolor(BLINK);
   char cia,temporada;
   clrscr();
   int edad,estudiante;
   float precio;
    gotoxy(20,4);
    printf("COMPANYA DE TURISMO << LA LIBERTAD >> ");
    gotoxy(15,7);
    printf("ENTRE POR FAVOR LA COMPANYA VOLAR(v) O ALAS(a)\n ");
    gotoxy(15,8);
    scanf("%c",&temporada);
    clrscr();
    gotoxy(20,4);
    printf("COMPANYA DE TURISMO << LA LIBERTAD >> ");
    gotoxy(15,7);
    printf("ENTRE POR FAVOR LA CLASE DE TEMPORADA ALTA(a) O BAJA(b)\n");
    gotoxy(15,8);
    scanf("%s",&temporada);
    clrscr();
    gotoxy(20,4);
    printf("COMPANYA DE TURISMO << LA LIBERTAD >> ");
    gotoxy(20,7);
    printf("ENTRE POR FAVOR LA EDAD DEL PASAJERO\n ");
    gotoxy(20,8);
    scanf("%d",&edad);
    clrscr();
    gotoxy(20,4);
    printf("COMPANYA DE TURISMO << LA LIBERTAD >> ");
    gotoxy(15,7);
    printf("ENTRE POR FAVOR SI ES ESTUDIANTE (1) SI NO LO ES (0)\n ");
    gotoxy(15,8);
    scanf("%d",&estudiante);
    clrscr();

    precio=(float)tarifa_basica;

    if (estudiante && (cia=='A') && (edad>=18) && temporada=='b')
	 precio=tarifa_basica*0.9;
    if ((cia=='A') && (temporada=='a'))
	 precio=tarifa_basica*1.3;
     else
	 if ((cia=='v') && (temporada=='a'))
	    precio= tarifa_basica*1.2;
	    if(edad<18)
		precio= tarifa_basica*0.5;
		if ((cia=='v') && (edad>=60))
		precio=precio+1000;
		gotoxy(25,12);
		printf("EL PRECIO DEL TIQUETE ES %2.f",precio);
		getch();
}