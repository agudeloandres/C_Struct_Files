#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <process.h>


int main(void)
{
   /* request auto detection */
   int gdriver = DETECT,i, gmode, sw,j ;
int j1,j2 , errorcode,count,corregir;
   char a[1],h='1';
   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {

      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             /* return with error code */
   }





 j=50;
 i=0;
 while (i<=250) {

   settextstyle(1, 0, 5);
   setcolor(0);
   outtextxy(j,i,"CARLOS ANDRES");
 i=i+5;
 }
j=50;
 i=0;
 while (i<=  350){
   settextstyle(1, 0, 5);
   setcolor(15);
   outtextxy(j+2,i,"CARLOS ANDRES");
 i=i+5;
 }
 i=0;
 while (i<=  350) {
   setcolor(0);
  settextstyle(1, 0, 5);
    outtextxy(j,i,"CARLOS ANDRES");
    outtextxy(j+2,i,"CARLOS ANDRES");
 i=i+5;
 }

   setcolor(11);
   settextstyle(1, 0, 5);
   outtextxy(50,i+5,"CARLOS ANDRES");
   setcolor(1);
   settextstyle(1, 0, 5);
   outtextxy(52,i+5,"CARLOS ANDRES");
 getch();
 }