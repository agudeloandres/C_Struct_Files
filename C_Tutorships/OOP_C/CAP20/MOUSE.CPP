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
	void OprimirBoton();
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



void MOUSE::OprimirBoton() {
	int Vert, Horiz;
	while ( Estado (&Vert,&Horiz) == 0)
		;
	LibBotones();
}



