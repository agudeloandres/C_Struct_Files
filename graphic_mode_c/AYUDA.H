// *******************************************************************
// **      FUNCION QUE IMPRIME AYUDA, CONCEPTOS E INTRODUCCION      **
// *******************************************************************

void MostrarArchivo(char *FILE,int Color_Fondo, int Color_Titulo, int Color_Letra)
                    { int x=12,y=42,i,longitud,j;
                         char variable[80];
			 ifstream flujod(FILE,ios::binary);  
			 if(!flujod)
                         { cout <<"ERROR AL INTENTAR ABRIR EL ARCHIVO";
                           exit(1);
                         }
                         setfillstyle(SOLID_FILL,Color_Fondo);
                         bar(5,37,635,442);
                         setcolor(Color_Titulo);

                         while(!(flujod.eof()))
                         { if(!(flujod.eof()))
                           { flujod>>variable;
                             longitud=strlen(variable);
                             for(i=0;i<=longitud;i++)
                             if(variable[i]=='$') variable[i]=' ';
                             if(x>12)
                               { y=y+12; x=12;}
                                 if(y>430)
                                 { while (y!=13&&y!=27)
                                       y=getch();
                                   if(y==27)
                                       break;
                                    setfillstyle(SOLID_FILL,Color_Fondo);
                                    bar(5,37,635,442);
                                   y=42; 
                                  }
                                outtextxy(x,y,variable);     
                                x++;
                                setcolor (Color_Letra);
                                longitud=0;
                                }
                         }
                            if (y!=27)
                            {   while (y!=13&&y!=27)
                                   y=getch();
                                flujod.close();
                            }

                        }
