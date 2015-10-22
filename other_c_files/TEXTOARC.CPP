#include <iostream.h>
#include <stdio.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct alumno {
       float codigo;
       char nombre[35];
       float telefono;
       };

 void main()
 {
 fstream archivo;
 alumno estudiante;

 char op,c,nom[35];
 float cod,tel;
 int n,i;
 //ABRIR EL ARCHIVO EN FORMA OUTPUT=SALIDA=ESCRIBIR
 archivo.open("estud.dat",ios::in|ios::binary);
 clrscr();
 gotoxy(31,2);
 printf("MANEJO DE ARCHIVOS");
 gotoxy(10,4);
 printf("CODIGO    NOMBRE              TELEFONO");
 i=6;
 while(!archivo.eof()){
 //LEER REGISTRO DEL ARCHIVO GRABADO ESTUD.DAT
 archivo.read((char*) &estudiante,sizeof(estudiante));
 if(archivo.eof()){
    break;
 }
 gotoxy(9,i);
 printf("%7.0f",estudiante.codigo);
 gotoxy(21,i);
 printf("%-35s",estudiante.nombre);
 gotoxy(59,i);
 printf("%7.0f",estudiante.telefono);
 i++;
 }
 archivo.close();
}

