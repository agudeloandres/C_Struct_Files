#include <stdlib.h>
#include <stdio.h>
#include<conio.h>
main (){
int i;
clrscr();
for (i=1;i<=20;i++){
printf("%10d",rand());
if (!(i%4))
printf("\n");
}
getch();
}

