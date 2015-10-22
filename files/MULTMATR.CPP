#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

void main (){
int a[10][10],b[10][10],c[10][10],mi[10][10];
int f1,c1,f2,c2,x,y,l,j,k,w,fm,cm,sum,cm2,q1,q2,rt;

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

if(c1==f2){
printf("\nLA MATRIZ PRODUCTO ES : ");
for(fm=0;fm<=f1-1;fm++){
 for(cm=0;cm<=c2-1;cm++){
  sum=0;
   for(cm2=0;cm2<=c1-1;cm2++){
    sum+=(a[fm][cm2]*b[cm2][cm]);
   }
  c[fm][cm]=sum;
  }
 }


for (q1=0;q1<=f1-1;q1++){
l=5;
rt=w+2;
  for(q2=0;q2<=c2-1;q2++){
    gotoxy(l,rt+q1+2);
    printf("%d",c[q1][q2]);
l+=5;
}
rt++;
}
}

else
  printf("\nLAS MATRICES NO SE PUEDEN MULTIPLICAR !");


getch();
}