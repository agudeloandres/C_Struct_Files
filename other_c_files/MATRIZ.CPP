# include <iostream.h>
//definicion del prototipo
void lectura_mat(int matriz[20][20],int);
void escritura_mat(int matriz[20][20],int);
void lectura_vect (int vector[20],int);
void escritura_vect(int vector[20],int);
int sum_diag_ppal(int matriz[20][20],int);
int sum_diag_sdria(int matriz[20][20],int);
void transpuestamatriz(int matriz[20][20],int tmatriz [20][20],int);
//programa que realiza diferentes operaciones cn matrices
void main()
{

int a[20][20],b[20][20],i,j,n,m,n1,m1;
int X1[20],X2[20],at[20][20],bt[20][20],ax1[20],bx2[20];
int sdpa,sdsa,sdpb,sdsb,su,pro;

cout<<"digite el número de filas y columnas de a:";
cin>>n;
cout<<"digite el número de filas y columnas de b:";
cin>>m
;
//lectura matriz a
cout<<"digite los valores de la matriz a\n:";
lectura_mat(a,n);

//lectura matriz b
cout<<"digite los valores de la matriz b:";
lectura_mat(b,m);

//suma de los elementos de la diagonal principal de  la matriz a

sdpa=sum_diag_ppal(a,n);

//suma de los elementos de la diagonal secundaria de a

sdsa=sum_diag_sdria(a,n);

//suma de los elementos de la diagonal principal de la matriz b

sdpa=sum_diag_ppal(a,n);

//suma de los elementos de la diagonal secundaria de b

sdsb=sum_diag_sdria(b,n);

//matriz transpuesta de a
transpuesta (a,n,at);

//matriz transpuesta de b
transpuesta(b,bt,m);

//hallar vector x1 

for (i=1;i<=n;i++){
     su=0;
     for(j=1;j<=n;j+=2){
	su+=a[i][j];
     }
     X1[i]=su;
}    
//hallar vector x2

for(i=1;i<=m;i++){
    pro=1;
    for(j=2;j<=m;j+=2){
	pro*=b[i][j];
    }
    X2[i]=pro;
}

//Calculo del producto a*x1
for (i=1;i<=n;i++){
su=0;
for (j=1;j<=n;j++){
su+=a[i][j]*x1[j];
}
ax1[i]=su;
}
//calculo del prducto b*x2
for (i=1;i<=m;i++){
su=0;
for (j=1;j<=m;j++){
su+=b[i][j]*x2[j];
}bx2[i]=su;
}
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
}
//funcion escribir vector
void esc_vector(int vector[20],int fil_col)
{
int i;
for(i=1;i<=fil_col;i++){
    cout<<"vector("<<i<<")=";
    cout<<vector[i]<<"\n";
}
}


