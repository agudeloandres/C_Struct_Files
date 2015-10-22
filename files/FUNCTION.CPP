# include <stdio.h>
#include <conio.h>
main () {
int x;
int square (int);//prototipo
clrscr();
for (x=1;x<=10;x++)
printf("%d\n",square(x));
getch();
}
int square (int y){
return y*y;
}

