#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define ESC  0x1b

void marco(void);
void boton(int,int,int,int,int,int,int,int);
void press(int,int,int,int,int,int,int,int);
void rectangulo(int,int,int,int);
void Fondo(void);
void conv_text(int,int,char[],int);
void TextResaltado(int,int,char []);
void TextSombra(int,int,char []);
void DrawTable(int,int,int,int,int);
void Erase(int,int,int,int,int);
void barra_estado(int,int,int,int);
void barra_titulo(int,int,int,char []);
void marco_grabado(int,int,int,int);
float CuadroDato(int,int ,char *, char * );
void Box(int,int,int,int,char []);
void Line3D(int,int,int,int);
void CajaDialogo(char [],float * ,float *);
void DibujeIcono(int,int,int*,int,int);
int * Network(void);
int * Cerrar(void);

void main (){

int gdriver=0,gmode,opc,opc1,opc2,opc3,opc4,opc5,opc6,opc7,opc8,opc9;


initgraph(&gdriver,&gmode," ");

Box(120,40,520,420,"Acerca de Hackerz.Com");boton(425,375,500,395,8,15,7,3);
conv_text(437,382,"Aceptar",0);
Line3D(140,335,500,335);barra_estado(153,80,200,148);
settextstyle(1,0,6);conv_text(158,69,"H",1);conv_text(173,94,"S",1);
settextstyle(10,0,2);conv_text(219,86,"Hackerz Software",1);
settextstyle(0,0,1);conv_text(186,160,"Copyright (c) 1999-2000 Hackerz Software",0);
conv_text(186,178,"All rights Reserved.",0);conv_text(186,210,"Requerimientos:",0);
conv_text(186,230,"  Windows 95/98/NT",0);conv_text(186,250,"  16 MB de Memoria RAM",0);
conv_text(186,270,"  Procesador 486 100 MHZ",0);conv_text(186,290,"  Tarjeta de Video de 1 MB",0);
conv_text(135,350," WARNING: This App was designed by Mac.",0);
conv_text(140,370,"This Software is Shareware.",0);
if (getch()>=0) press(425,375,500,395,8,15,7,3);
//getch();
closegraph();restorecrtmode();system("cls");exit(0);
}
///******************************************
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
//**********************
void conv_text(int x,int y , char N[],int Color){
setcolor(8);
outtextxy(x,y,N);
setcolor(15);
outtextxy(x-2,y-2,N);
setcolor(Color);
outtextxy(x-1,y-1,N);
setcolor(WHITE);
}
//*************
void Fondo(void){
marco();
//setbkcolor(BLACK);//Darle el Borde del Boton Negro
boton(90,70,500,120,8,15,7,5);}
//*************
void TextResaltado(int X ,int Y,char Texto [] ){
setcolor(1);
outtextxy(X+1,Y+1,Texto);
setcolor(3);
outtextxy(X,Y,Texto);
setcolor(1);
outtextxy(X-1,Y-1,Texto);
setcolor(15);
}
//*******************
void TextSombra(int x,int y, char text []){
setcolor(7);
outtextxy(x+1,y+1,text);
setcolor(0);
outtextxy(x,y,text);
setcolor(15);
outtextxy(x-1,y-1,text);
}

//*******************
void DrawTable( int left, int top,int right, int bottom, int Color){
setfillstyle(1,Color);setcolor(Color);
bar(left,top,right+1,bottom-281);setlinestyle(0,1,3);
rectangle(left+1,top+30,right,bottom);
//Columns
line(left+148,top+30,left+148,bottom);
line(right-212,top+30,right-212,bottom);
}
//*******************
void Erase( int left, int top,int right, int bottom, int Color){
setfillstyle(1,Color);bar(left,top,right,bottom);}
//*************************
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

//***************
void Line3D(int x1,int y1, int x2, int y2){
  setlinestyle(0,0,1);setcolor(8);
  line(x1,y1,x2,y2);
  setlinestyle(0,0,1);setcolor(15);
  line(x1,y1+1,x2,y1+1);
}
//*************

//**********************
float CuadroDato(int posX,int Posy,char *Mensaje, char *Mens )
{
 int Posx=posX;
 setcolor(0);

 conv_text(Posx-220,Posy+12,Mensaje,1);
 conv_text(413,Posy+12,Mens,1);
 setbkcolor(0);
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
// *Posicion=*Posicion+1; //Incrementa Posicion
return atof(Cadena);
}


void CajaDialogo(char Titulo[],float * Periodos,float *Tasa)
{

 //int Posicion=0;
 setfillstyle(SOLID_FILL,LIGHTGRAY);
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
  settextstyle(1,0,1);
 conv_text(240,144,Titulo,1);
 settextstyle(0,0,1);
 // *Periodos=CuadroDato(190,"Digite Numero de Periodos","");
 // *Tasa=CuadroDato(250,"Digite La Tasa de Interes","");

 conv_text(155,308,"NOTA: ",1);
 conv_text(155,323,"EL PERIODO CERO (0) ES EL MOMENTO INICIAL",1);
 getch();
}
//**************************
void Box(int x,int y,int x1,int y1,char Titulo []){
boton(x,y,x1,y1,8,15,7,5);marco_grabado(x+10,y+28,x1-10,y1-10);
barra_titulo(x+2,y+2,x1-1,Titulo);DibujeIcono(x+7,y+3,Network(),16,16);
boton(x1-17,y+5,x1-5,y+17,8,15,7,1);DibujeIcono(x1-15,y+7,Cerrar(),9,9);
}
//**************************

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