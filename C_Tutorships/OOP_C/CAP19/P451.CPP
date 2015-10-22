#include "iostream.h"
#include "graphics.h"
#include "string.h"
#include "conio.h"

class TEXTO {
	int fuente,direccion,tamano;
	char cadena[40];
public:
	void init (int a,int b,int c,char *d);
	void escribir();
	int tipoletra();
	int dir();
	int dimension();
	char *s();
};

void TEXTO::init (int a,int b,int c,char *d) {
	fuente = a;
	direccion = b;
	tamano = c;
	strcpy (cadena, d);
}
void TEXTO::escribir() { outtext(cadena);  }

int TEXTO::tipoletra() { return fuente;  }

int TEXTO::dir() { return direccion;  }

int TEXTO::dimension() { return tamano;  }

char *TEXTO::s() { return cadena ;  }

int main() {
	TEXTO a,b,c,d;

	a.init (GOTHIC_FONT,  VERT_DIR,  10,  "Turbo");

	b.init (TRIPLEX_FONT,  HORIZ_DIR,  10,  "Pascal");

	c.init (SANS_SERIF_FONT,  HORIZ_DIR,  10,  "Lenguaje");

	d.init (TRIPLEX_FONT,  VERT_DIR,  10,  "C++");


	// Otras instrucciones


	int unidad=DETECT,modo;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	settextstyle (a.tipoletra(), a.dir(), a.dimension()  );
	a.escribir();
	getch();

	clearviewport();
	settextstyle (b.tipoletra(), b.dir(), b.dimension()  );
	b.escribir();
	getch();

	clearviewport();
	settextstyle (c.tipoletra(), c.dir(), c.dimension()  );
	c.escribir();
	getch();

	clearviewport();
	settextstyle (d.tipoletra(), d.dir(), d.dimension()  );
	d.escribir();
	getch();

	closegraph();
	return 0;
}


