 # include <conio.h>
 # include <stdio.h>
 # include <iostream.h>

 // DECLARACION DE PROTOTIPOS DE FUNCIONES

 void lect_mat ( int matriz [10][10],int);
 void esc_mat ( int matriz [10][10],int);
 void lect_vect(int vector [10],int);
 void esc_vect(int vector[10],int);
 void trans_mat(int matriz [10][10],int tmatriz[10][10],int);
 int sum_dpral(int matriz [10][10],int);
 int sum_dsdria(int matriz [10][10],int);
 void product(int matriz[10][10],int vect[10],int vector[10],int);
 // PROGRAMA QUE REALIZA DIFERENTES OPERACIONES CON MATRICES


 void main()
 {
 textcolor(WHITE);
 textbackground(BLUE);
 clrscr();
 int A[10][10],B[10][10],i,j,n,m,n1,m1,C[10],D[10];
 int X1[10],X2[10],At[10][10],Bt[10][10],AX1[10],BX2[10];
 int sdpA,sdpB,sdsA,sdsB,sum,prod;

 cout << " DIGITE EL NRO DE FILAS Y COLUMNAS DE LA MATRIZ A: ";
 cin>>n;
 cout << " DIGITE EL NRO DE FILAS Y COLUMNAS DE LA MATRIZ B: ";
 cin>>m;
 cout<<" \n LOS ELEMETOS DE LA MATRIZ A SON : \n";

 lect_mat (A,n);

 cout<<"\n LOS ELEMENTOS DE LA MATRIZ B SON : \n ";

 lect_mat (B,m);

 // SUMA DE LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL DE A

 sdpA= sum_dpral(A,n);


 // SUMA DE LOS ELEMENTOS DE LA DIAGONAL SECUNDARIA DE A

 sdsA= sum_dsdria(A,n);

 // TRANSPUESTA DE LOS ELEMENTOS DE LA MATRIZ A

 trans_mat(A,At,n);

 // SUMA DE LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL DE B

 sdpB= sum_dpral (B,m);

 // SUMA DE LOS ELEMENTOS DE LA DIAGONAL SECUNDARIA DE B

 sdsB= sum_dsdria(B,m);

 // TRANSPUESTA DE LOS ELEMENTOS DE LA MATRIZ B

 trans_mat(B,Bt,m);

 // HALLAR EL VECTOR X1

 for (i=1;i<=n;i++){
    sum=0;
    for(j=1;j<=n;j+=2){
      sum+=A[i][j];
    }
    X1[i]= sum;
 }

 // HALLAR EL VECTOR X2

 for (i=1;i<=m;i++){
   prod = 1;
   for(j=2;j<=m;j+=2){
     prod *=B[i][j];
   }
   X2[i]= prod;
 }

 product(A,X1,C,n);
 product(B,X2,D,m);

 cout<<"suma de los elementos diagonal principal de A ="<<sdpA<<"\n";
 cout<<"suma de los elemtos de la diagonal secundaria de A = "<<sdsA<<"\n";
 cout<<"suma de los elemntos de la diagonal principal de B= "<<sdpB<<"\n";
 cout<<"suma de los elemntos de la diagonal secundaria de B= "<<sdsB<<"\n";
 /*cout<<"\n el producto de A*X1: \n";
 getch();
 for (i=1;i<=n;i++){
 cout<<"\n X1["<<i<<"]=";
 cout <<C[i];
 }
 getch();
 cout <<"\n el producto de B*X2: \n ";
 for (i=1;i<=m;i++){
 cout<<"\n X2["<<i<<"]=";
 cout <<D[i];
 }*/
 getch(); 
 cout<< "\n IMPRIMIR TRANSPUESTA DE A \n";
 for (i=1;i<=n;i++){
   for (j=1; j<=n; j++){
    cout << "\n LA TRANSPUESTA DE: At["<<i<<","<<j<<"]= ";
    cout << At[i][j];
   }
 }
 getch();
 cout<<"\n IMPRIMIR TRANSPUESTA DE B \n";
 for(i=1;i<=m;i++){
   for(j=1;j<=m;j++){
    cout <<" \n LA TRAMSPUESTA DE: Bt["<<i<<","<<j<<"]=";
    cout << Bt[i][j];
   }
 }
getch();
}

// DEFINICION DE FUNCIONES

// fUNCION PARA LEER UNA MATRIZ

void lect_mat(int matr[10][10],int fil_col)
{
int i,j;
for (i=1;i<=fil_col;i++){
  for (j=1;j<=fil_col;j++){
   cout <<"\n"<<"A["<<i<<","<<j<<"]= ";
   cin >> matr[i][j];
  }
}
}
// SUMA DE LA DIAGONAL PRINCIPAL DE UNA MATRIZ CUADRADA

int sum_dpral(int matr[10][10],int fil_col)
{
int suma_dppal,i,j;
suma_dppal=0;
for (i=1;i<=fil_col;i++){
  suma_dppal+= matr[i][i];
}
return suma_dppal;
}

// SUMA DE LA DIAGONAL SECUNDARIA DE UNA MATRIZ CUADRADA

int sum_dsdria(int matriz [10][10],int fil_col)
{
int suma_dsra,i,n1;
suma_dsra=0;
n1= fil_col+1;
for (i=1;i<=fil_col;i++){
  suma_dsra+= matriz[i][n1-i];
}
return suma_dsra;
}
// CALCULO DE LA PRODUCTORIA

void product(int matr[10][10],int s[10],int r[10],int p)
{
int i,j,sum;
for (i=1;i<=p;i++){
   sum= 0;
   for(j=1;j<=p;j++){
    sum+= matr [i][j]*s[j];
   }
   r[i]= sum;
   }
}

// CALCULO DE LA TRANSPUESTA

void trans_mat(int matriz [10][10],int t_matriz[10][10],int fil_col)
{
int i,j;
for (i=1;i<=fil_col;i++){
  for(j=1;j<=fil_col;j++){
  t_matriz[i][j]=matriz[j][i];
  }
}
}
