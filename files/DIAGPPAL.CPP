 #include <stdio.h>
 #include <dos.h>
 #include <conio.h>
 void main()
 {
 textcolor(WHITE);
 textbackground(BLUE);
 clrscr();
 int *base,*dir;
 int cla[10][10],linf,lsupf,x1,linfc,lsupc, colum,k,w,p[10],suma,y,i,j;



 printf("** DAR EL NUMERO DE FILAS Y COLUMNAS DE LA MATRIZ**:  ");
 do{
 scanf("%d",&k);
 }while (k<=0);
 printf("/* DAR EL LIMITE INFERIOR DE LAS FILAS Y COLUMNAS DE LA MATRIZ/*:  ");
 do{
 scanf("%d",&linf);
 }while (linf < 0);
 linfc =linf;
 x1= 10-k+1;

 //***CALCULO DE LOS LIMITES***

 lsupf=linf+k-1;
 y=lsupf+x1-linfc+1;

 //***CAPTURA DE LA MATRIZ ***

 for (i=linf;i<=lsupf;i++){
   for (j=linf;j<=lsupf;j++){
      printf("cla[%d][%d]=",i,j);
      scanf("%d",&cla[i][j]);
      dir=&cla[i][j];

   }
 }
 //***USO DE UNA FUNCION DE ACCESO A UNA FUNCION DE DIRECCIONAMIENTO ***//
	      //***EN UNA MATRIZ***//

 suma = 0;
 base = &cla[linf][linf];
 for(i=linf;i<=lsupf;i++){

       dir=base+(i-linf)*y;
       p[i]=*dir;
       suma+=*dir;
 }
 printf("**\n LA SUMA DE LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL ES:%d\n",suma);

 //printf("** DIRECCION =%04x:%04x\n",FP_SEG(dir),FP_OFF(dir));

 base=&p[linf];
 printf("**\n LOS ELEMENTOS  DE LA DIAGONAL PRINCIPAL SON :\n");
    for (i=linf;i<=lsupf;i++){
	 dir = base + i-linf;
	 printf("p[%d][%d]=%d   ",i,i,*dir );
	 //printf("direccion=%04x:%04x\n", FP_SEG(dir),FP_OFF(dir));

    }
 getch();
 }



 
