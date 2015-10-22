# include <stdio.h>
# include <conio.h>
void main (){
int primo (int); //PROTOTIPO
int n,y;
clrscr();
printf("DIGITE UN NUMERO\n");
scanf("%d",&n);
y=primo(n);
if (y)
   printf("PRIMO\n");
else
 printf("NO ES PRIMO\n");

getch();
}
int primo(int x){
int i,count=0;
for (i=1;i<=x;i++){
if (!(x%i))
 count++;
}
if (count>2)
     return 0;
else
    return 1;
}