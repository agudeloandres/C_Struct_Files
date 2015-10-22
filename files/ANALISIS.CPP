/* PROGRAMA QUUE INVIERTE LAS POSICIONES DE UN VECTOR */

//ADRIANA PAMPLONA

#include <stdio.h>


void main()
{

int n,i,vector[100], h, auxiliar, a, k;

//if (vector[i] MOD(2)=0){
printf("DAR EL NUMERO DE ELEMENTOS DEL VECTOR\n");
 if (vector[i] %2==0){

scanf("%d", &n);

   
for (i=1; i<=n; i++){
    printf(" vector[%d]= ", i);
    scanf ("%d",&vector[i]);
}
 h=n/4;
 

for (i=1; i<=h; i++){
    auxiliar=vector[i];
    vector[i]=vector[n/2-i+1];
    vector[n/2-i+1]=auxiliar;
}


k=n/2;
a=n+(n/2);


 for (i=k+1; i<=n-h; i++){
    auxiliar=vector[i];
    vector[i]=vector[a-i+1];
    vector[a-i+1]=auxiliar;
}


printf ("VISUALIZACION DEL VECTOR RESULTANTE\n ");
   
for (i=1; i<=n; i++){
   printf("vector[%d]= %d",i,vector[i] );
 
}
}


}


