# include <iostream.h>
# include <stdio.h>
# include <string.h>
# include <conio.h>

// definicion de tipos de datos

typedef struct alumno {
	float codigo;
	char nombre[35];
	float nota;
        char sexo;
	float nota2;
	float nota3;
	float def;
};

void main ()
{
	alumno estudiante[20],*ptr;
	float cod;
	float not1;
	float not2;
	float not3;
	float pro1;
	float pro2;
	float pro3;
	float defi;
	float promedio;
	float pro_m;
        float pro_f;
	char nom[35],opcion;
        char sex;
	int n,j,i,lon;
	int nm,nf;

	// lectura de numero de estudiantes

	printf ("Digite Numero de Estudiantes : ");
	do {
		scanf("%d",&n);
		} while (n<=0);
		ptr=&estudiante[1];
		defi=0;
		// asignacion de los registros a la estructura

		for (i=1;i<=n;i++){
			// lectura de campo en cada registro
			clrscr();
			printf("Digite Numero de Cedula            :");
			scanf("%f",&cod);
			printf("Digite Digite Nombre               :");
			cin.getline(nom,35);
			printf("Sexo del Estudiantes               :");
                        do {
				sex=getchar();
			} while (sex !='f' && sex !='m');
			printf("Digite Nota del primer seguimiento :");
                       	scanf("%f",&not1);
			printf("Digite Nota del Segundo Seguimiento:");
			scanf("%f",&not2);
			printf("Digite Nota del Tercer Seguimiento :");
			scanf("%f",&not3);
			
			defi=(not1*0.35)+(not2*0.35)+(not3*0.30);

			// asignacion de campo leidos a cada registro

			ptr->codigo=cod;
			lon=strlen(nom);
			for (j=0;j<=lon;j++) {
				ptr->nombre[j]=nom[j];
			}

			ptr->nota=not1;
			ptr->nota2=not2;
			ptr->nota3=not3;
			ptr->def=defi;
                        ptr->sexo=sex;
                        ptr++;
			}

			// calculo de promedio

			promedio=0;
			pro_m=0;
                        pro_f=0;
			ptr=&estudiante[1];
			for (i=1;i<=n;i++){
				if (ptr->sexo = 'f')
				{
					pro_f+=(ptr->def);
                                        nf=nf+1;
				}
				else
				{
				pro_m+=(ptr->def);
                                nm=nm+1;
                                
				}
				promedio+=(ptr->def);
                        }

			promedio/=n;
			pro_m/=nm;
			pro_f/=nf;
			

			// impresion de los estudiantes

			clrscr();
			gotoxy(25,2);
			printf("ESTUDIANTES DE INGENIERIA DE SISTEMAS");
			gotoxy(1,4);
			printf("CEDULA    NOMBRE	       SEXO NOTA.1  NOTA.2  NOTA.3  DEF.");
			ptr=&estudiante[1];
			j=5;
			for (i=1;i<=n;i++){
				gotoxy(1,j);
				printf("%7.0f %-35s %c %2.1f %2.1f %2.1f %2.1f",ptr->codigo,ptr->nombre,ptr->sexo,ptr->nota,ptr->nota2,ptr->nota3,ptr->nota3,ptr->def);
				j++;
				ptr++;
			}

			printf ("\n \n Digite 0 y Enter para continuar :");
			do {
				opcion=getchar();
			} while (opcion !='0');

			// impresion de resultados

			clrscr();
			gotoxy(17,2);
			printf("RESUMEN DEL PROCESO");
			printf("\n  Promedio del Sexo Femenino.......: %2.2f",pro_f);
			printf("\n  Promedio del Sexo Masculino......: %2.2f",pro_m);
			printf("\n  Promedio del Curso en General....: %2.2f",promedio);
			printf("\n  Total Alumnos Leidos.............: %d",n);
			}



			 
