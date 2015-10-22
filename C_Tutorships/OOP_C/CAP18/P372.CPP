#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

#define clipon 1
#define clipoff 0

int main() {
	int unidad = 0,modo,k,x,y,tx,ty;
	char s[10],s1[10],*titulo;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setcolor (YELLOW);
	getaspectratio (&x,&y);
	tx = x;
	ty = y;
	itoa (x,s,10);
	itoa (y,s1,10);
	k = strlen (s) + strlen (" ") + strlen (s1) + 1;
	titulo = new char [k];
	strcpy (titulo,s);
	strcat (titulo," ");
	strcat (titulo,s1);
	outtextxy (0,10,titulo);
	delete titulo;
	gcvt ( (double)y / x,5,s);
	outtextxy (200,10,s);
	circle (200,200,100);

	setcolor (WHITE);
	setaspectratio (tx / 2,ty);
	getaspectratio (&x,&y);
	itoa (x,s,10);
	itoa (y,s1,10);
	k = strlen (s) + strlen (" ") + strlen (s1) + 1;
	titulo = new char [k];
	strcpy (titulo,s);
	strcat (titulo," ");
	strcat (titulo,s1);
	outtextxy (0,20,titulo);
	delete titulo;
	gcvt ( (double)y / x,5,s);
	outtextxy (200,20,s);
	circle (200,200,100);

	setcolor (RED);
	setaspectratio (tx,ty / 2);
	getaspectratio (&x,&y);
	
	itoa (x,s,10);
	itoa (y,s1,10);
	k = strlen (s) + strlen (" ") + strlen (s1) + 1;
	titulo = new char [k];
	strcpy (titulo,s);
	strcat (titulo," ");
	strcat (titulo,s1);
	outtextxy (0,30,titulo);
	delete titulo;
	gcvt ( (double)y / x,5,s);
	outtextxy (200,30,s);
	circle (200,200,100);
	getch();
	closegraph();
	return 0;
}