# include <stdio.h>         //DADOS 3 NUMEROS DETERMINA CUAL ES EL MAYOR Y
# include <math.h>         //CUAL ES EL MENOR RECIBIENDO COMO PARAMETROS
# include <conio.h>       //APUNTADORES.

main ()
{
int  may (int*,int*,int*);//prototipo
int  men (int*,int*,int*);//prototipo
clrscr();
int a,b,c;

printf("Digite 3 numeros enteros diferentes\n");
scanf("%d%d%d",&a,&b,&c);

printf("El numero mayor es : %d\n ",may(&a,&b,&c));
printf("El numero menor es : %d\n ",men(&a,&b,&c));
getch();
}

//FUNCIONES

int may (int *m ,int *n ,int *o){
if (*m > *n)
  if (*m > *o)
    return *m;

  if (*n > *m)
   if (*n > *o)
    return *n;

    if (*o > *n)
     if (*o > *m)
      return *o;
  }

int  men (int *x, int *y, int *z){
if (*x < *y)
  if (*x < *z)
    return *x;

  if (*y < *x)
   if (*y < *z)
    return *y;

    if (*z < *x)
     if (*z < *y)
      return *z;
}
