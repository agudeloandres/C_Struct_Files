# include <stdio.h>
# include <conio.h>
# include <f:\c.h>
main (){

i:
clrscr();
int m (int,int);

int a,b;

printf("DIGITE DOS VALORES \n");
scanf("%d%d",&a,&b);
  if (a==b)
  printf("IGUALES \n");
  else{


 if (m(a,b))
 printf("el mayor es  : %d ",a);
 else
 printf("el mayor es  : %d ",b);

}

getch();
goto i;
 }