/**********************************************************
 *  T E T R I S v1.0
 *  programming and graphics Andrew Deren
 *
 *  1 / 30 / 97
 **********************************************************/

//inlucde files
#include <stdio.h>
#include <allegro.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dir.h>
#include "c:\borlandc\bin\best\tdat.h"
//header file for data file created by grabber


//high score stucture name not implemented yet
struct HiScoreStruct {
	int score;
   char name[12];
};

//musics used from tdat.dat
int Music[3] = {MUSIC01, MUSIC02, MUSIC03};
int start_level;			//start from level selected under options
int start_blocks;			//number of initial rows on the map
int block[4][4];			//current block
int next_block;			//next block to be put
int map[10][20];			//map
int block_x, block_y;	//location of the block
int x_size, y_size;		//size of the block
volatile int timer;		//timer of the game
int current_block;		//current block type
int speed;					//speed of the game
int score, dels;			//game score and number of rows deleted
char text[256];			//some text used for using textout
struct HiScoreStruct HiScore;		//high score
int current_music;		//music currently played
BITMAP *map_buffer;		//double buffer for map displaying
DATAFILE *graphics;		//data file with graphics and sounds
BITMAP *temp_bitmap;		//temp 640x480 bitmap used by options and initial screens
int MusicVolume;			//current volume of the music
int SoundVolume;			//current volume of the sounds
bool soundOn;				//sounds on or not
bool musicOn;				//music on or not

//function prototypes
int Random(int x);
void IncrementTimer(...);
void DeleteRow(void);
int CanPut(void);
void NewGame(void);
void SetVolume(void);
void PlayGame(void);
void DrawVolume(int pos);
void SetVolume(void);
void Error(char *);
void InitGame(void);
void ClearBlock(void);
void GenerateBlock(int);
void DrawFrame(void);
void GenerateNew(void);
void PutBlock(void);
void RotateBlock(void);
void DrawMap(void);
void NewGame(void);
void DrawMenu(void);
void MainMenu(void);
void PlayGame(void);

//returns random number up to x-1
int Random(int x) {return random() % x;}

//increment game timer
void IncrementTimer(...)
{
 	timer++;
}
END_OF_FUNCTION(IncrementTimer);

//draw the options screen with cursor at pos
void DrawVolume(int pos)
{
 	clear(temp_bitmap);	//clear temp bitmap
   text_mode(-1);			//set transparent text mode
   //set drawing mode to pattern from datafile
   drawing_mode(DRAW_MODE_COPY_PATTERN, (BITMAP*)graphics[PATTERN].dat, 0, 0);
   //fill the temp buffer
   rectfill(temp_bitmap, 0, 0, 640, 480, 0);
   //put some text
   textout(temp_bitmap, font, "O P T I O N S", 140, 10, 36);
   textout(temp_bitmap, font, "Sound: ", 100, 50, 36);
   textout(temp_bitmap, font, "Music: ", 100, 100, 36);

   if (soundOn) textout(temp_bitmap, font, " On", 250, 50, 36);
   else textout(temp_bitmap, font, "Off", 250, 50, 36);
   if (musicOn) textout(temp_bitmap, font, " On", 250, 100, 36);
   else textout(temp_bitmap, font, "Off", 250, 100, 36);

	sprintf(text, "Sound Volume: %4d", SoundVolume);
   textout(temp_bitmap, font, text, 150, 130, 36);
   sprintf(text, "Music Volume: %4d", MusicVolume);
   textout(temp_bitmap, font, text, 150, 180, 36);
   sprintf(text, "Start Level: %4d", start_level);
   textout(temp_bitmap, font, text, 150, 230, 36);
   sprintf(text, "Start Blocks: %4d", start_blocks);
   textout(temp_bitmap, font, text, 150, 280, 36);
   //draw all the scorlbars
   for (int i=0; i<10; i++) {
		draw_sprite(temp_bitmap, (BITMAP*)graphics[BAR].dat, 106+i*25, 150);
      draw_sprite(temp_bitmap, (BITMAP*)graphics[BAR].dat, 106+i*25, 200);
      draw_sprite(temp_bitmap, (BITMAP*)graphics[BAR].dat, 106+i*25, 250);
      draw_sprite(temp_bitmap, (BITMAP*)graphics[BAR].dat, 106+i*25, 300);
   }
   draw_sprite(temp_bitmap, (BITMAP*)graphics[BAR2].dat, 100+SoundVolume, 150);
   draw_sprite(temp_bitmap, (BITMAP*)graphics[BAR2].dat, 100+MusicVolume, 200);
   draw_sprite(temp_bitmap, (BITMAP*)graphics[BAR2].dat, 100+start_level*25, 250);
   draw_sprite(temp_bitmap, (BITMAP*)graphics[BAR2].dat, 100+start_blocks*25, 300);
   draw_sprite(temp_bitmap, (BITMAP*)graphics[CURSOR].dat, 80, pos*50);
   textout(temp_bitmap, font, "Press arrow keys to change, ESC to exit", 100, 400, 36);
	blit(temp_bitmap, screen, 0, 0, 0, 0, 640, 480);
}

//options screen
void SetVolume(void)
{
 	int ch;
   int position = 1;
   DrawVolume(1);
	do {
     	if (keypressed()) {
        	ch = readkey();
         if ((ch >> 8) == KEY_DOWN) {position++; if (position == 7) position = 1;}
      	else if ((ch >> 8) == KEY_UP) {position--; if (position == 0) position = 6;}
         else if ( ((ch >> 8) == KEY_RIGHT) || ((ch >>8) == KEY_LEFT)){
      		if (position == 1) {if (soundOn) soundOn = FALSE; else soundOn = TRUE;}
         	else if (position == 2) {if (musicOn) musicOn = FALSE; else musicOn = TRUE;}
            else if (position == 3) {
              	if ((ch >> 8) == KEY_RIGHT) {
                 	SoundVolume+= 25;
                  if (SoundVolume > 255) SoundVolume=255;
               }
            	else {SoundVolume-=25;if (SoundVolume < 0) SoundVolume=0;}
            }
            else if (position == 4) {
              	if ((ch >> 8) == KEY_RIGHT) {
                 	MusicVolume+= 25;
                  if (MusicVolume > 255) MusicVolume=255;
               }
            	else {MusicVolume-=25; if (MusicVolume < 0) MusicVolume = 0;}
            }
         	else if (position == 5) {
               if ((ch >> 8) == KEY_RIGHT) {
                 	start_level++;
                  if (start_level > 10) start_level = 10;
               }
            	else {start_level--; if (start_level < 0) start_level = 0;}
            }
         	else if ( position == 6) {
              	if ((ch >> 8) == KEY_RIGHT) {
                 	start_blocks++;
                  if (start_blocks > 10) start_blocks = 10;
                }
                else {start_blocks--; if (start_blocks < 0) start_blocks = 0;}
            }
         } //end key up or down
      	else if ((ch >> 8) == KEY_ESC) break;
         DrawVolume(position);
      }//end keypressed;
   }while (1==1);
	set_volume(SoundVolume, MusicVolume);
	clear(screen);
}

void Error(char *string)
{
 	allegro_exit();
 	printf("Error: %s\n", string);
   exit(1);
}

void InitGame(void)
{
  	allegro_init();  			//initialize allegro
   install_keyboard();  	//install keyboard handler
   install_timer();			//install timer
   set_gfx_mode(GFX_AUTODETECT, 640, 480, 0, 0);	//set graphics mode to 640x480x256
	srandom((int)time(NULL));
   if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
		Error("Error initializing sound.");
   if (!file_exists("tdat.dat", FA_RDONLY | FA_ARCH, NULL))
       Error("Cannot find tdat.dat file.");
	graphics = load_datafile("tdat.dat");	//load graphics
  	map_buffer = create_bitmap(200, 400);	//create double buffer
   temp_bitmap = create_bitmap(640, 480);
   timer = 0;
   LOCK_FUNCTION(IncrementTimer);
   LOCK_VARIABLE(timer);
   install_int(IncrementTimer, 20);
   speed = 15;
   set_clip(map_buffer, 0, 0, 200, 400);
   score = 0;
   dels = 1;
  	FILE *file = fopen("tetris.hsc", "rb");
	if (file) {
   	fread(&HiScore, sizeof(struct HiScoreStruct), 1, file);
      fclose(file);
   }
  	else {
     	HiScore.score = 0;
      strcpy(HiScore.name, "Unknown");
   }
	font = (FONT*)graphics[TECH_FONT].dat;
   soundOn = TRUE;
   musicOn = TRUE;
   SoundVolume = 180;
   MusicVolume = 180;
   set_volume(SoundVolume, MusicVolume);
   start_level = 0;
   start_blocks = 0;
   current_music = Random(3);
   set_pallete(black_pallete);
}

void DrawFrame(void)
{
 	draw_sprite(screen, (BITMAP*)graphics[WALL03].dat, 80, 20);
   draw_sprite(screen, (BITMAP*)graphics[WALL04].dat, 300, 20);
   draw_sprite(screen, (BITMAP*)graphics[WALL05].dat, 80, 440);
   draw_sprite(screen, (BITMAP*)graphics[WALL06].dat, 300, 440);

   draw_sprite(screen, (BITMAP*)graphics[WALL03].dat, 340, 20);
   draw_sprite(screen, (BITMAP*)graphics[WALL04].dat, 580, 20);
   draw_sprite(screen, (BITMAP*)graphics[WALL05].dat, 340, 100);
   draw_sprite(screen, (BITMAP*)graphics[WALL06].dat, 580, 100);

   draw_sprite(screen, (BITMAP*)graphics[WALL03].dat, 340, 140);
   draw_sprite(screen, (BITMAP*)graphics[WALL04].dat, 440, 140);
   draw_sprite(screen, (BITMAP*)graphics[WALL05].dat, 340, 200);
   draw_sprite(screen, (BITMAP*)graphics[WALL06].dat, 440, 200);

   for (int i=0; i<11; i++) {
      draw_sprite(screen, (BITMAP*)graphics[WALL01].dat, 360+i*20, 20);
      draw_sprite(screen, (BITMAP*)graphics[WALL01].dat, 360+i*20, 100);
   }
	for (int i=0; i<3; i++) {
      draw_sprite(screen, (BITMAP*)graphics[WALL02].dat, 340, 40+i*20);
      draw_sprite(screen, (BITMAP*)graphics[WALL02].dat, 580, 40+i*20);

	}
	for (int i=0; i<4; i++) {
      draw_sprite(screen, (BITMAP*)graphics[WALL01].dat, 360+i*20, 140);
      draw_sprite(screen, (BITMAP*)graphics[WALL01].dat, 360+i*20, 200);
   }
   for (int i=0; i<10; i++) {
		draw_sprite(screen, (BITMAP*)graphics[WALL01].dat, 100+i*20, 20);
      draw_sprite(screen, (BITMAP*)graphics[WALL01].dat, 100+i*20, 440);
   }
	for (int i=0; i<2; i++) {
      draw_sprite(screen, (BITMAP*)graphics[WALL02].dat, 340, 160+i*20);
      draw_sprite(screen, (BITMAP*)graphics[WALL02].dat, 440, 160+i*20);
   }
	for (int i=0; i<20; i++) {
 		draw_sprite(screen, (BITMAP*)graphics[WALL02].dat, 80, 40+i*20);
      draw_sprite(screen, (BITMAP*)graphics[WALL02].dat, 300, 40+i*20);
   }
}

void ClearBlock(void)
{
 	for (int i=0; i<4; i++)  for (int j=0; j<4; j++) block[i][j] = 0;
}

void GenerateBlock(int kind)
{
 	ClearBlock();
	switch (kind) {
	case  1: block[1][0] = block[2][0] = block[0][1] = block[1][1] = 1; break;
   case 11: block[0][0] = block[0][1] = block[1][1] = block[1][2] = 1; break;
   case 21: block[1][0] = block[2][0] = block[0][1] = block[1][1] = 1; break;
   case 31: block[0][0] = block[0][1] = block[1][1] = block[1][2] = 1; break;

   case  2:	block[0][0] = block[1][0] = block[1][1] = block[2][1] = 1; break;
	case 12:	block[1][0] = block[1][1] = block[0][1] = block[0][2] = 1; break;
	case 22:	block[0][0] = block[1][0] = block[1][1] = block[2][1] = 1; break;
	case 32:	block[1][0] = block[1][1] = block[0][1] = block[0][2] = 1; break;

	case  3: block[0][0] = block[0][1] = block[1][0] = block[1][1] = 1; break;
	case 13: block[0][0] = block[0][1] = block[1][0] = block[1][1] = 1; break;
	case 23: block[0][0] = block[0][1] = block[1][0] = block[1][1] = 1; break;
	case 33: block[0][0] = block[0][1] = block[1][0] = block[1][1] = 1; break;

	case  4: block[1][0] = block[0][1] = block[1][1] = block[2][1] = 1; break;
	case 14: block[0][0] = block[0][1] = block[0][2] = block[1][1] = 1; break;
   case 24: block[0][0] = block[1][0] = block[2][0] = block[1][1] = 1; break;
   case 34: block[0][1] = block[1][0] = block[1][1] = block[1][2] = 1; break;

   case  5: block[2][0] = block[0][1] = block[1][1] = block[2][1] = 1; break;
   case 15: block[0][0] = block[0][1] = block[0][2] = block[1][2] = 1; break;
   case 25: block[0][0] = block[1][0] = block[2][0] = block[0][1] = 1; break;
	case 35: block[0][0] = block[1][0] = block[1][1] = block[1][2] = 1; break;

	case  6: block[0][0] = block[0][1] = block[1][1] = block[2][1] = 1; break;
	case 16: block[0][0] = block[1][0] = block[0][1] = block[0][2] = 1; break;
   case 26: block[0][0] = block[1][0] = block[2][0] = block[2][1] = 1; break;
   case 36: block[1][0] = block[1][1] = block[1][2] = block[0][2] = 1; break;

   case  7: block[0][0] = block[1][0] = block[2][0] = block[3][0] = 1; break;
	case 17: block[0][0] = block[0][1] = block[0][2] = block[0][3] = 1; break;
   case 27: block[0][0] = block[1][0] = block[2][0] = block[3][0] = 1; break;
	case 37: block[0][0] = block[0][1] = block[0][2] = block[0][3] = 1; break;
	default: Error("Unknown element to be generated."); break;
	}

   if ((kind == 7) || (kind == 27)) {x_size = 4; y_size = 1; }
	else if ((kind == 17) || (kind == 37)) {x_size = 1; y_size = 4;}
	else if (kind % 10 == 3) {x_size = 2; y_size = 2; }
	else if ((kind / 10 == 0) || (kind / 10 == 2)) {x_size = 3; y_size = 2;}
	else if ((kind / 10 == 1) || (kind / 10 == 3)) {x_size = 2; y_size = 3;}
   current_block = kind;
}

void GenerateNew(void)
{
	int temp = next_block;
   next_block = Random(7)+1;
   GenerateBlock(next_block);
	for (int i=0; i<4; i++) {
      for (int j=0; j<2; j++) {
         if (block[i][j] == 1)
           	draw_sprite(screen, (BITMAP*)graphics[BLOCK].dat, 360+i*20, 160+j*20);
			else draw_sprite(screen, (BITMAP*)graphics[EMPTY].dat, 360+i*20, 160+j*20);
		}
  	}
	GenerateBlock(temp);
   block_x = 3;
   block_y = 0;
   if (!CanPut()) {
      text_mode(-1);
      textout_centre(screen, font, "G A M E", 202, 152, 42);
		textout_centre(screen, font, "G A M E", 200, 150, 15);
      textout_centre(screen, font, "O V E R", 202, 202, 42);
      textout_centre(screen, font, "O V E R", 200, 200, 15);
		textout_centre(screen, (FONT*)graphics[GAME_FONT].dat, "Press Enter to", 202, 252, 42);
		textout_centre(screen, (FONT*)graphics[GAME_FONT].dat, "to start a new game", 202, 277, 42);
      textout_centre(screen, (FONT*)graphics[GAME_FONT].dat, "Press Enter to", 200, 250, 15);
      textout_centre(screen, (FONT*)graphics[GAME_FONT].dat, "to start a new game", 200, 275, 15);
      sprintf(text, "%3d", score);
      textout_centre(screen, (FONT*)graphics[GAME_FONT].dat, text, 202, 302, 42);
      textout_centre(screen, (FONT*)graphics[GAME_FONT].dat, text, 200, 300, 15);
		clear_keybuf();
		do {
        	if (key[KEY_ENTER]) break;
      } while (1==1);
   	clear_keybuf();
      NewGame();
   }
}

void PutBlock(void)
{
   for (int i=0; i<4; i++) {
      for (int j=0; j<4; j++) {
         if (block[i][j] == 1)
	         map[block_x+i][block_y+j] = block[i][j];
      }
   }
	if (soundOn) play_sample((SAMPLE*)graphics[MOVE_SOUND].dat, SoundVolume, 125, 1000, FALSE);
	DeleteRow();
}

void RotateBlock(void)
{
 	int old_block = current_block;
 	current_block += 10;
   if (current_block > 40) current_block -= 40;
   GenerateBlock(current_block);
   if (!CanPut())  {
     	current_block = old_block;
      GenerateBlock(current_block);
   }
}


int CanPut(void)
{
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (block[i][j] == 1) {
           if (block_x + i > 9) return FALSE;
           if (block_x + i < 0) return FALSE;
           if (block_y + j > 19) return FALSE;
           if (map[block_x+i][block_y+j] == 1) return FALSE;
         }
		}
   }
	return TRUE;
}


void DrawMap(void)
{
 	clear(map_buffer);
	for (int i=0; i<10; i++) {
 		for (int j=0; j<20; j++) {
         if (map[i][j] == 1)
           	draw_sprite(map_buffer, (BITMAP*)graphics[BLOCK].dat, i*20, j*20);
      }
   }
	for (int i=0; i<4; i++) {
      for (int j=0; j<4; j++) {
         if (block[i][j] == 1)
           	draw_sprite(map_buffer, (BITMAP*)graphics[BLOCK].dat, block_x*20+i*20, block_y*20+j*20);

  	   }
   }
	blit(map_buffer, screen, 0, 0, 100, 40, 200, 400);
   text_mode(0);
   sprintf(text, "%7d", score);
   textout(screen, font, text, 570-text_length(font, text), 50, 15);
   sprintf(text, "%7d", dels / 10);
   textout(screen, font, text, 570-text_length(font, text), 65, 15);
}

void DeleteRow(void)
{
 	int sum, i, j, del = 0;
	for (i=19; i>=0; i--) {
      sum = 0;
      for (j=0; j<10; j++) sum += map[j][i];
		if (sum == 10) {
        	for (j=i; j>=1; j--) for (int k=0; k<10; k++) map[k][j] = map[k][j-1];
         i += 2;
         del++;
		}
   }
	if (del > 0)
     	if (soundOn)
        	play_sample((SAMPLE*)graphics[DELETE_SOUND].dat, SoundVolume, 125, 1000, FALSE);
   dels += del;
   if (del > 0) score += (100*del)+((del-1)*25)+(dels/10)*25;
   speed = 25-(dels/10)*2;
   if (speed < 2) speed = 2;
}

void NewGame(void)
{
 	if (score > HiScore.score) HiScore.score = score;
 	for (int i=0; i<20; i++)
      for (int j=0; j<10; j++) map[j][i] = 0;
   score = 0;
   next_block = Random(7)+1;
   GenerateNew();
   DrawMap();
   dels = start_level*10;
   speed = 25-(dels/10)*2;
   text_mode(0);
   sprintf(text, "Score:");
   textout(screen, font, text, 365, 50, 15);
   sprintf(text, "Level:");
   textout(screen, font, text, 365, 65, 15);
   sprintf(text, "High Score: ");
   textout(screen, font, text, 365, 80, 15);
   sprintf(text, "%7d", HiScore.score);
   textout(screen, font, text, 570-text_length(font, text), 80, 15);
   for (int i=0; i<start_blocks; i++) {
      for (int j=0; j<10; j++) {
         if (Random(2)) map[j][19-i] = 1;
      }
   }
	timer = 0;
}

void DrawMenu(int pos)
{
 	text_mode(-1);
	clear(temp_bitmap);
   drawing_mode(DRAW_MODE_COPY_PATTERN, (BITMAP*)graphics[PATTERN].dat, 0, 0);
   rectfill(temp_bitmap, 0, 0, 640, 480, 0);
   draw_sprite(temp_bitmap, (BITMAP*)graphics[TITLE].dat, 170, 10);
   textout(temp_bitmap, font, "N E W  G A M E", 100, 200, 36);
   textout(temp_bitmap, font, "N E W  G A M E", 101, 201, 1);
   textout(temp_bitmap, font, "O P T I O N S", 100, 250, 36);
   textout(temp_bitmap, font, "O P T I O N S", 101, 251, 1);
   textout(temp_bitmap, font, "E X I T", 100, 300, 36);
   textout(temp_bitmap, font, "E X I T", 101, 301, 1);
   draw_sprite(temp_bitmap, (BITMAP*)graphics[CURSOR].dat, 80, (pos-1)*50+200);
	blit(temp_bitmap, screen, 0, 0, 0, 0, 640, 480);
}

void MainMenu()
{
 	int ch;
   int pos = 1;
 	DrawMenu(1);
   fade_in((RGB*)graphics[GAME_PALLETE].dat, 2);             //fade in slowly
   do {
     	if (keypressed()) {
        	ch = readkey();
         if ((ch >> 8) == KEY_UP) {pos--; if (pos == 0) pos = 3;}
         else if ((ch >>8) == KEY_DOWN) {pos++; if (pos==4) pos=1;}
         else if ((ch >> 8) == KEY_ENTER) {
           	if (pos == 1) {
              	PlayGame();
            }
            else if (pos == 2)
              	SetVolume();
            else if (pos == 3)
              	break;
         }
      	else if ((ch >> 8) == KEY_ESC) break;
      	DrawMenu(pos);
      } // end if keypressed
   } while (1==1);
	fade_out(1);
   if (musicOn) stop_midi();
}

void PlayGame(void)
{
 	int ch;
   rectfill(screen, 0, 0, 640, 480, 0);
   DrawFrame();
   drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
   rectfill(screen, 360, 40, 580, 100, 0);
   current_music = Random(3);
   if (musicOn) play_midi((MIDI*)graphics[Music[current_music]].dat, TRUE);
   draw_sprite(screen, (BITMAP*)graphics[TETRIS].dat, 340, 300);
   NewGame();
   while (1==1) {
     	if (keypressed()) {
         ch = readkey();
	     	if ((ch >> 8) == KEY_LEFT) {block_x--; if (!CanPut()) block_x++;
         }
			if ((ch >> 8) == KEY_RIGHT) {block_x++; if (!CanPut()) block_x--;
			}
	      if ((ch >> 8) == KEY_UP)   RotateBlock();
	      if ((ch >> 8) == KEY_DOWN) {
           	while (CanPut()) {DrawMap();	block_y++;
            };
         	block_y--;
         }
      	if ((ch >> 8) == KEY_F2) NewGame();
         else if ((ch >> 8) == KEY_F5) {
            if (musicOn) {
              	stop_midi();
               current_music++;
               if (current_music > 2) current_music = 0;
               play_midi((MIDI*)graphics[Music[current_music]].dat, TRUE);
            }
         }
	   	else if ((ch >> 8) == KEY_ESC) {
           text_mode(-1);
           textout(screen, font, "Do you really want", 125, 200, 15);
           textout(screen, font, "to quit? (Y/N)", 125, 225, 15);
           if ((ch = readkey()) >> 8 == KEY_Y)  break;
         }
      	else if ((ch >> 8) == KEY_F12){
           	BITMAP* bmp;
            bmp = create_sub_bitmap(screen, 0, 0, SCREEN_W, SCREEN_H);
            save_pcx("tetdat.pcx", bmp, (RGB*)graphics[GAME_PALLETE].dat);
            destroy_bitmap(bmp);
         }
			clear_keybuf();
      }
		if (timer > speed) {
	   	block_y++;
         if (!CanPut()) {block_y--;  PutBlock();  GenerateNew();
         }
      	timer = 0;
      }
      if (!CanPut()) {PutBlock(); GenerateNew();
      }
      DrawMap();
   }
	stop_midi();
}


main()
{
 	InitGame();
   MainMenu();
	allegro_exit();
   FILE *file;
   file = fopen("tetris.hsc", "wt");
   if (file) {
     	fwrite(&HiScore, sizeof(struct HiScoreStruct), 1, file);
      fclose(file);
   }
	printf("                             Ader Software 1997                        \n");
   printf("                             T E T R I S   v1.0                        \n");
   printf(" --------------------------------------------------------------------- \n");
   printf("                         Programing and Graphics by                    \n");
   printf("                                  MAC                        \n");
   printf("                             aderen@eecs.uic.edu                       \n");
   printf("           http://www.eecs.uic.edu/~aderen/ader/main.html         \n");
   printf(" --------------------------------------------------------------------- \n");
   printf("                            Special Thanks To:                         \n");
   printf("                      DJ Delorie - for making DJGPP                    \n");
   printf("           Shawn Hargreaves - for making allegro game library          \n");
   printf("              and all the other people who contributed to              \n");
   printf("                 DJGPP development tools and utilities.                \n");
   printf(" --------------------------------------------------------------------- \n");
   printf("\n\n\n");
}


