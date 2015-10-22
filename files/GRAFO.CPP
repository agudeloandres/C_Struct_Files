# include<stdio.h>
# include<conio.h>
# include<time.h>
# include<graphics.h>
# include<iostream.h>
void Lect_Mat(int [8][8],int);
void pointer(int ,int x[],int y[]);
void arco(int A[8][8],int x[],int y[],int);
main()
{
 int x[7]={220,120,360,460,160,400,280};
 int y[7]={100,200,100,200,300,300,330};
 int A[8][8],control,modo,l;
 //control=DETECT;
 detectgraph(&control,&modo);
 initgraph(&control,&modo,"F:");

 printf("Digite longitud de la Matriz: ");
 do{
   cin>>l;
 }while(l<2 || l>7);
 clearviewport();
 Lect_Mat(A,l);
 pointer(l,x,y);
 arco(A,x,y,l);
 getch();
 closegraph();
}



void Lect_Mat(int A[8][8],int l)
{
 int i,j,k;
 printf("ELEMENTOS DE LA MATRIZ\n");
 i=0;
  for(k=0;k<l;k++){
    for(j=0;j<l;j++){
      do{
	printf("A[%d][%d] =  ",k,j);
	 cin>>A[k][j];
      }while(A[k][j]<0 || A[k][j]>1);
       }

 }

}






void pointer(int l,int x[], int y[])
{
int i,j;

 for(i=0;i<l;i++){
	circle(x[i],y[i],5);
     }
  }




void arco(int A[8][8],int x[],int y[],int l)
{
int i=0,j,k;
    for(k=0;k<l;k++){
      for(j=0;j<l;j++){
	if(A[j][k]==1){
	  line(x[i],y[i],x[j],y[j]);
	  }

      }
      i++;
 }
}
