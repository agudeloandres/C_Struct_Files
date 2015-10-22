#include <stdio.h>
#include <conio.h>
long factorial (long);//prototipo
main(){
int n,x;
textcolor (WHITE);
textbackground(BLUE);
clrscr();
printf("DIGITE UN VALOR \n");
scanf("%d",&n);
printf("%d!=%ld\n",n,factorial(n));
getch();
}
long factorial (long number){
if (number <=1)
return 1;
else
return (number*factorial(number-1));
}