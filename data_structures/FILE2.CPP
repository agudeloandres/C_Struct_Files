#include<iostream.h>     //PROGRAMA QUE CREA UN PROGRAMA QUE CONSULTA UN ARCHIVO
#include<stdio.h>        // DE REGISTROS PRIMERO DEBE EJECUTARSE EL PROGRAMA
#include<fstream.h>      // FILE 3
#include<string.h>
#include<stdlib.h>
#include<conio.h>
//programa para el manejo de archivos
typedef struct alumno{
	float codigo;
	char nombre[35];
	float telefono;
	};
void main()
{
clrscr();
fstream archivo;
alumno  estudiante;
char op,c,nom[35];
float cod,tel;
int n,i;
unsigned int sw;
//abrir archivo para leer
archivo.open("estud.dat",ios::in|ios::binary);
//validar si existe archivo
if(archivo.fail()){
    cout<<"archivo estud.dat no existe-Dar 0 para continuar";
    do{
       op=getchar();
    }while (op !='0');
    exit(1);
}
clrscr();
gotoxy(31,2);
printf("MANEJO DE ARCHIVOS");
gotoxy(10,4);
printf("CODIGO        NOMBRE                     TELEFONO");
i=6;
while(!archivo.eof()){
//leer registro de archivo grabado estud.dat
archivo.read((char*) &estudiante,sizeof(estudiante));
if(archivo.eof()){
   printf("\n\nfin de archivo");
   break;
}
gotoxy(10,i);
printf("%7.0f",estudiante.codigo);
gotoxy(21,i);
printf("%-35s",estudiante.nombre);
gotoxy(53,i);
printf("%7.0f",estudiante.telefono);
i++;
estudiante.codigo=0;
estudiante.telefono=0;
}
archivo.close();
getch();
}
