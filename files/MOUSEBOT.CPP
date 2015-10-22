#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"graphics.h"
#include<dos.h>
#include<string.h>
#include <math.h>
#include <alloc.h>
#include <assert.h>
#include <ctype.h>
#define CR 0x0d
#include "c:\borlandc\bin\files\mouse.cpp"

void  main(void)
{
    void conv_text(int,int,char[]);
    void Boton(int,int,int,int,int,int,int,int);
    void Windows(int,int,int,int);
    void press(int,int,int,int,int,int,int,int);
    void DibujeIcono(int,int,int*,int,int);
    int * Lapiz(void);
    int * Icono(void);
    int * Mac(void);
    int *logo(void);
    int * Desktop(void);

  //DETECT=0


   int gdriver = DETECT, gmode, errorcode,n,i,rr,error;
   char *text,N[10],r,num[255],c;
    MOUSE mouse;


    //inicializa modo grafico
    initgraph(&gdriver, &gmode, "");
    if (graphresult() != grOk){        //grOK=0; Los errores son negativos
    printf("ERROR ASSHOLE\n");
    error=graphresult();
    printf("%d %s\n",error,grapherrormsg(error));

    }


mouse.Inicializar(); //Inicializa Mouse
mouse.Mostrar(); //Muestra Puntero del Mouse
int Boton_Creditos=0,Vert,Horiz,x,y,Boton2;
Boton(100,100,170,170,8,15,7,9);conv_text(118,130,"Salir");

	char Op,Op1;
	int Loop=1;

	//while (toupper(getche())!='S') {
	 while(Loop){
		Boton2 = mouse.Estado (&Vert, &Horiz);
		//mouse.OprimirBoton();
		if (Boton2 == IZQUIERDO || Boton2== DERECHO) {
			mouse.Posicionar(Vert,Horiz);
			if (Vert >= 100 && Vert <= 170 && Horiz >=100 && Horiz <=170){
			   mouse.Esconder();
			   press(100,100,170,170,8,15,7,9);
			   mouse.Mostrar();
			   Loop=0;
			}
		}
	       /*else
	       if (toupper(getche())=='B') {press(100,100,170,170,8,15,7,9);u=0;}*/
	 }
	 //if (toupper(getche())=='S') {press(100,100,170,170,8,15,7,9);}

    //
  //getch();
   closegraph();
}

//***************************** FUNCIONES *********************************//
//////////////////***********/////////////
void Boton(int x1,int y1,int x2,int y2,int c1,int c2,int c3,int N)
{
 int y;
 setlinestyle(0,0,0);
 setfillstyle(SOLID_FILL,c3);
 bar(x1,y1,x2,y2);
 for(y=0;y<N;y++)
    {
     setcolor(c1);
     line(x1-y,y2+y,x2+y,y2+y);
     line(x2+y,y1-y,x2+y,y2+y);
     setcolor(c2);
     line(x1-y,y1-y,x1-y,y2+y);
     line(x1-y,y1-y,x2+y,y1-y);
    }
 setcolor(0);
 line(x1-y,y2+y,x2+y,y2+y);
 line(x2+y,y1-y,x2+y,y2+y);
 line(x1-y,y1-y,x1-y,y2+y);
 line(x1-y,y1-y,x2+y,y1-y);
}
//*****************
//*********************
void press (int x1,int y1,int x2, int y2, int c1,int c2, int c3, int n){
int y;
sound(800);
delay(50);
nosound();
for(y=0;y<n;y++)
    {
     setcolor(c2);
     line(x1-y,y2+y,x2+y,y2+y);
     line(x2+y,y1-y,x2+y,y2+y);
     setcolor(c1);
     line(x1-y,y1-y,x1-y,y2+y);
     line(x1-y,y1-y,x2+y,y1-y);
    }
delay(330);
for(y=0;y<n;y++)
    {
     setcolor(c1);
     line(x1-y,y2+y,x2+y,y2+y);
     line(x2+y,y1-y,x2+y,y2+y);
     setcolor(c2);
     line(x1-y,y1-y,x1-y,y2+y);
     line(x1-y,y1-y,x2+y,y1-y);
    }
 delay(230);
}
//*********************
void conv_text(int x,int y , char N[]){
setcolor(8);
outtextxy(x,y,N);
setcolor(15);
outtextxy(x-2,y-2,N);
setcolor(1);
outtextxy(x-1,y-1,N);
setcolor(WHITE);
}
//*************
