#include<stdio.h>
#include<conio.h>
#include<dos.h>
main(){
textcolor(BLUE);
textbackground(LIGHTGRAY);
clrscr();
int a[10][10]={0},b[10][10]={0};
int f,c,m,n,x,y,l,k;
printf("DIGITE EL TAMA¥O DE LA MATRIZ \n");
scanf("%d%d",&f,&c);
for(m=0;m<=f-1;m++){
x=7;
for(n=0;n<=c-1;n++){
gotoxy(x,m+5);
scanf("%d",&a[m][n]);
x+=7;
}
}

printf("LA TRANSPUESTA DE LA MATRIZ ES : \n");
y=m+5+2;
for(k=0;k<=c-1;k++){
x=7;
for(l=0;l<=f-1;l++){
b[k][l]=a[l][k];
gotoxy(x,y+3);
printf("%d",b[k][l]);
x+=7;

}
y++;
}
getch();
}