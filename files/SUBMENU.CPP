 #include <stdio.h>
 #include<conio.h>
 void datos(int a[5][5],int b[5][5],int y,int z );
 void prod ( int a[5][5],int b[5][5],int c[5][5],int y,int z,int l );
 void mult();
 void vect_comun ( int p[5][5],int q[5][5],int v[5],int y,int z );
 void ord_fila_A(int a[5][5],int y,int z);
 int Menu(void);
 main()
 {
  int opc,a[5][5],b[5][5],c[5][5],p[5][5],q[5][5],v[5],y,z,l;
  clrscr();

      while((opc=Menu()) != 6)
      {
	switch(opc){
		   case 1:
			  datos(a,b,y,z);
			  break;
		   case 2:
			  prod(a,b,c,y,z,l);
			  break;
		   case 3:
			 vect_comun(p,q,v,y,z);
			  break;
		/*   case 4:
			  mult();
			  break; */
		   case 5:
			  ord_fila_A(a,y,z);
			  break;
		   case 6:
			  break;
		  }
	    }
	  return 0;
 }
void datos( int a[5][5], int b[5][5],int y,int z)
{
    int opc1,i,j,ini;

    clrscr();


       gotoxy(5,7);
       printf("   Submenu De Datos   \n ");
       printf("1.Entrada De Dimensiones \n");
       printf("2.Entrada De Los Elementos De Las Matrices \n");
       printf("3.Retornar \n");

       printf("Digite Opcion :   ");
     scanf("%d", &opc1);

     while (opc1!=3){
      switch(opc1) {

		    case 1:
			 printf(" \n Digite El Numero De Filas :  ");
			 scanf("%d",&y);
			 printf(" \n Digite El Numero De Columnas:  ");
			 scanf("%d",&z);
			 datos( a,b,y,z);
		      //	 datos();
		    
			 break;
		    case 2:

			 printf(" \n Digite Elementos De La Matriz A:  ");
			 for(i=0;i<y;i++) {
			   for(j=0;j<z;j++) {
				 printf("a[%d][%d] ",i,j);
				 scanf("%d",&a[i][j]);
			    }
			 }
			 printf(" \n Digite Elementos De La Matriz B:  ");
			 for(i=0;i<z;i++)
			 {
			   for(j=0;j<y;j++) {
			   printf("b[%d][%d] ",i,j);
			   scanf("%d",&b[i][j]);
			   }
			}
		      datos( a,b,y,z);
		      break;
		    case 3:
		       clrscr();
		       Menu();
			  }
 }		
 }	 
 void prod (int a[5][5],int b[5][5],int c[5][5],int y,int z,int l )
{
  int i,j,k,sum;
     for(i=0; i<y; i++)
     {
       for(j=0; j<l; j++)
  sum=0;
       {
	 for(k=0; k<z; k++)
	 {
	 sum+= a[i][k] * b[k][i];
	 }
	 c[i][j]=sum;
       }
     }
     printf("\n\n  LA MATRIZ RESULTANE  :  ");
     for(i=0; i<y; i++);
     {
     k=2;
	for(j=0; j<l; j++)
	{
	printf("%d",c[i][j] );
	k+=5;
	}
     }
 getch();

}

//SUB-MENU VECTOR COMUN
 void vect_comun (int p[5][5], int q[5][5], int v[5], int y, int z )
 {
  int i,j,k,s,com=0,w1;
  int f,g;
  clrscr();

 //Compara elementos comunes de las matrices
  for(i=0;i<y;i++)
  {
    for(j=0;j<z;j++)
    {
 //Toma elementos matriz (A) y compara con (B)
      for(f=0;f<y;f++)
      {
	 for(g=0;g<z;g++)
	 {
	 w1=p[i][j];
	   if(w1==q[f][g] )
	   {
	   v[com]=w1; //Incrementa w1,eliminando el anterior
	   com++;
	   }
	 }
      }
    }
  }
  printf(" \n LOS ELEMENTOS COMUNES DE LAS MATRICES SON  : \n");
  for(i=0;i<com;i++)
  {
  printf("%d",v[i] );
  }
  getch();
 }



  void ord_fila_A (int a[5][5],int y,int z)
  {
    int i,j,k,temp;
    for(i=0;i<y;i++) {
      for(j=0;j<z;j++) {
	for(k=i+1;k<=y;k++) {
	  if (a[i][j] < a[k][j] ) {
	     temp=a[i][j];
	     a[i][j]=a[k][j];
	     a[k][j]=temp;
	     }
	  }
	}
      }
    for(i=0;i<y;i++) {
      for(j=0;j<z;j++) {
	 printf(" \t %d",a[i][j] );
	 }
	 printf(" \n ");
      }
  }

 int Menu(void)
 {
 int opc;
	    gotoxy(30,5);
      printf("Menu Principal \n");
	    gotoxy(28,8);
      printf("1.Entrada de Datos \n");
	    gotoxy(28,9);
      printf("2.Producto A*B \n");
	    gotoxy(28,10);
      printf("3.Vector de Elementos Comunes \n");
	    gotoxy(28,11);
      printf("4.Vector de Multiplos \n");
	    gotoxy(28,12);
      printf("5.Ordenamiento \n");
	    gotoxy(28,13);
      printf("6.Salir \n");
	    gotoxy(28,14);
      printf("Digite Opcion Deseada :  ");
      gotoxy(35,28);
      scanf("%d",&opc);
      return opc;
   }







