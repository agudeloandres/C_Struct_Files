# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <conio.h>
# include <dos.h>


struct card {
      char *face;
      char *suit;
      };
  typedef struct card tarjeta;
  void filldeck (tarjeta*,char*[],char*[]);
  void shuffle (tarjeta*);
  void deal (tarjeta*);


  main()
  {
  clrscr();
  tarjeta deck[52];
  char *carta[] = {"Ace","Deuce","Three","Four","Five","Six","Seven",
  "Eigth","Nine","Ten","Jack","Queen","King"};
  char *pintas[] ={"Hearts","Diamonds","Clubs","Spades"};
  gotoxy(15,5);printf("Repartiendo la baraja randomizada\n");
  printf("\n");

  srand(clock());
  delay(700);
  filldeck(deck,carta,pintas);
    delay(700);
  shuffle(deck);
    delay(700);
  deal(deck);

  getch();
  }


  void filldeck (tarjeta*wdeck,char*wface[],char*wsuit[])
  {
  int i;
  for(i=0; i<=51; i++){
   wdeck[i].face=wface[i%13];
   wdeck[i].suit=wsuit[i%4];
   }
 }
 void shuffle (tarjeta*wdeck)
 {
 int i,j;
 tarjeta temp;

 for(i=0; i<=51; i++){
     j = rand()%52;

     if(i!=j){
     temp = wdeck[i];
     wdeck[i]=wdeck[j];
     wdeck[j]=temp;
     }
   }
  }
  void deal(tarjeta*wdeck)
  {
  int i;
    for(i=0; i<=51; i++){
      printf("%s%s",wdeck[i].face,wdeck[i].suit);
      delay(50);
      (i+1)%2?putchar('\t'):putchar('\n');

      }
    }