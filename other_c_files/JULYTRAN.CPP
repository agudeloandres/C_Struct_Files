#include<iostream.h>
//prototipo de las funciones de las matrices
void leer_matriz(int matriz[10][10],int);
void producto(int matriz[10][10],int vector[10],int vectores[10],int );
void transpuesta(int matriz[10][10],int matransp[10][10],int);
int su_diag_ppal(int matriz[10][10],int);
int su_diag_sec(int matriz[10][10],int);

void main()
{
//funciones del programa y variables

int a[10][10],b[10][10],fico,i,j,n,m,h[10],s[10];
int x1[10],x2[10],at[10][10],bt[10][10];
int ax1[10],bx2[10];
int sdpa,sdpb,sdsa,sdsb,su,pro;

cout<<"Digite el numero de filas y columnas de a:\n";
cin>>n;

cout<<"Digite el numero de filas y columnas de b:\n";
cin>>m;

//leer_la matriz a

cout<<"Digite los valores de la matriz a\n";
leer_matriz (a,n);

//leer_la matriz b

cout<<"Digite los valores de la matriz b\n";
leer_matriz (b,m);

//suma de la diagonal principal de a:

sdpa=su_diag_ppal(a,n);

//suma de la diagonal principal de b:

sdpb=su_diag_ppal(b,m);

//suma de la diagonal secundaria de a:

sdsa=su_diag_sec(a,n);

//suma de la diagonal secundaria de b:

sdsb=su_diag_sec(b,m);

//se busca la matriz transpuesta de a:

transpuesta(a,at,n);

//se busca la matriz transpuesta de b:

transpuesta(b,bt,m);

//se busca vector x1 de la matriz a:

for (i=1;i<=n;i++){
su=0;
for (j=1;j<=n;j+=2){
su+=a[i][j];
}
x1[i]=su;
}

//se busca vector x2 de la matriz b:

for (i=1;i<=m;i++){
pro=1;
for (j=1;j<=m;j+=2){
pro*=b[i][j];
}
 x2[i]=pro;
}

//se busca el producto de a:

producto (a,x1,h,n);

//se busca el producto de b:

producto (b,x2,s,m);

cout<<"la sumatoria de la diagonal principal de a es:"<<sdpa<<"\n";
cout<<"la sumatoria de la diagonal principal de b es:"<<sdpb<<"\n";
cout<<"la sumatoria de la diagonal secundaria de a es:"<<sdsa<<"\n";
cout<<"la sumatoria de la diagonal secundaria de b es:"<<sdsb<<"\n";

cout<<"\n imprima el vector de a*x1:";
for (i=1;i<=n;i++){
cout<<"\n El producto de a es:["<<i<<"]=\n";
cout<<h[i];
}
cout<<"\n imprima el vector de b*x2:\n";
for (i=1;i<=n;i++){
cout<<"\n El producto de b es:["<<i<<"]=\n";
cout<<s[i];
} 

cout<<"\n Imprima la matriz transpuesta de a: \n";
for (i=1;i<=n;i++){
 for (j=1;j<=n;j++){
   cout<<" La matriz transpuesta de a es:at["<<i<<","<<j<<"]=";
   cout<<at[i][j]<<"\n";
 }
}
cout<<"\n Imprima la matriz transpuesta de b: \n";
for (i=1;i<=m;i++)
{
for (j=1;j<=m;j++)
{
cout<<" La matriz transpuesta de b es:bt["<<i<<","<<j<<"]=";
cout<<bt[i][j]<<"\n";
}
}
}

// funciones de cada uno
// lectura

void leer_matriz(int matriz[10][10],int fi_co)
{
int i,j;
for(i=1;i<=fi_co;i++)
{
for(j=1;j<=fi_co;j++)
{
cout<<":matriz("<<i<<","<<j<<")=";
cin>>matriz[i][j];
}
}

}
//suma de la diagonal principal
int su_diag_ppal(int matriz[10][10],int fi_co)
{
int i,sdp;
sdp=0;
for (i=1;i<=fi_co;i++)
{
sdp+=matriz[i][i];
}
return sdp;
}
//suma de la diagonal secundaria
int su_diag_sec(int matriz[10][10],int fi_co)
{
int i,sds,fico;
sds=0;
fico=fi_co+1;
for(i=1;i<=fi_co;i++)
{
sds+=matriz[i][fico-1];
}
return sds;
}
//matriz transpuesta
void transpuesta(int matriz [10][10],int matransp[10][10],int fi_co)
{
int i,j;
for(i=1;i<=fi_co;i++)
{
for(j=1;j<=fi_co;j++)
{
matransp[i][j]=matriz[j][i];
}
}

}


//la productoria

void producto(int matriz[10][10],int c[10],int l[10],int w)
{
int i,j,su;
for(i=1;i<=w;i++){
su=0;
for(j=1;j<=w;j++){
su+=matriz[i][j]*c[j];
}
l[i]=su;
}
}


