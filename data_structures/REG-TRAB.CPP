#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <string.h>
typedef struct profesores{
	float cedula;
	char nombre[30];
	int horas;
	float valor;
	float salario;
};
void main()
{
clrscr();
profesores docentes[26];
float ced,sum,valor,salario;
char nom[30];
int lo,i,j,n,horas;
printf("digite cantidad de profesores:  ");
do{
scanf("%d",&n);
}while(n<=0 || n>26);

for(j=1;j<=n;j++){

printf("digite cedula ");
do{
scanf("%7f",&ced);
}while(ced<0 || ced>9999999);
docentes[j].cedula=ced;
printf("digite nombre ");
cin.getline(nom,30);
lo=strlen(nom);
for(i=0;i<=lo;i++){
   docentes[j].nombre[i]=nom[i];
}
printf("digite horas ");
do{
scanf("%d",&horas);
}while(horas<0 || horas>160);
docentes[j].horas=horas;

printf("digite valor  ");
do{
scanf("%f",&valor);
}while(valor<0 || valor>25000);
docentes[j].valor=valor;
docentes[j].salario=(docentes[j].horas*docentes[j].valor);


sum+=docentes[j].salario;

}
clrscr();
gotoxy(22,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA");
gotoxy(29,3);
printf("PROGRAMA DE INGENIERIA");
gotoxy(28,4);
printf("NOMINA PROFESORES ");

i=7;
gotoxy(3,i);
printf("CEDULA");
gotoxy(11,i);
printf("NOMBRE");
gotoxy(41,i);
printf("HORAS ");
gotoxy(49,i);
printf("VALOR ");
gotoxy(58,i);
printf("SALARIO ");
for(j=1;j<=n;j++){
gotoxy(3,i+1);
printf("%-7.0f",docentes[j].cedula);
gotoxy(11,i+1);
printf("%-30s",docentes[j].nombre);
gotoxy(42,i+1);
printf("%d",docentes[j].horas);
gotoxy(48,i+1);
printf("%6.0f",docentes[j].valor);
gotoxy(59,i+1);
printf("%6.0f",docentes[j].salario);

i++;

}



gotoxy(2,20);
printf("TOTAL NOMINA ");
gotoxy(59,20);
printf("%6.0f",sum);
getch();

}

