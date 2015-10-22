#include <stdio.h>
#include <conio.h>
#include <dos.h>

//SACA LA MATRIZ TRIANGULAR INFERIOR DE UNA MATRIZ 2x2

void main(){
clrscr();
int sum,d,col,n,m,a[2][2],lif,lic,lsc,lsf,s,i,j;
int *dir,*base;
printf("digite tama¤o de las filas ");
do{
   scanf("%d",&n);
 }while(n<=0);
 printf("digite tama¤o de las columnas ");
 do{
    scanf("%d",&m);
  }while(m<=0);
 printf("digite limite inferior de las filas");
 do{
     scanf("%d",&lif);
  }while(lif<0);
 printf("digite limite inferior de las columnas ");
 do{
    scanf("%d",&lic);
  }while(lic<0);
  lsf=lif+n-1;
  lsc=lic+m-1;
  s=(lsc-lic+1);

  for(i=lif;i<=lsf;i++){
   for(j=lic;j<=lsc;j++){
      printf("a[%d][%d]=  ",i,j);
      scanf("%d",&a[i][j]);
      dir=&a[i][j];
   }
  }

  base=&a[lif][lic];
  for(i=lif;i<=lsf;i++){
   col=(i-lif)*s;

   for(j=lic;j<=lsc;j++){
     if(i>=j){
       dir=base+col+(j-lic);

       printf(" %d",*dir);
      }
   }
    }
   getch();
}
