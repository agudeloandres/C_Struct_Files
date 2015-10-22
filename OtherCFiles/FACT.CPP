
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<a:factoria.h>
main()

{
clrscr();
int a,b,i,n,v[100];
clrscr();
printf("Digite el numero de elementos: ");
scanf("%d",&n);
printf("Digite los elementos: ");
for(i=1;i<=n;i++){
 do{
 scanf("%d",&v[i]);
} while(v[i]>=8);
 }
if(n!=1){
   i=1;
   while(i<=n){
    if(i<=n-1){
     printf("el producto de %d %d es %d\n ",v[i],v[i+1],producto(v[i],v[i+1]));
    }
    else{
     printf("el producto del elemento %d no se puede realizar porque el vector es impar\n\n ",v[n]);
     }
    i+=2;
   }

}
 else{
  printf(" el producto no se puede realizar..!");
}

   for(i=1;i<=n;i++){
     printf(" \nel factorial del elemento %d es %d",v[i],factorial(v[i]));
   }
 printf("\n\nla sumatoria del vector es %d ",suma_vector(v,n));

getch();
}