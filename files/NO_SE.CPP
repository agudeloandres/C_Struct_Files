#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int i;
   int stangle = 0, endangle = 0;
   int xrad = 0, yrad = 0;
   int rad;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

      /* set the fill style */
   int a=330;
     setfillstyle(1,WHITE);
     for (i=50;i<=56;i++){
     sector(i, 250, a+=5, 5,50 , 50);
   delay(100);
     }


      getch();

   /* clean up */






   closegraph();
   return 0;
}

