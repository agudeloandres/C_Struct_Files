#include <stdio.h>
#include <conio.h>
main (){
int power (int ,int);
int a,b;
clrscr();
printf ("DIGITE DOS NUMEROS \n");
scanf("%d%d",&a,&b);
printf("LA POTENCIA ES : %d\n",power(a,b));
getch();
}

int power (int x,int y){ //Funcion Recursiva
if (y==1)
return x;
else
return x*power(x,y-1);
}