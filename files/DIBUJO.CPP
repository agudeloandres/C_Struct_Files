#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   void dibujo(void);
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode,x,y;

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

   /* draw a line */
   //line(0, 0, getmaxx(), getmaxy());

    dibujo();



   /* clean up */
   getch();
   closegraph();
   return 0;
}

 void dibujo(void)
{
	int x=280,y=200;
	setcolor(15);
	rectangle(x,y,x+79,y+79);
	setfillstyle(1,15);
	floodfill(x+1,y+1,15);
	setcolor(0);
	line(x+7,y+11,x+7,y+15);
	putpixel(x+8,y+11,0);
	setcolor(9);
	line(x+8,y+12,x+8,y+14);
	putpixel(x+8,y+15,0);
	putpixel(x+9,y+11,0);
	line(x+9,y+12,x+9,y+14);
	putpixel(x+9,y+15,0);
	putpixel(x+10,y+11,0);
	line(x+10,y+12,x+10,y+14);
	putpixel(x+10,y+15,0);
	putpixel(x+11,y+11,0);
	line(x+11,y+12,x+11,y+14);
	putpixel(x+11,y+15,0);
	putpixel(x+12,y+11,0);
	line(x+12,y+12,x+12,y+14);
	putpixel(x+12,y+15,0);
	setcolor(0);
	line(x+13,y+9,x+13,y+11);
	setcolor(9);
	line(x+13,y+12,x+13,y+14);
	setcolor(0);
	line(x+13,y+15,x+13,y+17);
	putpixel(x+14,y+10,0);
	setcolor(9);
	line(x+14,y+11,x+14,y+15);
	putpixel(x+14,y+16,0);
	setcolor(0);
	line(x+15,y+3,x+15,y+11);
	setcolor(9);
	line(x+15,y+12,x+15,y+14);
	setcolor(0);
	line(x+15,y+15,x+15,y+23);
	putpixel(x+16,y+3,0);
	setcolor(8);
	line(x+16,y+4,x+16,y+11);
	putpixel(x+16,y+12,0);
	putpixel(x+16,y+13,9);
	putpixel(x+16,y+14,0);
	line(x+16,y+15,x+16,y+22);
	putpixel(x+16,y+23,0);
	putpixel(x+17,y+3,0);
	line(x+17,y+4,x+17,y+12);
	putpixel(x+17,y+13,0);
	line(x+17,y+14,x+17,y+22);
	putpixel(x+17,y+23,0);
	putpixel(x+18,y+3,0);
	line(x+18,y+4,x+18,y+22);
	putpixel(x+18,y+23,0);
	putpixel(x+19,y+3,0);
	line(x+19,y+4,x+19,y+22);
	putpixel(x+19,y+23,0);
	putpixel(x+20,y+3,0);
	line(x+20,y+4,x+20,y+5);
	setcolor(0);
	line(x+20,y+6,x+20,y+26);
	putpixel(x+21,y+3,0);
	setcolor(8);
	line(x+21,y+4,x+21,y+5);
	putpixel(x+21,y+6,0);
	setcolor(11);
	line(x+21,y+7,x+21,y+14);
	setcolor(8);
	line(x+21,y+15,x+21,y+16);
	setcolor(11);
	line(x+21,y+17,x+21,y+25);
	putpixel(x+21,y+26,0);
	putpixel(x+22,y+3,0);
	putpixel(x+22,y+4,8);
	putpixel(x+22,y+5,0);
	line(x+22,y+6,x+22,y+14);
	setcolor(8);
	line(x+22,y+15,x+22,y+16);
	setcolor(11);
	line(x+22,y+17,x+22,y+24);
	putpixel(x+22,y+25,0);
	putpixel(x+23,y+3,0);
	putpixel(x+23,y+4,8);
	putpixel(x+23,y+5,0);
	line(x+23,y+6,x+23,y+24);
	putpixel(x+23,y+25,0);
	setcolor(0);
	line(x+24,y+3,x+24,y+4);
	setcolor(11);
	line(x+24,y+5,x+24,y+23);
	putpixel(x+24,y+24,0);
	setcolor(0);
	line(x+25,y+3,x+25,y+4);
	setcolor(11);
	line(x+25,y+5,x+25,y+23);
	putpixel(x+25,y+24,0);
	putpixel(x+26,y+3,0);
	line(x+26,y+4,x+26,y+22);
	putpixel(x+26,y+23,0);
	setcolor(0);
	line(x+27,y+3,x+27,y+23);
}
