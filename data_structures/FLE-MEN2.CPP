//menu para manejo de archivos

#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<fstream.h>

void inside_inde(float,int);
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
 int n,i,k,z,lo;
 int sw;
 char c,salida[80];
 char opc;

 //creacion del menu
sw=0;

do{
   gotoxy(25,2);
   printf("M E N U   P R I N C I P A L");
   gotoxy(17,4);
   printf("CREAR ARCHIVO.............................[1]\n");
   gotoxy(17,5);
   printf("ADICIONES.................................[2]\n");
   gotoxy(17,6);
   printf("CONSULTAR.................................[3]\n");
   gotoxy(17,7);
   printf("MODIFICACIONES............................[4]\n");
   gotoxy(17,8);
   printf("TERMINAR..................................[5]\n");
   gotoxy(17,10);
   printf("DIGITE OPCION DESEADA: ");
   do{
      opc=getchar();
      }while(opc < '0' && opc >'5');
      clrscr();
      switch(opc){

      case '1':if(sw==0){
		  sw=1;
		  estudiantes.open("estud.dat",ios::in); //abriendo de lectura unicamente
		  //proceso de validacion de la existencia de un archivo
		  if (estudiantes.good()){
		      cout<<"archivo estud.dat existe-continua: ";
		      do{
			c=getchar();
		      }while (c!='S' && c!= 's' && c!='N' && c!='n');
		      if (c=='N' || c=='n'){
			  exit(1);
		      }
		  }
		  estudiantes.close();
		  estudiantes.open("estud.dat",ios::out);//abrir para empezar a escribir(borrar)
		  //creacion de archivo
		  cout<<"dar entrada: ";
		  cin.getline(salida,80);
		  estudiantes<<salida;
		  estudiantes.close();
		  //lectura del archivo de texto
		  estudiantes.open("estud.dat",ios::in);
		  if (estudiantes.fail()){
		      cout<<"no existe archivo";
		      exit(1);
		  }
		  while (!estudiantes.eof()) {
			 estudiantes>>salida;
			 cout<<salida<<"   " ;
		  }
		  estudiantes.close();
		  cout<<"\n\n\n ";
		  //adicionar mas texto al archivo
		  estudiantes.open ("estud.dat",ios::app);
		  cin.getline(salida,80);
		  n=strlen(salida);
		  for(i=0;i<=n;i++){
		      estudiantes.put(salida[i]);//otra forma de escribir en un archivo
		  }
		  estudiantes.close();
		  //lectura del archivo de texto
		  estudiantes.open ("estud.dat",ios::in);
		  while (!estudiantes.eof()){
		  estudiantes>>salida;
		  cout<<salida<<"  ";
	    }
	    getch();
	}
	break;
      case '2':if(sw==1){
		// abrir el archivo en forma output=salida=escribir.
		estudiantes.open("estud.dat",ios::in|ios::binary);
		//proceso de validacion de la existencia de un archivo
		if(estudiantes.good()){
		   cout<<"archivo estud.dat existe-continua(S/N): ";
		   do{
		     op=getchar();
		   }while (op!='S' && op!= 's' && op!='N' && op!='n');
		   if (op=='N' || op=='n'){
		       exit(1);
		   }
		}
		estudiantes.close();
		estudiantes.open("estud.dat",ios::out|ios::binary);
		//captura de datos a grabar en el archivo.
		clrscr();
		gotoxy(31,2);
		printf("MANEJO DE ARCHIVOS");
		gotoxy(10,4);
		printf("codigo   : ");
		gotoxy(10,6);
		printf("nombre   : ");
		gotoxy(10,8);
		printf("telefono : ");
		do{
		   gotoxy(23,4);
		   printf("                   ");
		   gotoxy(23,6);
		   printf("                                 ");
		   gotoxy(23,8);
		   printf("                   ");
		   gotoxy(23,4);
		   scanf("%f",&cod);
		   gotoxy(23,6);
		   cin.getline (nom,35);
		   gotoxy(23,8);
		   scanf("%f",&tel);
		   estudiante.codigo=cod;
		   n=strlen(nom);
		   for(i=0;i<=n;i++){
		      estudiante.nombre[i]=nom[i];
		   }
		   estudiante.telefono=tel;
		   // escritura del registro captura en el archivo.
		   estudiantes.write((char*) &estudiante,sizeof(estudiante));
		   gotoxy(10,16);
		   printf("Mas datos (S/N): ",k);
		   do{
		      op=getchar();
		   }while(op!='S' && op!= 's' && op!='N' && op!='n');
		   gotoxy(10,16);
		   printf("                              ");
		   }while(op=='S' || op=='s');
		   estudiantes.close();
	       }
	       else{
	       gotoxy(25,10);
	       printf("por favor crear archivo");
	       getch();
	       clrscr();
	       }
	       break;

	case '3':if(sw==1){
		    //abrir archivo para leer.
		    estudiantes.open("estud.dat",ios::in|ios::binary);
		    //validacion para archivo si ya existe.
		    if(estudiantes.fail()){
		       cout<<"archivo estud.dat no existe dar 0 y continua";
		       do{
			 op=getchar();
		       }while(op!='0');
		       exit(1);
		    }
		    clrscr();
		    gotoxy(31,2);
		    printf("MANEJO DE ARCHIVOS");
		    gotoxy(10,4);
		    printf(" codigo    nombre                telefono      ");
		    i=6;
		    while(!estudiantes.eof()){
		    // leer registro del archivo estud.dat.
			 estudiantes.read((char*) &estudiante,sizeof(estudiante));
			 if(estudiantes.eof()){
			    printf("\n\n FIN");
			    break;
			 }
			 gotoxy(9,i);
			 printf("%7.0f",estudiante.codigo);
			 gotoxy(21,i);
			 printf("%-35s",estudiante.nombre);
			 gotoxy(43,i);
			 printf("%7.0f",estudiante.telefono);
			 i++;
			 estudiante.codigo=0;
			 estudiante.telefono=0;
		    }
		    estudiantes.close();
		    getch();
		 }
		 else{
		 gotoxy(25,10);
		 printf("adicione registros por favor");
		 getch();
		 clrscr();
		 }
		 break;
       case '4':if(sw==1){
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
		      printf("digite el codigo a registro buscar: ");
		      scanf("%f",&cod);
		      estudiantes.read((char*) &estudiante,sizeof(estudiante));
		      while (!estudiantes.eof() && cod != estudiante.codigo);
		      lo=43;
		      z=-lo;
		      estudiantes.seekg(z,ios::cur);
		      printf("digite nuevo nombre: ");
		      cin.getline (nom,35);
		      n=strlen(nom);
		      for(i=0;i<=n;i++){
			  estudiante.nombre[i]=nom[i];
		      }
		      printf("digite nuevo telefono: ");
		      scanf("%f",&tel);
		      estudiante.telefono=tel;
		      // escritura del registro captura en el archivo.
		      estudiantes.write((char*) &estudiante,sizeof(estudiante));
		      gotoxy(10,16);
		      printf("Mas datos (S/N): ");
		      do{
			op=getchar();
		      }while(op!='S' && op!= 's' && op!='N' && op!='n');
		   } while(op=='S' || op=='s');
		   estudiantes.close();
		}
		else{
		    gotoxy(25,10);
		    printf("adicione registros por favor");
		    getch();
		    clrscr();
		}
		break;

	       }

	       }while(opc!='5');
		gotoxy(25,15);
		printf("FINALIZACION DEL PROGRAMA");
		getch();
	}


