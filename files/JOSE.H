//**********************  FUNCIONES **********************//

void marco (void){
int q,q2,q3,q4;
clrscr();
gotoxy(0,0);
printf("É");
for (q=1;q<=78;q++){
gotoxy(q,0);
printf("Í");
}
gotoxy(79,0);
printf("»");

for (q2=2;q2<=23;q2++){
gotoxy(80,q2);
printf("º");
}
gotoxy(80,24);
printf("¼");

for(q3=79;q3>=1;q3--){
gotoxy(q3,24);
printf("Í");}

gotoxy(1,24);
printf("È");

for (q4=23;q4>=2;q4--){
gotoxy(1,q4);
printf("º");}
return;
}
////////////////////////

void menu (void){
 marco ();
gotoxy(24,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA\n");
gotoxy(30,4);
printf("TRABAJO DE PROGRAMACION\n");
gotoxy(32,7);
printf("MENU PRINCIPAL");
gotoxy(18,11);
printf("1.  MANEJO DE VECTORES");
gotoxy(18,14);
printf("2.  MANEJO DE MATRICES");
gotoxy(18,17);
printf("3.  MANEJO DE CARACTERES");
gotoxy(18,20);
printf("4.  TERMINAR");
gotoxy(30,23);
printf("DIGITE OPCION [ ]");
gotoxy(45,23);

getch();
return ;
}
//////////////////////

void submenu_vect (void){
marco ();
gotoxy(24,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA\n");
gotoxy(30,4);
printf("TRABAJO DE PROGRAMACION\n");
gotoxy(32,7);
printf("* MANEJO DE VECTORES *");
gotoxy(18,11);
printf("1.  UNION DE VECTORES");
gotoxy(18,14);
printf("2.  SUMA DE VECTORES");
gotoxy(18,17);
printf("3.  MULTIPLICACION DE VECTORES");
gotoxy(18,20);
printf("4.  RETORNAR");
gotoxy(30,23);
printf("DIGITE OPCION [ ]");
gotoxy(45,23);

getch();
return ;
}
/////////////////////////////

void submenu_mat (void){
marco();
gotoxy(24,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA\n");
gotoxy(30,4);
printf("TRABAJO DE PROGRAMACION\n");
gotoxy(32,7);
printf("* MANEJO DE MATRICES *");
gotoxy(18,11);
printf("1.  SUMA DE  MATRICES");
gotoxy(18,14);
printf("2.  MULTIPLICACION DE MATRICES");
gotoxy(18,17);
printf("3.  DIAGONAL PRINCIPAL");
gotoxy(18,20);
printf("4.  RETORNAR");
gotoxy(30,23);
printf("DIGITE OPCION [ ]");
gotoxy(45,23);

getch();
return ;
}
//////////////////////////////////

void suma_vect (void) {
int vec1[10];
 int vec2[10];
 int vec3[10];
 int tam,i,tam2,j,k;
 clrscr();
 gotoxy(16,6);
 printf("DIGITE EL TAMA¥O DEL PRIMER VECTOR:  ");
 scanf("%d",&tam);

 for (i=0;i<tam;i++)
 {
 gotoxy(12,6);
  printf(" digite el valor para la posicion %d del vector ",i);
  scanf("%d",&vec1[i]);
 }

 clrscr();
  gotoxy(16,6);
 printf(" DIGA EL TAMA¥O DEL SEGUNDO VECTOR:  ");
 scanf("%d",&tam2);

 for (j=0;j<tam2;j++)
 {
 gotoxy( 12,6);
 printf(" diga el valor para la posicion %d del vector:  ",j);
  scanf("%d",&vec2[j]);
}

 for (k=0;k<tam;k++)
 {

 vec3[k]=vec1[k]+vec2[k];

   }

 for(k=0;k<tam;k++)
 {
  gotoxy(12,k+1);
  printf(" LA SUMA DEL VECTOR ES :%d   \n",vec3[k]);

  }

  getch();

  }
////////////////////////

void mult_vect (void){
int vec1[10];
 int vec2[10];
 int vec3[10];
 int tam,i,tam2,j,k;
 clrscr();
 gotoxy(16,6);
 printf("DIGITE EL TAMA¥O DEL PRIMER VECTOR:  ");
 scanf("%d",&tam);

 for (i=0;i<tam;i++)
 {
 gotoxy(12,6);
  printf(" digite el valor para la posicion %d del vector ",i);
  scanf("%d",&vec1[i]);
 }

 clrscr();
  gotoxy(16,6);
 printf(" DIGA EL TAMA¥O DEL SEGUNDO VECTOR:  ");
 scanf("%d",&tam2);

 for (j=0;j<tam2;j++)
 {
 gotoxy( 12,6);
 printf(" diga el valor para la posicion %d del vector:  ",j);
  scanf("%d",&vec2[j]);
}


 for (k=0;k<tam;k++)
 {

 vec3[k]=vec1[k]*vec2[k];


   }


 for(k=0;k<tam;k++)
 {
  gotoxy(12,k+1);
  printf(" LA MULTIPLICACION DEL VECTOR ES :%d   \n",vec3[k]);

  }

  getch();

  }
///////////////////////////
void suma_mat(void){
int max[50][50];
   int max1[50][50];
   int res[50][50];
   int fil1,col1,fil2,col2,c,a,d,b,l,x,y,est;
    clrscr();
   printf("digite el # de filas \n");
    scanf("%d",&fil1);
   printf("digite el # de columna \n");
    scanf("%d",&col1);
   printf("digite el # de filas \n");
    scanf("%d",&fil2);
   printf("digite el # de columna \n");
    scanf("%d",&col2);

    if (col1==fil2 && fil1 == col2){
    printf("\n DIGITE LA PRIMERA MATRIZ \n");
      for(l=0;l<fil1;l++){
	 for(b=0;b<col1;b++){
	 scanf("%d",&max[l][b]);
	   }
       }

      printf("\n DIGITE LA SEGUNDA MATRIZ \n");

	    for(c=0;c<fil2;c++){
	  for(d=0;d<col2;d++){
		    scanf("%d",&max1[c][d]);
	  }

       }

     }
     else { printf("Error matrices no concuerdan");getch(); exit (1);}

	  for(a=0;a<fil1;a++){
	      for(b=0;b<col2;b++){
	      est=0;
		for(c=0;c<fil2;c++){
		     est = est + (max[a][c] + max1[c][b]);
		 }
	       res[a][b]=est;
	      }
	   }
	clrscr();
	printf("la matriz resultante es");
	b=5;
	   for(x=0;x<fil1;x++){   a=8;
	      for(y=0;y<col2;y++){
	       gotoxy(a,b);
	       printf("[%d]",res[x][y]);
	       a=a+4;
	       }
	       b=b+2;
	   }
			   getch();return ;
			   }

/////////////////////////////////
void mult_mat(void){
 int max[50][50];
   int max1[50][50];
   int res[50][50];
   int fil1,col1,fil2,col2,c,a,d,b,l,x,y,est;
    clrscr();
   printf("digite el # de filas \n");
    scanf("%d",&fil1);
   printf("digite el # de columna \n");
    scanf("%d",&col1);
   printf("digite el # de filas \n");
    scanf("%d",&fil2);
   printf("digite el # de columna \n");
    scanf("%d",&col2);

    if (col1==fil2 && fil1 == col2){
    printf("\n DIGITE LA PRIMERA MATRIZ \n");
      for(l=0;l<fil1;l++){
	 for(b=0;b<col1;b++){
	 scanf("%d",&max[l][b]);
	   }
       }

      printf("\n DIGITE LA SEGUNDA MATRIZ \n");

	    for(c=0;c<fil2;c++){
	  for(d=0;d<col2;d++){
		    scanf("%d",&max1[c][d]);
	  }

       }

     }
     else { printf("Error matrices no concuerdan");getch(); exit (1);}

	  for(a=0;a<fil1;a++){
	      for(b=0;b<col2;b++){
	      est=0;
		for(c=0;c<fil2;c++){
		     est = est + (max[a][c] * max1[c][b]);
		 }
	       res[a][b]=est;
	      }
	   }

       clrscr();

	printf("la matriz resultante es");
	b=5;
	   for(x=0;x<fil1;x++){   a=8;
	      for(y=0;y<col2;y++){
	       gotoxy(a,b);
	       printf("[%d]",res[x][y]);
	       a=a+4;
	       }
	       b=b+2;
	   }
			   getch();return ;
			   }
