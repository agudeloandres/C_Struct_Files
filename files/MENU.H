 //************************ FUNCIONES DE MENU*****************************//
#define CPR(x) cprintf("%s",x)

//********************************
void piso_color(int piso,int color){
   textbackground(piso);
   textcolor(color);
   }

//********************************
void marco (int a,int b,int c, int d){
#define arrizq 201
#define arrder 187
#define abajizq 200
#define abajder 188
#define vert 186
#define horiz 205
#define PR(x) cprintf("%c",x)
 int i;
 window(1,1,80,25);       //Activa la ventana mayor para dibujar el marco
 gotoxy(a-1,b-1);
 PR(arrizq);
 for (i=a;i<=c;i++)
     PR(horiz);
 PR(arrder);
 for(i=b;i<=d;i++){
   gotoxy(c+1,i);
   PR(vert);
 }
 gotoxy(a-1,d+1);
 PR(abajizq);
 for(i=a;i<=c;i++)
   PR(horiz);
   PR(abajder);
   for(i=b;i<=d;i++){
    gotoxy(a-1,i);
    PR(vert);
    }
    window(a,b,c,d);             //Activa ventana dentro del marco
  }

//**********************

void persiana(int c){
 extern char *op[];
 switch(c){
	     case 80:switch(wherey()){
			 case 7:
				piso_color(BLACK,WHITE);
				CPR(op[0]);
				piso_color(WHITE,BLACK);
				gotoxy(20,wherey()+2);
				CPR(op[1]);
				gotoxy(20,wherey());
				break;

			case 9:
				piso_color(BLACK,WHITE);
				CPR(op[1]);
				piso_color(WHITE,BLACK);
				gotoxy(20,wherey()+2);
				CPR(op[2]);
				gotoxy(20,wherey());
				break;

			case 11:
				piso_color(BLACK,WHITE);
				CPR(op[2]);
				piso_color(WHITE,BLACK);
				gotoxy(20,wherey()+2);
				CPR(op[3]);
				gotoxy(20,wherey());
				break;

			case 13:
				piso_color(BLACK,WHITE);
				CPR(op[3]);
				piso_color(WHITE,BLACK);
				gotoxy(20,wherey()+2);
				CPR(op[4]);
				gotoxy(20,wherey());
				break;
			case 15:

				piso_color(BLACK,WHITE);
				CPR(op[4]);
				piso_color(WHITE,BLACK);
				gotoxy(20,7);
				CPR(op[0]);
				gotoxy(20,wherey());
				break;

			} //FIN SWITCH WHEREY()

		     break;


	     case 72:switch(wherey()){
			case 7:
			      piso_color(BLACK,WHITE);
			      CPR(op[0]);
			      piso_color(WHITE,BLACK);
			      gotoxy(20,15);
			      CPR(op[4]);
			      gotoxy(20,wherey());
			      break;
		       case 9:
			      piso_color(BLACK,WHITE);
			      CPR(op[1]);
			      piso_color(WHITE,BLACK);
			      gotoxy (20,wherey()-2);
			      CPR(op[0]);
			      gotoxy(20,wherey());
			      break;
		      case 11:
			      piso_color(BLACK,WHITE);
			      CPR(op[2]);
			      piso_color(WHITE,BLACK);
			      gotoxy (20,wherey()-2);
			      CPR(op[1]);
			      gotoxy(20,wherey());
			      break;
		      case 13:
			      piso_color(BLACK,WHITE);
			      CPR(op[3]);
			      piso_color(WHITE,BLACK);
			      gotoxy (20,wherey()-2);
			      CPR(op[2]);
			      gotoxy(20,wherey());
			      break;
		      case 15 :
			      piso_color(BLACK,WHITE);
			      CPR(op[4]);
			      piso_color(WHITE,BLACK);
			      gotoxy (20,wherey()-2);
			      CPR(op[3]);
			      gotoxy(20,wherey());
			      break;

			}//FIN SWITCH WHEREY()
		      break;

	      default:break;


     } //FIN SWITCH PRINCIPAL
 }