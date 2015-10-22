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


#include "C:\BORLANDC\BIN\BECERRA\C__ORIEN\cap20\mouse.cpp"

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

class ClaseBoton : public Ventana {
	char *NombreBoton;
	unsigned Clave;
	unsigned LlaveAlterna;
public:
	ClaseBoton (int X,int Y,char *p);
	void DibujarBoton(unsigned *Ctrl);
	~ClaseBoton();
	void Oprimir();
	int Interface(TipoMensaje Mensaje);
};

ClaseBoton::ClaseBoton (int X, int Y,char *p) : Ventana (X,Y,X+64,Y+32,0,0) {
	NombreBoton = new char [strlen (p) + 1 ];
	strcpy (NombreBoton, p);
	Clave = LlaveAlterna = 0;
}

void ClaseBoton::Oprimir() {
	sound (2000);
	delay (100);
	nosound();
}
ClaseBoton :: ~ClaseBoton() {
	delete NombreBoton;
}

void ClaseBoton::DibujarBoton(unsigned *Ctrl) {
	DibujarVentana();
	mouse.Esconder();
	char *T = new char [strlen (NombreBoton) + 1];
	strcpy (T,NombreBoton);
	int j, i = 0,pos = -1;
	while (i < strlen (T) ) {
		if (T [i] == '^') {
			pos = i;
			Clave = Ctrl [T[i+1] - 'A'];
			j = i;
			while (j < strlen (T) ) {
				T[j] = T[j+1];
				j++;
			}
			break;
		}
		i++;
	}
	if (strcmp (T, "OK") == 0)
		LlaveAlterna = 0x1c0d;
	else if (strcmp (T,"CANCELA") == 0)
		LlaveAlterna = 0x011b;
	i = X1 - X + 1 - strlen (T) * 8;
	i = i / 2;
	setcolor (BLACK);
	outtextxy (X + i,Y+12,T);
	if (pos >= 0)
		line ((X+i)+pos*8, Y+20, (X+i)+pos*8 + 6, Y+20);
	delete T;
	mouse.Mostrar();
}

int ClaseBoton::Interface(TipoMensaje Mensaje) {
	if (Mensaje.Tipo != 0 &&
		Mensaje.X >= X && Mensaje.X <= X1 &&
		Mensaje.Y >= Y && Mensaje.Y <= Y1) {
		Oprimir();
		return 1;
	}
	else if (Mensaje.Tipo == 4) {
				if (Mensaje.Llave == Clave ||
						Mensaje.Llave == LlaveAlterna) {
						Oprimir();
						return 1;
				}
	}
	return 0;
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
		struct TipoMensaje Mensaje;
		mouse.Mostrar();
		ClaseBoton B1 (100,200,"^OK");
		ClaseBoton B2 (180,200,"^CANCELA");
		ClaseBoton B3 (260,200,"U^NO");
		ClaseBoton B4 (340,200,"DO^S");
		ClaseBoton B5 (420,200,"^TRES");
		ClaseBoton B6 (20,200,"CUAT^RO");
		B1.DibujarBoton(Ctrl);
		B2.DibujarBoton(Ctrl);
		B3.DibujarBoton(Ctrl);
		B4.DibujarBoton(Ctrl);
		B5.DibujarBoton(Ctrl);
		B6.DibujarBoton(Ctrl);
		int i,Vert,Horiz,Boton;
		mouse.LibBotones();
		Boton = 0;
		while ( Boton == 0) {
			Accion ( &Mensaje);
			if (B1.Interface (Mensaje) == 1)
				Boton = 1;
			else if (B2.Interface(Mensaje) == 1)
				Boton = 2;
			if (B3.Interface (Mensaje) == 1)
				Boton = 3;
			else if (B4.Interface(Mensaje) == 1)
				Boton = 4;
			if (B5.Interface (Mensaje) == 1)
				Boton = 5;
			if (B6.Interface (Mensaje) == 1)
				Boton = 6;
		}
		setcolor (WHITE);
		mouse.Esconder();
		switch (Boton) {
			case 1 : outtextxy (0,0,"Boton 1"); break;
			case 2 : outtextxy (0,0,"Boton 2"); break;
			case 3 : outtextxy (0,0,"Boton 3"); break;
			case 4 : outtextxy (0,0,"Boton 4"); break;
			case 5 : outtextxy (0,0,"Boton 5"); break;
			case 6 : outtextxy (0,0,"Boton 6"); break;
		}
		mouse.Mostrar();
		mouse.LibBotones();
		mouse.OprimirBoton();
	}
	closegraph();
	return 0;
}

