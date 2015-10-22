#include "iostream.h"
#include "math.h"   // M_PI
#include "stdio.h"
#include "stdarg.h"

char *Significado[] = {
	"Numero e",
	"Logaritmo de 2 en base e = (ln(e))/ln2",
	"Logaritmo en base 10 de e ",
	"Logaritmo natural de 2",
	"Numero pi",
	"Pi / 2",
	"Pi / 4",
	"1 / pi",
	"2 / p1",
	"1 / raiz cuadrada de pi",
	"2 / raiz cuadrada de pi",
	"Raiz cuadrada de 2",
	"La mitad de la raiz cuadrada de 2"
};


void Constantes (...) {
	va_list ListaDeArgumentos;
	va_start (ListaDeArgumentos,msg);
	double Valor;
	unsigned i=0;
	Valor = va_arg (ListaDeArgumentos,double);
	while (fabs(Valor)  > 0.1) {
		printf ("%-40s %15.10lf\n",Significado[i],Valor);
		Valor = va_arg (ListaDeArgumentos,double);
		i++;
	}
	va_end (ListaDeArgumentos);
}

void main() {
	// Constantes matematicas del C++
	cout << "CONSTANTES MATEMATICAS\n";
	void Constantes(...);
	Constantes (M_E,
					M_LOG2E, M_LOG10E, M_LN2,
					M_PI, M_PI_2, M_PI_4,
					M_1_PI, M_2_PI,
					M_1_SQRTPI, M_2_SQRTPI, M_SQRT2, M_SQRT_2,
					0.0001
	);
}









