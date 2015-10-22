#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void ModoGrafico(){

   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

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

}


void Bar3DDraw(void)
{
  static long barheight[] = {
    1, 2, 4, 8, 16,32,40, 0, 6, 2, 4,9,10,8,9,4,3,1,2,6,5,4,3,2,1,3,6,9,10};
  struct viewporttype vp;
  int xstep, ystep;
  int i, j, h, color, bheight;
  char buffer[50];
  int    MaxX, MaxY;		/* The maximum resolution of the screen */
  int    MaxColors;		/* The maximum # of colors available	*/

  //MaxColors = getmaxcolor() + 1;	/* Read maximum number of colors*/

  MaxX = getmaxx();
  //MaxY = getmaxy();			/* Read size of screen		*/
  h = 3 * textheight( "H" );
  getviewsettings( &vp );
  settextjustify( CENTER_TEXT, TOP_TEXT );
  settextstyle( TRIPLEX_FONT, HORIZ_DIR, 4 );
  outtextxy( MaxX/2, 6, "** Histograma **" );
  settextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );
  setviewport( vp.left+50, vp.top+40, vp.right-50, vp.bottom-10, 1 );
  getviewsettings( &vp );

  line( h, h-16, h, vp.bottom-vp.top-h );
  line( h, (vp.bottom-vp.top)-h, (vp.right-vp.left)-h+10, (vp.bottom-vp.top)-h );
  xstep = ((vp.right-vp.left) - (15*h)) / 10;  //Salen 10*3-1 barras (29)
  ystep = ((vp.bottom-vp.top) - (14*h)) / 10;   //Salen 4*4 divisiones en Y (16)
  j = (vp.bottom-vp.top) - h;
  settextjustify( CENTER_TEXT, CENTER_TEXT );

  for( i=0 ; i<100 ; ++i ){
    line( h/2, j, h, j );
    itoa( i, buffer, 10 );
    //outtextxy( 0, j, buffer );
    j -= ystep;
  }

  j = h;
  settextjustify( CENTER_TEXT, TOP_TEXT );

  //Draw the fucking 3D Bars
  for( i=0 ; i<30 ; ++i ){
    //color = random(16);
    setfillstyle( i%12, i%16);
    line( j, (vp.bottom-vp.top)-h, j, (vp.bottom-vp.top-3)-(h/2) );
    itoa( i, buffer, 10 );
    //outtextxy( j, (vp.bottom-vp.top)-(h/2), buffer );
    if( i < 29 ){
      bheight = (vp.bottom-vp.top) - h - 1;
      bar3d( j, (vp.bottom-vp.top-h)-(barheight[i]*ystep), j+xstep, bheight, 4, 1 );

    }
    j += xstep;
  }

  getch();

  j = h;
  for (i=0;i<28;++i){
    setcolor(1);setlinestyle(0,0,3);
    line(j+xstep/100, (vp.bottom-vp.top-h)-(barheight[i]*ystep),j+xstep,(vp.bottom-vp.top-h)-(barheight[i+1]*ystep));
    j += xstep;

  }


  getch();
}


void main(){
 ModoGrafico();
 Bar3DDraw();
 closegraph();
}