#include<i ostream.h>       
#include<stdio.h>
#include<conio.h>
void main ()
{
clrscr();
int i,n,p,cont,f;
char a[6],b[6];

for (i=0;i<=5;i++) {
     scanf ("%d",&a[i]);


     }
printf ("POR FAVOR ESCRIBA LA POSICION QUE DESEA INICIAR: ");
scanf ("%d", &f);
  printf (" POR FAVOR DIGITE EL ESTADO DE LA POSICION :" );
     scanf ("%d",&p);

 for (i=0;i<=5;i++) {

     if (a[f]==0 && p==1){
	b[f]= 0;
	p= 2;
	printf ("\n %d", b[f] );
	printf (  "Y SU NUEVO ESTADO ES: %d\n",p);
	f++;
	if(f==6){
	f=0;
	}
	}
	else{
	if (a[f]==0 && p==2) {
	   b[f]= 0;
	   p= 3;
	   printf (" %d\n", b[f] );
	   printf ( " Y SU NUEVO ESTADO ES: %d\n", p);
	   f++;
	   if(f==6){
	   f=0;
	   }
	   }
	   else{
	   if (a[f]==1 && p==2){
	       b[f]= 1;
	       p= 2;
	       printf ("\n %d", b[f] );
	       printf ( "\n Y SU NUEVO ESTADO ES: %d\n", p);
	       f++;
		   if(f==6){
		   f=0;
		   }
	       }
	       else{
	       if (a[f]==0 && p==3){
		   b[f]=' ';
		   p=5;
		   printf ("\n %d", b[f] );
		   printf ( "\n Y SU NUEVO ESTADO ES: %d\n", p);
		   f--;
		   if(f==6){
		   f=0;
		   }
		   }
		   else{
		   if (a[f]==1 && p==3){
		       b[f]=0;
		       p= 4;
		       printf ("\n %d", b[f] );
		       //cont+= 1;
		       printf ( "\n Y SU NUEVO ESTADO ES: %d\n", p);
		       f--;
		       if(f==6){
		       f=0;
		       }
		       }
		       else{
		       if (a[f]==0 && p==4 ){
			  b[f]=1;
			  p=2;
			  printf ("\n %d", b[f] );
			  printf ( "\nY SU NUEVO ESTADO ES: %d\n", p);
			  //cont+= 1;
			  f++;
			  }
			 }
		      }
		    }
		   }
		  }
		  getch();
		 }
		 }