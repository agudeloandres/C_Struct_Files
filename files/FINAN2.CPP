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
void rectangulo(int,int,int,int);
void Fondo(void);
void conv_text(int,int,char[]);
void TextResaltado(int,int,char []);
void TextSombra(int,int,char []);
void DrawTable(int,int,int,int,int);
void Erase(int,int,int,int,int);
void barra_estado(int,int,int,int);
void barra_titulo(int,int,int,char []);
void marco_grabado(int,int,int,int);
float CuadroDato(int,int ,char *, char * );
void Box(int,int,int,int,char []);
void CajaDialogo(char [],float * ,float *);
void DibujeIcono(int,int,int*,int,int);
int * Network(void);
int * Cerrar(void);

void main (){

int gdriver=0,gmode,opc,opc1,opc2,opc3,opc4,opc5,opc6,opc7,opc8,opc9;
//char op,*op1=NULL,*op2=NULL,*op3=NULL,*op4=NULL,*op5=NULL,*op6=NULL,*op7=NULL,*op8=NULL,*op9=NULL,opcion;
float Tas,Period;
double Ing[15],Gast[15];

initgraph(&gdriver,&gmode," ");

//************CUADRO DE ENTRADA DE DATOS *****************//
marco();
Box(120,120,530,350,"Ingreso De Datos - Mac Software");
Period=CuadroDato(370,175,"Digite Numero de Periodos","");
Tas=CuadroDato(370,225,"Digite Tasa de Interes","");
conv_text(150,295,"NOTA: ");
conv_text(150,310,"EL PERIODO CERO (0) ES EL MOMENTO INICIAL");
getch();cleardevice();
//************************************************************//
Fondo();settextstyle(1,0,3);conv_text(188,82,"GASTOS - INGRESOS");
DrawTable(32,140,602,450,15);
TextResaltado(12,140, "   PERIODOS");TextResaltado(240,140,"GASTOS");
TextResaltado(435,140,"INGRESOS");


float Ip,Ip1,SumaIngresos=0,SumaEgresos=0,VPN;
Ip=(float)(Tas/100);
Ip1 =(float)(1+Ip);


for(int I=0;I<=Period;I++){
gotoxy(12,12+I); printf("%d",I);
gotoxy(31,12+I);scanf("%lf",&Gast[I]);
gotoxy(59,12+I);scanf("%lf",&Ing[I]);
}

for(I=0;I<=Period;I++){
SumaIngresos+=(float)(Ing[I]/pow(Ip1,I));
SumaEgresos+=(float)(Gast[I]/pow(Ip1,I));
}

VPN=(float)(SumaIngresos-SumaEgresos);

getch();Erase(32,140,610,460,1);

TextSombra(150,230,"Valor Presente Neto = $");
gotoxy(56,16);printf("%.4f",VPN);
VPN<=0?TextSombra(190,270,"No es Rentable"):TextSombra(210,270,"Es Rentable");
getch();
closegraph();restorecrtmode();system("cls");exit(0);
}    //FIN
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

//**********************
float CuadroDato(int posX,int Posy,char *Mensaje, char *Mens )
{
 int Posx=posX;
 setcolor(0);

 conv_text(Posx-220,Posy+12,Mensaje);
 conv_text(413,Posy+12,Mens);
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
 conv_text(240,144,Titulo);
 settextstyle(0,0,1);
 // *Periodos=CuadroDato(190,"Digite Numero de Periodos","");
 // *Tasa=CuadroDato(250,"Digite La Tasa de Interes","");

 conv_text(155,308,"NOTA: ");
 conv_text(155,323,"EL PERIODO CERO (0) ES EL MOMENTO INICIAL");
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