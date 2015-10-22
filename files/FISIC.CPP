
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>

main(){


// PRESENTACION # 1.
textbackground(0);
textcolor (1);
clrscr();
int fil11,fil21,col11,col21;
fil11=1;
fil21=24;
textcolor(1);
while(fil11<=12){
     col11=1;
     while(col11<=80){
	  gotoxy(col11,fil11); printf("Û");
	  gotoxy(col11,fil21); printf("Û");
	  col11++;
     }
     fil11++;
     fil21--;
     delay(100);
}
// PRESENTACION # 2
textbackground(0);
textcolor (1);
clrscr();
int fil1,fil2,col1,col2;
fil1=1;
fil2=24;
textcolor(1);
while(fil1<=24){
     col1=1;
     col2=41;
     while(col1<=40){
	  gotoxy(col1,fil1); printf("Û");
	  gotoxy(col2,fil2); printf("Û");
	  col1++;
	  col2++;
     }
     fil1++;
     fil2--;
     delay(100);
}




// INICIO DE PROGRAMA.

textbackground(3);
textcolor(1);
vj:  // vuelve y juega.
_setcursortype(_SOLIDCURSOR);
clrscr();
int tipo;

// MENU DESICION DEL TIPO DE EJERCICIO.

gotoxy(29,1);  printf("<<  T R A B A J O.  >>");
gotoxy(16,5);  printf("<<  MENU PARA SELECCION DE TIPO DE EJERCICIO. >>");
gotoxy(20,7);  printf("ษอออออออออออออออออออออออออออออออออออออป");
gotoxy(20,8);  printf("บ 1 = Desplazamiento horizontal.      บ");
gotoxy(20,9);  printf("บ 2 = Desplazamiento con rozamiento.  บ");
gotoxy(20,10); printf("บ 3 = Desplazamiento vertical.        บ");
gotoxy(20,11); printf("บ 4 = Caida libre.                    บ");
gotoxy(20,12); printf("บ 5 = Salir.                          บ");
gotoxy(20,13); printf("วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
gotoxy(20,14); printf("บ Opciขn ==> [ ]                      บ");
gotoxy(20,15); printf("ศอออออออออออออออออออออออออออออออออออออผ");
gotoxy(34,14); scanf ("%d",&tipo);


switch(tipo){
      case 1:  // TIPO 1 DE EJERCICIO PLANO HORIZONTAL LIBRE.
	   clrscr();
	   float a,f,x,w;
	   float fx,ra;
	   gotoxy(20,1); printf("<<  TRABAJO EN PLANO HORIZONTAL LIBRE. >>");
	   gotoxy(2,3);  printf("Indique la fuerza urtilizada en Newtons  ==> "); scanf("%f",&f);
	   gotoxy(2,5);  printf("Indique el angulo de la fuerza en Grados ==> "); scanf("%f",&a);
	   gotoxy(2,7);  printf("Indique la distancia recorrida en Metros ==> "); scanf("%f",&x);

	   // PROCESOS.
	   ra = a * 3.141592/180; // convierte el angulo en radoanes.
	   fx = f * cos(ra);      // calcula la componente de la fuerza en el eje x.
	   w = fx * x;            // calcula el valor del trabajo.

	   // RESPUESTAS.
	   gotoxy(2,9); printf("El trabajo realizado fue de %.2f Julios.",w);

	   break;

      case 2:  // TIPO 2 DE EJERCICIO PLANO HORIZONTAL CON ROZAMIENTO.
	   clrscr();
	   float a2,f2,x2,w2,wne2,wr2;
	   float fx2,ra2,fr2,cr2,masa2,nor2;
	   gotoxy(15,1); printf("<<  TRABAJO EN PLANO HORIZONTAL CON ROZAMIENTO. >>");
	   gotoxy(2,3);  printf("Indique la fuerza urtilizada en Newtons  =======> "); scanf("%f",&f2);
	   gotoxy(2,5);  printf("Indique el angulo de la fuerza en Grados =======> "); scanf("%f",&a2);
	   gotoxy(2,7);  printf("Indique la distancia recorrida en Metros =======> "); scanf("%f",&x2);
	   gotoxy(2,9);  printf("Indique la masa del cuerpo en kilogramos =======> "); scanf("%f",&masa2);
	   gotoxy(2,11); printf("Indique el coeficiente de rozamiento cinetico ==> "); scanf("%f",&cr2);

	   // PROCESOS.
	   ra2 = a2 * 3.141592/180; // convierte el angulo en radoanes.
	   fx2 = f2 * cos(ra);      // calcula la componente de la fuerza en el eje x.
	   w2 = fx2 * x2;           // calcula el trabajo de la fuerza.
	   nor2 = masa2 * 9.8;      // calcula la normal.
	   fr2 = cr2 * nor2;        // calcula la fuerza de rozamiento.
	   wr2 = fr2 * x2;          // calcula el trabajo del rozamiento.
	   wne2 = w2 - wr2;         // calcula el trabajo neto.
	   // RESPUESTAS.
	   gotoxy(2,13); printf("El trabajo realizado por la fuerza fue de %.2f Julios.",w2);
	   gotoxy(2,15); printf("El trabajo realizado por el rozamiento fue de %.2f Julios.",wr2);
	   gotoxy(2,17); printf("El trabajo neto fue de %.2f Julios.",wne2);

	   break;

      case 3:  // TIPO 1 DE EJERCICIO PLANO HORIZONTAL LIBRE.
	   clrscr();
	   float masa3,alt3;
	   float wn3,peso3;
	   gotoxy(20,1); printf("<<  TRABAJO EN MOVIMIENTO VERTICAL. >>");
	   gotoxy(2,3);  printf("Indique la masa del cuerpo en kilogramos ==> "); scanf("%f",&masa3);
	   gotoxy(2,5);  printf("Indique la altura recorrida en Metros =====> "); scanf("%f",&alt3);

	   // PROCESOS.
	   peso3 = masa3 * 9.8;  // calcula el peso del cuerpo.
	   wn3 = peso3 * alt3;   // calcula el trabajo ralizado.

	   // RESPUESTAS.
	   gotoxy(2,8); printf("El trabajo realizado fue de %.2f Julios.",wn3);

	   break;

      case 4:
	   h:
	   clrscr();
	   int a4,c4;
	   float x4,vi4,h4,t4;
	   clrscr();
	   gotoxy(25,1);  printf("<<  C A I D A   L I B R E.  >>");
	   gotoxy(16,5);  printf("<<  MENU PARA SELECCION DE TIPO DE EJERCICIO. >>");
	   gotoxy(19,7);  printf("ษออออออออออออออออออออออออออออออออออออออออป");
	   gotoxy(19,8);  printf("บ Este tipo de ejercicio supone un       บ");
	   gotoxy(19,9);  printf("บ objeto que es lanzado hacia arriba     บ");
	   gotoxy(19,10); printf("บ y trabaja con una gravedad de 9.8m/sý  บ");
	   gotoxy(19,11); printf("วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
	   gotoxy(19,12); printf("บ 1 = Velocidad inicial.                 บ");
	   gotoxy(19,13); printf("บ 2 = Tiempo.                            บ");
	   gotoxy(19,14); printf("บ 3 = Tiempo y velocidad inicial.        บ");
	   gotoxy(19,15); printf("บ 4 = Salir al menu principal.           บ");
	   gotoxy(19,16); printf("วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
	   gotoxy(19,17); printf("บ Opciขn ==> [ ]                         บ");
	   gotoxy(19,18); printf("ศออออออออออออออออออออออออออออออออออออออออผ");
	   gotoxy(33,17); scanf ("%d",&c4);
	   switch(c4){
		 case 1:
		      clrscr();
		      gotoxy(14,1); printf("<<  CAIDA LIBRE LANZAMIENTO VERTICAL HACIA ARRIBA. >>");
		      gotoxy(2,3);  printf("Digite la velocidad inicial del cuerpo en m/s: ");
		      scanf("%f",&vi4);
		      h4=vi4*vi4/2*9.8;
		      gotoxy(2,5); printf("La altura alcanzada por el objeto fue  %.2f m ",h4);
		      t4=vi4/9.8;
		      gotoxy(2,7); printf("El tiempo total de vuelo  %.2f s ",t4*2);
		      break;

		 case 2:
		      clrscr();
		      gotoxy(14,1); printf("<<  CAIDA LIBRE LANZAMIENTO VERTICAL HACIA ARRIBA. >>");
		      gotoxy(2,3);  printf("Digite el tiempo de subida en segundos: ");
		      scanf("%f",&t4);
		      vi4=9.8*t4;
		      h4=vi4*t4-9.8*t4*t4/2;
		      gotoxy(2,5); printf("La velocidad inicial del cuerpo fue  %.2f m/s",vi4);
		      gotoxy(2,7); printf("El espacio recorrido fue  %.2f m",h4);
		      break;

		 case 3:
		      clrscr();
		      gotoxy(14,1); printf("<<  CAIDA LIBRE LANZAMIENTO VERTICAL HACIA ARRIBA. >>");
		      gotoxy(2,3);  printf("Digite el tiempo de subida en segundos: ");
		      scanf("%f",&t4);
		      gotoxy(2,5);  printf("Digite la velocidad inicial del cuerpo en m/s: ");
		      scanf("%f",&vi4);
		      x4=vi4/2*9.8*t4;
		      gotoxy(2,7);  printf("El espacio recorrido por el cuerpo fue  %.2f m",x4);
		      break;
		 case 4:
		      clrscr();
		      goto vj;
		 default:
		      gotoxy(32,17); printf("Opciขn invalida. \a\a");
		      delay(800);
		      goto h;
		 }
		 // REINICIO.
		 gotoxy(24,24); printf("Pulse una tecla para reiniciar. \a");
		 getch();
		 goto h;

      case 5:  // SALIDA.
	   clrscr();
	   exit(0);

      default:
	   gotoxy(33,14); printf("Opciขn invalida. \a");
	   delay(800);
	   goto vj;

      }
      // REINICIO.
      gotoxy(24,24); printf("Pulse una tecla para reiniciar. \a");
      getch();
      goto vj;

// FIN DEL PROGRMA. //
}




