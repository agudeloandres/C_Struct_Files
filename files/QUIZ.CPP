# include <stdio.h>
# include <conio.h>

 main ()
{
int mcd (int,int);
int a,b;
clrscr();
printf("digite dos enteros que no sean primos \n");
scanf("%d%d",&a,&b);

printf("el minimo comun divisor entre %d y %d  es: %d ",a,b,mcd(a,b));
getch();
}


//DEFINICION FUNCION
int mcd (int a, int b){
int i,t;
if (a>=b)
for (i=a;i>1;i--){

if ((a%i)==0){
 if ((b%i)==0)
 t=i;

 }
 }

else
    if (b>a)

for (i=b;i>1;i--){

if ((b%i)==0){
 if ((a%i)==0)
 t=i;

 }
 }


return t;
}