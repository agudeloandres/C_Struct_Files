 # include <stdio.h>
 # include <iostream.h>
 # include <string.h>
 # include <conio.h>
 typedef struct estudiantes{
	 float codigo;
	 char  nombre[33];
	 float nota1;
	 float nota2;
	 float nota3;
  };
  void main()
 {
 clrscr();
 estudiantes *alumnos;
 float cod,not1,not2,not3,sum=0;
 char nom[35];
 int lo,i;
 //lectura de datos
 printf("Digite el c¢digo = ");
 scanf("%f",&cod);
 alumnos->codigo=cod;
 printf("Digite nombre");
 cin.getline(nom,35);
 lo=strlen(nom);
 //Asignacion de una variable
 for (i=1;i<=lo;i++){
  alumnos->nombre[i]=nom[i];
  }

  //Lectura de las notas

  printf ("digite nota1\n");
  scanf("%f",&not1);
  alumnos->nota1=not1;
  printf ("digite nota2\n");
  scanf("%f",&not2);
  alumnos->nota2=not2;
  printf ("digite nota3\n");
  scanf("%f",&not3);
  alumnos->nota3=not3;

  //Calculo de la nota
  sum=(not1 + not2 + not3)/3;

  //Escritura de datos y promedio
  printf("Datos del Alumno y su promedio");
  printf("codigo=%7.0f  nombre=%-35s nota1=%3.1f nota2=%3.1f nota3=%3.1f Promedio=%3.1f",alumnos->codigo,alumnos->nombre,alumnos->nota1,alumnos->nota2,alumnos->nota3,sum);
  getch();

  }