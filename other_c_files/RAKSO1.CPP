#include <iostream.h>
#include <f:ruma.h>

 //programa que haya las sumas de matriz
  void main ()
  {

  int i,j,k, a[10][10], b[10][10], pro[10][10];
  int sumdiaga, sum, sumdiagb, sumdisea, sumdiseb, n, n1;   

  cout<<"Digite numero de Filas y Columnas de A y B =";
   do {
  cin>>n;
  }
  while ( n>0 && n>10);

  // lectura de elementos de la matriz a
    lee_matriz (a,n);
   
  // lectura elementos de matriz b
    lee_matriz (b,n);

  // suma diag principal matriz a
    sumdiaga=suma_dia_ppal(a,n);

  // suma diag principal matriz b
    sumdiagb=suma_dia_ppal(b,n);

  // suma diag secundaria matriz a
    suma_disec(a,n);

  // suma diag secundaria matriz b
    suma_disec(b,n);

  // producto de las dos matrices
    producto (a, b, pro, n);

  // impresion matriz a
    imprimir (a,n);

  // impresion matriz b
    imprimir (b,n);

  // impresion de producto a*b
    imprimir (pro, n);

  // impresion de sumas diagonales
     
    sumdiaga=suma_dia_ppal (a,n);
      cout <<"\n suma diag principal A ="<<sumdiaga;


    sumdiagb=suma_dia_ppal (b,n);
      cout <<"\n suma diag principal B ="<<sumdiagb;


    sumdisea=suma_disec(a,n);
      cout<<"\n suma diag secndaria A =" <<sumdisea;


    sumdiseb=suma_disec(b,n);
      cout<<"\n suma diag secndaria B =" <<sumdiseb;

  }
  
   
