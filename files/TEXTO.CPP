
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "string.h"

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   char* text,c;

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


   do{
   text='\0';
   c=getch();
   sprintf(text,"%c",c);
   outtext(text);
   }while (c!=13);



   getch();
   closegraph();
   return 0;
}
