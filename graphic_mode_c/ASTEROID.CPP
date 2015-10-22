#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>


typedef struct
  {
  float x, y;
  } POINT;


typedef struct
  {
  int    NumPoints;
  POINT  Point[ 3 ];   } SHAPE;             


typedef struct
  {
  POINT  Loc;
  int    ViewAngle;
  POINT  Direction;
  SHAPE  Shape;
  SHAPE  Screen;
  } OBJECT;


struct
  {
  OBJECT Ship;
  } g;



void TranslatePoint( POINT *Dest, POINT *Src, int Angle )
  {
  double Radians;

  Radians = Angle * 0.01745;

  Dest->x = Src->x * cos( Radians ) - Src->y * sin( Radians );
  Dest->y = Src->x * sin( Radians ) + Src->y * cos( Radians );
  }



void TranslateObject( OBJECT *Object )
  {
  int i;

  for( i = 0; i < Object->Shape.NumPoints; i++ )
    {
    TranslatePoint( &Object->Screen.Point[ i ], &Object->Shape.Point[ i ], Object->ViewAngle );

    Object->Screen.Point[ i ].x += Object->Loc.x;
    Object->Screen.Point[ i ].y += Object->Loc.y;
    }
  }



void DrawObject( OBJECT *Object )
  {
  int i;

  for( i = 1; i < Object->Shape.NumPoints; i++ )
    {
    line( Object->Screen.Point[ i - 1 ].x, Object->Screen.Point[ i - 1 ].y,
	  Object->Screen.Point[ i     ].x, Object->Screen.Point[ i     ].y );
    }

  line( Object->Screen.Point[ i - 1 ].x, Object->Screen.Point[ i - 1 ].y,
	Object->Screen.Point[ 0     ].x, Object->Screen.Point[ 0     ].y );
  }



void MoveObject( OBJECT *Object )
  {
  Object->Loc.x += Object->Direction.x;
  Object->Loc.y += Object->Direction.y;


  if( Object->Loc.x < 0 )    Object->Loc.x = Object->Loc.x + 640;
  if( Object->Loc.x > 639 )  Object->Loc.x = Object->Loc.x - 640;
  if( Object->Loc.y < 0 )    Object->Loc.y = Object->Loc.y + 480;
  if( Object->Loc.y > 479 )  Object->Loc.y = Object->Loc.y - 480;
  }


void SyncToVerticalRetrace( void )
  {

  while( inp( 0x3da ) & 8 )
    ;


  while( !(inp( 0x3da ) & 8) )
    ;
  }


#define ROTATE_STEP  3       // Number of degrees to rotate
#define SPEED        0.12    // Speed control
#define FRICTION     0.995   // Speed reduction per frame

void Supervisor( void )
  {
  unsigned short KeyboardStatus;
  int c = 0, EraseFlag = 1, Color = WHITE;

  while( c != 'q' && c != 'Q' )
    {
    TranslateObject( &g.Ship );

    DrawObject( &g.Ship );   // Draw the ship

    // Get the keyboard status bits from the BIOS data area

    KeyboardStatus = *(unsigned short far *)MK_FP( 0x40, 0x17 );

    MoveObject( &g.Ship );

    // Simulate friction.

    g.Ship.Direction.x *= FRICTION;
    g.Ship.Direction.y *= FRICTION;

    // If a real keystroke is waiting get it

    if( kbhit() )
      {
      c = getch();

      if( c == 'e' || c == 'E' )
        {
        EraseFlag = !EraseFlag;    // Toggle erase flag
        }
      }

    if( KeyboardStatus & 0x0002 )    // left shift, rotate left
      {
      g.Ship.ViewAngle -= ROTATE_STEP;
      if( g.Ship.ViewAngle < 0 )  g.Ship.ViewAngle = 360 - ROTATE_STEP;
      }

    if( KeyboardStatus & 0x0001 )    // right shift, rotate right
      {
      g.Ship.ViewAngle += ROTATE_STEP;
      if( g.Ship.ViewAngle > 359 )  g.Ship.ViewAngle = 0 + ROTATE_STEP;
      }

    if( KeyboardStatus & 0x4000 )    // shift-lock, fire
      {
      // Not supported yet.
      }

    if( KeyboardStatus & 0x0008 )    // alt, thrust
      {
      double Radians;

      Radians = g.Ship.ViewAngle * 0.01745;

      g.Ship.Direction.x += sin( Radians ) * SPEED;
      g.Ship.Direction.y -= cos( Radians ) * SPEED;
      }

    SyncToVerticalRetrace();     // Pause until vertical retrace

    if( EraseFlag )  DrawObject( &g.Ship );    // Erase the ship

    if( c == 'c' || c == 'C' )   // Change color
      {
      Color ^= (WHITE ^ LIGHTGREEN);
      setcolor( Color );
      c = 0;
      }
    }
  }


// Initialization code.

void Init( void )
  {
  int GraphicsDriver = VGA;     // assume VGA graphics card
  int GraphicsMode = VGAHI;     // use VGA 640x480 16 color mode

  initgraph( &GraphicsDriver, &GraphicsMode, NULL );
  setwritemode( XOR_PUT );

  g.Ship.Shape.NumPoints = 3;

  g.Ship.Shape.Point[ 0 ].x =   0;
  g.Ship.Shape.Point[ 0 ].y = -16;
  g.Ship.Shape.Point[ 1 ].x =  -8;
  g.Ship.Shape.Point[ 1 ].y =  +8;
  g.Ship.Shape.Point[ 2 ].x =  +8;
  g.Ship.Shape.Point[ 2 ].y =  +8;

  g.Ship.ViewAngle = 0;

  g.Ship.Loc.x = 320;
  g.Ship.Loc.y = 240;

  g.Ship.Direction.x = 0;
  g.Ship.Direction.y = 0;
  }


void Cleanup( void )
  {
  closegraph();
  }


void main( int Argc, char *Argv[] )
  {
  puts( "\n\n" );
  puts( "Asteroids.  October 1994, \"What's the Code?\"\n" );
  puts( "Left shift:   Rotate left" );
  puts( "Right shift:  Rotate right" );
  puts( "Alt:          Thrust" );
  puts( "E:            Toggle 'erase' mode" );
  puts( "C:            Toggle color between white and green" );
  puts( "Q:            Quit\n" );

  puts( "Press any key to begin..." );

  getch();

  Init();

  Supervisor();

  Cleanup();
  }
