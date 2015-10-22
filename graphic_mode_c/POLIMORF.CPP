#include <string.h>
#include <iostream.h>



class BaseDeDatos
{
	char autor[50];
	char titulo[50];
	char fecha[50];

	public:
		BaseDeDatos (char* quien,char* que,char* cuando);
		virtual void Mostrar (void);
};

BaseDeDatos::BaseDeDatos (char* quien,char* que,char* cuando)
{
	strcpy(autor,quien);
	strcpy(titulo,que);
	strcpy(fecha,cuando);
}

void BaseDeDatos::Mostrar (void)
{
	cout << endl << endl;
	cout << "Autor = " << autor << endl;
	cout << "T¡tulo= " << titulo << endl;
	cout << "Fecha = " << fecha << endl;
}


class Pintura: public BaseDeDatos
{
	int ancho,alto;

	public:
				   Pintura (char* autor,char* titulo,char* fecha,int w,int h);
		virtual void Mostrar (void);
};


Pintura::Pintura (char* autor,char* titulo,char* fecha,int w,int h): BaseDeDatos(autor,titulo,fecha)
{
	ancho= w;
	alto = h;
}

void Pintura::Mostrar (void)
{
	BaseDeDatos::Mostrar();
	cout << "Tipo: Pintura" << endl;
	cout << "Tama¤o: " << ancho << " x " << alto << endl;
}

class Musica: public BaseDeDatos
{
	char clave[40];

	public:
				   Musica  (char* autor,char* titulo,char* fecha,char* k);
		virtual void Mostrar (void);
};

Musica::Musica (char* autor,char* titulo,char* fecha,char* k): BaseDeDatos(autor,titulo,fecha)
{
	strcpy(clave,k);
}

void Musica::Mostrar (void)
{
	BaseDeDatos::Mostrar();
	cout << "Tipo: M£sica" << endl;
	cout << "Clave: " << clave << endl;
}

class DeCamara: public Musica
{
	int numero_de_musicos;

	public:
				   DeCamara (char* autor,char* titulo,char* fecha,char* k,int nom);
		virtual void Mostrar  (void);
};

DeCamara::DeCamara (char* autor,char* titulo,char* fecha,char* clave,int nom): Musica(autor,titulo,fecha,clave)
{
	numero_de_musicos= nom;
}

void DeCamara::Mostrar (void)
{
	Musica::Mostrar();
	cout << "Otro: M£sica de C mara" << endl;
	cout << "N£mero de M£sicos: " << numero_de_musicos << endl;
}

void ImprimirInformacion (BaseDeDatos& D)
{
	D.Mostrar();
}

void main (void)
{
	Musica Sinfonia ("Beethoven, Luduiwg van",
				  "Novena Sinfon¡a",
				  "1824",
				  "Re Menor");

	Pintura Cuadro ("da Vinci, Leonardo",
				 "Mona Lisa",
				 "1503",
				 24,36);

	DeCamara Opus ("Mozart, Wolfgang Amadeus",
				"Hoffmesiter",
				"1786",
				"Re Mayor",
				4);

	ImprimirInformacion(Sinfonia);
	ImprimirInformacion(Cuadro);
	ImprimirInformacion(Opus);
}