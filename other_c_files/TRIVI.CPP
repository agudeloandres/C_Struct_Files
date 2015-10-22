
#include <stdio.h>
int factorial(int);

//programa uso de la recursividad
void main()
{
 int n,factorial(int);
 int fact;
 printf("digite el el número=");
 scanf("%d",&n);
 fact= factorial(n);
 printf("El factiorial de %d es=%d", n,fact);
 }

  //llamado  de la funcion factorial
  int factorial (int n)
  {
  int fact;
  if(n==0){
  fact=n;
  }
  //caso trivial
  else{
  fact=n*factorial(n-1);
  }
  return fact;
  }
