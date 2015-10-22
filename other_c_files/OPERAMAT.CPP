#include <iostream.h>
#include <conio.h>

 
// DECLARANDO PROTOTIPO

void lectura_mat(int matriz[10][10],int);
void escritura_mat(int matriz[10][10],int);
void lectura_vect(int vector[10],int);
void escritura_vect(int vector[10],int);
int suma_diag_ppal(int matriz[10][10],int);
int suma_diag_sdria(int matriz[10][10],int);
void transpuesta(int matriz[10][10],int tmatriz[10][10],int );
void producto(int matriz[10][10],int vector[10],int vecto[10],int);


/*PROGRAMA QUE REALIZA DIFERENTES OPERACIONES
 CON MATRICES*/

void main()
{

int col[10],col1[10],a[10][10],b[10][10],t,i,j,n,m,n1,m1;
int x1[10],x2[10],bt[10][10],at[10][10],ax1[10],bx2[10];
int sdpa,sdsa,sdpb,sdsb,su,pro;


cout<<"nro de filas y columnas de A:";
cin>>n;
cout<<"nro de filas y columnas de B:";
cin>>m;

cout<<"\n elementos de A\n";
lectura_mat(a,n);

cout<<"\n elementos de B\n";
lectura_mat(b,m);

//SUMA DE LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL DE A

   sdpa=suma_diag_ppal(a,n);
              
//SUMA DE LOS ELEMENTOS DE LA DIAGONAL SECUNDARIA DE A
   sdsa=suma_diag_sdria(a,n);

/* INTERCAMBIAR FILAS POR COLUMNAS DE A ES DECIR QUE
   LAS FILAS DE A SERAN COLUMNAS DE AT*/
    
   transpuesta(a,at,n);

//SUMA DE LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL DE B;
   sdpb=suma_diag_ppal(b,m);

//SUMA DE LOS ELEMENTOS DE LA DIAGONAL SECUNDARIA DE B;
   sdsb=suma_diag_sdria(b,m);

/* INTERCAMBIAR FILAS POR COLUMNAS DE B ES DECIR QUE LAS
FILAS DE A SERAN COLUMNAS DE BT*/

   transpuesta (b,bt,m);

                
//HALLANDO EL VECTOR x1

   for(i=1;i<=n;i++){
       su=0;
     for(j=1;j<=n;j+=2){
      su+=a[i][j];
     }
    x1[i]=su;
   }

//HALLANDO EL VECTOR x2

   for(i=1;i<=m;i++){
        pro=1;
     for(j=2;j<=m;j+=2){
       pro *=b[i][j];
     }
     x2[i]=pro;
   }
//LLAMANDO LAS PRODUCTORIASs
    producto(a,x1,col,n);
    producto(b,x2,col1,m);               
 cout<<"suma de los elementos de la diagonal principal de A ="<<sdpa<<"\n";
 cout<<"suma de los elementos de la diagonal secundaria de A ="<<sdsa<<"\n";
 cout<<"suma de los elementos de la diagonal principal de B="<<sdpb<<"\n";
 cout<<"suma de los elementos de la diagonal secundaria de B="<<sdsb<<"\n";

//CALCULANDO LAS TRANSPUESTAS

 cout<<"\n la matriz transpuesta de A es \n";
 escritura_mat(at,n);
 cout<<"\n la matriz transpuesta de B  es \n";
 escritura_mat(bt,m);
 cout<<"el producto de A*x1:\n";

    for (i=1;i<=n;i++){
      cout<<"\n Ax1["<<i<<"]=";
      cout<<col[i];
    }
 cout<<"\n el producto de B*x2:\n";

    for(i=1;i<=m;i++){
      cout<<"\n Bx2["<<i<<"]=";
      cout<<col1[i];
    } 
 }
  
//DEFINICION DE FUNCIONES

//FUNCION PARA LEER UNA MATRIZ

  void lectura_mat(int mat[10][10],int fil_col){
  int i,j;
    for(i=1;i<=fil_col;i++){
       for(j=1;j<=fil_col;j++){
         cout<<"mat["<<i<<","<<j<<"]=";
         cin>> mat[i][j];
       }
    }
  }
 
//SUMA DE LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL DE UNA MATRIZ CUADRADA

   int suma_diag_ppal(int mat[10][10],int fil_col){
   int suma_diag,i;
    suma_diag=0;
     for(i=1;i<=fil_col;i++){
       suma_diag+=mat[i][i];
     }
      return suma_diag;
   }

//SUMA DE LA DIAGONAL SECUNDARIA DE UNA MATRIZ CUADRADA

  int suma_diag_sdria(int mat[10][10],int fil_col){
  int suma_d_sec,i,n1;
    suma_d_sec=0;
     n1=fil_col+1;
     
  for(i=1;i<=fil_col;i++){
    suma_d_sec+=mat[i][n1-i];
  }
  return suma_d_sec;
  }

//CALCULANDO LAS TRANSPUESTAS

  void transpuesta( int mat[10][10],int tmat[10][10],int fil_col){
   int i,j;
    for(i=1;i<=fil_col;i++){
     for(j=1;j<=fil_col;j++){
      tmat[i][j]=mat[j][i];
     }
    }
   }
//FUNCION ESCRIBIR MATRIZ

  void escritura_mat(int mat[10][10],int fil_col){
   int i,j;
    for(i=1;i<=fil_col;i++){
      for(j=1;j<=fil_col;j++){
        cout<<"mat("<<i<<","<<j<<")=";
        cout<<mat[i][j]<<"\n";
       }
    }
   }
//FUNCION ESCRIBIR VECTOR
    void escritura_vector(int vector[10],int fil_col){
      int i;
       for(i=1;i<=fil_col;i++){
	cout<<"vect("<<i<<")=";
	cout<<vector[i]<<"\n";
      }
    }

// DESARROLLANDO LA PRODUCTORIA

  void producto(int matriz[10][10],int y[10],int f[10],int k){
  int i,j,su;
   for(i=1;i<=k;i++){
     su=0;
    for(j=1;j<=k;j++){
      su+=matriz[i][j]*y[j];
    }
    f[i]=su;
   }
  }




    
    

    
    
        

