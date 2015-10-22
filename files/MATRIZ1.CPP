#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

main (){
int m[10][10],n[10][10]={0};
int t,c,x,l,q,r,w;
textbackground(11);
textcolor(4);
clrscr();
printf("DIGITE EL TAMA¥O DE LA MATRIZ CUADRADA \n");
scanf("%d",&t);
printf("DIGITE LOS ELEMENTOS DE LA MATRIZ\n");
for (c=0;c<=t-1;c++){
l=5;
for (x=0;x<=t-1;x++){
gotoxy(l,5+c);
scanf("%d",&m[c][x]);
l+=5;
}
}
printf("\nLA MATRIZ IDENTICA ES : ");
for (q=0;q<=t-1;q++){
l=5;
w=x+7;
for (r=0;r<=t-1;r++){
gotoxy(l,w+q);
n[r][r]=1;
printf("%d",n[q][r]);
l+=5;
}
w++;
}
printf("\n\nLOS ELEMENTOS DE SU DIAGONAL PRINCIPAL SON :");
for (c=0;c<=t-1;c++){
printf("\n\t%d",m[c][c]);
}
getch();
}
