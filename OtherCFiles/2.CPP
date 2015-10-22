#base_dato estudent[60];
int n,i,lon,j;
float code,note[3],sum;
char name[30];
clrscr();
printf(" digite cantidad de estudiantes\n");
do{
     scanf("%d",&n);
} while(n<0 && n>60);

// lectura  y asignacion de datos a cada registro

   for(i=0; i<=n;i++){
       clrscr();
       printf("Codigo : ");
	     scanf("%f",&code);
       printf("Nombre : ");
	     cin.getline(name,30);

	for(i=1; i<=3; i++){

       printf("nota  :  %d  ",i);
	     scanf("%f",&note[i]);
	  }
