#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
  /* request autodetection */
  int gdriver = DETECT, gmode, errorcode;
  int midx, midy, x,y;
  int xradius = 100, yradius = 50;

  /* initialize graphics and local variables */
  initgraph(&gdriver, &gmode, "");

  /* read result of initialization */
  errorcode = graphresult();
  if (errorcode != grOk) {  /* an error occurred */
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");
    getch();
    exit(1);          /* terminate with an error code */
  }



  /* loop through the fill patterns */
  for (x =300 ;x<=500; x++ ) {
  setcolor(RED);
    /* set fill pattern */
    setfillstyle(1, getmaxcolor());

    /* draw a filled ellipse */
    fillellipse(x, 300, xradius+=15, yradius-=2);

  }


   for (x =500 ;x>=300; x-- ) {
  setcolor(BLACK);
    /* set fill pattern */
    setfillstyle(1, BLACK);

    /* draw a filled ellipse */
    fillellipse(x, 300, xradius-=15, yradius+=2);

  }
  getch();

  /* clean up */
  closegraph();
  return 0;
}

