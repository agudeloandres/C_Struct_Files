#define arrizq 201
#define arrder 187
#define abajizq 200
#define abajder 188
#define vert 186
#define horiz 205

#define PR(x) cprintf("%c",x)
#include "conio.h"

void marco (int a,int b,int c,int d);
void main(){
 clrscr();
 marco(5,3,75,22);
 getch();
 }


void marco (int a,int b,int c, int d){
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


