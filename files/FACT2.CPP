#include<conio.h>
#include<stdio.h>
#include<iostream.h>

//programa que halla factorial
double factorial (int); //Prototipo

void main()

{
   int n;
   double fact;

   clrscr();
   printf("digite el valor de n:");
   do  {

      scanf("%d",&n);
      }while (n<0);

      //llamar la funcion factorial.
	fact=factorial(n);
	printf("factorial %d es =%10.2f",n,fact);
      getch();
      }





      double  factorial (int n)    //Funcion

      {

	double fact;
	if (n==0)  {
	  fact=1.0;
	}
	else {
	   fact=(double) n*factorial(n-1);
	  }


         return fact;
	 }
