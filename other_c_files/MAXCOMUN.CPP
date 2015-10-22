# include<stdio.h>
# include"conio.h"
# include"dos.h"
int MCD(int, int);
void main()
{
int N,M;

int max;
clrscr();
printf ("Digite N");
scanf ("%d", &N);
printf ("digite M");
scanf ("%d", &M);
max= MCD(M,N);
printf ("EL MAXIMO COMUN DIVISOR ES %d y %d es: %d\n: ", M,N,max);
printf ("\n N = %04X:%04X",FP_SEG(N), FP_OFF(N));
printf ("\n M = %04X:%04X",FP_SEG(M), FP_OFF(M));
printf ("\n MCD = %04X:%04X",FP_SEG(MCD), FP_OFF(MCD));


}


//LLAMANDO A LA FUNCION MAXCOMUN
int MCD (int N ,int M)
{
int maxi;
if (N>M){
   maxi= MCD(M,N); //caso trivial

   }
   else{
   if (N==0){
      maxi= M;  //Caso trivial
      }
      else{
      if (N>0){
      
      maxi= MCD(N,M%N); //Caso general
      }
    } 
   }
   return maxi;
   
   }
