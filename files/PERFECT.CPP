# include <stdio.h>
# include <conio.h>
main() {
int perfect (int);
void fac(int);
int i;
clrscr();
for (i=1;i<=1000; i++)
	if (perfect(i)){
		printf("Es Perfecto %d",i);
		fac(i);
		getchar();}
}
void fac(int a){
int i;
for (i=1;i<a;i++)
	if (!(a%i))
	printf("\n El factor =%d  ",i);
}


int  perfect (int k)
{
	int sum=0,i;
	for (i=1;i<k;i++)
		if (!(k%i)){
			sum+=i;
		       //printf ("\n Un factor de %d es %d " ,k,i);
			//getchar();
		}
	if (sum==k)
		return 1;

	else

		return 0;
}



