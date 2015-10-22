// *******************************************************************
// **                DEFINICION DE VARIABLES GLOBALES               **
// *******************************************************************

char DatoEsfera[4][12];

// *******************************************************************
// **           INCLUYE LAS BIBLIOTECAS DE BORLAN C++               **
// *******************************************************************

#include "graphics.h"  
#include "fstream.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"
#include "dos.h"
#include "stdio.h"
#include "c:\borlandc\bin\SIMULACI\mouse.h"
#include "c:\borlandc\bin\SIMULACI\botones.h"
#include "c:\borlandc\bin\SIMULACI\inicio.h"
#include "c:\borlandc\bin\SIMULACI\opcion.h"
#include "c:\borlandc\bin\SIMULACI\pantalla.h"
#include "c:\borlandc\bin\SIMULACI\ayuda.h"
#include "c:\borlandc\bin\SIMULACI\escala.h"
#include "c:\borlandc\bin\SIMULACI\objeto.h"
Simulador *Proyecto;
#include "c:\borlandc\bin\SIMULACI\caja.h"

// *******************************************************************
// **           FUNCION QUE CAPTURA UNA PORCION DE MEMORIA          **
// *******************************************************************
void * getmemoria (int n)
{
  return new char[n+1];
}
// *******************************************************************
// **          FUNCION QUE DIBUJA LOS BOTONES PRESIONADOS           **
// *******************************************************************

void Presion_Boton(int x0, int y0, int x1, int y1)
{  setcolor (BLACK);
   line (x0,y0,x0,y1);
   line (x0,y0,x1,y0);
   setcolor (WHITE);
   line (x0,y1,x1,y1);
   line (x1,y1,x1,y0);
   setcolor (DARKGRAY);
   line (x0+1,y1-1,x1-1,y1-1);
   line (x1-1,y1-1,x1-1,y0+1);
}


// *******************************************************************
// **          FUNCION QUE DIBUJA LOS BOTONES DEL PAINT             **
// *******************************************************************

void Boton_Paint(int x0, int y0, int x1, int y1)
{  setcolor (WHITE);
   line (x0,y0,x0,y1);
   line (x0,y0,x1,y0);
   setcolor (BLACK);
   line (x0,y1,x1,y1);
   line (x1,y1,x1,y0);
   setcolor (DARKGRAY);
   line (x0+1,y1-1,x1-1,y1-1);
   line (x1-1,y1-1,x1-1,y0+1);
}

// *******************************************************************
// **          FUNCION QUE DIBUJA LOS CUADROS DE LA PALETA          **
// *******************************************************************

void Cuadro_Paleta(int x0, int y0, int x1, int y1, int color_relleno)
{
 setfillstyle(SOLID_FILL,color_relleno);
 bar (x0,y0,x1,y1);
 setcolor(BLACK);
 line (x0,y0,x1,y0);
 line (x0,y0,x0,y1);
 setcolor(WHITE);
 line (x0,y1,x1,y1);
 line (x1,y0,x1,y1);
}


// *******************************************************************
// **            FUNCION QUE MUESTRA EL MENU PRINCIPAL             **
// *******************************************************************

void Main_Principal()
{

// **                  DIBUJA LA BARRA AZUL ARRIBA                  **
 setfillstyle(SOLID_FILL,BLUE);
 bar (0,0,640,18);
 setcolor(WHITE);
 settextstyle(0,0,0);
 outtextxy(24,5,"Examen Final de Simulacion");
// **                DIBUJA EL BOTON DE MINIMIZAR                   **
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar (588,2,602,16);
 Boton_Paint (588,2,602,16);
 DibujeIcono(591,4,Minimizar(),9,8);
// **                DIBUJA EL BOTON DE RESTAURAR                   **
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar (604,2,618,16);
 Boton_Paint (604,2,618,16);
 DibujeIcono(607,4,Restaurar(),9,8);
// **                DIBUJA EL BOTON DE SALIR                       **
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar (620,2,634,16);
 Boton_Paint (620,2,634,16);
 DibujeIcono(623,4,Salir(),9,8);
// **                    DIBUJA EL FONDO GRIS                       **
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar (0,19,640,35);
 bar (637,35,640,480);
 bar (0,19,59,480);
 bar (0,393,640,480);
// **               DIBUJA EL MENU ARCHIVO Y AYUDA                  **

 setcolor(BLACK);
 settextstyle(0,0,0);
 outtextxy(8,25,"Introduccion");
 outtextxy(122,25,"Demostracion");
 outtextxy(233,25,"Funcionamiento");
 outtextxy(360,25,"Ayuda");
 outtextxy(417,25,"Acerca de...");

// **             DIBUJA EL FONDO BLANCO DE PINTADO                  **
 Cuadro_Paleta(4,36,636,446,15);

// **             DIBUJA EL ICONO DE LA BARRA DE TITULO              **
 DibujeIcono(2,2,Icono(),16,16);

// **             DIBUJA LA MARIPOSA EN EL FONDO BLANCO              **
 DibujeIcono(317,236,Relleno(),14,16);

// **             DIBUJA LA MARIPOSA EN ESCALA 5:1                   **
 Escala(317,236);

// **             DIBUJA LA BARRA DE AYUDA Y DIRECCION               **
  setcolor(WHITE);
  line (4,475,500,475);
  line (503,475,603,475);
  line (606,475,636,475);
  line (500,450,500,475);
  line (603,450,603,475);
  line (636,450,636,475);

  setcolor(DARKGRAY);
  line (4,450,500,450);
  line (503,450,603,450);
  line (606,450,636,450);
  line (4,450,4,475);
  line (503,450,503,475);
  line (606,450,606,475);

 setcolor(YELLOW);
 outtextxy(512,462,"FBL&JDR&BP");
 setcolor(RED);
 outtextxy(510,460,"FBL&JDR&BP");
}


// *******************************************************************
// **            FUNCION QUE INICIALIZA EL MODO GRAFICO             **
// *******************************************************************

void InicializarModoGrafico()
{int controlador=9, modo=2;
 initgraph(&controlador,&modo," ");
 }


// *******************************************************************
// **            FUNCION QUE BORRA EL TEXTO DE AYUDA                **
// *******************************************************************

void Borra_Texto (int x,int y,int x1,int y1)
{
  setfillstyle(SOLID_FILL,LIGHTGRAY);
  bar (x,y,x1,y1);
}



main()
{
 int Bandera,Boton,modo,Opcion,TempV,TempH,Vert,Horiz;
 int x,y,salida,n;
 int Color_Actual;
 int Nuevax, Nuevay, posX, posY;
 int i,contx,conty;
 int lado1,lado2,lado3,tempx,tempy;
 int LadoCuadrado,entero;
 int x0prima,y0prima,x0,y0,x1,y1;
 float lado4;
 void *getmemoria(int),*p;
 MOUSE mouse;

 InicializarModoGrafico();

 Inicio_Programa();

 Main_Principal();

 mouse.Inicializar();

  Bandera = 0;
  Boton = 0;
  Proyecto=new Simulador();
  while (Bandera == 0)
  {
   mouse.Mostrar();
   Boton = mouse.Estado(Vert,Horiz);
   x = Vert;
   y = Horiz;
   if(kbhit())
    getch();
   if (Boton==IZQUIERDO)
   {    Opcion=Retorna_Opcion(x,y);
        switch(Opcion)
        {
// *********************************************
// **          1 CASO PARA SALIR              **
// *********************************************
           case 1:
                mouse.Esconder();
                Bandera=1;
                Presion_Boton(620,2,634,16);
                delay(200);
                Boton_Paint (620,2,634,16);
                break;
// *********************************************
// **         2 CASO PARA INTRODUCCION       **
// *********************************************
           case 2:
                mouse.Esconder();
                setfillstyle(SOLID_FILL,BLUE);
                bar(3,20,110,34);
                setcolor(WHITE);
                settextstyle(0,0,0);
                outtextxy(8,25,"Introduccion");
                setcolor(BLACK);
                outtextxy(9,460,"Presione < ENTER > para continuar o < ESC > para salir");
                MostrarArchivo("INTRODUC.TXT",WHITE,BLACK,BLUE);
                Cuadro_Paleta(4,36,636,446,15);
                delay(100);
                setfillstyle(SOLID_FILL,LIGHTGRAY);
                bar(3,20,110,34);
                setcolor(BLACK);
                settextstyle(0,0,0);
                outtextxy(8,25,"Introduccion");
                DibujeIcono(317,236,Relleno(),14,16);
                Escala(317,236);
                break;
// *********************************************
// **         3 CASO PARA DEMOSTRACION       **
// *********************************************
           case 3:
                mouse.Esconder();
                setfillstyle(SOLID_FILL,BLUE);
                bar(116,20,224,34);
                setcolor(WHITE);
                settextstyle(0,0,0);
                outtextxy(122,25,"Demostracion");
                setcolor(BLACK);
                outtextxy(9,460,"Ingrese los valores iniciales de las variables");
                delay(100);
                CajaDialogo();
                              
                setfillstyle(SOLID_FILL,WHITE);
                bar(50,50,550,430);
                setfillstyle(SOLID_FILL,LIGHTGRAY);
                bar(116,20,224,34);
                setcolor(BLACK);
                settextstyle(0,0,0);
                outtextxy(122,25,"Demostracion");
                DibujeIcono(317,236,Relleno(),14,16);
                Escala(317,236);
                break;

// *********************************************
// **         4 CASO PARA FUNCIONAMIENTO     **
// *********************************************
           case 4:
                mouse.Esconder();
                setfillstyle(SOLID_FILL,BLUE);
                bar(228,20,350,34);
                setcolor(WHITE);
                settextstyle(0,0,0);
                outtextxy(233,25,"Funcionamiento");
                setcolor(BLACK);
                outtextxy(9,460,"Presione < ENTER > para continuar o < ESC > para salir");
                MostrarArchivo("FUNCIONA.TXT",WHITE,BLACK,BLUE);
                Cuadro_Paleta(4,36,636,446,15);
                delay(100);
                setfillstyle(SOLID_FILL,LIGHTGRAY);
                bar(228,20,350,34);
                setcolor(BLACK);
                settextstyle(0,0,0);
                outtextxy(233,25,"Funcionamiento");
                DibujeIcono(317,236,Relleno(),14,16);
                Escala(317,236);
                break;

// *********************************************
// **         5 CASO PARA TEMAS AYUDA        **
// *********************************************
           case 5:
                mouse.Esconder();
                setcolor(BLACK);
                setfillstyle(SOLID_FILL,BLUE);
                bar(354,20,406,34);
                setcolor(WHITE);
                settextstyle(0,0,0);
                outtextxy(360,25,"Ayuda");
                setcolor(0);
                outtextxy(9,460,"Presione < ENTER > para continuar o < ESC > para salir");
                MostrarArchivo("AYUDA.TXT",WHITE,BLACK,BLUE);
                Cuadro_Paleta(4,36,636,446,15);
                delay(100);
                setfillstyle(SOLID_FILL,LIGHTGRAY);
                bar(354,20,406,34);
                setcolor(BLACK);
                settextstyle(0,0,0);
                outtextxy(360,25,"Ayuda");
                DibujeIcono(317,236,Relleno(),14,16);
                Escala(317,236);
                break;

// *********************************************
// **         6 CASO PARA ACERCA DE SHOW     **
// *********************************************
           case 6:
                mouse.Esconder();
                setfillstyle(SOLID_FILL,WHITE);
                bar(50,50,550,430);
                setfillstyle(SOLID_FILL,BLUE);
                bar(410,20,518,34);
                setcolor(WHITE);
                settextstyle(0,0,0);
                outtextxy(417,25,"Acerca de...");
                Inicio_Programa();
                delay(100);
                setfillstyle(SOLID_FILL,WHITE);
                bar(50,50,550,430);
                setfillstyle(SOLID_FILL,LIGHTGRAY);
                bar(410,20,518,34);
                setcolor(BLACK);
                settextstyle(0,0,0);
                outtextxy(417,25,"Acerca de...");
                DibujeIcono(317,236,Relleno(),14,16);
                Escala(317,236);
                break;

        }
   mouse.Esconder();
   mouse.LibBotones();
   Borra_Texto (5,451,499,474);
   
   }
 }
 
 cleardevice();
 closegraph();
 restorecrtmode();
 return 0;

}
