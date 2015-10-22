#include"stdio.h"
#include"dos.h"
#include"conio.h"
#include"f:\binary.h"
#include"f:\enhebrado.h"
 void  main()
{
   ne *head,*q,*p,*avail;
    char opcion,opcion1;
    float inf;
    unsigned int sw=0;
     do{
       menu ();
       do{
          opcion=getchar();

        }while(opcion<'0' && opcion>'5');
       switch (opcion){
	  case '1':
		   if (sw==0){
		       p=new ne;
		       head=p;
		       head->llink=head;
		       head->ltag=0;
		       head->rlink=head;
		       head->rtag=0;
		       avail=0;
		       sw=1;
		       clrscr();
		       gotoxy(31,12);
		       printf("ARBOL INICIALIZADO");
		       validar();
		   }
		   else{
			clrscr();
			gotoxy(32.5,12);
			printf("ARBOL YA CREADO");
			validar();
		   }
	  break;
	  case '2':
		   if (sw==0){
		      control_sw();
		    }
		    else{
			 clrscr();
			 gotoxy(24,12);
			 printf("DIGITE LA INFORMACION = ");
			 gotoxy(47,12);
			 leer_info(&inf);
			 inclusion_nodo_enhebrado(&head,inf,&p);
		    }
	  break;
	  case '3':
		   if (sw==0){
		    control_sw();
		    }
		    else{
			 if(head->ltag==1){
			 clrscr();
			 gotoxy(24,2);
			 printf("RECORRIDO DE UN ARBOL EN INORDEN\n");
			 recorrido_inorden(head);
			 validar();
			 }
		      else{
		       clrscr();
		       gotoxy(34.5,6);
		       printf("ARBOL VACIO");
		       validar();
		      }
	  }

	  break;
	  case '4':if(sw==0){
		     control_sw();
		    }
		    else{
		      if(head->ltag==1){
			 clrscr();
			 gotoxy(24,12);
			 printf("DIGITE LA INFORMACION A CANCELAR = ");
			 leer_info(&inf);
			 clrscr();
			 remover_nodo_del_arbolne(&head,inf,&avail);
		      }
		      else{
		       clrscr();
		       gotoxy(34.5,6);
		       printf("ARBOL VACIO");
		       validar();
		      }
		    }
	  break;

	 default:break;
       }
    }while(opcion!='5');
   clrscr();
    gotoxy(30,12);
    printf("FIN DE PROCESO");
}
