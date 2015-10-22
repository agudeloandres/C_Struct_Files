 #include<graphics.h>
 #include<stdio.h>
 #include<conio.h>       //SUMA DE GRAFOS NO DIRIGIDOS
 #include <math.h>      // Representaci¢n en listas de adyacencia
 #include<stdlib.h>
 #include<string.h>

 #define MAXPUNTOS  4 /*M ximo n£mero de v‚rtices de cada grafo*/

 typedef struct Caja{
	int Vert;
	struct Caja *Sig;
 }Caja;
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
 /* Lectura de la lista de adyacencia*/
 void LeerLista(Caja* Vec[], int* NPuntos){
	int i;	while( 1 ){
	  printf("Ingrese el dato(1...%d) de puntos del grafo:  ", MAXPUNTOS);
	  scanf( "%d", NPuntos ); if( *NPuntos<1 || *NPuntos>MAXPUNTOS )
		 continue;
	  break;
	}
	for(i= 0; i<*NPuntos; ++i)
	  Vec[i]= 0;
	if( *NPuntos>1 ){ for( i= 0; i<*NPuntos; ++i ){ int Ady;
					  printf("Ingrese los nodos adyacentes al %d (0 para terminar):\n", i+1);
		 scanf("%d", &Ady);
		 while(Ady){
			if(Ady>*NPuntos)
			  printf("El valor ingresado exede al n£mero de vertices\n");
			else{
			  Caja *Nuevo= (Caja*) malloc(sizeof(Caja));
			  Nuevo->Vert= Ady;
			  Nuevo->Sig= Vec[i];
			  Vec[i]= Nuevo;
			}
			scanf("%d", &Ady);
		 }
	  }
	}
 }
 /*Centra un texto en la pantalla*/
 void Centrar( char *Cadena, int y ){
	gotoxy( 40-strlen( Cadena )/2, y );
	cprintf( "%s", Cadena );
 }
 /* Impresi¢n de la lista de adyacencia */
 void VerLista(Caja* Vec[], int NPuntos){
	int i;	Caja *Actual;	for( i= 0; i<NPuntos; ++i ){
	  printf("\n%d-> ", i+1);  Actual= Vec[i]; while(Actual){
		 printf("  %d", Actual->Vert);
		 Actual= Actual->Sig;
	  }
	}
 }

 /*Suma de las listas de adyacencia de los grafos*/
 Caja** Sumar( Caja* L1[], Caja* L2[], int n1, int n2){
	int i, j;Caja* *Retorno= (Caja**)malloc(2*MAXPUNTOS*sizeof(Caja*));
	for(i= 0; i<n1+n2; ++i) Retorno[i]= 0;for(i= 0; i<n1; ++i){
	  Caja *Actual= L1[i];  while(Actual){ Caja *Nuevo= (Caja*) malloc(sizeof(Caja));
		 Nuevo->Vert= Actual->Vert; Nuevo->Sig= Retorno[i];		 Retorno[i]= Nuevo;
		 Actual= Actual->Sig;
	  }
	  /*Añada todos los vertices del grafo 2*/
	  for(j= 0; j<n2; ++j){
		 Caja *Nuevo= (Caja*)malloc(sizeof(Caja));
		 Nuevo->Vert= n1+j+1;
		 Nuevo->Sig= Retorno[i];
		 Retorno[i]= Nuevo;
	  }

	}

	for(i= 0; i<n2; ++i){  Caja *Actual= L2[i];  while(Actual){
		 Caja *Nuevo= (Caja*) malloc(sizeof(Caja));
		 Nuevo->Vert= n1+Actual->Vert; Nuevo->Sig= Retorno[i+n1];
		 Retorno[i+n1]= Nuevo; Actual= Actual->Sig;
	  }
	  /*Añada todos los vertices del grafo 1*/
	  for(j= 0; j<n1; ++j){
		 Caja *Nuevo= (Caja*)malloc(sizeof(Caja));
		 Nuevo->Vert= j+1; Nuevo->Sig= Retorno[n1+i]; Retorno[n1+i]= Nuevo;
	  }

	}

	return Retorno;
 }



 /* Dibujo de los grafos */

 void VerGrafo(Caja* Vec[], int NPuntos, int Donde){

	int x[MAXPUNTOS], y[MAXPUNTOS]; /*Coordenadas de cada v‚rtice*/
	int LetraX[MAXPUNTOS], LetraY[MAXPUNTOS];
	float AnguloDistancia= (2.0*3.1415)/(float)NPuntos;
	int CentroX, CentroY;  /*Coordenadas del centro del grafo*/
	float Radio= 90.0;     /*Distancia de cada v‚rtice con el centro*/
	int i;
	char Cadena[64];

	CentroX= Donde? getmaxx()/2+getmaxx()/4:getmaxx()/4;
	CentroY= Donde? getmaxy()/2+45:getmaxy()/2-45;
	if( NPuntos==1 ){  x[0]= CentroX;  y[0]= CentroY;
	  LetraX[0]= CentroX + 20;  LetraY[0]= CentroY - 20;
	}
	else
	  for( i= 0; i<NPuntos; ++i ){
		 x[i]= CentroX+(int)(Radio*cos((float)i*AnguloDistancia));
		 y[i]= CentroY-(int)(Radio*sin((float)i*AnguloDistancia));
		 LetraX[i]= CentroX+(int)((Radio+20.0)*cos((float)i*AnguloDistancia));
		 LetraY[i]= CentroY-(int)((Radio+20.0)*sin((float)i*AnguloDistancia));
	  }

	sprintf( Cadena, Donde?"...Grafo 2":"Grafo 1..." );
	if(Donde==0) outtextxy( 0, 0, Cadena );	else
	  outtextxy( getmaxx()-textwidth(Cadena)-10, getmaxy()-10, Cadena );
	for( i= 0; i<NPuntos; ++i ){  Caja *Actual= Vec[i];  while(Actual){
		 int Ady= (Actual->Vert)-1; line( x[i], y[i], x[Ady], y[Ady] );
		 Actual= Actual->Sig;
	  }
	}

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

	Caja* Vec1[MAXPUNTOS*2];Caja* Vec2[MAXPUNTOS*2];Caja **Suma;
	int n1, n2;     /* N£mero de vertices de grafo 1 y grafo 2 */


	clrscr();
	textcolor(WHITE);
	//Centrar("SUMA DE GRAFOS NO DIRIGIDOS", 2);
	  //	  Centrar("Representaci¢n en listas de adyacencia", 3);

	textcolor(500);
	printf("\n\n\nLectura de la lista 1:\n\n");
	LeerLista(Vec1, &n1);
	//printf("\n\n\nLISTA LEIDA. PRESIONE LA BARRA ESPACEADORA PARA CONTINUAR...");
	//while(getch()!=' ');

	printf("\n\n\nLectura de la lista 2:\n\n");
	LeerLista(Vec2, &n2);
	//printf("\n\n\nLISTA LEIDA. PRESIONE LA BARRA ESPACEADORA PARA CONTINUAR...");
	//while(getch()!=' ');

	clrscr();
	printf("\nVISUALIZACION DE LA LISTA DE ADYACENCIA 1:");
	VerLista(Vec1, n1);
	//printf("\n\n\nPRESIONE LA BARRA ESPACEADORA PARA CONTINUAR...");
	//while(getch()!=' ');
	clrscr();
	printf("\nVISUALIZACION DE LA LISTA DE ADYACENCIA 2:");
	VerLista(Vec2, n2);
	//printf("\n\n\nPRESIONE LA BARRA ESPACEADORA PARA CONTINUAR...");
	//while(getch()!=' ');
	Suma= Sumar(Vec1, Vec2, n1, n2);

	clrscr();
	printf("\nSUMA DE LA LISTA DE ADYACENCIA:");
	VerLista(Suma, n1+n2);

	Inigr();VerGrafo(Vec1, n1, 0);	getch();VerGrafo(Vec2, n2, 1);
	getch();VerGrafoSuma(n1, n2);getch();closegraph();return 0;
 }


