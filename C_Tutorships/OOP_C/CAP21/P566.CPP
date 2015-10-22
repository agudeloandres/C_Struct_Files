#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "stdio.h"
#include "dos.h"
#include "stdlib.h"
#include "bios.h"
#include "string.h"

unsigned Ctrl[] = {
	0x1e01, 0x3002, 0x2e03, 0x2004, 0x1205, 0x2106,
	0x2207, 0x2308, 0x1709, 0x240a, 0x250b, 0x260c,
	0x320d, 0x310e, 0x180f, 0x1910, 0x1011, 0x1312,
	0x1f13, 0x1414, 0x1615, 0x2f16, 0x1117, 0x2d18,
	0x1519, 0x2c1a
};


#include "c:\borlandc\bin\becerra\c__orien\cap20\mouse.cpp"

MOUSE mouse;
struct TipoMensaje {
	int Tipo,X,Y,Boton;
	unsigned Llave;
};

void getch1(unsigned *c) {
	*c = bioskey (1);
	if (*c != 0)
		*c = bioskey (0);
}

void Accion (struct TipoMensaje *p) {
	int Boton,Vert,Horiz,c;

	p->Boton = mouse.Estado (&p->X, &p->Y);
	getch1(&p->Llave);

	while (p->Boton == 0 &&  p->Llave == 0) {
		p->Boton = mouse.Estado (&p->X, &p->Y);
		getch1(&p->Llave);
	}
	if (p->Boton != 0)
		p->Tipo = Boton;
	else p->Tipo = 4;
}

class Ventana {
	void Error (char *);
	int *Copia;
protected:
	int X,Y;
	int X1,Y1;
	int TieneBorde,Buffer;
	TipoMensaje Mensaje;
public:
	Ventana (int Xi,int Yi,int X1i, int Y1i,
					int TieneBordei, int Bufferi);
	~Ventana();
	void DibujarVentana();
	void Interactuar();
};

Ventana::Ventana (int Xi,int Yi,int X1i, int Y1i,
					int TieneBordei, int Bufferi) {
	X = Xi;
	Y = Yi;
	X1 = X1i;
	Y1 = Y1i;
	Copia = NULL;
	TieneBorde = TieneBordei;
	Buffer = Bufferi;
}
Ventana::~Ventana() {
	if (Copia != NULL) {
		mouse.Esconder();
		putimage (X,Y,Copia,COPY_PUT);
		delete Copia;
		mouse.Mostrar();
	}
}
void Ventana::DibujarVentana() {
	int i;
	mouse.Esconder();
	if (Buffer != 0) {
		i = imagesize (X, Y, X1, Y1);
		if (i == -1)  // Asi debe ser y no como en el programa de la
							// pagina 565. Favor corregir sobre el texto.
			Error("Imagen muy grande para almacenar");
		Copia = new int [i];
		if (Copia == NULL)
			Error("Memoria Insuficiente");
		getimage (X, Y, X1, Y1, Copia);
	}
	setcolor (WHITE);
	rectangle (X, Y, X1, Y1);
	setfillstyle (SOLID_FILL, LIGHTGRAY);
	bar (X+1, Y+1, X1-1, Y1-1);
	if (TieneBorde != 0) {
		// Implemente aqui el Tipo de Borde deseado
	}
	mouse.Mostrar();
}
void Ventana::Interactuar() {
	Accion (&Mensaje);
}

void Ventana::Error(char *p) {
	setbkcolor(YELLOW);
	setcolor (BLACK);
	outtextxy(0,0,p);
	getch();
	closegraph();
	exit (1);
}

int main() {
	{
		int unidad = 0,modo;
		mouse.Inicializar();
		initgraph (&unidad,&modo,"c:\\bc\\bgi");
		if (graphresult() != 0) {
			cout << "Error al tratar de pasar al modo grafico\n";
			getch();
			return 1;
		}
		mouse.Mostrar();
		setcolor(BLUE);
		Ventana ObjetoV1 (10,20,250,170,0, 0);
		ObjetoV1.DibujarVentana();
		Ventana *ObjetoV2 = new Ventana(40,50,280,200,1,1);
		ObjetoV2->DibujarVentana();
		mouse.LibBotones();
		ObjetoV2->Interactuar();
		delete ObjetoV2;
		mouse.LibBotones();
		ObjetoV1.Interactuar();
	}
	closegraph();
	return 0;
}

