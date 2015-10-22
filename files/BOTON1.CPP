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

int main(void)
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


   int gdriver = DETECT, gmode, errorcode,n,i,rr,x,y,error;
   char *text,N[10],r,num[255],c;
    MOUSE mouse;


    //inicializa modo grafico
    initgraph(&gdriver, &gmode, "");
    if (graphresult() != grOk){        //grOK=0; Los errores son negativos
    printf("ERROR ASSHOLE\n");
    error=graphresult();
    printf("%d %s\n",error,grapherrormsg(error));

    }

   //setbkcolor(3);
   /* setbkcolor(1);
    Boton(50,10,300,80,8,15,7,5);
    settextstyle(8,0,3);
    setcolor(BLUE);
    outtextxy(155,25,"BOTON ");
    setcolor(RED);
    outtextxy(155,25,"B");

    if (toupper(getch())=='B'){
    cleardevice();
    Boton(50,10,300,80,15,8,7,5);
    outtextxy(155,25,"UNDIDO");
    setcolor(WHITE);
     settextstyle(0,0,1);}*/
     //outtextxy(300,90,"digite una palabra");
    //scanf("%s",N);
    //outtextxy(300,70,N);
    //conv_text(410,25,"carlos");
    //outtextxy(300,120,"digite un numero");
    //scanf("%d",&n);
    //sprintf(text,"%d",n);

    /*outtextxy(100,200,"presione una tecla");
    rr=getch();
    sprintf(text,"%d",r);
    outtextxy(100,300,text);
    getch();*/
  /*settextstyle(7,0,3);
   i=0;
    do{
      num[i]=getch();
      sprintf(text,"%c",num[i]);
      outtext(text);
      i++;
   }while ((getch())!=CR);*/
 /*setviewport(300,200,500,400,1);
 setfillstyle(SOLID_FILL,LIGHTGRAY);   //Recuadro con marco grabado
 bar(129,125,512,355);
 setcolor(WHITE);
 line (130,126,511,126);
 line (130,126,130,354);
 line (142,138,142,341);
 line (142,138,498,138);
 line (500,137,500,343);
 line (141,343,500,343);

   setcolor(BLACK);
   line (129,355,512,355);
   line (512,125,512,355);
 setcolor(DARKGRAY);
 line (130,354,511,354);
 line (511,126,511,354);
 rectangle(141,137,499,342);

  do{
    for(i=0;i<=19904;i++)
    putpixel(random(640),random(480),random(getmaxcolor()+1));

    delay(5);
    //}
  }while(!kbhit());*/



   /* setcolor(RED);
    setlinestyle(0, 1, 2);
    circle(299,199,150);               //Rellenando Circulo de Colors
    for(i=0;i<=360;i++){
    pieslice(300,200,0,i,150);
    delay(7);
    }
    delay(10);
    for(i=0;i<=360;i++){
    setcolor(i);
    setfillstyle(0,i);
    pieslice(300,200,0,i,150);
    delay(7);
    }
    getch();*/


DibujeIcono(445,192,Lapiz(),15,9);
DibujeIcono(400,250,Icono(),16,16);
DibujeIcono(400,350,Mac(),24,22);
DibujeIcono(200,50,logo(),17,20);
DibujeIcono(200,20,Desktop(),16,16);
mouse.Inicializar(); //Inicializa Mouse
mouse.Mostrar(); //Muestra Puntero del Mouse
int Boton_Creditos=0,Vert,Horiz,x1,y1;
Boton(100,100,170,170,8,15,7,9);

while ( (Boton_Creditos=mouse.Estado(&Vert,&Horiz) ) ==0){
  Boton_Creditos = mouse.Estado(&Vert,&Horiz);
   /*x = Vert;
   y = Horiz;*/

   /*if(kbhit()){
      getch();*/

     if ( (Boton_Creditos) == IZQUIERDO)
     {
      if (Vert >= 100 && Vert <= 170 && Horiz >=100 && Horiz <=170){
      mouse.Esconder();
      press(100,100,170,170,8,15,7,9);
      mouse.Mostrar();
      //mouse.LibBotones();
     }
      //mouse.LibBotones();
     }
      //mouse.LibBotones();
     }



    //setbkcolor(WHITE);
    /*Boton(28,5,633,22,8,15,7,2);  // COLORS
    Boton(28,25,477,42,8,15,7,2);
    Boton(450,25,550,42,7,8,15,2);
    Boton(533,25,633,42,7,8,15,2);
    Boton(7,5,25,22,8,15,7,2);
    Boton(7,25,25,42,8,15,7,2);
    Windows(5,45,635,475);
    Windows(200,130,410,260);*/
   getch();
   closegraph();
   return 0;
}

//***************************** FUNCIONES *********************************//

void Windows(int x1,int y1,int x2,int y2)
{
 int i;
 setcolor(BLACK);
 rectangle(x1,y1,x2,y2);
 setfillstyle(1,1);
 bar(x1+1,y1+1,x2-1,y2-1);
 for(i=1;i<3;i++)
    {
     setcolor(WHITE);
     line(x1+i,y1+i,x2-i,y1+i);
     line(x1+i,y1+i,x1+i,y2-i);
     line(x1+i+3,y2-i-3,x2-i-3,y2-i-3);
     line(x2-i-3,y1+i+3,x2-i-3,y2-i-3);
     setcolor(11);
     line(x1+i+3,y1+i+3,x2-i-3,y1+i+3);
     line(x1+i+3,y1+i+3,x1+i+3,y2-i-3);
     line(x1+i,y2-i,x2-i,y2-i);
     line(x2-i,y1+i,x2-i,y2-i);
    }
 line(x1+i+4,y1+i+4,x1+i+4,y2-i-4);
 line(x1+i+4,y1+i+4,x2-i-4,y1+i+4);
 setcolor(WHITE);
 line(x1+i+4,y2-i-4,x2-i-4,y2-i-4);
 line(x2-i-4,y1+i+4,x2-i-4,y2-i-4);
}
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
void conv_text(int x,int y , char N[]){
setcolor(8);
outtextxy(x,y,N);
setcolor(15);
outtextxy(x-2,y-2,N);
setcolor(1);
outtextxy(x-1,y-1,N);
setcolor(WHITE);
}
//****************
void opcion(char * x,int y){
   settextstyle(8,0,3);
   char r,*buffer;
   r=getch();
   sprintf(buffer,"%c",r);
   outtextxy(100,200,buffer);
   gets(x);y=atoi(x);
   settextstyle(1,0,3);
   }
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
int * Lapiz(void)
 {
  static int Escribe[15][9]={
	   7,7,7,7,7,0,0,0,7,
	   7,7,7,7,0,4,4,4,0,
	   7,7,7,7,0,4,15,15,0,
	   7,7,7,0,0,4,15,0,7,
	   7,7,7,0,14,0,0,0,7,
	   7,7,0,14,15,7,0,7,7,
	   7,7,0,15,14,0,0,7,7,
	   7,0,15,14,7,0,7,7,7,
	   7,0,14,15,0,0,7,7,7,
	   0,14,15,7,0,7,7,7,7,
	   0,0,14,0,0,7,7,7,7,
	   0,0,0,0,7,7,7,7,7,
	   0,0,0,7,7,7,7,7,7,
	   0,0,7,7,7,7,7,7,7,
	   0,7,7,7,7,7,7,7,7,
	  };
  return (int*) Escribe;
 }
//*********************
int * Icono(void)
 {
    static int Esquina[16][16]={
	     8,8,8,8,8,8,8,8,8,8,8,1,1,1,1,1,
	     8,15,15,15,15,15,15,15,15,15,7,8,1,1,1,1,
	     8,15,15,15,15,15,15,15,15,15,7,15,8,1,1,1,
	     8,15,15,15,15,15,4,4,4,4,0,0,0,0,1,9,
	     8,15,15,15,15,8,8,8,8,4,15,15,7,1,9,9,
	     8,15,15,15,15,12,12,12,12,4,15,15,7,9,9,1,
	     8,15,15,2,2,0,12,12,12,4,15,15,9,9,1,1,
	     8,15,2,14,10,2,0,12,12,4,15,9,9,1,1,1,
	     8,15,2,10,10,2,0,12,12,1,9,9,1,0,1,1,
	     8,15,2,10,10,2,0,15,15,11,9,1,7,0,1,1,
	     8,15,15,0,0,0,15,15,8,0,1,15,7,0,1,1,
	     8,15,15,15,15,12,12,8,7,0,15,15,7,0,1,1,
	     8,15,15,12,12,4,4,4,0,15,15,15,7,0,1,1,
	     8,15,4,4,4,15,15,15,15,15,15,15,7,0,1,1,
	     8,7,7,7,7,7,7,7,7,7,7,7,7,0,1,1,
	     0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
	    };
   return (int*) Esquina;
 }

//*********************
int *Mac(void)
{
  static int Macintosh[24][22]={
  7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
  7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
  7,15,15,15,15,15,7,7,7,7,7,7,7,7,7,7,15,15,15,15,15,7,
  7,1,1,1,1,1,7,7,7,7,7,7,7,7,7,7,1,1,1,1,1,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7,15,1,1,1,7,7,
  7,15,1,1,1,1,8,7,7,7,7,7,7,7,7,15,1,1,1,1,7,7,
  7,15,1,1,1,1,1,8,7,7,7,7,7,7,15,1,1,1,1,1,7,7,
  7,15,1,1,1,1,1,1,8,7,7,7,7,15,1,1,1,1,1,1,7,7,
  7,15,1,1,1,8,1,1,1,8,7,7,15,1,1,1,15,1,1,1,8,7,
  7,15,1,1,1,8,15,1,1,1,8,15,1,1,1,8,15,1,1,1,8,7,
  7,15,1,1,1,8,7,15,1,1,1,1,1,1,8,7,15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,15,1,1,1,1,8,7,7,15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,15,1,1,8,7,7,7,15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,15,8,7,7,7,7,15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7,15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7,15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7,15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7,15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7,15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7,15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7,15,1,1,1,8,7,
  7,1,1,1,1,1,7,7,7,7,7,7,7,7,7,7,1,1,1,1,1,7,
  7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,7,
  7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
  };
  return (int *) Macintosh;
  }
//*********************
int * logo(void){
 static int log[17][20]={
  7 ,7 ,7 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,7 ,7 ,
  7 ,7 ,7 ,0 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,0 ,7 ,7 ,7 ,
  7 ,7 ,7 ,0 ,7 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,0 ,7 ,7 ,7 ,
  7 ,7 ,7 ,0 ,7 ,0 ,15,15,15,15,15,15,15,15,0 ,7 ,0 ,7 ,7 ,7 ,
  7 ,7 ,7 ,0 ,7 ,0 ,15,15,15,15,15,15,15,15,0 ,7 ,0 ,7 ,7 ,7 ,
  7 ,7 ,7 ,0 ,7 ,0 ,15,15,15,15,15,15,15,15,0 ,7 ,0 ,7 ,7 ,7 ,
  7 ,7 ,7 ,0 ,7 ,0 ,15,15,15,15,15,15,15,15,0 ,7 ,0 ,7 ,7 ,7 ,
  7 ,7 ,7 ,0 ,7 ,0 ,15,15,15,15,15,15,15,15,0 ,7 ,0 ,7 ,7 ,7 ,
  7 ,7 ,7 ,0 ,7 ,0 ,15,15,15,15,15,15,15,15,0 ,7 ,0 ,7 ,7 ,7 ,
  7 ,7 ,7 ,0 ,7 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,0 ,7 ,7 ,7 ,
  7 ,7 ,7 ,0 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,0 ,7 ,7 ,7 ,
  7 ,7 ,7 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,7 ,7 ,
  0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,0 ,
  0 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,0 ,0 ,0 ,0 ,7 ,7 ,0 ,
  0 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,0 ,
  0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
 };
 return (int *) log;
}
//*********************
 int * Desktop(void){
 #define w 15
 #define g 10
 #define c 11
 #define a 14
 #define R 12
 static int desk[16][16]={
 w,8,8,8,8,8,8,8,8,w,w,w,w,w,w,w,
 8,w,w,w,w,w,w,w,0,w,w,w,w,w,w,w,
 8,w,0,0,0,0,1,w,0,w,w,w,w,w,w,w,
 8,w,0,c,9,9,1,w,0,w,w,w,w,w,w,w,
 8,w,0,9,9,9,1,w,0,w,w,w,w,w,w,w,
 8,w,1,1,1,1,1,8,8,8,8,8,8,8,8,w,
 8,7,7,7,7,7,8,w,w,w,w,w,w,w,0,w,
 8,0,0,0,0,0,8,w,0,0,0,0,0,7,0,w,
 8,w,w,w,w,w,8,w,0,c,2,2,8,7,0,w,
 8,7,g,8,8,8,8,w,0,2,2,2,8,7,0,w,
 w,0,0,0,0,0,8,w,0,8,8,8,8,7,0,w,
 w,w,8,0,w,w,8,7,7,7,7,7,7,7,0,w,
 w,w,8,0,w,w,8,0,0,0,0,0,0,0,8,0,
 8,8,a,6,0,8,8,w,w,w,w,w,w,w,8,0,
 0,0,a,6,0,0,8,7,g,8,8,8,8,8,8,0,
 w,w,0,0,w,w,w,0,0,0,0,0,0,0,0,w,
 };
 return (int *) desk;
 }
//*********************
void DibujeIcono(int x,int y, int *BitMap,int NumFila,int NumColumna)
 { for(int i=0;i<NumFila;i++)
     for(int j=0;j<NumColumna;j++)
      putpixel(x+j,y+i,*(BitMap++));
 }