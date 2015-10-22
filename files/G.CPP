#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode,x,w;

   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "C:\BGI ");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             /* return with error code */
   }


   setbkcolor(BLUE);
   settextstyle(1,0,3);
   outtextxy(155,50,"INYECTANDO VIRUS ! ");

   bar3d(100,100,450,150,10,1);
   for (x=101;x<=449;x++){
   setfillstyle(1,RED);
   bar(x,101,x,149);
   delay(10);
   }
   for(w=0;w<=300;w++){
   setcolor(w);
   settextstyle(3,0,8);
   outtextxy(100,250,"INFECTADO !!");
   printf("\a\a\a");
   }
   getch();
   closegraph();
   return 0;
}
