
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <process.h>


void main(void)
{
   /* request auto detection */
   int gdriver = DETECT,i, gmode, sw,j,color ;

   //char a[1],h='1';
   void conv_text(int,int,char [],int);

   initgraph(&gdriver, &gmode, "");


   setbkcolor(7);
   settextstyle(8,0,3);
   conv_text(180,10,"I'm Just a Hacker",4);
   setfillstyle(1, 14);
   setcolor(14);
   for (i=0;i<=80;i++){
   //pieslice(50,120,0,360,20);
   circle(300,160,i);
   }
   setcolor(1);
   line (270,110,270,140);
   for(i=0;i<=15;i++){
   circle(340,125,i);
    }
    line(280,83,340,130);line(350,135,375,185);
    arc(305, 170, 180, 360, 40);


   i=-600;
   while (i<=680){

   settextstyle(7,0,5);
   conv_text(180,400,"By MaCiNtOsH",1);
   settextstyle(1, 0, 6);
   setcolor(color);outtextxy(i-1,250,"You've Been Hacked !!");
   setcolor(1);outtextxy(i,250,"You've Been Hacked !!");
   //delay(1);
   color=getbkcolor();
   if (i==680){i=-500;}
   i++;
   }
 getch();
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