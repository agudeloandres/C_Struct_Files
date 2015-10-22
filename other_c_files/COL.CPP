//programa principal que maneja lista lineales cada nodo tiene información un entero

#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
# include<a:\rulls.h>

void main()
{
unsigned int sw;
int *ln,*l1,*li,*lk,*lo,*avail;
int k,n,k1;
int info;
//localizar espacio disponible

printf("digite el maximo numero de nodos de la lista");

do
{
scanf("%d",&n);
}while(n<=0);

//asignacion espacio disponible

avail=new int[n];
//asignacion de condiciones iniciales
lo=avail;

avail++;
k=0;
do{
  printf("mas datos...digite 0(si), 1(no)");
  do{
 scanf("%d",&sw);
 }while(sw>0 && sw>1);

if(sw==0){
 k++;
 lk=avail;
 crea_nodo_lls(lk,n,k,&sw,1);
 }
}while(sw==0 && k<=n);

//imprimir lista lineal

ln=lk;
escritura_nodos_lls(ln,lo,1);

//liberar memoria

delete lo;
}