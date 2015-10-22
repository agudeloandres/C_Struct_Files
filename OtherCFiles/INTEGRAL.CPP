

/* integra.c - aproximaciones de una integral
**
** Pablo A. Straub, 21 abril 1997
**
** Comando de compilacion:
**  % cc -o integra -lm rectangulo.c trapezoidal.c
        simpson.c integra.c
*/

#include <math.h>
#include <stdio.h>

double rectangular (double (*f)(double),
    double a, double b, int n);
double trapezoidal (double (*f)(double),
    double a, double b, int n);
double simpson (double (*f)(double),
    double a, double b, int n);
    
double f (double);

void main()
{
    int j;
    double a = 0.0, b = 2.0;
    
    printf("Evaluaciones  rectangulos    trapecios", "      Simpson\n");
    for (j = 24; j < 50; j++)
        printf("  %3d  %18.5lf %12.5lf %12.5lf\n",
	       2+2*j, rectangular(f, a, b, 2+2*j),
	       trapezoidal(f, a, b, 2+2*j),
	       simpson(f, a, b, j));
}

double f (double x)
{
    return 1 / (1 + exp(x)) - 0.5;
}
