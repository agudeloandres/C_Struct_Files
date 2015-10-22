# include <stdio.h>
# include <conio.h>
main ()
{
int vocal;
int Na=0,Ne=0,Ni=0,No=0,Nu=0;
printf("entre la vocal\n");
printf("entre ctrl-d para finalizar \n");
while((vocal=getchar())!=EOF){
switch (vocal){
case 'A':case 'a' :
++Na;
break;
case 'E': case 'e' :
++Ne;
break;
case 'I' : case 'i':
++Ni;
break;
case 'O' : case
