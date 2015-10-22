#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
main (){
void incog (double,double,double);//PROTOTIPO
double a,b,c;
textbackground(BLUE);
textcolor(WHITE);
clrscr();
printf("                  ECUACION CUADRATICA :\n");
printf("\n\nAX^2+BX+C\n");
printf("\nDIGITE LOS COEFICIENTES DE LA ECUACION A B Y C \n\n");
scanf("%lf%lf%lf",&a,&b,&c);
incog(a,b,c);
getch();
}

//FUNCION INCOG
void incog (double x, double y , double z){
double d,re,im;
if (x==0 && y==0)
printf("LA ECUACION ES DEGENERADA\n");
else if (x==0)
printf("LA UNICA RAIZ ES : %.2lf\n",-z/y);
else{
re = -y/(2*x);
d =  y*y-4*x*z;
im = sqrt (fabs(d))/(2*x);
if (d>=0){
printf("RAICES REALES \n");
printf("%.2lf\n%.2lf",re+im,re-im);
}
else{
printf("RAICES COMPLEJAS\n");
printf("%.2lf + %.2lf i\n",re,fabs(im));
printf("%.2lf - %.2lf i\n",re,fabs(im));
}
}
}

