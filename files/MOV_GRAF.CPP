#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <process.h>


void main(void)
{
   /* request auto detection */
   int gdriver = DETECT,i, gmode, sw,j ;
int j1,j2 , errorcode,count,corregir;
   //char a[1],h='1';
   void conv_text(int,int,char [],int);

   initgraph(&gdriver, &gmode, "");


 j=50;
 i=0;
 while (i<=400) {

   settextstyle(1, 0, 5);
   setcolor(i);
   outtextxy(j,i,"MACINTOSH");
 i=i+5;
 }
j=50;
 i=0;
 while (i<=  400){
   settextstyle(1, 0, 5);
   setcolor(i);
   outtextxy(j+2,i,"MACINTOSH");
 i=i+5;
 }
 i=0;
 while (i<=  400) {
   setcolor(0);
  settextstyle(1, 0, 5);
    outtextxy(j,i,"MACINTOSH");
    outtextxy(j+2,i,"MACINTOSH");
 i=i+5;
 }

   setcolor(11);
   settextstyle(1, 0, 5);
   outtextxy(180,i+5,"MACINTOSH");
   setcolor(1);
   settextstyle(1, 0, 5);
   outtextxy(182,i+5,"MACINTOSH");

   getch();
   closegraph();
   }

//**************************************************
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