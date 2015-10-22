
#include <iostream.h>
void main()
{
int a[10],b[10],suma[10],prod[10],i,j,n;
unsigned int sw;
cout<<"digite tamaño del vector :  ";
do
{
cin>> n;
}
while (n<=1);
cout<< " digite variable sw : ";
cin>>sw;
cout<< " digite elementos del vector a ";
for (i=1; i<=n;i++)
{
cout<< " ,elemento :"<< "a["<< i <<"]";
cin>> a[i];
}
cout<< " digite elementos del vector b ";
for (i=1;i<=n;i++)
{
cout<< " ,elemento :"<< "b["<< i <<"]";
cin>> b[i];
}
switch(sw)
{
  case 0 :
  for (i=1;i<=n;i++)
  {
  suma[i]=a[i]+b[i];                                                        
  }
  cout<<" El resultado es : "<<"\n ";
  for (i = 1; i <= n; i++)
  {
  cout<<"La suma es : suma [ "<<i<<"]= ";
  cout<< suma [i] <<" \n ";
  }
  
  break;
  case 1:
  for (i = 1; i <= n; i++)
  {
  prod [i] = a[i]*b[i];
  }
  cout<< " El producto de la suma es prod; ";
  for (i = 1; i <= n; i++)
  {
  cout<< " El producto es : prod [" <<i<< "]= ";
  }
  break;
  default:
  cout<< " No se puede realizar nada ";
  }
  } 
   


