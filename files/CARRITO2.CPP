#include "graphics.h"
#include "stdlib.h"
#include "stdio.h"
#include "dos.h"
#include "conio.h"

main (){

int gdriver=0,gmode;
unsigned int size1,c=0,x1=246,y1=146;
void *car2;
int pol[]={245,145,305,145,305,170,345,170,345,200,245,200};

initgraph(&gdriver,&gmode," ");
   setbkcolor(WHITE);
   setfillstyle(1,BLUE);
   fillpoly(6,pol);
   setcolor(BLUE);
   setfillstyle(1,GREEN);
   fillellipse(253,200,15,15);
   fillellipse(337,200,15,15);
   size1=imagesize(235,144,355,215);
   car2=malloc(size1);
   getimage(235,144,355,215,car2);getch();
   for (;c<=50;c++){
   cleardevice();
   x1+=3;
   y1+=4;
   putimage(x1,y1,car2,0);
   delay(50);
   }
   free(car2);
 getch();
closegraph();
}