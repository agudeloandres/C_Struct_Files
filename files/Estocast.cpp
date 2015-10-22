#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
#include <dos.h>
main()
{
ini:
  window( 1, 1, 80, 25 );
     textbackground(WHITE);
     textcolor( BLUE );
			    //  **************************************
clrscr();                  //   *     INGRESO DE LOS VALORES         *
int i,j,n,m,h,l,s,t,w;    //    **************************************
float a[40][40],b[40],c[40],C;
gotoxy(26,2);cout<<"PROCESOS ESTOCASTICOS";
gotoxy(3,4);cout<<"DIGITE EL TAMAฅO DEL VECTOR:  ";scanf("%d",&n);
gotoxy(3,6);cout<<"DIGITE EL TAMAฅO DE LA MATRIZ:\n";
gotoxy(35,6);scanf("%d",&m);
gotoxy(38,6);cout<<"X";
gotoxy(40,6);scanf("%d",&h);
 if(m==n){
   gotoxy(3,8);cout<<"DIGITE EL NUMERO DE ITERACIONES: ";scanf("%d",&s);
   gotoxy(3,10);cout<<"DIGITE LOS VALORES DEL VECTOR:\n";
    for(i=1 ;i <= n; i++){
     scanf("%f",&b[i]);
    }
   cout<<"DIGITE LOS VALORES DE LA MATRIZ:\n";
    for(i=1;i<=m;i++){
     for(j=1;j<=h;j++){
      scanf("%f",&a[i][j]);
      }
     }
   clrscr();
   t=1;
    for(i=1;i<=s;i++){
     for(l=1;l<=h;l++){
      C=0;
       for(j=1;j<=n;j++){
	C=(float)b[j]*a[j][l]+C;
       }
      c[l]=C;
     }

    for(j=1;j<=h;j++){
     b[j]=c[j];
    }
   w=1;
   gotoxy(20,4);cout<<"RESULTADOS DE LAS PROBABILIDADES\n";
   for(j= 1; j<=h ;j++){
     gotoxy(15+w,6+t);
     printf("%f",c[j]);
     w=w+12;
    }
   t=t+2;
  }              //  **********************************
  getche();     //   *   DE ESTA MANERA SE MUESTRAN   *
	       //    *        LOS MENSAJES DE         *
 }            //     *            ERRORES             *
 else {      //      **********************************
  gotoxy(35,10);cout<<"ERROR\a\a\a";
  gotoxy(5,14);cout<<" EL TAMAฅO DE LA COLUMNA DE LA MATRIZ ES DIFERENTE A LA DEL VECTOR\a\a";
  textcolor(2);
  delay(2400);
  goto ini;
 }
//     *****************************************************************
//     * 	        PANTALLA DE SALIDA DEL PROGRAMA    	       *
//     *****************************************************************

     clrscr();
     gotoxy(26,4);cout<<"PROCESOS ESTOCASTICOS";
      int v,k;
 gotoxy(4,2);  cout<<"ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
 for (v=3; v < 24; ++v){
    gotoxy(4,v);
      cout<<"บ";
  }
 gotoxy(4,23); cout<<"ศ";
  for (k=5; k< 73; ++k){
   gotoxy(k,72);
    cout<<"อ";
    }
    gotoxy(72,23); cout<<"ผ";
 for (v=3; v < 23; ++v){
    gotoxy(72,v);
      cout<<"บ";
    }

     gotoxy(23,8);cout<<"JUAN CARLOS BERMUDEZ DIAZ";
     gotoxy(25,10);cout<<"ELIANA M. VILLALOBOS M.";
     gotoxy(26,12);cout<<"ALEJANDRA CASTAฅEDA R.";
     gotoxy(29,14);cout<<"OSVALDO PAEZ B.";
     gotoxy(25,16);cout<<"MARIA ALEJANDRA KERGUELEN";
     gotoxy(20,19);cout<<"UNIVERSIDAD COOPERATIVA DE COLOMBIA";
     gotoxy(35,22);cout<<"1998";
     getche();
     return 0;


}
