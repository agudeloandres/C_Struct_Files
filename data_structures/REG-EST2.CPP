#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <string.h>
typedef struct estudiantes{
	float codigo;
	char nombre[35];
	float nota1;
	float nota2;
	float nota3;
};
void main()
{
clrscr();
estudiantes alumnos[26];
float cod,nota,sum[26];
char nom[35];
int lo,i,j,n;

do{
printf("digite cantidad de estudiantes:  ");
scanf("%d",&n);
 }while(n<=0 || n>26);
for(j=1;j<=n;j++){


do{
printf("digite codigo ");
scanf("%7f",&cod);
}while(cod<0 || cod>9999999);
alumnos[j].codigo=cod;
printf("digite nombre ");
cin.getline(nom,35);
lo=strlen(nom);
for(i=0;i<=lo;i++){
   alumnos[j].nombre[i]=nom[i];
}

do{
printf("digite nota 1  ");
scanf("%f",&nota);
}while(nota<0 || nota>5);
alumnos[j].nota1=nota;


do{
printf("digite nota 2  ");
scanf("%f",&nota);
}while(nota<0 || nota>5);
alumnos[j].nota2=nota;


do{
printf("digite nota 3  ");
scanf("%f",&nota);
}while(nota<0 || nota>5);
alumnos[j].nota3=nota;
sum[j]=(alumnos[j].nota1*.35+alumnos[j].nota2*.35+alumnos[j].nota3*.3);
}
//calculo de notas
sum[j]=0;
clrscr();
gotoxy(22,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA");
gotoxy(29,3);
printf("PROGRAMA DE INGENIERIA");
gotoxy(29,4);
printf("ESTRUCTURA DE DATOS  I");
gotoxy(31,5);
printf("NOTAS ESTUDIANTES");


i=7;
gotoxy(2,i);
printf("CODIGO");
gotoxy(11,i);
printf("NOMBRE");
gotoxy(45,i);
printf("NOTA 1");
gotoxy(53,i);
printf("NOTA 2");
gotoxy(61,i);
printf("NOTA 3");
gotoxy(69,i);
printf("PROMEDIO");
for(j=1;j<=n;j++){
gotoxy(2,i+1);
printf("%7.0f",alumnos[j].codigo);
gotoxy(11,i+1);
printf("%-35s",alumnos[j].nombre);
gotoxy(45,i+1);
printf("%3.1f",alumnos[j].nota1);
gotoxy(53,i+1);
printf("%3.1f",alumnos[j].nota2);
gotoxy(61,i+1);
printf("%3.1f",alumnos[j].nota3);
gotoxy(69,i+1);
printf("%3.1f",sum[j]);
i++;


}
getch();
}

