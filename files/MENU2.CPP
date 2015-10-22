# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <math.h>

  func_suma()
  {
  int s,t,o,u,i;
 clrscr();
  textcolor(24);
  textbackground(11);
  gotoxy(5,1);
  printf("digite el valor de la altura    =[   ]");
  gotoxy(40,1);
  scanf("%d",&t);
  gotoxy(5,2);
  printf("digite el valor de la base      =[   ]");
  gotoxy(40,2);
  scanf("%d",&s);


 clrscr();
   textcolor(14);
   textbackground(14);
   for(o=0;o<t;o++)
   {
   gotoxy(s+s,o+1);
   printf("");
   }
   for(u=1;u<s;u++)
   {
   gotoxy(u*2,t);
   printf("");
   }
   gotoxy(4,t-1);
   printf("");
   getch();


  clrscr();
    textcolor(18);
    textbackground(24);
    for(o=0;o<s;o++)
    printf("$ ");
    for(u=1;u<t;u++)
    printf("\n$");
    gotoxy(s*2-3,2);
    printf("$");
    getch();


   clrscr();
      textcolor(14);
      textbackground(11);
      for(o=1;o<=t;o++)
      printf("\n");
      for(u=1;u<s;u++)
      printf(" ");
      gotoxy(s*2-3,t);
      printf(" ");
      getch();

    clrscr();
	textcolor(24);
	textbackground(14);
	for(o=1;o<=t;o++)
	{
	gotoxy(s+s*2,o);
	printf("");
	}
	for(u=1;u<s;u++)
	{
	gotoxy(u*3,1);
	printf("");
	}
	gotoxy(6,2);
	printf("");
	getch();

	}
     matematicas();

  tablas_multiplicar()
  {
  }
  func_division()
  {
  }



  funciones_matematicas()
  {
    int opc3,menu();
    textbackground(17);
    clrscr();
    do{ // gotoxy(
	 gotoxy(15,4);
		      printf(" FUNCIONES MATEMATICAS ");
	 gotoxy(15,8);
		      printf(" 1.FUNC SUMA");
	 gotoxy(15,10);
		      printf("2. TABLAS DE MULTIPLICAR");
	 gotoxy(15,12);
		      printf("3. FUNC DIVISION");
	 gotoxy(15,14);
		      printf("4. MENU PRINCIPAL");
	 gotoxy(20,20);
		      printf("DIGITE SU OPCION:  ");
	 scanf("%d",&opc3);
	 switch (opc3)
	 {
	   case 1: func_suma();
		   break;
	   case 2: tablas_multiplicar();
		   break;
	   case 3: func_division();
		   break;
	   case 4: menu();
		   break;
	}
      }
      while ((opc3!=1) && (opc3!=2) && (opc3!=3) && (opc3!=4));
      menu();
  }




  multiplicacion_matrices()
  {
int mat1[50][50];
int mat2[50][50];
int mat3[50][50];
int m,n,r,s,i,j,h,k,aux,l,o;
clrscr();
printf("digite # de filas de la matriz     1 :  ");
scanf("%d",&n);
printf("digite # de columnas de la matriz  1 :  ");
scanf("%d",&m);
printf("digite # de filas de la matriz     2 :  ");
scanf("%d",&r);
printf("digite # de columnas de la matriz  2  : ");
scanf("%d",&s);
if (m==r){
    clrscr();
     gotoxy(1,1);
     printf("digite un valor de la matriz 1  ");
      for (i=1;i<=n;i++){
	for (j=1;j<=m;j++){
	    gotoxy(j*3,i*2);
	    scanf("%d",&mat1[i][j]);
	}
     }

   clrscr();
    gotoxy(1,1);
    printf("digite un valor de la matriz 2  ");
    for (h=1;h<=r;h++){
	for (k=1;k<=s;k++){
	     gotoxy(k*3,h*2);
	     scanf("%d",&mat2[h][k]);

	 }
     }
       for (i=1;i<=n;i++){
	 for (k=1;k<=s;k++){
	     aux = 0;
	     for (j=1;j<=m;j++){
		 aux = aux + (mat1[i][j] * mat2[j][k]);
	      }
	      mat3[i][k] = aux;
	 }
      }
     clrscr();
     gotoxy(1,1);
     printf("el producto  es  ");
     for (i=1;i<=n;i++){
       for (k=1;k<=s;k++){
	   printf("\n");
	   gotoxy(k*3,i*5);
	   printf("%d",mat3[i][k]);
	  }
      }
   }
   getch();


  }
  matrices();
  triangular_superior()
  {

    int max[50][50];
    int fil,col,i,j,l,k;
	clrscr();
    printf("digite el # de filas \n");
    scanf("%d",&fil);
    printf("digite el # de columna \n");
    scanf("%d",&col);

      if (fil==col)
       {
	 l=1;

	 for(i=1;i<=fil;i++)
	   {

	     for(j=1;j<=col;j++)
	       {
		  max[i][j]=1;
	       }
	   }
	 for(i=1;i<=fil;i++)
	   {
	     for(j=1;j<=col;j++)
	       {
		 if(i>=j)

		    max[i][l]=1;
		  else  {
		    max[i][j]=0;
		     }
	       }
	   }
	 if (j<=i)
	    max[i][j]=0;
	  else
	    max[i][j]=1;
	   clrscr();
	 for (i=1;i<=fil;i++)
	   {
	     for (k=1;k<=col;k++)
	       {
		 printf("\n");
		 gotoxy(k*3,i*2);
		 printf("%d",max[i][k]);

	       }
	   }
		getch();
		matrices();
       }
  }
  matriz_z()
  {
  int a[50][50];
int n,x,i,j;
textcolor(7);
textbackground(5);
clrscr();
printf("DIGITE EL TAMA¥O DE LA MATRIZ CUADRADA    ");
scanf("%d",&n);
for (i=1;i<=n;i++){
  for (j=1;j<=n;j++){
  if (j==(n-i+1)||(i==1)||(n==i)){
  a[i][j]=1;
 }else
   a[i][j]=0;
  }
 }
clrscr();
x=8;
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
printf("\n");
gotoxy(j*x,i+1);
printf("%d",a[i][j]);
}
}
getch();

 matrices();
  }


  matrices()
  {
   int opc2,menu();
   textbackground(13);
    clrscr();
    do{
	 gotoxy(15,4);
		      printf(" MANEJO DE MATRICES ");
	 gotoxy(15,8);
		      printf("1. MULTIPLICACION DE MATRICES ");
	 gotoxy(15,10);
		      printf("2. TRIANGULAR SUPERIOR ");
	 gotoxy(15,12);
		      printf("3. MATRIZ EN Z ");
	 gotoxy(15,14);
		      printf("4. MENU PRINCIPAL ");
	 gotoxy(15,21);
		      printf("digite su opcion: \t ");

	 scanf("%d", & opc2);
	 switch (opc2)
	 {
	    case 1: multiplicacion_matrices();
		    break;

	    case 2: triangular_superior();
		    break;
	    case 3: matriz_z();
		    break;
	    case 4: menu();
		    break;
	 }
      }
      while ((opc2!=1) && (opc2!=2) && (opc2!=3) && (opc2!=4));
  }


  union_vectores()
  {


      int vec1[100];
      int vec2[100];
      int B[100];
      int tam;
      int i,j,r,s,c,vectores();
      clrscr();
      printf("digite tama¤o del primer vector \t");
      scanf("%d",&tam);
      for(i=1;i<=tam;i++)
      {
	 printf("digite valor para la pocision %d del primer vector    ",i);
	 scanf("%d"  ,&vec1[i]);
      }
       printf("Digite el tama¤o del segundo vector \t");
       scanf("%d",&r);
       for(j=1;j<=r;j++)
       {
	  printf("digite valor para la pocision %d del segundo vector   ",j);
	  scanf("%d"  ,&vec2[j]);
       }
	for(i=1;i<=tam;i++)
	{
	   B[i]=vec1[i];
	}
	 c=1;s=tam+r;
	 for(i=tam+1;i<=s;i++)
       {
	  B[i]=vec2[c];
	  c++;
       }
	printf("El vector de la union es \n ");
	for(i=1;i<=s;i++)
	{
	   printf("\n");
	   printf("El valor en la pocision %d es :  %d ",i,B[i]);
	   getch();
  }
   vectores();
  }
  metodo_burbuja()
  {
    int vec[100];
    int tam;
    int i,j,men,p,vectores();
    clrscr();
    printf("digite tama¤o del vector ");
    scanf("%d",&tam);
    for(i=1;i<=tam;i++)
    {
       printf("digite valor para la pocision %d del vector  ",i);
       scanf("%d",&vec[i]);
    }
     p=tam-1;
     for(i=1;i<=p;i++)
     {
	men=vec[i];
	for(j=i+1;j<=tam;j++)
	{
	   if( vec[j]<men )
	   {
	      vec[i]=vec[j];
	      vec[j]=men;
	      men=vec[i];
	   }
	}
     }
      printf("El vector arreglado queda asi :");
      for(i=1;i<=tam;i++)
      {
	 printf("\n");
	 printf("El valor de la posicion %d del vector es  :  "  ,  i);
	 printf("%d"    ,    vec[i]);
      }
      getch();
      vectores();
  }


  suma()
  {
     int vecA [100];
     int vecB [100];
     int vecC [100];
     int i,j,tama,m,k,tama2,vectores();
     clrscr();
     printf("digite el tama¤o del vector");
     scanf("%d",&tama);
     for(i=1;i<=tama;i++)
     {
	printf("digite el valor para la posicion  %d del vector  ",i);
	scanf ("%d",&vecA[i]);
     }
      printf ("digite el tama¤o del vector");
      scanf ("%d",&tama2);
      for (j=1; j<=tama2; j++)
      {
	 printf("digite el valor para la posicion %d del segundo vector  ",j);
	 scanf ("%d",&vecB[j]);
      }
       for(m=1; m<=tama; m++)
       {
	  vecC[m]=vecA[m]+vecB[m];
	  printf("\n El valor para la posicion %d del vector es :  %d",m,vecC[m]);
	  getch();
       }

       vectores();
  }



  vectores()
  {
    int opc1,menu();
    textbackground(12);
    clrscr();
    do{
	gotoxy(15,3);
		    printf(" MANEJO DE VECTORES ");
	gotoxy(15,7);
		    printf("1. UNION DE VECTORES ");
	gotoxy(15,9);
		    printf("2. VECTOR METODO BURBUJA ");
	gotoxy(15,11);
		    printf("3. SUMA DE VECTORES ");
	gotoxy(15,13);
		    printf("4. MENU PRINCIPAL ");
	gotoxy(15,19);
		    printf("digite su opcion: \t");
	scanf("%d",& opc1);
	switch (opc1)
	{
	  case 1: union_vectores();
		  break;
	  case 2: metodo_burbuja();
		  break;
	  case 3: suma();
		  break;
	  case 4: menu();
		  break;
	}
      }
	while ((opc1!=1) && (opc1!=2) && (opc1!=3) && (opc1!=4));
	return(0);
  }


  salir()
  {
  }

   menu()
   {
     int opc,menu();
     textbackground(6);
     clrscr();
     do{
	 gotoxy(15,2);
		     printf(" MENU PRINCIPAL ");
	 gotoxy(15,8);
		     printf("1. VECTORES ");
	 gotoxy(15,10);
		     printf("2. MATRICES ");
	 gotoxy(15,12);
		     printf("3. FUNCIONES MATEMATICAS ");
	 gotoxy(15,14);
		     printf("4. SALIR ");
	 gotoxy(15,18);
		     printf("digite su opcion: \t");
	 scanf("%d",&opc);
	 switch (opc)
	 {
	   case 1: vectores();
		   break;
	   case 2: matrices();
		   break;
	   case 3: funciones_matematicas();
		   break;
	   case 4: salir();
		   break;
	 }
       }
       while ((opc!=1) && (opc!=2) && (opc!=3) && (opc!=4));
   }
 main()
  {
   clrscr();
   menu();
  }

