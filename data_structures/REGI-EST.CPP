#include <stdio.h>
#include <string.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>
typedef struct estudiantes{
	float codigo;
	char nombre [35];
	float nota1,nota2,nota3;
    };
void main(){
clrscr();
estudiantes alumnos;
int longitud,i;
float cod,nota,sum;
char nom[36];
//lectura de datos
gotoxy(22,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA\n");
gotoxy(22,3);
printf("PROGRAMA DE INGENIERIA DE SISTEMAS\n");
gotoxy(28,4);
printf("ESTRUCTURA DE DATOS I\n");
gotoxy(29,5);
printf("NOTAS ESTUDIANTES\n\n");

printf(" codigo\n ");
scanf("%f",&cod);
alumnos. codigo = cod;
gotoxy(18,7);
printf(" nombre ");
gotoxy(19,8);
cin.getline (nom,35);
longitud= strlen(nom);
//asignacion de una variable
for(i=0;i<=longitud;i++){
    alumnos. nombre[i]=nom[i];
}
//notas
gotoxy(38,7);
printf(" nota1: ");
gotoxy(39,8);
scanf("%f",&nota);
alumnos.nota1=nota;
gotoxy(48,7);
printf(" nota2: ");
gotoxy(49,8);
scanf("%f",&nota);
alumnos.nota2=nota;
gotoxy(58,7);
printf(" nota3: ");
gotoxy(59,8);
scanf("%f",&nota);
alumnos.nota3=nota;
//calculo nota
sum=(alumnos.nota1 + alumnos.nota2 + alumnos.nota3)/3;
//escritura de datos y promedio
gotoxy(69,7);
//printf("DATOS DEL ALUMNO Y SU PROMEDIO\n");
//printf("//codigo%7.0f   nombre%-35s   nota1%3.1f   nota2%3.1f   nota3%3.1f  promedio=%3.1f ",alumnos.codigo,alumnos.nombre,alumnos.nota1,alumnos.nota2,alumnos.nota3,sum);
printf("promedio");
gotoxy(69,8);
printf("%3.1f",sum);
getch();
}