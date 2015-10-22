#include "stdio.h"
#include "conio.h"
#include "graphics.h"
#include "stdlib.h"
#include "dos.h"
#include "c:\borlandc\bin\files\mouse.cpp"

void main(void)
{
 void seleccionar(int,int,int,int);
 void borrar(int,int,int,int,int,int);
 void barra_estado(int,int,int,int);
 void barra_titulo(int,int,int,char[]);
 void marco_grabado(int,int,int,int);
 void Boton (int,int,int,int,int,int,int,int);
 void conv_text(int,int,char[]);
 void choice(int);
 void menuP(int);
 void hora (void);
 void Date(int x,int y);
 int * Mac(void);
 int * Bell(void);
 int * Star(void);
 int * logo(void);
 int * Network(void);
 int * Pc(void);
 int * Minimizar(void);
 int * Restaurar(void);
 int * Cerrar(void);
 int * Candy_Font(void);
 void DibujeIcono(int,int,int*,int,int);

 char *menu[]={
	"INGRESO DE DATOS",
	"CONSULTA DE DATOS",
	"EDICION DE DATOS",
	"CANCELACION DATOS",
	"SALIDA A D.O.S."
	};
 int unidad=0,modo,c,j,f,i,d,boton,Horiz,Vert;



 initgraph(&unidad,&modo,"C:\BORLANDC\BIN");
 MOUSE mouse;
 mouse.Inicializar();



 Boton(2,2,637,477,8,15,7,3);
 barra_titulo(4,4,636,"Hackerz Software - Macintosh");
 marco_grabado(180,100,470,390);
 barra_estado(28,35,612,65);
 barra_estado(28,440,300,463);barra_estado(303,440,530,463);barra_estado(533,440,612,463);
 settextstyle(2,0,6);conv_text(55,443,"Macintosh Corp. 2000");Date(310,443);
 DibujeIcono(540,444,Bell(),17,16);DibujeIcono(563,442,Mac(),20,22);DibujeIcono(588,444,Pc(),16,16);
 DibujeIcono(10,5,Network(),16,16);
 Boton(589,7,601,19,8,15,7,1);DibujeIcono(591,10,Minimizar(),9,9);
 Boton(603,7,615,19,8,15,7,1);DibujeIcono(605,9,Restaurar(),9,9);
 Boton(620,7,632,19,8,15,7,1);DibujeIcono(622,9,Cerrar(),9,9);
 settextstyle(1,0,3);
 conv_text(225,37," MENU PRINCIPAL");  //Titulo
 settextstyle(1,0,1);


 j=135;f=130;i=160;
 for(c=0;c<5;c++){
 Boton(225,f,425,i,8,15,7,3); //Pinta los botones y escribe su item
 conv_text(240,j,menu[c]);
 j+=50;f+=50;i+=50;         //Espacio entre botones
 }
 mouse.Mostrar();
 //boton = mouse.Estado (&Vert,&Horiz);
 moveto(220,75); //situa el cursor en esa posicion coordenadas graficas

 d=getch();
 while (d==0){
     //hora();
    d=getch();
       menuP(d);
    d=getch();
    choice(d);

 } // FIN WHILE

 closegraph();
 }  // FIN

 //********************** FUNCIONES ***************************************//

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
//**********************
void marco_grabado(int x1,int y1,int x2,int y2){
  setcolor(8);
  rectangle(x1,y1,x2,y2);
  setcolor(15);
  line(x1+1,y1+1,x2-1,y1+1);line(x1+1,y1+1,x1+1,y2-1);
  line(x1,y2+1,x2+1,y2+1);line(x2+1,y2+1,x2+1,y1+1);
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
//*******************
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
void borrar(int x1,int y1,int x2,int y2,int cant_rect,int distancia_rect){
      int f=y1,j=y2,c;  //Esta funcion Borra todos los cuadritos azules
      setcolor(7);      //para que de la impresion del movimiento del cursor
      for(c=0;c<cant_rect;c++){
      rectangle(x1,f,x2,j);
      f+=distancia_rect;j+=distancia_rect;
      }
 }
//*************************
void seleccionar(int x1,int y1,int x2,int y2){
	  setcolor(BLUE);     //Esta funcion dibuja el rectangulo azul y
	  rectangle(x1,y1,x2,y2); //ubica el cursor en la posicion x1,y1
	  moveto(x1,y1); // Y asi dar la impresion del movimiento del cursor.
}
//*************************
void mover_cursor(int x1,int y1, int x2, int y2){
borrar(219,125,431,165,5,50);
seleccionar(x1,y1,x2,y2);
}
//*************************
void hora(){
struct time hora;
char *cadena_hora,*cadena_minutos;
 gettime(&hora);
 itoa(hora.ti_hour,cadena_hora,10);itoa(hora.ti_min,cadena_minutos,10);
 settextstyle(2,0,6);
 conv_text(538,443,cadena_hora);conv_text(562,443,":");conv_text(570,443,cadena_minutos);
 settextstyle(1,0,1);
}
void Date(int x, int y){
struct date d;
char *Year,*Day,*Month;
getdate(&d);
   itoa(d.da_year,Year,10);itoa(d.da_day,Day,10);itoa(d.da_mon,Month,10);
   settextstyle(2,0,6);
   conv_text(x,y,"Fecha = ");
   conv_text(x+80,y,Day);conv_text(x+100,y,"/");
   conv_text(x+110,y,Month);conv_text(x+130,y,"/");conv_text(x+140,y,Year);
}
//**********************
void menuP (int d){
switch(d){

	      case 80: switch(gety()){

		       case 75: //Cuando empieza el ciclo.
		       mover_cursor(219,125,431,165);
		       break;

		       case 125:
		       mover_cursor(219,175,431,215);
		       break;

		       case 175:
		       mover_cursor(219,225,431,265);
		       break;

		       case 225:
		       mover_cursor(219,275,431,315);
		       break;

		       case 275:
		       mover_cursor(219,325,431,365);
		       break;

		       case 325:
		       mover_cursor(219,125,431,165);
		       break;

		       default:break;

		       } //fin switch gety()

		      break;


	case 72: switch(gety()){

		     case 75:   //Solamente cuando empieza se da este case
		       mover_cursor(219,325,431,365);
		       break;

		       case 125:
		       mover_cursor(219,325,431,365);
		       break;

		       case 175:
		       mover_cursor(219,125,431,165);
		       break;

		       case 225:
		       mover_cursor(219,175,431,215);
		       break;

		       case 275:
		       mover_cursor(219,225,431,265);
		       break;

		       case 325 :
		       mover_cursor(219,275,431,315);
		       break;

		       default:break;

		       } //fin switch gety()
		  break;

	      default : break;


	    }//fin switch
}
//**********************
void choice(int c){
   switch (gety()){

     case 125:
     if (c==13) press(225,130,425,160,8,15,7,3);
     break;

     case 175:
     if (c==13) press(225,180,425,210,8,15,7,3);
     break;

     case 225:
     if (c==13) press(225,230,425,260,8,15,7,3);
     break;

     case 275:
     if (c==13) press(225,280,425,310,8,15,7,3);
     break;

     case 325:
     if (c==13) press(225,330,425,360,8,15,7,3);
     break;

    default:break;

  }//FIN SWITCH
} //FIN
//***************************
int *Mac(void)
{
  static int Macintosh[20][22]={
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
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7, 15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7, 15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7, 15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7, 15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7, 15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7, 15,1,1,1,8,7,
  7,15,1,1,1,8,7,7,7,7,7,7,7,7,7,7, 15,1,1,1,8,7,
  7,1,1,1,1,1,7,7,7,7,7,7,7,7,7,7,1,1,1,1,1,7,

  };
  return (int *) Macintosh;
  }
//*********************
int *Minimizar(void){
 static int Min[9][9]={
  7,7,7,7,7,7,7,7,7,
  7,7,7,7,7,7,7,7,7,
  7,7,7,7,7,7,7,7,7,
  7,7,7,7,7,7,7,7,7,
  7,7,7,7,7,7,7,7,7,
  7,7,7,7,7,7,7,7,7,
  7,0,0,0,0,0,0,0,7,
  7,0,0,0,0,0,0,0,7,
  7,7,7,7,7,7,7,7,7,

  };
return (int *) Min;
}
//*********************
int * Restaurar(void){
 static int Rest[9][9]={
  7,7,0,0,0,0,0,0,0,
  7,7,0,0,0,0,0,0,0,
  7,7,0,7,7,7,7,7,0,
  0,0,0,0,0,0,0,7,0,
  0,0,0,0,0,0,0,7,0,
  0,7,7,7,7,7,0,0,0,
  0,7,7,7,7,7,0,7,7,
  0,7,7,7,7,7,0,7,7,
  0,0,0,0,0,0,0,7,7,
  };
 return (int *) Rest;
 }
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
int * Bell(void){
 static int Camp[17][16]={
  7,7,7,7,7,7,7,7,8,8,7,7,7,7,7,7,
  7,7,7,7,7,7,7,8,0,15,8,7,7,7,7,7,
  7,7,7,7,7,7,8,0,0,15,15,8,7,7,7,7,
  7,7,7,7,7,8,14,0,15,15,15,8,7,7,7,7,
  7,7,7,7,8,14,14,0,15,15,15,8,7,7,7,8,
  7,7,7,8,14,14,14,0,15,15,15,8,7,7,8,7,
  8,8,8,14,14,14,14,0,0,15,15,8,7,8,7,7,
  8,14,8,14,14,14,14,0,14,0,15,8,7,7,7,7,
  8,14,8,14,14,14,14,0,14,14,0,8,7,8,8,8,
  8,14,8,14,14,14,14,0,14,0,15,8,7,7,7,7,
  0,0,8,14,14,14,14,0,0,15,15,8,7,8,7,7,
  7,7,7,0,14,14,14,0,15,15,15,8,7,7,8,7,
  7,7,7,7,0,14,14,0,15,15,15,8,7,7,7,8,
  7,7,7,7,7,0,14,0,15,15,15,8,7,7,7,7,
  7,7,7,7,7,7,0,0,0,15,15,8,7,7,7,7,
  7,7,7,7,7,7,7,0,0,15,8,7,7,7,7,7,
  7,7,7,7,7,7,7,7,0,0,7,7,7,7,7,7,
  };
  return (int *) Camp;
  }
//*********************
int * Star(void){
static int est[11][13]={
  8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,
  8 ,8 ,15,15,15,1 ,1 ,1 ,15,15,15,8 ,8 ,
  8 ,8 ,8 ,15,15,1 ,1 ,1 ,15,15,8 ,8 ,8 ,
  8 ,14,8 ,8 ,15,1 ,1 ,1 ,15,8 ,8 ,14,8 ,
  8 ,14,14,8 ,8 ,1 ,1 ,1 ,8 ,8 ,14,14,8 ,
  8 ,8 ,14,14,8 ,8 ,1 ,8 ,8 ,14,14,8 ,8 ,
  7 ,8 ,8 ,14,14,8 ,8 ,8 ,14,14,8 ,8 ,7 ,
  7 ,7 ,8 ,8 ,14,14,14,14,14,8 ,8 ,7 ,7 ,
  7 ,7 ,7 ,8 ,8 ,14,14,14,8 ,8 ,7 ,7 ,7 ,
  7 ,7 ,7 ,7 ,8 ,8 ,8 ,8 ,8 ,7 ,7 ,7 ,7 ,
  7 ,7 ,7 ,7 ,7 ,8 ,8 ,8 ,7 ,7 ,7 ,7 ,7 ,
  };
  return (int *) est;
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
int * Pc (void){
 #define w 15
 #define c 11
 static int Computer[16][16]={
 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
 7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,
 7,7,7,7,7,8,7,7,7,7,7,7,7,8,0,7,
 7,7,7,7,8,w,w,w,w,w,w,7,8,8,0,7,
 7,7,7,7,8,w,0,0,0,0,0,7,8,8,0,7,
 7,7,7,7,8,w,0,c,2,2,8,7,8,8,0,7,
 7,7,7,7,8,w,0,2,2,2,8,7,8,8,0,7,
 7,7,7,7,8,w,0,8,8,8,8,7,8,8,0,7,
 7,7,7,7,8,w,7,7,7,7,7,7,8,0,8,8,
 7,7,7,7,8,0,0,0,0,0,0,0,0,8,7,0,
 7,7,7,8,7,7,7,7,7,7,7,7,8,7,8,0,
 7,7,7,8,0,8,0,8,0,8,0,8,0,8,8,0,
 7,7,8,0,7,0,7,0,7,0,7,0,7,0,0,7,
 7,8,w,w,w,w,w,w,w,w,w,w,7,0,7,7,
 7,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,
 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
 };
 return (int *) Computer;
 }

//*********************
void DibujeIcono(int x,int y, int *BitMap,int NumFila,int NumColumna)
 { for(int i=0;i<NumFila;i++)
     for(int j=0;j<NumColumna;j++)
      putpixel(x+j,y+i,*(BitMap++));
 }