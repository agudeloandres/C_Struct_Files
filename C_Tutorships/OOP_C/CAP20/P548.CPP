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

char *Menu [] = {
	"uno     ",
	"dos     ",
	"tres    ",
	"cuatro  ",
	"cinco   "
};

void uno(MOUSE &mouse) {
	int Boton,Vert,Horiz;
	mouse.LimVert (0,getmaxx() );
	mouse.LimHoriz (0,getmaxy() );
	mouse.Esconder();
	clearviewport();  outtext("uno");
	mouse.Mostrar();
	mouse.LibBotones();
	while (  (Boton = mouse.Estado (&Vert, &Horiz) ) == 0 )
		;
	mouse.LibBotones();
}

void dos(MOUSE &mouse) {
	int Boton,Vert,Horiz;
	mouse.LimVert (0,getmaxx() );
	mouse.LimHoriz (0,getmaxy() );
	mouse.Esconder();
	clearviewport();  outtext("dos");
	mouse.Mostrar();
	mouse.LibBotones();
	while (  (Boton = mouse.Estado (&Vert, &Horiz) ) == 0 )
		;
	mouse.LibBotones();
}

void tres(MOUSE &mouse) {
	int Boton,Vert,Horiz;
	mouse.LimVert (0,getmaxx() );
	mouse.LimHoriz (0,getmaxy() );
	mouse.Esconder();
	clearviewport();  outtext("tres");
	mouse.Mostrar();
	mouse.LibBotones();
	while (  (Boton = mouse.Estado (&Vert, &Horiz) ) == 0 )
		;
	mouse.LibBotones();
}

void cuatro(MOUSE &mouse) {
	int Boton,Vert,Horiz;
	mouse.LimVert (0,getmaxx() );
	mouse.LimHoriz (0,getmaxy() );
	mouse.Esconder();
	clearviewport();  outtext("cuatro");
	mouse.Mostrar();
	mouse.LibBotones();
	while (  (Boton = mouse.Estado (&Vert, &Horiz) ) == 0 )
		;
	mouse.LibBotones();
}

void cinco(MOUSE &mouse) {
	int Boton,Vert,Horiz;
	mouse.LimVert (0,getmaxx() );
	mouse.LimHoriz (0,getmaxy() );
	mouse.Esconder();
	clearviewport();  outtext("cinco");
	mouse.Mostrar();
	mouse.LibBotones();
	while (  (Boton = mouse.Estado (&Vert, &Horiz) ) == 0 )
		;
	mouse.LibBotones();
}

void EscribirMenu(MOUSE &mouse) {
   mouse.Esconder();
	clearviewport();
   mouse.LimVert (100,200);
	mouse.LimHoriz (50,100);
	for (int i=0; i < 5; i++)
		outtextxy (100, i * 10 + 50,Menu[i]);
	mouse.Mostrar();
}

int main() {
	int unidad = DETECT, modo,i,Vert,Horiz,Boton;
	MOUSE mouse;
	void uno(MOUSE &),dos(MOUSE &);
	void tres(MOUSE &),cuatro(MOUSE &),cinco(MOUSE &);
	void EscribirMenu(MOUSE &);

	mouse.Inicializar();

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	mouse.Mostrar();
		
		EscribirMenu(mouse);
		Boton = 0;
		while (Boton != DERECHO) {
			Boton = mouse.Estado(&Vert, &Horiz);
			if (Boton == IZQUIERDO) {
					if (Horiz >= 50 && Horiz <= 59) {
						uno(mouse);
						EscribirMenu(mouse);
					}
					else if (Horiz >= 60 && Horiz <= 69) {
						dos(mouse);
						EscribirMenu(mouse);
					}
					else if (Horiz >= 70 && Horiz <= 79) {
						tres(mouse);
						EscribirMenu(mouse);
					}
					else if (Horiz >= 80 && Horiz <= 89) {
						cuatro(mouse);
						EscribirMenu(mouse);
					}
					else if (Horiz >= 90 && Horiz <= 99) {
						cinco(mouse);
						EscribirMenu(mouse);
					}
				mouse.LibBotones();
			}
		}

	closegraph();
	return 0;
}


