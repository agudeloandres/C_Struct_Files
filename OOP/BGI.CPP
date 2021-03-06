#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int huge detectLEEVGA(void);


main()
{

	int driver=0, mode;
	int ysize, xsize;
	int i;


//driver =installuserdriver ("LEEVGA", detectLEEVGA);

initgraph(&driver,&mode," ");
	{
	int ec;
	if ((ec=graphresult()) < 0)  {
		printf("unable to register\n");
		printf("reason <%s>\n", grapherrormsg(ec));
		exit(-1);
		return(-1);
	}
	}


 driver = DETECT;
	initgraph(&driver, &mode, "");

	{
	int ec;
	if ((ec=graphresult()) < 0)  {
		printf("unable to open this graphics mode\n");
		printf("reason <%s>\n", grapherrormsg(ec));
		exit(-1);
		return(-1);
	}
	}


printf("  max x=       %d\n",	xsize=getmaxx());
printf("  max y=       %d\n",	ysize=getmaxy());
printf("  modename=    %s\n", getmodename(0));
printf("  drivername=  %s\n", getdrivername());
printf("  maxcolors=   %d\n", getmaxcolor());
printf("  palette size=%d\n", getpalettesize());


#define DO 1
#ifdef DO
	setfillstyle ( SOLID_FILL, 15 );
	setcolor ( 12 );

	outtextxy(xsize/6,ysize/3,"A b C d E f G h I J k"); getch();
	printf("  Outtext  ( DEFAULT FONT )  is done\n"); getch();

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	outtextxy(xsize/6,ysize/4,"0 1 2 3 4 5 6 7 8 9 0");
	printf("  Outtext  ( TRIPLEX_FONT )  is done\n"); getch();

setlinestyle(DASHED_LINE,0,NORM_WIDTH);

 for (i=10; i < xsize/3*2 ; i++) {
	putpixel(i,ysize/4,12);
}
printf("  pixel puts are done, press a key\n");getch();

#endif

setfillstyle ( SLASH_FILL, 11 );
setlinestyle(DASHED_LINE,0,NORM_WIDTH);

pieslice(xsize/2,ysize/2,45,45+90,ysize/3);


circle (xsize/2, ysize/2,ysize/2);
ellipse(xsize/2,ysize/2,0,0,100,100);
printf("  circle done press a key\n");getch();

setlinestyle(CENTER_LINE,0,NORM_WIDTH);
line (  10,ysize/2,ysize-100,ysize/2);
line ( xsize/2, 10 , xsize/2 , ysize/2 );
printf("  lines done, press a key\n");getch();

rectangle (10,20,xsize/6,ysize/2);
printf("  rectangle done, press a key\n");getch();


setlinestyle(DOTTED_LINE,0,THICK_WIDTH);

setfillstyle ( XHATCH_FILL, 21 );
setcolor(83);
bar3d ( xsize/2,ysize/2,  xsize/6*5,ysize, 50, 1);
printf("  bar is done, press a key\n");getch();
setlinestyle(DASHED_LINE,0,NORM_WIDTH);


{
	int pp[10]={100,100, 100,150, 180,195, 300,150, 330,100};

setfillstyle ( CLOSE_DOT_FILL, 11 );

fillpoly ( 5 , &pp );
printf("  filled polygon is done, press a key\n");getch();
}




setrgbpalette(12,1,2,3);

{
typedef struct {
	char r,g,b;
} entry;

struct p {
	char size;
	entry index[256];
} palette;

palette.size = 3*256;
palette.index[0].r =1;
palette.index[0].g =2;
palette.index[0].b =3;


setallpalette(&palette);
}




 cleardevice();
 printf("  clear done\n");


 printf("  press a key\n");getch();
 closegraph();

}




/* ______________________ */

int huge detectLEEVGA(void)
{

	printf("detecting\n");
	
	/*
		You must write code here to detect whether or not
		the graphics card is available and what its maximum mode
		is.  By returning the value of ONE here, I am telling 
		it I have detected my graphics card and the mode I want 
		it to use is ONE.
		
	*/	

	return(1);
}