#include<iostream.h>      //PROGRAMA QUE CREA UN ARCHIVO DE TEXTO
#include<stdio.h>         //LLAMADO DATOS1.DAT
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
//programa para el manejo de archivos
void main()
{
clrscr();
fstream archivo;
char c,salida[80];
int n,i;
//bad() para operacion no valida
//fail() para error que ocurre
//clear() borrar estado de error
//eof()
//good() e/s funciona
archivo.open("datos1.dat",ios::in);
//proceso de validacion de la existencia archivo
if(archivo.good()){
     cout<<"archivo datos1.dat existe-continua";
     do{
	c=getchar();
     }while (c!='S' && c!='s' && c!='N' && c!='n');
     if (c=='N' || c=='n'){
	    exit(1);
     }
}
archivo.close();
archivo.open("datos1.dat",ios::out);
//creacion de archivo
cout <<"dar entrada";
cin.getline (salida,80);
archivo<<salida;
archivo.close();
//lectura del archivo texto
archivo.open("datos1.dat",ios::in);
if (archivo.fail()){
       cout<<"no existe archivo";
       exit(1);
}
while (!archivo.eof()){
      archivo>>salida;
      cout<<salida<<" ";
}
archivo.close();
//adicionar mas texto al archivo
archivo.open("datos1.dat",ios::app);
scanf("%d",&n);
cin.getline(salida,80);
archivo<<n<<" ";
n=strlen(salida);
for(i=0;i<=n;i++){
     archivo.put(salida[i]);
}
archivo.close();
//lectura del archivo de texto
archivo.open("datos1.dat",ios::in);
while(!archivo.eof()){
     //archivo.get(c);
     //couty<<c;
     archivo>>salida;
     cout<<salida<<" ";
}
archivo.close();
getch();
}

