#include <stdio.h>
#include <conio.h>



main (){


long factorial (int);
long factor;
int n;


clrscr();

printf ("Digite un Numero :  ");

scanf("%d",&n);

factor=factorial(n);

printf ("El factorial de %d es : %ld ",n,factor);


getch();
}




long factorial(n){

 int fac;

 if (n==0)
      fac = 1;

 else{

    fac= n*factorial(n-1);

 }
 return fac;

}
