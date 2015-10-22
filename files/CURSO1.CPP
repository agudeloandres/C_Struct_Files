# include <stdio.h>
# include <conio.h>
main()

{
int x, par =0, positivo =0;
clrscr();
printf("Teclee valor .. \n");
scanf("%d",&x);

 if(!(x%2))
    par++;
 if(x>0)
    positivo++;

 if(par)
   printf("Este numero es par \n");
 else
   printf("Este numero es impar \n");

 if(positivo)
   printf("Tambien positivo \n");
 else
   printf("Tambien negativo");

 getch();
 }





