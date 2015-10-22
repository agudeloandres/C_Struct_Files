#include "stdio.h"
#include "conio.h"
#define CPR(x) cprintf("%s",x)

void ref1(int ,int ,int ,char *);
void ref2(int,int,int ,char *);
void piso_color(int ,int );
void escr_menu(int ,char *[],struct text_info *,int *);
void marco (int ,int ,int ,int );

void main (){
int c,d;
struct text_info p;

char *archivos[]={
       "Inicializacion Archivos",
       "Ingreso Libreria   ",
       "Retiro Libreria    ",
       "Cambio Datos       ",
       "Estado Cuenta      ",
       "ESC para salir del menu"
       };
char *actualiza[]={
       "Cambio Datos Libreria",
       "Cambio Datos Libros  ",
       "Ingreso Libro Nuevo  ",
       "Retiro Libro         ",
       "ESC para salir       "
       };
char *factura[]={
       "Facturar  ",
       "Abonar    ",
       "Consultar Factura",
       "ESC para salir "
       };
char *listado[]={
       "Listado Libreria",
       "Listado Libros  ",
       "Listado Facturas",
       "ESC para salir  "
       };
char *termina[]={
       "Termina ",
       "ESC     "
       };



piso_color(BLACK,WHITE);
clrscr();
_setcursortype(_NOCURSOR);
piso_color(WHITE,BLACK);
CPR("Archivos de datos");
gotoxy(21,1);
piso_color(BLACK,WHITE);
CPR("Actualizacion");
gotoxy(36,1);
CPR("Facturacion");
gotoxy(53,1);
CPR("Listados");
gotoxy(68,1);
CPR("Terminar");

marco(2,3,25,8);
escr_menu(6,archivos,&p,&c);
d=0;
if (c==75 || c==77){
  d=c;c=0;
 }
 else c=getch();
 while (c==0){
   if (d==0)
    c=getch();
   else {
    c=d;d=0;
  }
  switch(c){
    case 77:switch(p.winleft){
			     case 2: ref1(1,BLACK,WHITE,"Archivos de datos");
				     ref2(21,WHITE,BLACK,"Actualizacion");
				     marco(22,3,43,7);
				     escr_menu(5,actualiza,&p,&c);
				     break;
			     case 22:ref1(21,BLACK,WHITE,"Actualizacion");
				     ref2(36,WHITE,BLACK,"Facturacion");
				     marco(37,3,54,6);
				     escr_menu(4,factura,&p,&c);
				     break;
			     case 37:ref1(36,BLACK,WHITE,"Facturacion");
				     ref2(53,WHITE,BLACK,"Listados");
				     marco(54,3,70,6);
				     escr_menu(4,listado,&p,&c);
				     break;
			     case 54:ref1(53,BLACK,WHITE,"Listados");
				     ref2(68,WHITE,BLACK,"Terminar");
				     marco(69,3,78,4);
				     escr_menu(2,termina,&p,&c);
				     break;
			     case 69:ref1(68,BLACK,WHITE,"Terminar");
				     ref2(1,WHITE,BLACK,"Archivos de datos");
				     marco(2,3,25,8);
				     escr_menu(6,archivos,&p,&c);
				     break;
				     default:cprintf("%c",7);
		       }
		       break;
    case 75:switch(p.winleft){
			     case 2: ref1(1,BLACK,WHITE,"Archivos de datos");
				     ref2(68,WHITE,BLACK,"Terminar");
				     marco(69,3,78,4);
				     escr_menu(2,termina,&p,&c);
				     break;
			     case 22:ref1(21,BLACK,WHITE,"Actualizacion");
				     ref2(1,WHITE,BLACK,"Archivos de datos");
				     marco(2,3,25,8);
				     escr_menu(6,archivos,&p,&c);
				     break;
			     case 37:ref1(36,BLACK,WHITE,"Facturacion");
				     ref2(21,WHITE,BLACK,"Actualizacion");
				     marco(22,3,43,7);
				     escr_menu(5,actualiza,&p,&c);
				     break;
			     case 54:ref1(53,BLACK,WHITE,"Listados");
				     ref2(36,WHITE,BLACK,"Facturacion");
				     marco(37,3,54,6);
				     escr_menu(4,factura,&p,&c);
				     break;
			     case 69:ref1(68,BLACK,WHITE,"Terminar");
				     ref2(53,WHITE,BLACK,"Listados");
				     marco(54,3,70,6);
				     escr_menu(4,listado,&p,&c);
				     break;
				     default:cprintf("%c",7);
			}

		 }
		 d=0;
		 if(c==75||c==77){
		 d=c;
		 c=0;
		 }
		 else c=getch();
	       }
	   }


//***************************
void piso_color(int piso,int color){
textbackground(piso);
textcolor(color);
}
//*******************************
	void ref1(int n,int piso,int color,char *s){
	   window(1,1,80,25);
	   gotoxy(n,1);
	   piso_color(piso,color);
	   CPR(s);
	   }
//******************************
void ref2(int n,int piso,int color,char *s){
window(1,1,80,25);
gotoxy(n,1);
piso_color(piso,color);
CPR(s);
piso_color(BLACK,WHITE);
}
//*****************************

void escr_menu(int n,char *a[],struct text_info *p,int *c){
int i,j,d;
piso_color(BLACK,WHITE);
for (i=0;i<n;i++){
gotoxy(1,i+1);
CPR(a[i]);
}

piso_color(WHITE,BLACK);
gotoxy(1,1);
CPR(a[0]);
gotoxy(1,1);
*c=getch();
 while(*c==0){
   *c=getch();
   switch(*c){
     case 80:piso_color(BLACK,WHITE);
	     CPR(a[wherey()-1]);
	     piso_color(WHITE,BLACK);
	     if(wherey()==n-1)
	      gotoxy(1,1);
	      else gotoxy(1,wherey()+1);
	      CPR(a[wherey()-1]);
	      gotoxy(1,wherey());
	      break;
     case 72:piso_color(BLACK,WHITE);
	     CPR(a[wherey()-1]);
	     piso_color(WHITE,BLACK);
	     if(wherey()==1)
	      gotoxy(1,n-1);
	      else gotoxy(1,wherey()-1);
	      CPR(a[wherey()-1]);
	      gotoxy(1,wherey());
	      break;
     case 77:break;
     case 75:break;
  }
 if(*c==77||*c==75){
  break;
 }
 else *c=getch();

}
piso_color(BLACK,WHITE);
gettextinfo(p);
window((*p).winleft-1,(*p).wintop-1,(*p).winright+1,(*p).winbottom+1);
clrscr();
}
//*********************
void marco (int a,int b,int c, int d){
#define arrizq 201
#define arrder 187
#define abajizq 200
#define abajder 188
#define vert 186
#define horiz 205
#define PR(x) cprintf("%c",x)
 int i;
 window(1,1,80,25);       //Activa la ventana mayor para dibujar el marco
 gotoxy(a-1,b-1);
 PR(arrizq);
 for (i=a;i<=c;i++)
     PR(horiz);
 PR(arrder);
 for(i=b;i<=d;i++){
   gotoxy(c+1,i);
   PR(vert);
 }
 gotoxy(a-1,d+1);
 PR(abajizq);
 for(i=a;i<=c;i++)
   PR(horiz);
   PR(abajder);
   for(i=b;i<=d;i++){
    gotoxy(a-1,i);
    PR(vert);
    }
    window(a,b,c,d);             //Activa ventana dentro del marco
  }







