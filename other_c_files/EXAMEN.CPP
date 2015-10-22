#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

//manejo de estructura utilizando selección directa
   typedef struct cliente{
     char nombre[35];
     int unid;
float codigo,valor_unitario;
};


void main()
{
clrscr();
cliente *l;

char name[35];
float valor;
int cod,*apunt,unidad;
printf("PEDIDO DEL ALMACEN MAYOR");
printf(" Por favor ingrese el codigo  ");
scanf ("%d",cod);
printf(" Por favor ingrese el nombre del articulo  ");
//cin.getline(name,35);
scanf("%s",name);
printf(" Por favor: cual es la medida deseada  ");
scanf ("%d",&unidad);
printf(" Por favor ingrese el valor unitario reál  ");
scanf ("%6.f",&valor);
l->nombre=name;
l->codigo=cod;
l->valor_unitario=valor;
l->unid=unidad;
printf("El codigo del articulo es: ",l->codigo);
printf("El nombre del articulo es: ",l->nombre);
printf("Su medida es: ",l->unid);
printf("El valor unitario es: ",l->valor_unitario);
}