#include "dos.h"
#include "conio.h"

#define si 201
#define sd 187
#define ii 200
#define id 188
#define lh 205
#define lv 186

void main() {
	void marco (int a,int b,int c, int d);
	window (1,1,80,25);

	textbackground (0);
	textcolor (15);

	clrscr();
	marco (2,2,79,24);
	getch();
	window (1,1,80,25);
	textbackground (0);
	textcolor (15);
	clrscr();

}

void marco (int a,int b,int c, int d) {
	int i,j;
	void vaya(int i,int j) ;
	void escriba_c (char c,int veces) ;

	window (1,1,80,25);
	vaya (a-1,b-1);
	escriba_c (si,1);
	vaya(a,b-1);
	escriba_c(lh,c-a+1);
	vaya (c+1,b-1);
	escriba_c (sd,1);
	for (i=b; i <= d; i++ ) {
		vaya (c+1,i);
		escriba_c (lv,1);
	}
	vaya (c+1,d+1);
	escriba_c(id,1);
	vaya (a-1,d+1);
	escriba_c (ii,1);
	vaya (a,d+1);
	escriba_c(lh,c-a+1);
	for (i=b; i <= d; i++ ) {
		vaya (a-1,i);
		escriba_c (lv,1);
	}
	window (a,b,c,d);
	gotoxy (1,1);

}

void vaya(int i,int j) {
	union REGS r;

	r.h.ah = 2;
	r.h.dh = j-1;
	r.h.dl = i-1;
	r.h.bh = 0;
	int86 (0x10,&r,&r);
}


void escriba_c (char c,int veces) {
	union REGS r;

	r.h.ah = 0xa;
	r.h.al = c;
	r.h.bh = 0;
	r.x.cx = veces;
	int86 (0x10,&r,&r);
}


