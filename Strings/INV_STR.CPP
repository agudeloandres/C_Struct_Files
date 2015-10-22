#include <stdio.h>
#include <conio.h>   //iMPRIME EL SEGUNDO NOMBRE DE UN ARREGLO DE CHAR
#include <dos.h>     // DE FOMA INVERTIDA  P A C A ==> A C A P
main () {
clrscr();
int i,j;              //0    //1     //2     //3
char *  nombres [4]={"lola","paca","vilma","betty"};
char **q;
q=nombres; //No lleva & por ser un array

//Para el segundo nombre: paca

for (i=0;i<=3;i++){
printf("%c ",*(*(q+1)+i)); //Imprime caracter por caracter
delay(100);   //   ^indica la cadena 1 osea paca
}
printf("\n");

for (i=0;i<=3;i++){
printf("%c ",*(*(q+1)+(3-i))); //Imprime por caracter inversamente
delay(100);
}
getch();
}
