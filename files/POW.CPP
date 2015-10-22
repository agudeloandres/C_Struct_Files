#include <stdio.h>
#include <conio.h>



main (){


int potencia (int,int);
int pow,a,b;


clrscr();

printf ("Digite dos  Numeros :  ");

scanf("%d %d",&a,&b);


pow=potencia(a,b);

printf ("la potencia de %d a la  %d  es : %d ",a,b,pow);


getch();
}




int potencia(a,b){

 int pot;

 if (b==1)
      pot = a;

 else{

    pot=a*potencia(a,b-1);

 }
 return pot;

}