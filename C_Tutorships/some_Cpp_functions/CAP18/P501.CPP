#include "graphics.h"
#include "conio.h"
#include "stdlib.h"
#include "stdio.h"
void main() {
 int drive=DETECT,modo=DETECT;
 initgraph(&drive,&modo,"c:\\bc\\bgi");
 rectangle (10,10,200,150);
 line (10,10,200,150);
 line (10,150,200,10);
 bar (100,50,150,100);
 getch();
 unsigned int n = imagesize(10,10,200,150);
 char *imagen = new char [n];
 getimage (10,10,200,150,imagen);

 FILE *p = fopen ("ximagen","w");
 int i;
 i=0;
 while (i < n) {
	fputc(imagen[i],p);
	i++;
 }
 //fwrite (imagen,n,1,p) ; // ver pagina 214 de las funciones
 fclose (p);
 delete imagen;
 bar (0,0,300,300);
 getch();
 p=fopen ("ximagen","r");
 unsigned int x,y;
 char *q;
 q = (char *)&x;
 *q = fgetc (p);
 q++;
 *q = fgetc (p);
 //	fread (&x,2,1,p);
 q = (char *)&y;
 *q = fgetc (p);
 q++;
 *q = fgetc (p);
 //	fread (&y,2,1,p);

 n = imagesize (0,0,x,y);
 imagen = new char [n];
 rewind (p);
 i=0;
 while (i < n) {
	imagen [i] = fgetc(p);
	i++;
 }
 //fread(imagen,n,1,p);
 fclose (p);
 cleardevice();
 getch();
 putimage (200,10,imagen,COPY_PUT);
 getch();
 delete imagen;
 closegraph();

}