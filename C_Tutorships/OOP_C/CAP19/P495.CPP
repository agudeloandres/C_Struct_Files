#include "iostream.h"
#include "graphics.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"

class TEXTO {
	int fuente,direccion,tamano;
	char *cadena;
public:
	TEXTO(int a,int b,int c,char *d);
	void escribir();
	int tipoletra();
	int dir();
	int dimension();
	char *s();
	~TEXTO() {
		outtext (cadena);
		outtext (" ");
		delete cadena;
	}
};
TEXTO::TEXTO(int a,int b,int c,char *d) {
	fuente = a;
	direccion = b;
	tamano = c;
	cadena = new char [strlen (d) + 1];
	strcpy (cadena, d);
}
void TEXTO::escribir() { outtext(cadena);  }

int TEXTO::tipoletra() { return fuente;  }

int TEXTO::dir() { return direccion;  }

int TEXTO::dimension() { return tamano;  }

char *TEXTO::s() { return cadena ;  }


class textoColor : public TEXTO {
	int color;
public:
	textoColor(int a, int b, int c, char *d, int col);
	void escribir();
	~textoColor() {
		outtext("tc ");
		outtext (s () );
		outtext (" ");
	}
	int col() { return color; }
};

textoColor:: textoColor(int a, int b, int c, char *d, int col)
						: TEXTO (a,b,c,d) {
	color = col;
}
void textoColor::escribir() {
	int t;
	clearviewport();
	t = getcolor();
	setcolor(color);
	settextstyle(tipoletra(), dir(), dimension() );
	outtext(s() );
	setcolor (t);
}

class textoAmpliar : public textoColor {
	int m1x,m2x,m1y,m2y;
public:
	textoAmpliar (int a, int b, int c, char *d,int col,
						int m1xi, int m2xi, int m1yi, int m2yi);
	~textoAmpliar() {
		outtext ("TA ");
	}
	void escribir();
};

textoAmpliar::textoAmpliar (int a, int b, int c, char *d,int col,
						int m1xi, int m2xi, int m1yi, int m2yi)
							: textoColor (a,b,c,d,col) {
	m1x = m1xi;
	m2x = m2xi;
	m1y = m1yi;
	m2y = m2yi;
}

void textoAmpliar::escribir() {
	int t;
	clearviewport();
	t = getcolor();
	setcolor(col() );
	settextstyle(tipoletra(), dir(), dimension() );
	setusercharsize (m1x, m2x, m1y, m2y);
	outtext(s() );
	setcolor (t);
}


int main() {
	{
		TEXTO t(0,0,0,"Algo");
		TEXTO a(GOTHIC_FONT,VERT_DIR,10,"Turbo");
		textoColor b(TRIPLEX_FONT,HORIZ_DIR,10,"Pascal",LIGHTBLUE);
		textoAmpliar c(SANS_SERIF_FONT,HORIZ_DIR,10,"Lenguaje",
								LIGHTRED,5,1,10,1);
		TEXTO *p;
		textoColor *q;
		textoAmpliar *r;

		int unidad=DETECT,modo;

		initgraph (&unidad,&modo,"c:\\bc\\bgi");
		if (graphresult() != 0) {
			cout << "Error al tratar de pasar al modo grafico\n";
			getch();
			return 1;
		}
		t = a;         			// 1
		a = c;						// 2
		a.escribir();				// 3
		getch();
		clearviewport();
		a = t;						// 4
		q = &b;						// 5
		p = q;						// 6
		p->escribir();				// 7
		getch();
		clearviewport();
		r = &c;						// 8
		q = r;						// 9
		q->escribir();				// 10
		getch();
		clearviewport();
		settextstyle (DEFAULT_FONT,HORIZ_DIR,0);
	}
	// Aqui se destruyen los objetos en el siguiente orden:
	// 1) El destructor de la clase derivada
	// 2) El destructor de la clase base
	// Favor estudiar numeral 12.2
	getch();
	closegraph();
	return 0;
}


