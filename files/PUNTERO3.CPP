#include<stdio.h>
#include<conio.h>  //Funcion que devuelve el nombre del mes 1 a 12 dado

void main (){
unsigned int dia, mes , anyo;
char *m;
char *nombre_mes(unsigned int mm);

clrscr();
printf("Introduce fecha (dd-mm-aaaa) :  ");

//Los datos en la entrada iran separados por '-'

scanf("%u-%u-%u",&dia,&mes,&anyo);
m =nombre_mes(mes);
printf("\n\nMes : %s\n",m);
getch();
}

char *nombre_mes(unsigned int mm){
 //Mes es un array de punteros a cadenas de caracteres
 static char *mes[]={"Mes no correcto","Enero","Febrero","Marzo","Abril","Mayo",
		      "Junio","Julio","Agosto","Septiembre","Octubre","Noviembre",
		      "Diciembre"};

  return ((mm > 0 && mm <= 12) ? mes[mm] : mes[0]);
}
