#include "iostream.h"
#include "stdio.h"
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
        int Estado (int &,int &);
	void Posicionar (int Vert, int Horiz);
	void BotonInfo(int Boton,int *Vert, int *Horiz,
							int *Estado,int *Veces);
	void BotonLib(int Boton,int *Vert, int *Horiz,
							int *Estado,int *Veces);
	void LimVert (int x, int x1);
	void LimHoriz (int y, int y1);
	void LibBotones();
	void CambioMouse(int *Vert, int *Horiz);
/*      void FormaCursor();  */
        void Forma_Lupa();
        void Forma_Precision();
        void Forma_Escribir();
        void Forma_Relleno();
        void Forma_Arena();
        void Forma_Borrar();
        void Forma_Lapiz();
        void Forma_Giro();
        void OprimirBoton();
	void VelocidadMouse(int x, int y);
	void AreaProtegida(int x, int y, int x1, int y1);
	void DoblaVelocidad(int Veloc);
	void VentActual(int *p, int *q, int *r, int *s);
	void Sensitividad(int *p, int *q);
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

int MOUSE::Estado(int &Vertical, int &Horizontal) {
	union REGS r;

	r.x.ax = 0x03;

	int86 (0x33,&r,&r);
        Vertical = r.x.cx;
        Horizontal = r.x.dx;
	return r.x.bx;
}

void MOUSE::Posicionar (int Vert, int Horiz) {
	union REGS r;

	r.x.ax = 0x04;
	r.x.dx = Horiz;
	r.x.cx = Vert;

	int86 (0x33,&r,&r);
}

void MOUSE::BotonInfo(int Boton,int *Vert,int *Horiz,int *Estado,int *Veces) {
	union REGS r;

	r.x.ax = 0x05;
	r.x.bx = Boton - 1;

	int86 (0x33,&r,&r);
	*Vert = r.x.cx;
	*Horiz = r.x.dx;
	*Estado = r.h.al;
	*Veces = r.x.bx;
}

void MOUSE::BotonLib(int Boton,int *Vert,int *Horiz,int *Estado,int *Veces) {
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

        Boton = Estado (Vert,Horiz);
	while (Boton != 0)
                Boton = Estado (Vert,Horiz);
}


void MOUSE::CambioMouse(int *Vert, int *Horiz) {
	union REGS r;

	r.x.ax = 0x0b;
	int86 (0x33,&r,&r);
	*Vert = r.x.cx;
	*Horiz = r.x.dx;
}

int relleno[32] = {
        0xff3f, 0xfe1f, 0xfc1f, 0x8007, 0x0003, 0x1001, 0x2000, 0x2000,
        0x0000, 0x0000, 0x0801, 0x0c03, 0x0e07, 0x0f0f, 0x8fff, 0xdfff,

        0x00c0, 0x0120, 0x02a0, 0x45c8, 0x8bb4, 0x07e2, 0x0fc1, 0x0582,
        0x1b06, 0x1a0d, 0x141a, 0x1234, 0x9168, 0x9090, 0x5000, 0x2000
};

int lupa[32] = {
        0xc03f, 0x801f, 0x000f, 0x000f, 0x0007, 0x0007, 0x0007, 0x0007,
        0x000f, 0x000f, 0x8007, 0xc003, 0xf001, 0xff80, 0xffc0, 0xffe1,

        0x30c0, 0x4f20, 0xbfd0, 0xbfd0, 0x7fe8, 0x7fe8, 0x7fe8, 0x7fe8,
        0xbfd0, 0xbfd0, 0x4f88, 0x3044, 0x0fa2, 0x0051, 0x0029, 0x0012
};

int precision[32] = {
        0xfc7f, 0xfc7f, 0xfc7f, 0xfc7f, 0xf83f, 0xf83f, 0x0000, 0x0001,
        0x0000, 0xf83f, 0xf83f, 0xfc7f, 0xfc7f, 0xfc7f, 0xfc7f, 0xffff,

        0x0280, 0x0280, 0x0280, 0x0280, 0x06c0, 0x0440, 0xfbbf, 0x0280,
        0xfbbf, 0x0440, 0x06c0, 0x0280, 0x0280, 0x0280, 0x0280, 0x0000
};


int arena[32] = {
        0xc003, 0xc003, 0xc003, 0xe007, 0xe007, 0xe007, 0xe007, 0xf00f,
        0xf00f, 0xe007, 0xe007, 0xe007, 0xe007, 0xc003, 0xc003, 0xc003,

        0x2004, 0x27e4, 0x2004, 0x17e8, 0x17e8, 0x1768, 0x12c8, 0x0990,
        0x0990, 0x13c8, 0x16e8, 0x1568, 0x12a8, 0x2004, 0x27e4, 0x2004
};

int borrar[32] = {
        0xffff, 0xffff, 0xffff, 0xffff, 0xf00f, 0xf00f, 0xf00f, 0xf00f,
        0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xffff, 0xffff, 0xffff, 0xffff,

        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07e0, 0x07e0, 0x07e0,
        0x07e0, 0x07e0, 0x07e0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};


int escribir[32] = {
        0xf007, 0xf007, 0xfe3f, 0xfe3f, 0xfe3f, 0xfe3f, 0xfe3f, 0xfe3f,
        0xfe3f, 0xfe3f, 0xfe3f, 0xfe3f, 0xfe3f, 0xfe3f, 0xf007, 0xf007,

        0x0888, 0x0f78, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140,
        0x0140, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140, 0x0f78, 0x0888
};

int lapiz[32] = {
        0xffff, 0xff07, 0xfe03, 0xfe03, 0xfc07, 0xfc07, 0xf80f, 0xf80f,
        0xf01f, 0xf01f, 0xe03f, 0xe03f, 0xe07f, 0xe0ff, 0xe1ff, 0xe3ff,

        0x0000, 0x0088, 0x0104, 0x0134, 0x0288, 0x0288, 0x05d0, 0x0590,
        0x0ba0, 0x0b20, 0x1740, 0x1240, 0x1080, 0x1100, 0x1200, 0x1400
};

int giro[32] = {
        0xffff, 0xff87, 0xff03, 0xff07, 0xc303, 0xc303, 0x87e1, 0x87e1,
        0x87e1, 0x87e1, 0xc3c3, 0xc183, 0xe007, 0xf81f, 0xfc3f, 0xffff,

        0x0000, 0x0078, 0x0084, 0x0088, 0x2484, 0x24a4, 0x4812, 0x4812,
        0x4812, 0x4812, 0x2424, 0x2244, 0x1008, 0x0420, 0x03c0, 0x0000
};

void MOUSE::Forma_Precision() {
	union REGS r;
	struct SREGS s;
	r.x.ax = 0x09;
	r.x.bx = 7;
	r.x.cx = 7;
        s.es = FP_SEG (precision);
        r.x.dx = FP_OFF (precision);
	int86x (0x33,&r, &r, &s );
}


void MOUSE::Forma_Escribir() {
	union REGS r;
	struct SREGS s;
	r.x.ax = 0x09;
	r.x.bx = 7;
	r.x.cx = 7;
        s.es = FP_SEG (escribir);
        r.x.dx = FP_OFF (escribir);
	int86x (0x33,&r, &r, &s );
}

void MOUSE::Forma_Relleno() {
	union REGS r;
	struct SREGS s;
	r.x.ax = 0x09;
	r.x.bx = 7;
	r.x.cx = 7;
        s.es = FP_SEG (relleno);
        r.x.dx = FP_OFF (relleno);
	int86x (0x33,&r, &r, &s );
}

void MOUSE::Forma_Lupa() {
	union REGS r;
	struct SREGS s;
	r.x.ax = 0x09;
	r.x.bx = 7;
	r.x.cx = 7;
        s.es = FP_SEG (lupa);
        r.x.dx = FP_OFF (lupa);
	int86x (0x33,&r, &r, &s );
}

void MOUSE::Forma_Arena() {
	union REGS r;
	struct SREGS s;
	r.x.ax = 0x09;
	r.x.bx = 7;
	r.x.cx = 7;
        s.es = FP_SEG (arena);
        r.x.dx = FP_OFF (arena);
	int86x (0x33,&r, &r, &s );
}

void MOUSE::Forma_Borrar() {
	union REGS r;
	struct SREGS s;
	r.x.ax = 0x09;
	r.x.bx = 7;
	r.x.cx = 7;
        s.es = FP_SEG (borrar);
        r.x.dx = FP_OFF (borrar);
	int86x (0x33,&r, &r, &s );
}

void MOUSE::Forma_Lapiz() {
	union REGS r;
	struct SREGS s;
	r.x.ax = 0x09;
	r.x.bx = 7;
	r.x.cx = 7;
        s.es = FP_SEG (lapiz);
        r.x.dx = FP_OFF (lapiz);
	int86x (0x33,&r, &r, &s );
}

void MOUSE::Forma_Giro() {
	union REGS r;
	struct SREGS s;
	r.x.ax = 0x09;
	r.x.bx = 7;
	r.x.cx = 7;
        s.es = FP_SEG (giro);
        r.x.dx = FP_OFF (giro);
	int86x (0x33,&r, &r, &s );
}


void MOUSE::OprimirBoton() {
	int Vert, Horiz;
        while ( Estado (Vert,Horiz) == 0)
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


void Escribir (int Vert, int Horiz) {
	va_list lista,msg;
	char a[10];
	//va_start (lista,msg);
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

struct X a[10] = { 8,8,5,8,2,8,1,8,10,8,20,8,30,8,32,32,40,40,50,50
};

