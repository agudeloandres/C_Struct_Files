#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

 void main()
{
int z,w,q,m;
    int a,b,c,k,d[10][10],f[10][10];
    int cont,con ,co,o,p,r,t[10][10],juan,v;
	  clrscr();
	  for(a=1;a<=80;a++){
	    gotoxy(10+a,1);
	    putchar(1);
	      delay(10);
	      }
	  for(a=1;a<=20;a++){
	    gotoxy(10,1+a);
	    putchar(1);
	     delay(10);



		  }

	  printf (" RESERVACIONES CON 1 Y LUGARES VACIOS CON CEROS \n  ");
	ini:
       for(a=1;a<=4;a++){
	     k=15;
	   for(b=1;b<=9;b++){
	     gotoxy(b+k,a+10);
	      printf("0");
	      f[a][b]=0;

		  k+=5;

		   }
	       }
		 gotoxy(10,10);
		 printf("DIGITE RESERVACIONES");


		  for(a=1;a<=4;a++){
		   k=15;
		   for(b=1;b<=9;b++){

		    // if(f[a][b]==0){
		     gotoxy(10,10);

		       gotoxy(k+b,a+10);
		       scanf("%d",&t[a][b]);
			f[a][b]= t[a][b];
			k+=5;
		      //			}
				       }

				      }



			  for(a=1;a<=4;a++){
			   for(b=1;b<=9;b++){
			  if(f[a][b]==1){
			  printf("\nla pocicion %d,%d ,est  ocupada ",a,b);

					    }
				 else
				if(f[a][b]==0){
				 printf("\nla pocicion %d,%d esta vacia",a,b);
						   }
						   else
			    if(f[a][b]!=1||f[a][b]!=0){
			    printf("\nla pocicion %d,%d, esta erroneamente reservada",a,b);

						    }

					       }
				 }

				  printf("\n Digite n£mero de datos a verificar y <<enter>>  \n ");
				   scanf("%d",&juan);
				 for(v=1;v<=juan;v++){
				 printf("\n fila ");
				 scanf("%d",&a);
				 printf("\n columna ");
				 scanf(" %d",&b);
			  if(f[a][b]==1){
			  printf("\nla pocicion %d,%d ,esta ocupada ",a,b);

					    }
			    else
			    if(f[a][b]==0){
		   printf(" \nla pocicion %d,%d esta vacia ",a,b);
					}


			    else
			    if(f[a][b]!=1||f[a][b]!=0){
			    printf("\n\a\a\a la pocicion %d,%d, esta erroneamente reservada",a,b);
						    }


						      }
				   printf("desea cambiar reservaciones S(1)/N(2)");
				   scanf("%d",&v);
				   if(v==1){
				     clrscr();
				     goto ini;
					  }
					  else
					  clrscr();

					  printf("\n\n\n\n\n\n\n\n                          PROGRAMA FINALIZADO");
					  delay(2000);

				     }
			      getch();





