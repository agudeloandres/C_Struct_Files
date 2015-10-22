#include "iostream.h"
#include "dos.h"

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

void main()
{

	MOUSE mouse;
	mouse.Inicializar();
	if (mouse.FIni() == 1)
		cout << "Inicializado" << endl;
	else cout << "No esta inicializado" << endl;

	if (mouse.FDes() == 1)
		cout << "Desconectado" << endl;
	else cout << "Conectado" << endl;

  cout << mouse.NumBotones () << endl;
}
