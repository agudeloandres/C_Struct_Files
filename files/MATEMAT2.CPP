#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

//#include<a:sinmso>

 void main()
 {
 int i,way;
 char funcion[50],argt[50],cart[50],dif[50];
 char SEN[4]="SEN";
 char COS[4]="COS";
 char TAN[4]="TAN";
 char CSC[4]="CSC";
 char SEC[4]="SEC";
 char COTAN[6]="COTAN";
 char LN[3]="LN";

 int a,b,c,r,x1,g,t;
 float resul,d1,f,f1,k,k1,d,l,m1,res,m2;
 char z[10],x[10],a1[10],a2[10],a3[10],a4[10],a5[10],a6[10];//res[10];
 int q,q2,q3,q4;
clrscr();
textcolor(01);
textbackground(003);
delay(3);
gotoxy(0,0);
printf("É");
for (q=1;q<=78;q++){
delay(3);
gotoxy(q,0);
printf("Í");
}
delay(3);
gotoxy(79,0);
printf("»");

for (q2=2;q2<=23;q2++){
delay(3);
gotoxy(80,q2);
printf("º");
}
delay(3);
gotoxy(80,24);
printf("¼");

for(q3=79;q3>=1;q3--){
delay(3);
gotoxy(q3,24);
printf("Í");
}
delay(3);
gotoxy(1,24);
printf("È");

for (q4=23;q4>=2;q4--){
delay(3);
gotoxy(1,q4);
printf("º");}

//marco1 ();
gotoxy(24,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA\n");
gotoxy(30,4);
printf("TRABAJO DE MATEMATICAS \n");
gotoxy(32,7);
printf("INTEGRANTES :");
gotoxy(18,10);
printf("  KARINA ACOSTA          COD:5971004 ");
gotoxy(18,12);
printf("  LUIS BORREGO           COD:5971012 ");
gotoxy(18,14);
printf("  ISMEL CERCHAR          COD:5971018 ");
gotoxy(18,16);
printf("  INGRID ESCOBAR         COD:5971026 ");
gotoxy(18,18);
printf("  MAYERLY LOZANO         COD:5971034 ");
gotoxy(18,21);
printf("  PRESENTADO A: ");
gotoxy(32,21);
printf("   LIC: ALVARO MARRIAGA ");
gotoxy(30,23);
printf("DIGITE <ENTER> PARA CONTINUAR");
getch();
clrscr();
gotoxy(24,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA\n");
gotoxy(30,4);
printf("TRABAJO DE MATEMATICAS \n");
gotoxy(32,7);
printf("INTEGRANTES :");
gotoxy(18,10);
printf("  ...................ASTRID CARRASQUILLA          ");
gotoxy(18,12);
printf("  ...................SANDRA GOMEZ            ");
gotoxy(18,14);
printf("  ...................BELKIS CUCUNUBA          ");
gotoxy(18,16);
printf("  ...................ALEJADRA MONERI         ");
gotoxy(18,18);
printf("  ...................SILAK DEL TORO         ");
gotoxy(18,20);
printf("  ...................MILENA TORRES         ");
gotoxy(18,22);
printf("  ...................ANA MARIA VAN-LEENDEN ");
gotoxy(18,24);
printf("  PRESENTADO A: ");
gotoxy(32,24);
printf("   LIC: ALVARO MARRIAGA ");


  getch();
  clrscr();
 /* printf("VALORES QUE SE UTILIZARAN MAS ADELANTE\n");
  scanf("%s%s%s%s%s%s",&a1,&a2,&a3,&a4,&a5,&a6);*/
    clrscr();

  gotoxy(30,12);
  printf(" SEGUNDO ORDEN ");
  getch();
  clrscr();
  gotoxy(5,2);
  printf(" FORMATO DE  ECUACIONES LINEALES CON COEFICIENTES VARIABLES\n");
  gotoxy(20,10);
  printf(" d^2y          dy   ");
  delay(50);
  gotoxy(20,11);
  printf(" ----   + R(x) --  +S(x)y  = Q(x)   \n");
  delay(200);
  gotoxy(20,12);
  printf(" dx^2          dx ");
  gotoxy(30,23);
  printf("DIGITE <ENTER> PARA CONTINUAR");

  getch();
  clrscr();
  printf("  d^2y  +  dy +  y =      ");
  gotoxy(9,1);
  scanf("%d",&b);
  gotoxy(15,1);
  scanf("%d",&c);
  gotoxy(22,1);
  scanf("%s",&x);
/////////////////////////////////////////////////////////////////////////////
//CASO I
  if((b==0)&&(c!=0)){
  //clrscr();
   k1=-c;
   if(k1<0){
   k1=(-1*k1);
   }
   k=sqrt(k1);
   f=-k;
   f1=k;

  printf("  las raices son :\n");
  printf("  %.2f i\n",f);
  printf("  %.2f i\n",f1);

  printf("  Yc = C1 cos     x + C2 sen       x ");
  gotoxy(14,5);
  printf("%.2f\n",f);
  gotoxy(30,5);
  printf("%.2f\n",f1);
  printf("  Yp=u1(x) Y1 + u2(x) Y2 \n");
  printf("  Y1=cos      x ");
  gotoxy(10,7);
  printf("%.2f\n",f);
  printf("  Y2=sen      x ");
  gotoxy(10,8);
  printf("%.2f\n",f1);


  //wronsquiano
  printf("W=");
  for (q2=12;q2<=14;q2++){
  delay(3);
  gotoxy(12,q2);
  printf("º");
  }
  for (q2=12;q2<=14;q2++){
  delay(3);
  gotoxy(21,q2);
  printf("º");
  }
  gotoxy(14,12);
  printf("Y1");
  gotoxy(18,12);
  printf("Y2");
  gotoxy(14,14);
  printf("Y`1");
  gotoxy(18,14);
  printf("Y`2");

  //////////////////////////////////
  gotoxy(22,13);
  printf("W=");

  for (q2=12;q2<=14;q2++){
  delay(3);
  gotoxy(24,q2);
  printf("º");
  }
  for (q2=12;q2<=14;q2++){
  delay(3);
  gotoxy(60,q2);
  printf("º");
  }
  gotoxy(26,12);
  printf("cos x^  ");
  gotoxy(33,12);
  printf("%.2f",f);
  gotoxy(47,12);
  printf("sen x^  ");
  gotoxy(53,12);
  printf("%.2f",f1);
  gotoxy(30,14);
  printf(" sen x^ ");
  gotoxy(25,14);
  printf("%.2f",f1*(-1));
  gotoxy(37,14);
  printf("%.2f",f1-1);
  gotoxy(47,14);
  printf("cos x^ ");
  gotoxy(43,14);
  printf("%.2f",f);
  gotoxy(53,14);
  printf("%.2f",f+1);
  gotoxy(22,16);
  printf("W =     cos^2 x^    +(     sen^2x^     )");
  res=f*f1;
  gotoxy(25,16);
  printf("%.2f",res);
  gotoxy(36,16);
  printf("%.2f",f1-1);

  gotoxy(44,16);
  printf("%.2f",res);
  gotoxy(58,16);
  printf("%.2f",f+1);
  gotoxy(22,17);
  printf("W = 1 ");
  gotoxy(31,18);
  printf("-sen x^     ");
  gotoxy(38,18);
  printf("%.2f ",f);
  gotoxy(46,18);
  printf("* %s ",x);
  // CALCULO DE U`1(X)
  gotoxy(23,19);
  printf("u`1(x) = ");
  gotoxy(31,19);
  printf("---------------------------------------------");
   gotoxy(43,20);
   printf(" 1");
/*  printf("  =     cos^2 x^    +(      sen^2x^      )");
  res=f*f1;
  gotoxy(33,20);
  printf("%.2f",res);
  gotoxy(44,20);
  printf("%.2f",f1-1);

  gotoxy(53,20);
  printf("%.2f",res);
  gotoxy(66,20);
  printf("%.2f",f+1); */
  if(x==0){
  gotoxy(22,22);
 printf("u`1(x) =   %s",x);
 }
  //CALCULO DE U`2(X)
/*  gotoxy(46,25);
  printf("u`2(x) = ");
  gotoxy(33,25);
  printf("----------");
  gotoxy(55,26);
  printf(" * e^  x");
  gotoxy(34,26);
  printf("%.0f",k1);
  gotoxy(39,26);
  printf("%.0f",k1);
  // z=(-1*x);
  gotoxy(45,25);
  printf("u`2(x) =   %s",x);
  */
  getch();
  }
  ////////////////////////////////////////////////////////////////////////////
  // CASO II
  if((c==0)&&(b!=0)){
  d=0;
  d1=-b;
  printf("%.2f\n",d);
  printf("%.2f\n",d1);
  printf("Yc = C1 + C2e^  x");
  gotoxy(15,4);
  printf("%.0f\n",d1);
  printf("Y1=1\n");
  printf("dY1=0\n");
  printf("Y2=e^  x\n");
  gotoxy(6,7);
  printf("%.0f\n",d1);
  printf("dY2=  * e^  x ");
  gotoxy(5,8);
  printf("%.0f",d1);
  gotoxy(11,8);
  printf("%.0f",d1);
  getch();
  //wronquiano
  clrscr();
  gotoxy(30,1);
  printf("METODO WROQUIANO");

  gotoxy(10,5);
  printf("W=");
  for (q2=4;q2<=6;q2++){
  delay(3);
  gotoxy(12,q2);
  printf("º");
  }
  for (q2=4;q2<=6;q2++){
  delay(3);
  gotoxy(21,q2);
  printf("º");
  }
  gotoxy(14,4);
  printf("Y1");
  gotoxy(18,4);
  printf("Y2");
  gotoxy(14,6);
  printf("Y`1");
  gotoxy(18,6);
  printf("Y`2");

  //////////////////////////////////
  gotoxy(22,5);
  printf("W=");

  for (q2=4;q2<=6;q2++){
  delay(3);
  gotoxy(24,q2);
  printf("º");
  }
  for (q2=4;q2<=6;q2++){
  delay(3);
  gotoxy(42,q2);
  printf("º");
  }
  gotoxy(26,4);
  printf("1");
  gotoxy(34,4);
  printf("e^  x");
  gotoxy(36,4);
  printf("%.0f",d1);
  gotoxy(26,6);
  printf("0");
  gotoxy(31,6);
  printf("  * e^  x");
  gotoxy(32,6);
  printf("%.0f",d1);
  gotoxy(37,6);
  printf("%.0f",d1);
  gotoxy(22,8);
  printf("W =  * e^  x");
  gotoxy(25,8);
  printf("%.0f",d1);
  gotoxy(31,8);
  printf("%.0f",d1);
  //CALCULO DE U`1(X)
  gotoxy(31,10);
  printf("-e^  x*  ");
  gotoxy(34,10);
  printf("%.0f ",d1);
  gotoxy(39,10);
  printf("%s ",x);
  gotoxy(23,11);
  printf("u`1(x) = ");
  gotoxy(31,11);
  printf("----------");
  gotoxy(33,12);
  printf(" * e^  x");
  gotoxy(34,12);
  printf("%.0f",d1);
  gotoxy(39,12);
  printf("%.0f",d1);
// z=(-1*x);
  gotoxy(45,11);
  printf("u`1(x) =   %s/ %.0f",x,d1*-1);
   gets(x);
 for (i=0; i<strlen(x); i++)
 {
 argt[i]=toupper(x[i]);
 }
  //argt[i]=x;
  if (!strcmp(argt,SEN))
  {
   strcpy(dif,"-");
   strcat(dif,COS);
   }
  if (!strcmp(argt,COS))
    strcpy(dif,SEN);
  if (!strcmp(argt,TAN))
   {
   strcpy(dif,LN);
   strcat(dif," ");
   strcat(dif,"(");
   strcat(dif,SEC);
   strcat(dif,")");
   }
  if (!strcmp(argt,SEC))
  {
   strcpy(dif,LN);
   strcat(dif," ");
   strcat(dif,"(");
   strcat(dif,SEC);
   strcat(dif,"+");
   strcat(dif,TAN);
   strcat(dif,")");
   }
  if (!strcmp(argt,CSC))
  {
   strcpy(dif,"-");
   strcat(dif,LN);
   strcat(dif," ");
   strcat(dif,"(");
   strcat(dif,CSC);
   strcat(dif,"+");
   strcat(dif,COTAN);
   strcat(dif,")");
  }
  if (!strcmp(argt,COTAN))
  {
   strcpy(dif,"-");
   strcat(dif,LN);
   strcat(dif,"(");
   strcat(dif,CSC);
   strcat(dif,")");
  }

  printf("LA INTEGRAL DE LA FUNCION ES: %s",dif);


  //CALCULO U`2(X)
  gotoxy(31,14);
  printf(" 1 * ");
  gotoxy(34,14);
 // printf("%.0f ",d1);
  gotoxy(35,14);
  printf("%s ",x);
  gotoxy(23,15);
  printf("u`2(x) = ");
  gotoxy(31,15);
  printf("----------");
  gotoxy(33,16);
  printf(" * e^  x");
  gotoxy(34,16);
  printf("%.0f",d1);
  gotoxy(39,16);
  printf("%.0f",d1);
// z=(-1*x);
  gotoxy(45,15);
  printf("u`2(x) =   %s /   * e^   x",x);
  gotoxy(60,15);
  printf("%.0f",d1);
  gotoxy(67,15);
  printf("%.0f",d1);
 //////////////////
 //integrando u`1 y  u`
   getch();
  }
  ///////////////////////////////////////////////////////////////////////////
  // TERCER CASO
  if((b!=0)&&(c!=0)){
  a=1;
  g=(a*2);
  printf("%d\n",g);
  x1=(-4*c);
  printf("%d\n",x1);
  r=(b*b);
  printf("%d\n",r);
  t=r-x1;
  printf("%d\n",t);
  resul=sqrt(t);
  printf("%f",resul);
 m1=(-b+resul)/g;
 m2=(-b-resul)/g;
 gotoxy(30,15);
 printf("%.2f %.2f",m1,m2);
getch();

 }








//  getch();


   }
