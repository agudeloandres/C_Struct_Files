
 # include<conio.h>
 # include<iostream.h>
 # include<stdio.h>         //ARCHIVO PARA EDITAR ARCHIVOS O ACTUALIZAR
 # include<fstream.h>       //EDITA EL ARCHIVO CREADO EN FILE
 # include<string.h>
 # include<stdlib.h>

  //programa para el manejo de archivos

 typedef struct alumno{
	 float codigo;
	 char nombre[35];
	 float telefono;
  };

   void main()
 {
 clrscr();
  fstream estudiantes;
  alumno estudiante;
  char op,nom[35];
  float cod,tel;
  int z,i,lo;

   // abrir el archivo en forma input para validar su existencia

   estudiantes.open("estud.dat",ios::in|ios::binary);

   //proceso de validacion de la existencia de un archivo

   if (estudiantes.fail()){

       cout<<"archivo estud.dat no existe dar enter";
	   getch();
	    exit(1);
	}

   estudiantes.close();

   estudiantes.open("estud.dat",ios::in|ios::out|ios::binary);


    //captura de datos a grabar en el archivo.

     do{
       clrscr();

      gotoxy(23,4);
      printf("digite el codigo a registro buscar");
      scanf("%f",&cod);

      estudiantes.read((char*) &estudiante,sizeof(estudiante));

    // } while (!estudiantes.eof()|| cod != estudiante.codigo);

    //  estudiantes.read((char*) &estudiante,sizeof(estudiante));

      z=-lo;
      estudiantes.seekg(z,ios::cur);
      printf("digite nombre");
      cin.getline (nom,35);
	z=strlen(nom);
	for(i=0;i<=z;i++){
	 estudiante.nombre[i]=nom[i];
	}
       printf("digite codigo");
       scanf("%f",&cod);
       estudiante.codigo=cod;
       printf("digite telefono");
       scanf("%f",&tel);

	estudiante.telefono=tel;

	// escritura del registro captura en el archivo.

	 estudiantes.write((char*) &estudiantes,sizeof(estudiantes));
	 gotoxy(10,16);
	 printf("Mas datos (S/N): ");
	  do{
	  op=getchar();
	  }while(op!='S' && op!= 's' && op!='N' && op!='n');
	 // gotoxy(10,16);
	 // printf("                              ");
     }
	  while(op=='S' || op=='s');
	 estudiantes.close();
	}



