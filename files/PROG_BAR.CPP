#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
# include <dos.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, i,k;

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


    /* draw the 3-d bar */
      bar3d(100, 100, 400,140, 10, 1);

   /* loop through the fill patterns */
   k=0;
   for (i=100; i<=401; i++)
   {

      /* set the fill style */
      setfillstyle(1, BLUE);
      /* draw the bar */
      bar(100, 100, i,140);
    gotoxy (35,8);printf("%d%",k);
    gotoxy(30,8);printf("|");
    delay(8);
    gotoxy(30,8);printf("\\");
    delay(8);
    gotoxy(30,8);printf("-");
    delay(8);
    gotoxy(30,8);printf("/");
    delay(8);
    gotoxy(30,8);printf("|");
    delay(8);
    k=(300-i);

    system("del *.bak");
    system("del *.obj");


   }
    getch();
    system("dir");
   /* clean up */
   closegraph();
   return 0;
}

