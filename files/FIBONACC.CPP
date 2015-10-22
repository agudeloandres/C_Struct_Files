#include <stdio.h>
#include <conio.h>
long fibonacci (long);
main(){
clrscr();
printf("fibonacci(10)= %ld \n",fibonacci(10));
getch();
}


long fibonacci (long number)     //Funcion Recursiva
{
if ((number==0 || number ==1))
return number;
else
return fibonacci(number-1)+fibonacci(number-2);
}