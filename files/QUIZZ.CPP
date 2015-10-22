# include <stdio.h>
# include <conio.h>
 main ()
{
int ged (int,int);
int a,b;
clrscr();
printf("digite dos enteros \n");
scanf("%d%d",&a,&b);
printf("el maximo comun divisor entre %d y %d  es: %d ",a,b,ged(a,b));
getch();
}
//DEFINICION FUNCION
int ged (int a, int b){
int i,t;
if (a>=b){
for (i=1;i<=a;i++){
if ((a%i)==0){
 if ((b%i)==0){
 t=i;
 }
 }
 }
 }
else
    if (b>a){
for (i=1;i<=b;i++){
if ((b%i)==0){
 if ((a%i)==0){
 t=i;
 }
 }
 }
 }
return t;
}