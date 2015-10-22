#include <stdio.h>
#include <dos.h>
#include <conio.h>

void main()
{
int *base,*dir;
int cla[10][10],linf,lsupf,x1,linfc,lsupc,colum,k,w,p[10],suma,y,i,j;
textcolor(WHITE);
textbackground(BLUE);;
clrscr();
printf("**DIGITE EL NUMEROS DE FILAS Y COLUMNAS DE LA MATRIZ**:");
do{
scanf("%d",&k);
}while(k<=0);
printf("**DIGITE  EL LIMITE INFERIOR DE LAS FILAS Y COLUMNAS DE LA MATRIZ**: ");
do{
scanf("%d",&linf);
}while (linf<0);
linfc=linf;
x1= 10-k;

//***CALCULO DE LOS LIMITES***

lsupf=linf+k-1;

y=lsupf+x1-linfc;

//***CAPTURA DE LA MATRIZ***

for (i=linf;i<=lsupf;i++){
  for (j=linf;j<=lsupf;j++){
     printf("cla[%d][%d]=",i,j);
     scanf("%d",&cla[i][j]);
     dir=&cla[i][j];
  }
}

//*** USO A FUNCIONES DE ACCESO A FUNCIONES DE DIRECCIONAMIENTO***
     //***EN UNA MATRIZ***


suma=0;
base=&cla[linf][linf];
 for (i=linf;i<=lsupf;i++){
     dir=base+(i-linf)*y+(k-1);
     p[i]=*dir;
     suma+=*dir;
 }

 printf("**\nLA SUMA DE LOS ELEMENTOS DE LA DIAGONAL SECUNDARIA ES**:%d\n",suma);
// printf("dirección=%04x:%04x\n",FP_SEG(dir),FP_OFF(dir));

 base=&p[linf];
 printf("***LOS ELEMENTOS DE LA DIAGONAL SECUNDARIA SON***:\n");

 for(i=linf;i<=lsupf;i++){
    dir = base + i-linf;
    printf("p = %d    ",*dir);
   // printf("dirección =%04x:%04x\n",FP_SEG(dir),FP_OFF(dir));

 }
getch();
}
