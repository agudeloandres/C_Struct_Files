#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

main (){
int a[10][10],b[10][10],c[10][10]={0};
int f1,c1,f2,c2,x,y,l,j,k,w,sum,q,z,rt;
textbackground(BLUE);
textcolor(WHITE);
clrscr();
printf("DIGITE EL TAMA¥O DE LA MATRIZ  A   :   *   ");
gotoxy(38,1);
scanf("%d",&f1);
gotoxy(42,1);
scanf("%d",&c1);
for (x=0;x<=f1-1;x++){
l=5;
for (y=0;y<=c1-1;y++){
gotoxy(l,3+x);
scanf("%d",&a[x][y]);
l+=5;
}
}
printf("\nDIGITE EL TAMA¥O DE LA MATRIZ  B   :   *   ");
gotoxy(38,x+4);
scanf("%d",&f2);
gotoxy(42,x+4);
scanf("%d",&c2);
for (j=0;j<=f2-1;j++){
l=5;
w=x+5;
for (k=0;k<=c2-1;k++){
gotoxy(l,w+j);
scanf("%d",&b[j][k]);
l+=5;
}
w++;
}
if ((f1==f2) && (c1==c2)){
printf("\nLA MATRIZ SUMA ES :\n");
for (q=0;q<=f1-1;q++){
l=5;
rt=w+2;
for (z=0;z<=c1-1;z++){
c[q][z]=a[q][z]+b[q][z];
gotoxy(l,rt+q+2);
printf("%d",c[q][z]);
l+=5;
}
rt++;
}
}
else
printf("\nNO SE PUEDEN SUMAR LAS MATRICES !");
getch();
}

