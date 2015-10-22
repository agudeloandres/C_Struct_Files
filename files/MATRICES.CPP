#include <iostream.h>
//definicion del prototipo
void leer_matriz(int matriz[20][20],int);
void esc_matriz(int matriz[20][20],int);
void esc_vector(int vector[20],int);
int sum_diag_ppal(int matriz[20][20],int);
int sum_diag_sec(int matriz[20][20],int);
void mat_trans(int matriz[20][20],int,int matrizt[20][20]);
void mult_vec_mat(int matriz[20][20],int vec[20],int,int vec1[20]);

void main()
{
//programa para utilizacion de funciones
//definicion de variables

int i,j,m,n,sdpa,sdpb,sdsa,sdsb,pro,sum;
int X1[20],X2[20],aX1[20],bX2[20];
int a[20][20],b[20][20],at[20][20],bt[20][20];


cout<<"digite el número de filas y columnas de a\n";
cin>>n;
cout<<"digite el número de filas y columnas de b\n";
cin>>m
;
//leer la matriz a
cout<<"digite los valores de la matriz a\n";
leer_matriz(a,n);

//leer la matriz b
cout<<"digite los valores de la matriz b\n";
leer_matriz(b,m);

//suma de la diagonal principal de  la matriz a

sdpa=sum_diag_ppal(a,n);

//suma de la diagonal principal de la matriz b

sdpb=sum_diag_ppal(b,m);

//suma de la diagonal secundaria de a

sdsa=sum_diag_sec(a,n);

//suma de la diagonal secundaria de b

sdsb=sum_diag_sec(b,m);

//matriz transpuesta de a
mat_trans(a,n,at);
//matriz transpuesta de b
mat_trans(b,m,bt);


/*hallar vector X1 tal que c/u de los elementos del vector sea igual a
  la suma de cada una de las filas de a*/

for (i=1;i<=n;i++){
     sum=0;
     for(j=1;j<=n;j++){
	sum+=a[i][j];
     }
     X1[i]=sum;
}    
/*hallar vector X2 tal que c/u de los elementos del vector sea igual a
  la multiplicacion de las posiciones pares de c/u de las filas de b*/
for(i=1;i<=m;i++){
    pro=1;
    for(j=1;j<=m;j++){
	pro+=b[i][j];
    }
    X2[i]=pro;
} 
//multiplicar vector X1 a la matriz a 

mult_vec_mat(a,X1,n,aX1);

//multiplicar vector X2 a la matriz b

mult_vec_mat(b,X2,m,bX2);

//salidas del programa
//escribir matrices a y b
cout<<"la matriz a es:\n";
esc_matriz(a,n);
cout<<"la matriz b es:\n";
esc_matriz(b,m);

//escribir las transpuestas
cout<<"la matriz transpuesta de a es:\n";
esc_matriz(at,n);
cout<<"la matriz transpuesta de b es:\n";
esc_matriz(bt,m);

//escribir los vectores
cout<<"el vector resultante X1:\n";
esc_vector(X1,n);
cout<<"el vector resultante X2:\n";
esc_vector(X2,m);
cout<<"la multiplicacion del vector X1 a la matriz a es:\n";
esc_vector(aX1,n);
cout<<"la multiplicacion del vector X2 a la matriz b es:\n";
esc_vector(bX2,m);
//escribir las sumatorias de las diagonales

cout<<"la sumatoria de la diagonal principal de a es:"<<sdpa<<"\n";
cout<<"la sumatoria de la diagonal principal de b es:"<<sdpb<<"\n";
cout<<"la sumatoria de la diagonal secundaria de a es:"<<sdsa<<"\n";
cout<<"la sumatoria de la diagonal secundaria de b es:"<<sdsb<<"\n";
}

//definicion de funciones
//funcion leer matriz
void leer_matriz(int matriz[20][20],int fil_col)
{
int i,j;
for(i=1;i<=fil_col;i++){
    for(j=1;j<=fil_col;j++){
       cout<<"mat("<<i<<","<<j<<")=";
       cin>>matriz[i][j];
    }
}
return;
}
//funcion suma diagonal p/pal
int sum_diag_ppal(int matriz[20][20],int fil_col)
{
int i,j,sdp;
sdp=0;
for(i=1;i<=fil_col;i++){
   sdp+=matriz[i][i];
}
return sdp;
}

//funcion suma diagonal secundaria
int sum_diag_sec(int matriz[20][20],int fil_col)
{
int i,j,fc,sds;
sds=0;
fc=fil_col-1;
for(i=1;i<=fil_col;i++){
   sds+=matriz[i][i+fc];
   fc-=2;
}
return sds;
}

//funcion matriz transpuesta
void mat_trans(int matriz[20][20],int fil_col,int matrizt[20][20])
{
int i,j;
for(i=1;i<=fil_col;i++){
   for(j=1;j<=fil_col;j++){
      matrizt[i][j]=matriz[j][i];
   }
}
return;
}
//funcion escribir matriz
void esc_matriz(int matriz[20][20],int fil_col)
{
int i,j;
for(i=1;i<=fil_col;i++){
   for(j=1;j<=fil_col;j++){
      cout<<"matriz("<<i<<","<<j<<")=";
      cout<<matriz[i][j]<<"\n";
   }
}
return;
}
//funcion escribir vector
void esc_vector(int vector[20],int fil_col)
{
int i;
for(i=1;i<=fil_col;i++){
    cout<<"vector("<<i<<")=";
    cout<<vector[i]<<"\n";
}
return;
}
//funcion multiplicar vector por matriz
void mult_vec_mat(int mat[20][20],int vec[20],int fil_col,int vec1[20])
{
int i,j,sum;
for(i=1;i<=fil_col;i++){
    sum=0;
    for(j=1;j<=fil_col;j++){
       sum=mat[i][j]*vec[j];
    }
    vec1[i]=sum;
}
return;
}  

