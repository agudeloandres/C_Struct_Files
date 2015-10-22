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
   int i, x, y, l,color, maxx, maxy,
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

   settextstyle(7,0,14);
   while (!kbhit())
   {
      settextstyle(7,0,14);
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
	    for(l=1;l<=13;l++){
	    setcolor(x+l);
	    outtextxy(100,60,"CARLOS");
	    outtextxy(60,310,"ANDRES");


   struct  time t;
   gettime(&t);
   settextstyle(0,0,1);
   outtextxy(50,245,"La Hora Actual es:");gotoxy(25,16);printf(" %2d:%02d:%02d.%02d\n",
	  t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);

	    }

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
