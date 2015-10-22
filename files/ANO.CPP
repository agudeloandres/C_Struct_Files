# include <stdio.h>
# include <math.h>
# include <conio.h>

main ()
{
textbackground(11);
textcolor(4);
clrscr();
int year;
double amount , principal=1000, rate=0.05;
gotoxy(25,1);printf("PROGRAMA DE CONTABILIDAD\n");
printf("%s%21s\n","a¤os","cantidad en deposito");
for (year=1;year<=10;year++)
{
amount=principal* pow (1+rate,year);
printf("%4d%10.2f\n",year,amount);
}
getch();
}