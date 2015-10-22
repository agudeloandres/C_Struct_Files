#include "iostream.h"
#include "dos.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "graphics.h"
#include "stdarg.h"

#define IZQUIERDO 1
#define DERECHO 2

class MOUSE {
	int Inicializado;
	int Desconectado;
	int NBotones;
public:
	MOUSE(void);
	~MOUSE(void);
	int ExisteUnidad(void);
	void Inicializar();
	int FIni () { return Inicializado; }
	int FDes () { return Desconectado; }
	int NumBotones() { return NBotones; }
	void Mostrar();
	void Esconder();
	int Estado (int *Vertical, int *Horizontal);
	void Posicionar (int Vert, int Horiz);
	void Escribir (int Vert, int Horiz, ...);
};


MOUSE::MOUSE() {
	Inicializado = 0;
	Desconectado = 1;
}

int MOUSE::ExisteUnidad(void) {
	void far *direccion;
	union REGS r;
	direccion = getvect (0x33);
	return (direccion != NULL && *(unsigned char *)direccion != 0xcf);
}

void MOUSE::Inicializar () {
	union REGS r;
	Inicializado = ExisteUnidad();
	if (Inicializado )  {
		r.x.ax = 0x00;
		int86 (0x33,&r,&r);
		NBotones = r.x.bx;
		Desconectado = 0;
	}
	else Desconectado = 1;
}

MOUSE::~MOUSE(void) { }

void MOUSE::Mostrar() {
	union REGS r;

	r.x.ax = 0x01;

	int86 (0x33,&r,&r);
}

void MOUSE::Esconder() {
	union REGS r;

	r.x.ax = 0x02;

	int86 (0x33,&r,&r);
}

int MOUSE::Estado(int *Vertical, int *Horizontal) {
	union REGS r;

	r.x.ax = 0x03;

	int86 (0x33,&r,&r);
	*Vertical = r.x.cx;
	*Horizontal = r.x.dx;
	return r.x.bx;
}

void MOUSE::Posicionar (int Vert, int Horiz) {
	union REGS r;

	r.x.ax = 0x04;
	r.x.dx = Horiz;
	r.x.cx = Vert;

	int86 (0x33,&r,&r);
}


void MOUSE::Escribir (int Vert, int Horiz, ...) {
	va_list lista;
	char a[10];

	moveto (Vert,Horiz);
	va_start (lista,msg);
	int numero = va_arg (lista,int);
	while (numero != 999) {
		itoa (numero, a, 10);
		outtext (a);
		outtext ("  ");
		numero = va_arg (lista,int);
	}
}

int main() {
	int unidad = DETECT, modo,Boton,Horiz,Vert,Veces;
	MOUSE mouse;
	mouse.Inicializar();

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	mouse.Mostrar();
	Boton = mouse.Estado (&Vert, &Horiz);
	while (Boton != IZQUIERDO) {
		Boton = mouse.Estado (&Vert, &Horiz);
		if (Boton == DERECHO) {
			mouse.Esconder();
			mouse.Posicionar(Vert,Horiz);
			mouse.Escribir (Vert,Horiz,    Vert,Horiz,999);
			mouse.Mostrar();
			Boton = mouse.Estado (&Vert, &Horiz);
			while (Boton != 0)
				Boton = mouse.Estado (&Vert,&Horiz);
		}
	}
	while (Boton != 0)
		Boton = mouse.Estado (&Vert,&Horiz);
	getch();
	closegraph();
	return 0;
}

