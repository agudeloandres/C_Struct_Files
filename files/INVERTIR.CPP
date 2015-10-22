  # include <stdio.h>
  # include <conio.h>
   main()
  {
  void inv (int, int);
  int d,n;
  clrscr();
  printf ("de cuantos digitos es el numero \n");
  scanf("%d", &d);
  printf (" escriba el numero \n");
  scanf("%d", &n);
   inv(d,n);
  printf ("  es el numero invertido ");

  getch();
  }


  void inv (int x, int y)
  {
  int temp,c,m;

  m=0;
  temp=y;
  for (c=1; c<=x; c++){

  m= (temp % 10);
  printf("%d",m);
  temp=(int)(temp/10);
  }

  }
