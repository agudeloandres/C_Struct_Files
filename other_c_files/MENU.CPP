
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define PIXEL_COUNT 10000
#define DELAY_TIME 100   /* in milliseconds */

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int i, x, y, color, maxx, maxy,
       maxcolor, seed;

/* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

/* read result of initialization */
   errorcode = graphresult();
/* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
/* terminate with an error code */
      exit(1);
   }

   maxx = getmaxx() + 1;
   maxy = getmaxy() + 1;
   maxcolor = getmaxcolor() + 1;

   while (!kbhit())
   {
/* seed the random number generator */
      seed = random(32767);
      srand(seed);
      for (i=0; i<PIXEL_COUNT; i++)
      {
	 x = random(maxx);
	 y = random(maxy);
	 color = random(maxcolor);
	 putpixel(x, y, color);
      }
	    setcolor(9);
	    settextstyle(4,0,20);
	    outtextxy(100,60,"Adriana");
	      outtextxy(250,160,"Y");
	       outtextxy(150,280,"Cesar");
      delay(DELAY_TIME);
      srand(seed);
      for (i=0; i<PIXEL_COUNT; i++)
      {
	 x = random(maxx);
	 y = random(maxy);
	 color = random(maxcolor);
	 if (color == getpixel(x, y))
	    putpixel(x, y, 3+14);

      }
   }

/* clean up */
   getch();
   closegraph();
   return 0;
}