#define localizar (nodo *)malloc(sizeof(struct nodo))

struct nodo {
       int codigo;
       char nombre_soft[20];
       char autor_soft[20];
       int area;
       int precio;
       int year;
       struct nodo *sig;
       };


int sum1=0,sum2=0,sum3=0,sum4=0;
int sma=0,suso=0,suna=0,sues=0;
char *K={"NO HAY"};
char *Y={"NO HAY"};
char *P={"NO HAY"};
char *L={"NO HAY"};
char *M={"NO HAY"};
char *N={"NO HAY"};
char *H={"NO HAY"};
char *O={"NO HAY"};


void positivo(){
graphics(28,40,17,19);
gotoxy(30,18);
printf("I");delay(100);
printf("N");delay(100);
printf("S");delay(100);
printf("E");delay(100);
printf("R");delay(100);
printf("T");delay(100);
printf("A");delay(100);
printf("D");delay(100);
printf("O");delay(100);
getchar();
}

void insertar (struct nodo **cab,struct nodo *p,struct nodo *q,int c,char n[20],char a[20],int ar,int pc,int y)
{
 struct nodo *nuevo;

 nuevo=localizar;
 nuevo->codigo=c;
 stpcpy(nuevo->nombre_soft,n);
 stpcpy(nuevo->autor_soft,a);
 nuevo->area=ar;
 if (ar==1)
 { sum1++;}
 if (ar==2)
 { sum2++;}
 if (ar==3)
 { sum3++;}
 if (ar==4)
 { sum4++;}
 nuevo->precio=pc;
 nuevo->year=y;
 nuevo->sig=q;
 if (p!=NULL)
    {
    p->sig=nuevo;
    positivo();
    }
 else { *cab=nuevo;
	positivo();
 }
return;
}

void mantener(struct nodo **cab)
{
struct nodo *p,*q;
int encontro,c,ar,pc,y,ptr;
char n[20],a[20];
gotoxy(15,4);
cout<<"DIGITE LOS DATOS DEL SOFTWARE:\n";
gotoxy(15,6);
cout<<"CODIGO: ";
cin>>c;
gotoxy(15,7);
cout<<"NOMBRE DEL SOFTWARE: ";
cin>>n;
gotoxy(15,8);
cout<<"NOMBRE DEL AUTOR: ";
cin>>a;
gotoxy(15,9);
cout<<"AREA: ";
gotoxy(15,24);
cout<<"1)EDUCATIVO  2) CONTABLE 3)ENTRETENIMIENTO   4)MEDICO";
do{
gotoxy(21,9);
cin>>ar;
}while((ar<0)||(ar>4));
gotoxy(15,10);
cout<<"PRECIO: $";
cin>>pc;
gotoxy(15,11);
cout<<"AฅO DE CREACION: ";
cin>>y;

p=NULL;
q=*cab;
encontro=0;
while ((q!=NULL)&&(!encontro))
 {
ptr=strcmp(n,q->nombre_soft);
      if (ptr>0){
	   p=q;
	   q=q->sig;
      }
      else encontro=1;}
if (encontro)
   {
   if (n==q->nombre_soft)
       {
       clrscr();
       gotoxy(17,12);
       printf("EL SOFTWARE YA EXISTE EN LA LISTA\n");
       getch();
       }
   else insertar(cab,p,q,c,n,a,ar,pc,y);
   }
else insertar(cab,p,q,c,n,a,ar,pc,y);
return;
}


void retirar_p(struct nodo **cab,struct nodo *dato)
{
 struct nodo *aux,*p;
 int z,sw=0;

  p=*cab;
  if(p==NULL){
   printf("ERROR,NO ES POSIBLE RETIRAR,LA LISTA ESTA VACIA\n");
   getch();}
  else
   {
    printf("ELIJA EL REGISTRO A ELIMINAR (DIGITE EL CODIGO)\n");
    cin>>z;
	while(p!=NULL)
	{
	 if (p->codigo==z)
	   {
	    dato=p;
	    if(p==*cab)
	      {
	       *cab=p->sig;
	       delete(p);
	       cout<<"EL REGISTRO HA SIDO ELIMINADO";
	       getchar();
	       sw=1;
	       break;

	      }
	     else
	      {
	       aux=*cab;
	       while(aux->sig!=p)
		aux=aux->sig;
	       aux->sig=p->sig;
	       delete(p);
	       cout<<"SE ELIMINO EL REGISTRO";
	       getchar();
	       sw=1;
	       break;

	      }
	   }
	 else p=p->sig;
	  if (p->area==1)
	   { sum1--;}
	  if (p->area==2)
	   { sum2--;}
	  if (p->area==3)
	   { sum3--;}
	  if (p->area==4)
	   { sum4--;}


	}
	if (sw==0)
	 cout<<"EL REGISTRO NO EXISTE EN LA LISTA";
	 getchar();
  }
return;
}


void con1(struct nodo **cab)
{
 struct nodo *p;
 char j[20],h,sw=0;

 p=*cab;
 clrscr();
 cout<<"ESCRIBA EL NOMBRE DEL AUTOR PARA LA BUSQUEDA: ";
 cin>>j;
 while (p!=NULL)
   {
    h=strcmp(j,p->autor_soft);
    if (h==0)
     {

      cout<<p->nombre_soft;
      sw=1;
      getchar();
     }
    p=p->sig;
   }
  if (sw==1){
   cout<<"LISTA COMPLETA";
   getchar();}
  else{
   graphics(13,48,9,11);
   gotoxy(15,10);
   cout<<"NO EXISTEN SOFTWARE DE ESE AUTOR";
   getchar();}
   return;
}

void con2(struct nodo **cab)
{
 struct nodo *p;
 int b;

 p=*cab;
 while (p!=NULL)
  {
   b=p->area;
   switch(b)
    {
     case 1: sma+=p->precio;
	     break;

     case 2: suso+=p->precio;
	     break;

     case 3: suna+=p->precio;
	     break;

     case 4: sues+=p->precio;
	     break;
    }
   p=p->sig;
   }
   clrscr();
   graphics(18,55,8,23);
   gotoxy(24,11);
   cout<<"LA SUMATORIA DE LOS SOFTWARE";
   gotoxy(24,12);
   cout<<"POR AREA SON:";
   gotoxy(24,15);
   cout<<"EDUCATIVO: $";
   cout<<sma<<"\n";
   gotoxy(24,17);
   cout<<"CONTABLE: $";
   cout<<suso<<"\n";
   gotoxy(24,19);
   cout<<"ENTRETENIMIENTO: $";
   cout<<suna<<"\n";
   gotoxy(24,21);
   cout<<"MEDICO: $";
   cout<<sues<<"\n";
   getchar();
   return;
}

void con3(struct nodo **cab)
{
 clrscr();
 graphics(18,54,8,21);
 gotoxy(24,12);
 cout<<"NUMERO DE SOFTWARE DE:";
 gotoxy(24,15);
 cout<<"EDUCATIVO: "<<sum1<<"";
 gotoxy(24,16);
 cout<<"CONTABLE: "<<sum2<<"";
 gotoxy(24,17);
 cout<<"ENTRETENIMIENTO: "<<sum3<<"";
 gotoxy(24,18);
 cout<<"MEDICO: "<<sum4<<"";
 getch();
 return;
}
void con4(struct nodo **cab)
{
  int j,n=0,g=0,v=0,z=0;
  char *K={"NO HAY"},*Y={"NO HAY"},*P={"NO HAY"},*L={"NO HAY"},*M={"NO HAY"};
  char *N={"NO HAY"},*H={"NO HAY"},*O={"NO HAY"};
  struct nodo *p;

  p=*cab;
  while (p!=NULL)
  {
   j=p->area;
   switch(j)
    {
     case 1:
	    if (n < p->precio)

	     { n=p->precio;
	       K=p->nombre_soft;
	       Y=p->autor_soft;
	     }
	      break;
     case 2:
	    if (g < p->precio)
	     { g=p->precio;
	       P=p->nombre_soft;
	       L=p->autor_soft;
	     }
	     break;
     case 3:
	    if (v < p->precio)
	     { v=p->precio;
	       M=p->nombre_soft;
	       N=p->autor_soft;
	     }

	     break;

     case 4:
	    if (z < p->precio)
	     { z=p->precio;
	       H=p->nombre_soft;
	       O=p->autor_soft;
	     }

	     break;

    }
  p=p->sig;
  }
   clrscr();
   graphics(18,55,4,21);
   gotoxy(21,7);
   cout<<"LOS SOFTWARE MAS COSTOSOS POR AREA";
   gotoxy(21,10);
   cout<<"EDUCATIVO: "<<K<<"\n";
   gotoxy(21,11);
   cout<<"AUTOR: "<<Y<<"\n";
   gotoxy(21,13);
   cout<<"CONTABLE: "<<P<<"\n";
   gotoxy(21,14);
   cout<<"AUTOR: "<<L<<"\n";
   gotoxy(21,16);
   cout<<"ENTRETENIMIENTO: "<<M<<"\n";
   gotoxy(21,17);
   cout<<"AUTOR: "<<N<<"\n";
   gotoxy(21,19);
   cout<<"MEDICO: "<<H<<"\n";
   gotoxy(21,20);
   cout<<"AUTOR: "<<O<<"\n";
   getchar();
   return;
}

void con5 (struct nodo **cab)
{
 struct nodo *p;
 int q,si=0;
 char area1234;
 p=*cab;
 clrscr();
 cout<<"LISTA DE SOFTWARE DESPUES DE 1990\n";
 while (p!=NULL)
  {
   if (p->year > 1990)
    {
     cout<<"CODIGO: "<<p->codigo<<"\n";
     cout<<"NOMBRE: "<<p->nombre_soft<<"\n";
     cout<<"AUTOR: "<<p->autor_soft<<"\n";
     q=p->area;
     switch(q){
     case 1: cout<<"AREA: EDUCATIVO\n";
	     break;
     case 2: cout<<"AREA: CONTABLE\n";
	     break;
     case 3: cout<<"AREA: ENTRETENIMIENTO\n";
	     break;
     case 4: cout<<"AREA: MEDICO\n";
	     break;
     default:
	     break;
     }
     cout<<"PRECIO: "<<p->precio<<"\n\n";
     si++;
    }
   p=p->sig;
  }

 if(!si){

 graphics(13,56,9,11);
 gotoxy(15,10);
 cout<<"NO EXISTE SOFTWARE HECHO DESPUES DE 1990";
 }
 getchar();
 return;
}


void consulta(struct nodo **);

void consulta(struct nodo **cab)
{
 int w,h=0;

 while(h==0)
  {
   clrscr();
   graphics(7,70,2,23);
   gotoxy(18,5);
   printf("************ MENU CONSULTAS ***********\n\n");
   gotoxy(12,8);
   printf("1)LISTA DE SOFTWARE POR AUTOR\n\n");
   gotoxy(12,10);
   printf("2)SUMATORIA DE LOS PRECIOS DE LOS SOFTWARE POR AREA\n\n");
   gotoxy(12,12);
   printf("3)NUMERO DE SOFTWARE POR AREA DE DESEMPEฅO\n\n");
   gotoxy(12,14);
   printf("4)SOFTWARE MAS COSTOSO POR AREA Y AUTOR \n\n");
   gotoxy(12,16);
   printf("5)SOFTWARE HECHOS DESPUES DE 1990\n\n");
   gotoxy(12,18);
   printf("6)VOLVER AL MENU PRINCIPAL\n\n");
   gotoxy(27,21);
   printf("DIGITE OPCION [ ]");
   do{
    gotoxy(42,21);
    cin>>w;
    }while((w<1)||(w>6));
   switch(w)
     {
      case 1:
	     con1(cab);
	     break;

      case 2:
	     con2(cab);
	     break;

      case 3:
	     con3(cab);
	     break;
      case 4:
	     con4(cab);
	     break;

      case 5:
	     con5(cab);
	     break;

      case 6:
	     h=1;
	     break;

      default:
	     break;
     }
  }
 return;
}

void visual(struct nodo **cab)
{
 struct nodo *p;
 int kk=0;

 p=*cab;
 while(p!=NULL)
 {

gotoxy(1,1);
cout<<"ษออออออออหออออออออออหออออออออออหออออออหอออออออออหอออออออออออออออออป\n";
cout<<"บ CODIGO บ  NOMBRE  บ   AUTOR  บ AREA บ PRECIO  บ CREADO EN EL AฅOบ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"บ        บ          บ          บ      บ         บ                 บ\n";
cout<<"ศออออออออสออออออออออสออออออออออสออออออสอออออออออสอออออออออออออออออผ\n";

while(p!=NULL)
 {
  gotoxy(3,3+kk);
  cout<<p->codigo;
  gotoxy(12,3+kk);
  cout<<p->nombre_soft;
  gotoxy(23,3+kk);
  cout<<p->autor_soft;
  gotoxy(35,3+kk);
  cout<<p->area;
  gotoxy(41,3+kk);
  cout<<p->precio;
  gotoxy(53,3+kk);
  cout<<p->year;
  p=p->sig;
  kk++;
 }
 getchar();
 return;
 }

}
 void final()
 {
  graphics(11,68,22,24);
  gotoxy(13,23);
  cout<<"FIN DEL PROCESO. PULSE <BARRA ESPACEADORA> PARA SALIR.";
  while(getch()!=' ');
  clrscr();
  graphics(20,58,12,14);
  gotoxy(24,13);
  cout<<"UN PROGRAMA DE FOX MICROSYSTEMS";
  return;
 }
