 #include <stdio.h>
 #include <dos.h>
 #include <conio.h>
			 //UTILIZANDO FUNCIONES DE DIRECCIONAMIENTO
 void main () {

 int *base , *dir ,*dir2,*dir3;
 int a[30]={0}, b[30]={0},li ,ls , n , i, j=0,c=0;
 clrscr();
 printf ("DAR EL NUMERO DE ELEMENTOS DEL VECTOR ");
 do {
 scanf ("%d",&n);
 }while (n<=0);
 printf ("DAR EL LIMITE INFERIOR DEL VECTOR ");
 do {
 scanf ("%d",&li);
 } while (li<0);
 ls = li+n-1;
 for (i=li;i<=ls;i++){
 printf ("a[%d] = ",i);
 scanf ("%d",&a[i]);
 }
 base = & a[li];

 printf("\nELEMENTOS QUE SON  MULTIPLOS DE 2 :\n");
 for (i=li;i<=ls;i++){
 dir = base+(i-li);
 if (*dir % 2 == 0){              //se trabaja con apuntadores
  printf (" %d   ",*dir);
 printf ("a[%d]= %d DIRECCION %04x : %04x \n",i,*dir,FP_SEG (dir),FP_OFF (dir));
  }
  }
 printf ( " \nELEMENTOS QUE OCUPAN POSICION PAR : \n");
 for (i=li;i<=ls;i++){
 dir2 = base + (i-li) ;
 if (((dir2)-base + li) % 2 ==0){        // SE DESPEJA i (la posicion)
      printf (" %d  ",*dir2);
      printf ("DIRECCION :  %04x : %04x \n", FP_SEG(dir2), FP_OFF (dir2));
 }
 }
 printf("\nVECTOR b [j] \n");     //imprime el elemento impar de posicion -
  for (i=li;i<=ls;i++){            // multiplo de 3 y del vector a[i] lo -
  j=0;                              // asigna al vector b[j]
  dir3 = base + (i-li);
    if (( dir3 -base + li ) % 3 == 0 ){
       if(*dir3 % 2!=0){
	    b[j]=a[i];
	    printf("%d ",b[j]);
	    printf(" DIRECCION :  %04x : %04x \n", FP_SEG(dir3), FP_OFF (dir3));
	    j++;
       }
       }
       }
  getch();
  }





