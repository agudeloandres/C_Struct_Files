#include <iostream.h>
#include <stdio.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

// PROGRAMA PARA EL MANEJO DE ARCHIVOS BINARIOS

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
 int n,i,k;

 //ABRIR EL ARCHIVO EN FORMA I/O =SALIDA=ESCRIBIR

 archivo.open("estud.dat",ios::in|ios::out|ios::binary);

 //CAPTURA DE DE LA LLAVE A BUSCAR
 clrscr();
 gotoxy(31,2);
 printf (" MANEJO DE ARCHIVOS ");
 gotoxy(10,4);
 printf ("CODIGO");
 gotoxy(10,6);
 printf (" NOMBRE ");
 gotoxy(10,8);
 printf (" TELEFONO ");

 do{
   gotoxy(23,4);
   printf("                          ");
   gotoxy(23,6);
   printf("                          ");
   gotoxy(23,8);
   printf("                           ");
   gotoxy(23,4);
   scanf("%f", &cod);
   gotoxy(23,6);
   cin.getline(nom,35);
   gotoxy(23,8);
   scanf("%f", &tel);
   estudiante.codigo=cod;
   n=strlen(nom);
   for(i=0;i<=n;i++){
       estudiante.nombre[i]=nom[i];
       }
   estudiante.telefono=tel;
   //ESCRITURA DEL REGISTRO CAPTURA EN EL ARCHIVO

   archivo.write((char*) &estudiante,sizeof(estudiante));
   gotoxy(10,16);
   printf("MAS DATOS(S/N);");
   do{
     op=getchar();
     }while(op!='S' &&op!='s'&& op!='N' && op!='n');
     gotoxy(10,16);
     printf("              ");
   }while (op=='S' ||op=='s');
   archivo.close();
   }