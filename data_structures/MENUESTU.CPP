
//PROGRAMA PARA EL MANEJO DE REGISTRO DE N ESTUDIANTES

#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#define N 60
//DEFINICION DEL REGISTRO DE ESTUDIANTES

void marco(void);
typedef struct Estudiante{

	       int   Codigo;
	       char  Alum[40];
	       float N1,N2,N3;
	       float Prom,PromCurso;
	     };

void main()
{
 Estudiante Est[60],*AptEst;
 float P1,P2,P3,Def,PromTotal,temp;
 float MejAlum[60];
 int Opc,n,i,j,lon,Cod,sw,pass;
 char Nom[40];

 AptEst=&Est[0];
 clrscr();
 sw=0;

 do{
   marco();
   gotoxy(25,2);
   printf("M E N U   P R I N C I P A L");
   gotoxy(17,4);
   printf("CREAR REGISTROS..........................[1]\n");
   gotoxy(17,5);
   printf("LISTADO DE LOS ESTUDIANTES...............[2]\n");
   gotoxy(17,6);
//   printf("MEJOR ALUMNO DEL CURSO...................[3]\n");
   gotoxy(17,7);
   printf("PROMEDIO DEL CURSO.......................[4]\n");
   gotoxy(17,8);
   printf("SALIDA DEL PROGRAMA......................[5]\n\n");
   gotoxy(17,14);
   printf("DIGITE OPCION DESEADA: ");
   scanf("%d",&Opc);
   clrscr();
   switch(Opc){
       case 1:
	   if(sw==0){
	     sw=1;
	     gotoxy(2,3);
	     do{
	       printf("DIGITE CANTIDAD DE ESTUDIANTES: ");
	       scanf("%d",&n);
	     }while(n<=0 || n>60);

	     //LECTURA Y ASIGNACION A CADA REGISTRO

	   for(i=0;i<n;i++){
	       clrscr();
	       gotoxy(27,2);
	       printf("DATOS DE LOS ESTUDIANTES\n\n");
	       printf("DIGITE NOMBRE DEL ESTUDIANTE: ");
	       cin.getline(Nom,40);
	       printf("DIGITE CODIGO: ");
	       scanf("%d",&Cod);
	       do{
		 printf("DIGITE PRIMERA NOTA: ");
		 scanf("%f",&P1);
	       }while(P1<0 || P1>5);
	       do{
		 printf("DIGITE SEGUNDA NOTA: ");
		 scanf("%f",&P2);
	       }while(P2<0 || P2>5);
	       do{
		 printf("DIGITE TERCERA NOTA: ");
		 scanf("%f",&P3);
	       }while(P3<0 || P3>5);
	       Def=((P1*0.35)+(P2*0.35)+(P3*0.30));
	       PromTotal+=Def/n;
	       //ASIGNACION USANDO APUNTADOR
	       lon=strlen(Nom);

	       //ASIGNACION DE UNA VARIABLE STRING
	      for(j=0;j<=lon;j++){
		 AptEst->Alum[j]=Nom[j];
	      }
	       AptEst->Codigo=Cod;
	       AptEst->N1=P1;
	       AptEst->N2=P2;
	       AptEst->N3=P3;
	       AptEst->Prom=Def;
	       AptEst->PromCurso=PromTotal;
	       AptEst++;
	   }
	     printf("\n\n");
	     printf("PRESIONE UNA TECLA PARA CONTINUAR");
	     getch();
	     clrscr();
	   }
	   else{
	     gotoxy(19,10);
	     printf("REGISTROS YA DEFINIDOS... PRESIONE UNA TECLA");
	     getch();
	     clrscr();
	   }
	   break;

       case 2:
	   if(sw==1){
	     gotoxy(24,2);
	     printf("LISTA DE LOS ESTUDIANTES\n\n");
	     printf(" CODIGOS     NOMBRES Y APELLIDOS    Not1  Not2  Not3  Nota.Def\n\n");
	     AptEst=&Est[0];
	     j=6;
	     for(i=0;i<n;i++){
	       gotoxy(1,j);
	       printf("  %d       %-8s     ",AptEst->Codigo,AptEst->Alum);
	       gotoxy(37,j);
	       printf("%1.1f   %1.1f   %1.1f     %1.2f\n",AptEst->N1,AptEst->N2,AptEst->N3,AptEst->Prom);
	       AptEst++;
	       j++;
	     }
	     printf("\n\n");
	     printf("PRESIONE UNA TECLA PARA CONTINUAR");
	     getch();
	     clrscr();
	   }
	   else{
	     marco();
	     gotoxy(19,10);
	     printf("REGISTROS NO DEFINIDOS... PRESIONE UNA TECLA ");
	     getch();
	     clrscr();
	   }
	   break;

  /*     case 3:
	   if(sw==1){
	     gotoxy(26,2);
	     printf("M E J O R  A L U M N O\n\n");
	     for(i=0;i<n;i++){
	       MejAlum[i]=Def;
	       for(pass=0;pass<n;pass++)
		 for(j=0;j<n-1;j++)
		   if(MejAlum[j] > MejAlum[j+1]){
		     temp=MejAlum[j];
		     MejAlum[j]=MejAlum[j+1];
		     MejAlum[j+1]=temp;
		   }
	       }
	     printf("PROMEDIO DEL MEJOR ALUMNO ES: %1.2f",MejAlum[j+1]);
	     printf("\n\n");
	     printf("PRESIONE UNA TECLA PARA CONTINUAR");
	     getch();
	     clrscr();
	   }
	   else{
	     gotoxy(19,10);
	     printf("REGISTROS NO DEFINIDOS... PRESIONE UNA TECLA");
	     getch();
	     clrscr();
	   }
	   break;*/
       case 4:
	   if(sw==1){
	     AptEst=&Est[0];
	     for(i=0;i<n;i++){
	       gotoxy(1,3);
	       printf("EL PROMEDIO DEL CURSO ES: %1.2f",AptEst->PromCurso);
	       AptEst++;
	     }
	     printf("\n\n");
	     printf("PRESIONE UNA TECLA PARA CONTINUAR");
	     getch();
	     clrscr();
	   }
	   else{
	     gotoxy(19,10);
	     printf("REGISTROS NO DEFINIDOS... PRESIONE UNA TECLA");
	     getch();
	     clrscr();
	   }
	   break;
       default:
	   break;
     }
   }while(Opc!=5);
   gotoxy(30,10);
   printf("FIN DEL PROGRAMA");
}

//**************************************************
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
