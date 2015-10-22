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


#include "b:\cap20\mouse.cpp"

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
		if (i == -1)
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

class Titulada : public Ventana {
	void NombreVentana();
protected:
	char *Texto;
public:
	Titulada (int Xi,int Yi,int X1i, int Y1i,
					int TieneBordei, int Bufferi, char *Textoi);
	~Titulada();
	void DVentana();
	void DibujarAviso(char *);
};

Titulada::Titulada (int Xi,int Yi,int X1i, int Y1i,
					int TieneBordei, int Bufferi, char *Textoi) :
							Ventana (Xi,Yi,X1i, Y1i, TieneBordei, Bufferi) {
	Texto = new char [strlen (Textoi) + 1];
	strcpy (Texto, Textoi);
}

Titulada::~Titulada() {
	delete Texto;
}

void Titulada::NombreVentana() {
	mouse.Esconder();
	setcolor(WHITE);
	rectangle (X+9, Y+9, X1-9, Y+31);
	setfillstyle (SOLID_FILL, DARKGRAY);
	bar (X+10,Y+10, X1-10,Y+30);
	int i = X1 - X + 1 - strlen (Texto) * 8;
	i = i / 2;
	outtextxy (X+i,Y + 15, Texto);
	mouse.Mostrar();
}

void Titulada::DVentana() {
	DibujarVentana();
	NombreVentana();
}


void Titulada::DibujarAviso(char *p) {
	delete Texto;
	Texto = new char [strlen (p) + 1];
	strcpy (Texto, p);
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
		Titulada ObjetoV1 (10,20,250,170,0, 0,"MENU NOMINA");
		ObjetoV1.DVentana();
		Titulada *ObjetoV2 = new Titulada (40,50,280,200,1,1,"MENU CONTABLE");
		ObjetoV2->DVentana();
		mouse.LibBotones();
		ObjetoV2->Interactuar();
		delete ObjetoV2;
		mouse.LibBotones();
		ObjetoV1.Interactuar();
	}
	closegraph();
	return 0;
}

