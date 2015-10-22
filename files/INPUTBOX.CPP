#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "c:\borlandc\bin\files\mouse.cpp"
#define ESC  0x1b

void marco(void);
void boton(int,int,int,int,int,int,int,int);
void rectangulo(int,int,int,int);
void Fondo(void);
void conv_text(int,int,char[]);
void barra_estado(int,int,int,int);
void barra_titulo(int,int,int,char []);
void marco_grabado(int,int,int,int);
float CuadroDato(int ,char *, char * );
void creditos();
void Pause(void);
void presentacion(void);
void DibujeIcono(int,int,int*,int,int);
int * Network(void);
int * Cerrar(void);


MOUSE mouse;
void main (){

int gdriver=0,gmode,opc,opc1,opc2,opc3,opc4,opc5,opc6,opc7,opc8,opc9;
float Periodos,Tasa;

initgraph(&gdriver,&gmode," ");
mouse.Inicializar(); //Inicializa Mouse

boton(90,70,500,300,8,15,7,5);
barra_titulo(92,72,499,"Ingreso De Datos - Mac Software");
DibujeIcono(97,73,Network(),16,16);
boton(483,75,495,87,8,15,7,1);DibujeIcono(485,77,Cerrar(),9,9);
marco_grabado(100,98,490,290);
Periodos=CuadroDato(115,"Digite Numero de Periodos","");
Tasa=CuadroDato(185,"Digite Tasa de Interes","");
conv_text(125,253,"NOTA: ");
conv_text(125,268,"EL PERIODO CERO (0) ES EL MOMENTO INICIAL");
getch();
cleardevice();
printf("Periodo= %f  Tasa=%f",Periodos,Tasa);


getch();
closegraph();exit(0);restorecrtmode();system("cls");


} //FIN


//**********************************FUNCIONES******************************//
//*************
void rectangulo(int x1,int y1,int x2,int y2)
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
/*************************************************************************/
void marco(){
  cleardevice();
  setbkcolor(BLUE);
  rectangulo(3,3,getmaxx()-3,getmaxy()-3);
  }
//***********
void boton(int x1,int y1,int x2,int y2,int c1,int c2,int c3,int N)
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
//*************
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
void Fondo(void){
marco();
//setbkcolor(BLACK);//Darle el Borde del Boton Negro
boton(90,70,500,120,8,15,7,5);}
//*************
void barra_estado(int x1,int y1,int x2,int y2){
setcolor(BLACK);line(x1,y1,x2,y1);line(x1,y2,x1,y1);setcolor(8);line(x1-1,y1-1,x2-1,y1-1);line(x1-1,y2,x1-1,y1);
setcolor(WHITE);line(x2,y1,x2,y2);line(x2,y2,x1,y2);
//line(x2+1,y1,x2+1,y2);line(x2,y2+1,x1,y2+1);
}
//***********************
 void barra_titulo(int x1,int y1, int x2,char N []){
 setfillstyle(1,1);bar(x1,y1,x2,y1+18);
 setcolor(15);settextstyle(0,0,0);outtextxy(x1+26,y1+5,N);
 }
//***********************

//**********************
void marco_grabado(int x1,int y1,int x2,int y2){
  setcolor(8);
  rectangle(x1,y1,x2,y2);
  setcolor(15);
  line(x1+1,y1+1,x2-1,y1+1);line(x1+1,y1+1,x1+1,y2-1);
  line(x1,y2+1,x2+1,y2+1);line(x2+1,y2+1,x2+1,y1+1);
  }

//**********************
float CuadroDato(int Posy,char *Mensaje, char *Mens )
{
 int Posx=345;
 setcolor(0);
 conv_text(120,Posy+12,Mensaje);
 conv_text(413,Posy+12,Mens);
 setcolor(0);
 line(Posx,Posy,Posx,Posy+26);
 line(Posx,Posy-1,Posx+100,Posy-1);
 setcolor(15);
 line(Posx,Posy+26,Posx+100,Posy+26);
 line(Posx+100,Posy-1,Posx+100,Posy+26);
 char Numero,Cadena[12];
 int Pos=0;
 do
 {
 Numero=getch();
 if(Numero==8) // Si Presiona BackSpace para borrar
  {
   setcolor(7);
   outtextxy(Posx+2,Posy+5,Cadena);  //Escribe el numero del mismo color Gris
   Pos=Pos>0?Pos-1:0;               //Borra el Ultimo Digito del Vector
   Cadena[Pos]='\0';               //Le asigna Un espacio en Blanco
  }
 if(strchr("0123456789.-",Numero)) //Verifica que se inserto un Numero y
  {                                // No un Caracter Alfabetico
   Cadena[Pos]=Numero;             //Inserta en la posicion actual el Numero
   Pos=Pos<11?Pos+1:11;            //Aumenta en uno el tama¤o del vector
  }                                // Maximo 11 digitos
 Cadena[Pos]='\0';                 //Le asigna un espacio en blanco al ultimo
 setcolor(15);                     //Nodo aumentado que no vale nada
 outtextxy(Posx+2,Posy+5,Cadena);   //Escribe el numero en color blanco
 }while(Numero!=13);  //Realiza el ciclo mientras no se presione ENTER
return atof(Cadena);
// *Posicion=*Posicion+1; //Incrementa Posicion
}
//********************************

//**********************
void Pause(void)
{
  int c;
  c = getch();
  if( ESC == c ){
    closegraph();
    exit( 1 );
  }

  if( 0 == c ){
    c = getch();
  }
  cleardevice();
}
//*******************

//*********************************************
int * Network(void){
 #define w 15
 #define g 10
 #define a 14
 #define c 11
  static int Net[16][16]={
 1,8,8,8,8,8,8,8,8,1,1,1,1,1,1,1,
 8,w,w,w,w,w,w,w,0,1,1,1,1,1,1,1,
 8,w,0,0,0,0,1,w,0,1,1,1,1,1,1,1,
 8,w,0,c,9,9,1,w,0,1,1,1,1,1,1,1,
 8,w,0,9,9,9,1,w,0,1,1,1,1,1,1,1,
 8,w,1,1,1,1,1,8,8,8,8,8,8,8,8,1,
 8,7,7,7,7,7,8,w,w,w,w,w,w,w,0,1,
 8,0,0,0,0,0,8,w,0,0,0,0,0,7,0,1,
 8,w,w,w,w,w,8,w,0,c,2,2,8,7,0,1,
 8,7,g,8,8,8,8,w,0,2,2,2,8,7,0,1,
 1,0,0,0,0,0,8,w,0,8,8,8,8,7,0,1,
 1,1,8,0,1,1,8,7,7,7,7,7,7,7,0,1,
 1,1,8,0,1,1,8,0,0,0,0,0,0,0,8,0,
 8,8,a,6,0,8,8,w,w,w,w,w,w,w,8,0,
 0,0,a,6,0,0,8,7,g,8,8,8,8,8,8,0,
 1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,
 };
 return (int *) Net;
 }
//*********************
//*********************
int * Cerrar(void){
 static int Cer [9][9]={
  0,0,7,7,7,7,7,0,0,
  7,0,0,7,7,7,0,0,7,
  7,7,0,0,7,0,0,7,7,
  7,7,7,0,0,0,7,7,7,
  7,7,7,0,0,0,7,7,7,
  7,7,0,0,7,0,0,7,7,
  7,0,0,7,7,7,0,0,7,
  0,0,7,7,7,7,7,0,0,
  7,7,7,7,7,7,7,7,7,
  };
  return (int *) Cer;
  }
//*********************
void DibujeIcono(int x,int y, int *BitMap,int NumFila,int NumColumna)
 { for(int i=0;i<NumFila;i++)
     for(int j=0;j<NumColumna;j++)
      putpixel(x+j,y+i,*(BitMap++));
 }