#include <stdio.h>
#include <conio.h>

main(){
int n [10],i,sum;
clrscr();
for (i=0;i<=9;i++)
n[i]=2+2*i;
sum=0;
for (i=0;i<=9;i++){
printf("%d\t",n[i]);
}
getch();
for (i=0;i<=9;i++)
sum +=n[i];
printf("\n\nLA SUMA ES : %d ",sum);
getch();
}