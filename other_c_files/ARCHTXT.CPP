// ARCHIVOS DE TEXTOS
#include <iostream.h>
#include <stdio.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>

//PROGRAMA PARA ER MANEJO DE ARCHIVOS
void main()
{
fstream archivo;
char c;
archivo.open("aim.txt",ios::out); //cREA UN ARCHIVO NUEVO
//CREACION DE ARCHIVO

cout<<"ENTRA LINEAS DE TEXTO A GRABAR -terminar con <crt><z>\n";
while (cin.get(c)){
     archivo.put(c);
 }
 archivo.close();
 }


