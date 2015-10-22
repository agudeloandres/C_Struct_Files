
#include <iostream.h>
#include <stdio.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

// PROGRAMA PARA EL MANEJO DE ARCHIVOS BINARIOS

typedef struct persona {
       float cedula;
       char nombre[35];
       float horas;
       float valor;
       };

 void main()
 {
 fstream archivo;
 persona trabajador;

 char op,c,nom[35];
 float ced,hor,val;
 int n,i;
 //ABRIR EL ARCHIVO EN FORMA OUTPUT=SALIDA=ESCRIBIR
 archivo.open("trabaj.dat",ios::out|ios::binary);

 //CAPTURA DE DATOS A GRABAR EN EL ARCHIVO
 clrscr();
 gotoxy(31,2);
 printf (" MANEJO DE ARCHIVOS ");
 gotoxy(10,4);
 printf ("CEDULA");
 gotoxy(10,6);
 printf (" NOMBRE ");
 gotoxy(10,8);
 printf (" NUMERO DE HORAS ");
 gotoxy(10,9);
 printf (" VALOR DE LA HORA " );
 do{
   gotoxy(23,4);
   printf("    ");
   gotoxy(23,6);
   printf("    ");
   gotoxy(23,8);
   printf("   ");
   gotoxy(23,15);
   printf("                         ");
   gotoxy(23,4);
   scanf("%f", &ced);
   gotoxy(23,6);
   cin.getline(nom,35);
   gotoxy(23,8);
   scanf("%f", &hor);
   gotoxy (23,9);
   scanf ("%f", &val);
   trabajador.cedula=ced;
   n=strlen(nom);
   for(i=0;i<=n;i++){
       trabajador.nombre[i]=nom[i];
       }
   trabajador.horas=hor;
   //ESCRITURA DEL REGISTRO CAPTURA EN EL ARCHIVO

   archivo.write((char*) &trabajador,sizeof(trabajador));
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