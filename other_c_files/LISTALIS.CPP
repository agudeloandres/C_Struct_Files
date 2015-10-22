 //programa principal que maneja listas lineales secuanciales cada nodo tiene una informacion un registro

 #include <iostream.h>
 #include <dos.h>
 #include <stdio.h>
 #include <conio.h>
 #include<string.h>
 #include<a:\rulls.h>

 void main()
 {
 unsigned int sw;
 alumnos *ln,*lo, *l1, *li, *lk, *avail;
 int k,n;
 //localizar espacio disponible

 printf("digite el número maximo nodos de la lista");
	 do{
		 scanf("%d",&n);
       		 }while(n<=0);

 //asignacion del espacio disponible
   
 avail=new alumnos[n];

 //asignacion de condiciones iniciales
 lo=avail;
 avail++;
 k=0;

 do{
 	printf("Mas datos...Digite 0(si), 1(no");
        do{
 		scanf("%d",&sw);
 		}while (sw>0 &&sw>1);
		 if(sw==0){
			 k++;
			 lk=avail;
			 avail++;
			 crea_nodo_lls(lk,n,k,&sw,3);
 }
			 }while(sw==0 &&k<=n);

 //imprimir la lista lls

 ln=lk;
 escritura_nodos_lls(ln,lo,3);

 //liberar memoria

 delete lo;
 }