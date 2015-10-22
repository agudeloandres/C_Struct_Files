
 #include <conio.h>

 #include <iostream.h>

 #include <stdio.h>

 //Prototipos
 void leer_elementos(int *);
 void leer_matriz(float [10][10],int);
 float suma_diagonal_ppal (float[10][10], int);
 float suma_diagonal_sec (float [10][10], int);
 float producto_triangular_superior (float[10][10], int);
 int pares_ti (float[10][10], int);
 void transpuesta (float [10][10], int , float [10][10]);
 void escriba_matriz (float[10][10], int);

 void main()

 {

 float A[10][10],B[10][10],AT[10][10],BT[10][10];

 float sdpa,sdpb,prodta,prodtb,sdsa,sdsb;

 int n,m,paretia,paretib;

 //ENTRADA DE DATOS

 leer_elementos (&n);

 leer_matriz (A,n);

 leer_elementos (&m);

 leer_matriz (B,m);

 //PROCESO

 sdpa=suma_diagonal_ppal (A,n);

 sdpb=suma_diagonal_ppal (B,m);

 sdsa=suma_diagonal_sec (A,n);

 sdsb=suma_diagonal_sec (B,m);

 prodta=producto_triangular_superior (A,n);

 prodtb=producto_triangular_superior (B,m);

 paretia=pares_ti (A,n);

 paretib=pares_ti (B,m);

 transpuesta (A,n,AT);

 transpuesta (B,m,BT);

 //SALIDA

 clrscr();

 cout<<"matriz A"<<"\n";

 escriba_matriz (A,n);

 cout<<"matriz B"<<"\n";

 escriba_matriz (B,n);

 getch();

 clrscr();

 cout<<"transpuesta de A"<<"\n";

  escriba_matriz (AT,n);

  cout<<"transpuesta de B"<<"\n";

  escriba_matriz (BT,n);

  getch();

 cout<<"LA SUMA DE LA DIAGONAL PRINCIPAL DE A ES:" << sdpa<<"\n";

 cout<<"LA SUMA DE LA DIAGONAL PRINCIPAL DE B ES:"<< sdpb <<"\n";

 cout<<"LA SUMA DE LA DIAGONAL SECUNDARIA DE A ES:"<< sdsa <<"\n";

 cout<<"LA SUMA DE LA DIAGONAL SECUNDARIA DE B ES:"<< sdsb <<"\n";

 cout<<"EL PRODUCTO DE LA TRIANGULAR SUPERIOR DE A ES:"<< prodta<<"\n";

 cout<<"EL PRODUCTO DE LA TRIANGULAR SUPERIOR DE B ES:"<< prodtb<<"\n";

 cout<<"NUMEROS MAYORES QUE DOS DE LA TRIANGULAR INFERIOR DE A ES:"<< paretia<<"\n";

 cout<<"NUMEROS MAYORES QUE DOS DE LA TRIANGULAR INFERIOR DE B ES:"<< paretib<<"\n";

 getch();

 }

 ////************************ FUNCIONES *******************************////

 //*************************** Libreria prod.h ********************************

//******************* Rutina para leer grado de una matriz ********************

 void leer_elementos (int*nroelementos)

 {

  clrscr();

  do{

     cout<<"Digite grado de la matriz"<<"\n";

     cin>>*nroelementos;

     }while (*nroelementos<2);

     return;

    }


//******************* Rutina para leer una matriz ****************************

 void leer_matriz (float matriz [10][10], int nroelementos)

 {

  clrscr();

  int i, j, n1;

  n1=nroelementos-1;

  for (i=0; i<=n1; i++){

      for (j=0; j<=n1; j++){

	   cout<<"Matriz ["<<i<<","<<j<<"]  ="<<"\t";

	   cin >>matriz[i][j];

      }

  }

  return;

 }

//****************** Rutina para sumar diagonal ppal de una matriz ***********

 float suma_diagonal_ppal (float matriz [10][10], int nroelementos)

 {

  clrscr();

  int i, n1;

  float sdpa;

  n1=nroelementos-1;

  sdpa=0;

  for (i=0; i<=n1; i++){

      sdpa=sdpa+matriz[i][i];

  }

  return sdpa;

 }

//****************** Rutina para sumar diagonal secundaria de una matriz *****

 float suma_diagonal_sec (float matriz [10][10], int nroelementos)

 {

  clrscr();

  int i, n1;

  float sds;

  n1=nroelementos-1;

  sds=0;

  for (i=0; i<=n1; i++){

      sds=sds+matriz[i][n1-i];

  }

  return sds;

 }

//****************** Rutina para hallar producto de la triangular superior ***

float producto_triangular_superior (float matriz [10][10], int nroelementos)

 {

  clrscr();

  int i, j, n1;

  float prodts;

  n1=nroelementos-1;

  prodts=1;

  for (i=0; i<=n1; i++){

      for (j=0; j<=n1; j++){

	  if (i<j){

	     prodts=prodts*matriz [i][j];
	  }

      }

  }

  return prodts;
 }

//****************** Rutina para contar los numeros mayores que 2 en la triangular inferior ***

 int pares_ti (float matriz [10][10], int nroelementos)

  {

   clrscr();

   int i, j, n1;

   int cm2;

   n1=nroelementos-1;

   cm2=0;

   for (i=0; i<=n1; i++){

       for (j=0; j<=n1; j++){

	   if ((i>j) && (matriz [i][j]>2)){

	      cm2=cm2+1;

	   }

       }

   }

   return cm2;

   }

//******************* Rutina para hallar la transpuesta de una matriz  ***

  void transpuesta (float matriz[10][10], int nroelementos, float MAT[10][10])

   {

   clrscr();

   int i, j, n1;

   n1=nroelementos-1;

   for (i=0; i<=n1; i++){

       for (j=0; j<=n1; j++){

	    MAT[j][i]=matriz[i][j];

       }

   }

  return;

  }


//****************** Rutina para escribir una matriz *************************

 void escriba_matriz (float matriz [10][10], int nroelementos)

 {

 int i, j, n1;

 n1=nroelementos-1;

 for (i=0; i<=n1; i++){

     for (j=0; j<=n1; j++){

	 cout<<matriz[i][j]<<"\t";

     }

     cout<<"\n";

 }

 return;

 }
