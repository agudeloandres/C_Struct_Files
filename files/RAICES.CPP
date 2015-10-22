# include <stdio.h>
# include <conio.h>
# include <math.h>

main()
{
clrscr();

  float x= -10 ;
  int y = 0;

  printf("Voy a jecutar una serie de raices del numero 10 al 100 con paso de 10  ok!\n");


    for ( ; y <=110 ; y+=10)
      {  x+=10 ;
       printf("raiz de %d es %2f \n",y,sqrt(x));

    }

    printf("presione una tecla para finalizar");
    getch();

 }




