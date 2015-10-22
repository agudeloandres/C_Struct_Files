

/* newton.c - encuentra el cero de una funcion
**
** Autor: Pablo A. Straub, 25/09/1996
**
** Este programa muestra el metodo de Newton para
** encontrar la raíz (o cero) de una funcion.  En
** el ejemplo el metodo converge si abs(x) < 2.177
*/

#include <stdio.h>
#include "leer.c"
#include <math.h>

/* prototipos de funciones */

double newton (double (*f)(double),
   double (*d)(double), double x, double epsilon);
double f (double x);
double deriv_f (double x);
double cuadrado (double);


/* programa principal de newton.c */

void main ()
{
    double x0 = leer_flotante("Ingrese aproximacion:");
    double epsilon = leer_flotante("Ingrese precision:");
    printf("La raiz de la funcion es %10.7lf\n",
           newton(f, deriv_f, x0, epsilon));
}


/* newton - busca un cero de una funcion */

double newton (
    double (*func)(double),
    double (*deriv)(double),
    double x,
    double epsilon)
{
    double deltax = func(x) / deriv(x);
    while (fabs(deltax) > epsilon) {
	x = x - deltax;
	deltax = func(x) / deriv(x);
    }
    return x - deltax;
}


/* f - funcion a la que se le busca un cero o raiz */

double f (double x)
{
    return 1 / (1 + exp(x)) - 0.5;
}


/* deriv_f - derivada de la funcion */

double deriv_f (double x)
{
    return -exp(x) / cuadrado(1 + exp(x));
}


/* cuadrado - el cuadrado de un numero */

double cuadrado (double x)
{
    return x * x;
}
