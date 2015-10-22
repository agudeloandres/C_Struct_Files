# include <stdio.h>
# include <string.h>

struct cliendata {
	int cuenta;
	char apellido[15];
	char nombre[10];
	float balance;
};
main()
{
	int i;
	struct cliendata blankclient={0," "," ",0.0};
	FILE *cfptr;
	if ((cfptr=fopen("credito.dat","w"))==NULL)
		printf("No se pudo abrir..\n");
	else
	{
		for (i=1;i<=5;i++)
			fwrite(&blankclient ,sizeof (struct cliendata),1,cfptr);
			fclose (cfptr);
		}
}

	