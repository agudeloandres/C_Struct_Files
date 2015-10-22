#include "iostream.h"
#include "dos.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "graphics.h"
#include "stdarg.h"

#define IZQUIERDO 1
#define DERECHO 2
#define AMBOSBOTONES 3

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
	void BotonInfo(int Boton,int *Vert, int *Horiz,
							int *Estado,int *Veces);
	void BotonLib(int Boton,int *Vert, int *Horiz,
							int *Estado,int *Veces);
	void LimVert (int x, int x1);
	void LimHoriz (int y, int y1);
	void LibBotones();
	void CambioMouse(int *Vert, int *Horiz);
	void FormaCursor();
	void OprimirBoton();
	void VelocidadMouse(int x, int y);
	void AreaProtegida(int x, int y, int x1, int y1);
	void DoblaVelocidad(int Veloc);
	void VentActual(int *p, int *q, int *r, int *s);
	void Sensitividad(int *p, int *q);
	void Escribir (int Vert, int Horiz, ...);
	void MOUSE::DeterminaSensiti(int Vert, int Horiz);
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

void MOUSE::BotonInfo(int Boton,int *Vert,int *Horiz,
							int *Estado,int *Veces) {
	union REGS r;

	r.x.ax = 0x05;
	r.x.bx = Boton - 1;

	int86 (0x33,&r,&r);
	*Vert = r.x.cx;
	*Horiz = r.x.dx;
	*Estado = r.h.al;
	*Veces = r.x.bx;
}

void MOUSE::BotonLib(int Boton,int *Vert,int *Horiz,
							int *Estado,int *Veces) {
	union REGS r;

	r.x.ax = 0x06;
	r.x.bx = Boton - 1;

	int86 (0x33,&r,&r);
	*Vert = r.x.cx;
	*Horiz = r.x.dx;
	*Estado = r.h.al;
	*Veces = r.x.bx;
}

void MOUSE::LimVert(int x, int x1) {
	union REGS r;

	r.x.ax = 0x07;
	r.x.cx = x;
	r.x.dx = x1;
	int86 (0x33,&r,&r);
}

void MOUSE::LimHoriz (int y, int y1) {
	union REGS r;

	r.x.ax = 0x08;
	r.x.cx = y;
	r.x.dx = y1;
	int86 (0x33,&r,&r);
}

void MOUSE::LibBotones() {
	int Boton,Vert,Horiz;

	Boton = Estado (&Vert, &Horiz);
	while (Boton != 0)
		Boton = Estado (&Vert, &Horiz);
}


void MOUSE::CambioMouse(int *Vert, int *Horiz) {
	union REGS r;

	r.x.ax = 0x0b;
	int86 (0x33,&r,&r);
	*Vert = r.x.cx;
	*Horiz = r.x.dx;
}

int fig[32] = {
	0x3ff8, 0x1ff0, 0x0fe1, 0x87c3,0xc387,0xe10f, 0xf01f, 0xf83f,
	0xf83f, 0xf01f, 0xe10f, 0xc387, 0x87c3,0x0fe1, 0x1ff0,0x3ff8,


	0x8003,0xc006, 0x600c, 0x3018, 0x1830, 0x0c60, 0x06c0, 0x0380,
	0x0380, 0x06c0, 0x0c60,0x0830, 0x3018, 0x600c, 0xc006, 0x8003
};

void MOUSE::FormaCursor() {
	union REGS r;
	struct SREGS s;
	r.x.ax = 0x09;
	r.x.bx = 7;
	r.x.cx = 7;
	s.es = FP_SEG (fig);
	r.x.dx = FP_OFF (fig);
	int86x (0x33,&r, &r, &s );
}

void MOUSE::OprimirBoton() {
	int Vert, Horiz;
	while ( Estado (&Vert,&Horiz) == 0)
		;
	LibBotones();
}

void MOUSE::VelocidadMouse(int x,int y) {
	union REGS r;

	r.x.ax = 0x0f;
	r.x.cx = x;
	r.x.dx = y;

	int86 (0x33,&r,&r);
}

void MOUSE::DoblaVelocidad(int Veloc) {
	union REGS r;

	r.x.ax = 0x13;
	r.x.dx = Veloc;
	int86 (0x33,&r,&r);
}

void MOUSE::AreaProtegida(int x, int y, int x1, int y1) {
	union REGS r;
	r.x.ax = 0x10;
	r.x.cx = x;
	r.x.dx = y;
	r.x.si = x1;
	r.x.di = y1;
	int86 (0x33,&r, &r );
}
void MOUSE::Sensitividad(int *Vert, int *Horiz) {
	union REGS r;
	r.x.ax = 0x1b;
	int86 (0x33,&r,&r);
	*Vert = r.x.cx;
	*Horiz = r.x.bx;
}
void MOUSE::DeterminaSensiti(int Vert, int Horiz) {
	union REGS r;
	r.x.ax = 0x1a;
	int86 (0x33,&r,&r);
	r.x.cx = Vert;
	r.x.bx = Horiz;
}

void MOUSE::VentActual(int *p, int *q, int *rr, int *s) {
	union REGS r;
	r.x.ax = 0x31;
	int86 (0x33,&r, &r );
   *p = r.x.bx;
	*q = r.x.ax;
	*rr = r.x.dx;
	*s = r.x.cx;
}


void Escribir (int Vert, int Horiz, ...) {
	va_list lista;
	char a[10];

	va_start (lista,msg);
	int numero = va_arg (lista,int);
	moveto (Vert,Horiz);
	while (numero != 999) {
		itoa (numero, a, 10);

		outtext (a);
		outtext ("  ");
		numero = va_arg (lista,int);
	}
	va_end (lista);
}

struct X {
	int x,y;
};

struct X a[10] = { 	8,8, 5,8,2,8,1,8,10,8,
							20,8,30,8,32,32,40,40,50,50
};

/*int main()
{
	int unidad = DETECT, modo,boton,Horiz,Vert;
	char a[10],todo[30];
	MOUSE mouse;
	mouse.Inicializar();

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	mouse.Mostrar();
	getch();

	boton = mouse.Estado (&Vert,&Horiz);
	itoa (Horiz,a,10);
	strcpy (todo,a);
	itoa (Vert,a,10);
	strcat (todo," ");
	strcat (todo,a);
	itoa (boton,a,10);
	strcat (todo," ");
	strcat (todo,a);
	mouse.Esconder();
	outtextxy (0,0,todo);
	mouse.Mostrar();

	getch();

	boton = mouse.Estado (&Vert,&Horiz);
	itoa (Horiz,a,10);
	strcpy (todo,a);
	itoa (Vert,a,10);
	strcat (todo," ");
	strcat (todo,a);
	itoa (boton,a,10);
	strcat (todo," ");
	strcat (todo,a);
	mouse.Esconder();
	outtextxy (0,10,todo);
	mouse.Mostrar();

	getch();

	boton = mouse.Estado (&Vert,&Horiz);
	itoa (Horiz,a,10);
	strcpy (todo,a);
	itoa (Vert,a,10);
	strcat (todo," ");
	strcat (todo,a);
	itoa (boton,a,10);
	strcat (todo," ");
	strcat (todo,a);
	mouse.Esconder();
	outtextxy (0,20,todo);
	mouse.Mostrar();
	getch();

	closegraph();
	return 0;
}*/

