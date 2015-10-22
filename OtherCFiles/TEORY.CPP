
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
//void grap_point(void);
void two_points();
void three_points();
void four_points();
void five_points();
void six_points();
void seven_points();


main()
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax,i,y;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

int mat[10][10],p,j,Q=0,q,x;
//do{
printf("digite tama¤o de la matriz adya:");
scanf("%d",&p);
/*
}while(p==1);
printf("elementos de la matriz\n");
for(i=1;i<=p;i++){
  for(j=1;j<=p;j++){
     printf("mat[%d][%d]=",i,j);
     //do{
    scanf("%d",&mat[i][j]);
     // }while(mat[i][j] <47 || mat[i][j] >58);
     }
    }
   // Q=(((p*p)-p)/2);

   for(i=1;i<=p;i++){
      for(j=1;j<=p;j++) {
	  x = mat[i][j];
	  if(x==1){
	    Q += 1;
	  }
	  }
      }



     */
       Q=12;
    cleardevice();
  //  grap_point();
  if(p==2 && Q==2){
     two_points();
      getch();
    }
     if(p==3 && Q== 6) {
     three_points();
      getch();
    }
     if(p==4 && Q==12){
     four_points();
      getch();
    }

    return 0;
  }
 void grap_point(void)
 {
   gotoxy(30,4);
   printf(" GRAPICS OF POINTS");

   //line(160,200,480,200); //v3 a v2
  //  vertices de contacto V1
   line(170,200,310,135);// v1 a v2
   line(320,135,480,200);// v1 a v3
   line(315,135,315,250);// v1 a v4
   line(170,300,315,135);// v1 a v5
   line(320,135,480,300);// v1 a v6
   line(315,135,315,370);// v1 a v4
   line(160,200,480,200);// v2 a v3
   line(315,135,315,370);// v1 a v4
   line(320,245,480,200);//v3 a v4




   gotoxy(40,9);printf("V1");
 //  gotoxy(40,9);printf("*");
   gotoxy(40,16);printf("V4");
//   gotoxy(40,16);printf("*");
   gotoxy(40,24);printf("V7");
//   gotoxy(40,24);printf("*");
   gotoxy(20,13);printf("V2");
 //  gotoxy(20,13);printf("*");
   gotoxy(20,21);printf("V5");
//   gotoxy(20,21);printf("*");
   gotoxy(60,13);printf("V3");
//   gotoxy(60,13);printf("*");
   gotoxy(60,21);printf("V6");
//   gotoxy(60,21);printf("*");

 }
void two_points()
{
   gotoxy(40,9);printf("V1");
   gotoxy(20,13);printf("V2");
   line(170,200,310,135);// v1 a v2

}


void three_points()
{
   gotoxy(40,9);printf("V1");
   gotoxy(20,13);printf("V2");
   gotoxy(60,13);printf("V3");
   line(170,200,310,135);// v1 a v2
   line(320,135,480,200);// v1 a v3
   line(160,200,480,200);// v2 a v3

}

void four_points()
{
   gotoxy(40,9);printf("V1");
   gotoxy(20,13);printf("V2");
   gotoxy(60,13);printf("V3");
   gotoxy(40,16);printf("V4");
   line(170,200,310,135);// v1 a v2
   line(320,135,480,200);// v1 a v3
   line(160,200,480,200);// v2 a v3
   line(315,135,315,250);// v1 a v4
   line(150,180,200,250);// v2 a v3

}