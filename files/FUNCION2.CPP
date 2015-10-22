#include <stdio.h>
#include <conio.h>

main (){

int escaleno(int,int,int);
int isoceles(int,int,int);
int equilatero(int,int,int);
int a,b,c;
clrscr();
printf("teclee 3 valores enteros \n");
scanf("%d%d%d",&a,&b,&c);
if (escaleno(a,b,c)==1)
printf("ESCALENO \n");

if (isoceles(a,b,c)==1)
printf("ISOCELES \n");
if (equilatero(a,b,c)==1)
printf("EQUILATERO \n");
getch();
//return 0;
}

int escaleno(int x,int y,int z){
if ((x!=y) && (y!=z) && (x!=z))
return 1;
else
return 0;
}

int isoceles (int w,int m, int k){
if (((w==m)&& (w!=k)) || ((w==k) && (w!=k)) || ((m==k) && (m!=w)))
return 1;
else
 return 0;
 }

 int equilatero (int f,int k, int r){
 if ((f==k) && (f==r))
 return 1;
 else
   return 0;
   }

