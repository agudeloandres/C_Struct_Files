 #include<graphics.h>
 #include<stdio.h>
 #include<conio.h>
 #include <math.h>
 #include<stdlib.h>
 #include<string.h>

 #define MAXPUNTOS  4 /*M ximo n£mero de v‚rtices de cada grafo*/



/*Inicializaci¢n del modo gr fico*/

 void Inigr(void){
	int dispgraf=DETECT,modograf,coderror;
	initgraph(&dispgraf,&modograf,"");
	coderror=graphresult();
	  if(coderror!=grOk){
		 printf("\nError en la funci¢n gr fica : %s\n",grapherrormsg(coderror));
	 printf("pulse una tecla para terminar");
	 getch();
	 exit(1);
	  }
 }



 void LeerMatriz(int Matriz[2*MAXPUNTOS][2*MAXPUNTOS], int* NPuntos){
	int i, j;
	while( 1 ){
	  printf("Ingrese el n£mero(1...%d) de puntos del grafo:  ", MAXPUNTOS);
	  scanf( "%d", NPuntos );
	  if( *NPuntos<1 || *NPuntos>MAXPUNTOS )
		 continue;
	  break;
	}
	if( *NPuntos>1 )
	  printf("Ingrese el contenido de la matriz:\n");
	for( i= 0; i<*NPuntos; ++i ){
	  for( j= 0; j<i; ++j ){
		 printf("    Fila %d, Columna %d  ?  ", i+1, j+1 );
		 scanf( "%d", &Matriz[i][j] );
		 /*Valor de la posici¢n i,j = valor de la posici¢n j,i*/
		 Matriz[i][j]= Matriz[i][j]? 1 : 0;
		 Matriz[j][i]= Matriz[i][j];
	  }
	  Matriz[i][i]= 0; /* Diagonal principal=0 */
	}
 }



 /*Centra un texto en la pantalla*/

 void Centrar( char *Cadena, int y ){
	gotoxy( 40-strlen( Cadena )/2, y );
	cprintf( "%s", Cadena );
 }




 /* Impresi¢n de la matriz de adyacencia */

 void VerMatriz(int Matriz[2*MAXPUNTOS][2*MAXPUNTOS], int NPuntos){
	int i, j;
	for( i= 0; i<NPuntos; ++i )
	  for( j= 0; j< NPuntos; ++j ){
		 gotoxy( 10+j*5, i+7 );
		 printf("%d", Matriz[i][j] );
	  }
 }





 /*Suma de las matrices de adyacencia de los grafos*/
 void Sumar(int Mat1[][2*MAXPUNTOS],int Mat2[][2*MAXPUNTOS], int n1, int n2){
	int i, j;

	for(i= 0; i<n1; ++i)
	  for(j= 0; j<n2; ++j)
		 Mat1[i][n1+j]= Mat1[n1+j][i]= 1;
	for(i= 0; i<n2; ++i)
	  for(j= 0; j<n2; ++j)
		 Mat1[n1+i][n1+j]= Mat2[i][j];
 }



 /* Dibujo de los grafos */

 void VerGrafo(int Matriz[][2*MAXPUNTOS], int NPuntos, int Donde){

	int x[MAXPUNTOS], y[MAXPUNTOS]; /*Coordenadas de cada v‚rtice*/
	int LetraX[MAXPUNTOS], LetraY[MAXPUNTOS];
	float AnguloDistancia= (2.0*3.1415)/(float)NPuntos;
	int CentroX, CentroY;  /*Coordenadas del centro del grafo*/
	float Radio= 90.0;     /*Distancia de cada v‚rtice con el centro*/
	int i, j;
	char Cadena[64];

	CentroX= Donde? getmaxx()/2+getmaxx()/4:getmaxx()/4;
	CentroY= Donde? getmaxy()/2+45:getmaxy()/2-45;
	if( NPuntos==1 ){
	  x[0]= CentroX;
	  y[0]= CentroY;
	  LetraX[0]= CentroX + 20;
	  LetraY[0]= CentroY - 20;
	}
	else
	  for( i= 0; i<NPuntos; ++i ){
		 x[i]= CentroX+(int)(Radio*cos((float)i*AnguloDistancia));
		 y[i]= CentroY-(int)(Radio*sin((float)i*AnguloDistancia));
		 LetraX[i]= CentroX+(int)((Radio+20.0)*cos((float)i*AnguloDistancia));
		 LetraY[i]= CentroY-(int)((Radio+20.0)*sin((float)i*AnguloDistancia));
	  }

	sprintf( Cadena, Donde?"...Grafo 2":"Grafo 1..." );
	if(Donde==0)
	  outtextxy( 0, 0, Cadena );
	else
	  outtextxy( getmaxx()-textwidth(Cadena)-10, getmaxy()-10, Cadena );

	for( i= 0; i<NPuntos; ++i )
	  for( j= 0; j<i; ++j )
		 if( Matriz[i][j] )
			line( x[i], y[i], x[j], y[j] );

	setfillstyle( SOLID_FILL,  YELLOW );
	for( i= 0; i<NPuntos; ++i ){
	  bar( x[i]-5, y[i]-5, x[i]+5, y[i]+5 );
	  sprintf( Cadena, "V%d", i+1 );
	  outtextxy( LetraX[i]-8, LetraY[i]-4, Cadena );
	}
 }




 /* Muestra la suma de los grafos */
 void VerGrafoSuma(int n1, int n2){

	int Colores[8]={BLUE, CYAN, LIGHTRED, MAGENTA,
			LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA
		       };

	int x1[MAXPUNTOS], y1[MAXPUNTOS];
	int x2[MAXPUNTOS], y2[MAXPUNTOS];

	int LetraX1[MAXPUNTOS], LetraY1[MAXPUNTOS];
	int LetraX2[MAXPUNTOS], LetraY2[MAXPUNTOS];

	float AnguloDistancia1= (2.0*3.1415)/(float)n1;
	float AnguloDistancia2= (2.0*3.1415)/(float)n2;

	int CentroX1, CentroY1;
	int CentroX2, CentroY2;



	float Radio= 90.0;
	int i, j;
	char Cadena[64];

	CentroX1= getmaxx()/4;
	CentroY1= getmaxy()/2-45;
	CentroX2= getmaxx()/2+getmaxx()/4;
	CentroY2= getmaxy()/2+45;

	if( n1==1 ){
	  x1[0]= CentroX1;
	  y1[0]= CentroY1;
	  LetraX1[0]= CentroX1 + 20;
	  LetraY1[0]= CentroY1 - 20;
	}
	else
	  for( i= 0; i<n1; ++i ){
		 x1[i]= CentroX1+(int)(Radio*cos((float)i*AnguloDistancia1));
		 y1[i]= CentroY1-(int)(Radio*sin((float)i*AnguloDistancia1));
		 LetraX1[i]= CentroX1+(int)((Radio+20.0)*cos((float)i*AnguloDistancia1));
		 LetraY1[i]= CentroY1-(int)((Radio+20.0)*sin((float)i*AnguloDistancia1));
	  }

	if( n2==1 ){
	  x2[0]= CentroX2;
	  y2[0]= CentroY2;
	  LetraX2[0]= CentroX2 + 20;
	  LetraY2[0]= CentroY2 - 20;
	}
	else
	  for( i= 0; i<n2; ++i ){
		 x2[i]= CentroX2+(int)(Radio*cos((float)i*AnguloDistancia2));
		 y2[i]= CentroY2-(int)(Radio*sin((float)i*AnguloDistancia2));
		 LetraX2[i]= CentroX2+(int)((Radio+20.0)*cos((float)i*AnguloDistancia2));
		 LetraY2[i]= CentroY2-(int)((Radio+20.0)*sin((float)i*AnguloDistancia2));
	  }


	for( i= 0; i<n1; ++i )
	  for( j= 0; j<n2; ++j ){
       setcolor(Colores[i]);
		 line( x1[i], y1[i], x2[j], y2[j] );
     }


	setfillstyle( SOLID_FILL,  BLACK );
	bar(0,0,getmaxx(),10);
	bar(0,getmaxy(),getmaxx(),getmaxy()-10);

	setcolor(WHITE);
	setfillstyle( SOLID_FILL,  YELLOW );
	for( i= 0; i<n1; ++i ){
	  bar( x1[i]-5, y1[i]-5, x1[i]+5, y1[i]+5 );
	  sprintf( Cadena, "V%d", i+1 );
	  outtextxy( LetraX1[i]-8, LetraY1[i]-4, Cadena );
	}
	for( i= 0; i<n2; ++i ){
	  setfillstyle( SOLID_FILL,  YELLOW );
	  bar( x2[i]-5, y2[i]-5, x2[i]+5, y2[i]+5 );
	  sprintf( Cadena, "V%d", n1+i+1 );
	  setfillstyle( SOLID_FILL,  BLACK );
	  bar(LetraX2[i]-8, LetraY2[i]-4,
	      LetraX2[i]-8+textwidth(Cadena)+1,LetraY2[i]-4+textheight(Cadena)+1 );
	  outtextxy( LetraX2[i]-8, LetraY2[i]-4, Cadena );
	}

	strcpy(Cadena,"Suma (Grafo 1 + Grafo 2)...");
	outtextxy( getmaxx()/2-textwidth(Cadena)/2, 20, Cadena);

 }





 main(){

	int Mat1[MAXPUNTOS*2][2*MAXPUNTOS];
	int Mat2[MAXPUNTOS*2][2*MAXPUNTOS];
	int n1, n2;     /* N£mero de vertices de grafo 1 y grafo 2 */


	clrscr();
	textcolor(WHITE);
	Centrar("SUMA DE GRAFOS NO DIRIGIDOS", 2);
	Centrar("Representacion en matrices de adyacencia", 3);

	textcolor(7);

	printf("\n\n\nLectura de la matriz 1:\n\n");
	LeerMatriz(Mat1, &n1);
	printf("\n\n\nMATRIZ LEIDA. PRESIONE LA BARRA ESPACEADORA PARA CONTINUAR...");
	while(getch()!=' ');

	printf("\n\nLectura de la matriz 2:\n\n");
	LeerMatriz(Mat2, &n2);
	printf("\n\n\nMATRIZ LEIDA. PRESIONE LA BARRA ESPACEADORA PARA CONTINUAR...");
	while(getch()!=' ');

	clrscr();
	printf("\nVISUALIZACION DE LA MATRIZ 1:");
	VerMatriz(Mat1, n1);   /*Muestra ceros y unos de matriz 1*/
	printf("\n\n\nPRESIONE LA BARRA ESPACEADORA PARA CONTINUAR...");
	while(getch()!=' ');

	clrscr();
	printf("\nVISUALIZACION DE LA MATRIZ 2:");
	VerMatriz(Mat2, n2);   /*Muestra ceros y unos matriz 2*/
	printf("\n\n\nPRESIONE LA BARRA ESPACEADORA PARA CONTINUAR...");
	while(getch()!=' ');

	Sumar(Mat1, Mat2, n1, n2); /* La suma qued¢ en Mat 1 */

	clrscr();
	printf("\nVISUALIZACION DE LA MATRIZ SUMA:");
	VerMatriz(Mat1, n1+n2);  /* Muestra ceros y unos de la matriz suma */
	printf("\n\n\nPRESIONE LA BARRA ESPACEADORA PARA CONTINUAR...");
	while(getch()!=' ');

	Inigr(); /* Inicializa modo gr fico */
	VerGrafo(Mat1, n1, 0);     /*Matriz de arriba*/
	getch();
	VerGrafo(Mat2, n2, 1);     /*Matriz de abajo*/
	getch();

	VerGrafoSuma(n1, n2);      /*Uni¢n de v‚rtices*/
	getch();

	closegraph();
	return 0;
 }


