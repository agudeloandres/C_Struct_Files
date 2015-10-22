# include <stdio.h>
# include <dos.h>
# include <conio.h>
#include <graphics.h>
#include <stdlib.h>


int main(void)

{   /* request auto detection */

   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, i;

   /* initialize graphics and local
      variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error
		  code */
   }

   midx = getmaxx()/4;
   midy = getmaxy()/2;
   

      /* set the fill style */
      setfillstyle(6, getmaxcolor());

      /* draw the bar */
      bar(midx-47, midy-200, midx+350,
	 midy-35);


   /* TEXTO */

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

      /* output a message */

     int x ;

      for(x=100 ;x<= 104 ;x++) {
     settextstyle(0,0,3);
     setcolor(BLACK);
     outtextxy(x-6, 107," CARLOS ANDRES" );
     setcolor(BROWN);
     outtextxy(x, 100," CARLOS ANDRES" );
     delay(100);

     }


    textcolor(2);
    textbackground(0);
    int y=1, k,p,q,t;


    gotoxy(4,1); printf("Ú\n");
    gotoxy(74,1);printf("»\n");
    gotoxy(4,23);printf("À\n");
    gotoxy(74,23);printf("¼\n");

    for (k= 5; k<= 73; k ++)
  {gotoxy (k,y);
   delay(50);
  setbkcolor(0); printf("Í\n");
   gotoxy (k,23);printf("Í\n");
  }

   for (p=2; p<=22; p++)
  {gotoxy (4,p);printf("³\n");
   gotoxy (74,p);printf("º\n");
   delay(50);
   }

 /* recuadro interior  */

    gotoxy(14,3); printf("Ú\n");
    gotoxy(64,3);printf("»\n");
    gotoxy(14,13);printf("À\n");
    gotoxy(64,13);printf("¼\n");

    for (k= 15; k<= 63; k ++)
   {gotoxy (k,3);
    printf("Í\n");
    gotoxy (k,13);printf("Í\n");
    delay(20);
    }

   for (p=4; p<=12; p++)
   {gotoxy (14,p);printf("³\n");
    gotoxy (64,p);printf("º\n");
    delay(20);
    }


  textcolor (17);
  textbackground(3);
  gotoxy(25,20);printf("Press any key to continue..\n");
  getch();

}