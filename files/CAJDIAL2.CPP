#include "graphics.h"
#include "fstream.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"
#include "dos.h"
#include "stdio.h"

void main(){

   void CajaDialogo(char [],float *,float *);
   void Cuadro_Paleta(int,int,int,int,int);

   int controlador=9, modo=2;
   initgraph(&controlador,&modo," ");
   float *Tasa,*Periodos;

		CajaDialogo("INGRESO DE DATOS",Periodos,Tasa);
		cleardevice();getch();
		//printf("Datos : Tasa= %.3f  , Periodos= %.3f",(*Tasa),(*Periodos));
		closegraph();//restorecrtmode();
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


 //********************
 float CuadroDato(int Posy,char *Mensaje, char *Mens )
{
 int Posx=375;
 setcolor(0);
 conv_text(155,Posy+12,Mensaje);
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
 /*setcolor(RED);
 outtextxy(146,171,"Esfera");
 outtextxy(150,180,"Roja");*/
 settextstyle(1,0,1);
 conv_text(240,144,Titulo);
 settextstyle(0,0,1);
  *Periodos=CuadroDato(190,"Digite Numero de Periodos","");
  *Tasa=CuadroDato(250,"Digite La Tasa de Interes","");
 //CuadroDato(290,"Valor de Z","");
 conv_text(155,308,"NOTA: ");
 conv_text(155,323,"EL PERIODO CERO (0) ES EL MOMENTO INICIAL");
 getch();
 /*setcolor(BLUE);
 outtextxy(146,276,"Esfera");
 outtextxy(146,285,"Azul");
 CuadroDato(245,"Valor de X","X=3.051522");
 CuadroDato(280,"Valor de Y","Y=1.582542");
 CuadroDato(315,"Valor de Z","Z=15.62388");*/

}


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