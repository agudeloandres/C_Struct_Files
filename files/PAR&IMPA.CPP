#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

void main (){
int n,i,conti=0,contp=0;
clrscr();
printf("digite un numero\n");
scanf("%d",&n);
for (i=1;i<=n;i++){
if (i%2){
conti=conti+i;
printf("\n%d",i);
}
else {
printf("\n\t%d",i);
contp=contp+i;
}
}
printf("\nLa suma de los numeros impares es : %d ",conti);
printf("\nLa suma de los numeros pares es : %d ",contp);
}
