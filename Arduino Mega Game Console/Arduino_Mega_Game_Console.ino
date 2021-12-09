#include <SPFD5408_Adafruit_GFX.h>
#include <SPFD5408_Adafruit_TFTLCD.h>
#include <SPI.h>
#include <SD.h>

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0

#define SD_CS 53//For Arduino Mega

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, A4);

#define tileSize 40
#define centreX 100
#define centreY 80

//WALKBA~1.BMP  WALKBA~2.BMP  WALKBA~3.BMP  WALKBA~4.BMP
//WALKFR~1.BMP  WALKFR~2.BMP  WALKFR~3.BMP  WALKFR~4.BMP
//WALKLE~1.BMP  WALKLE~2.BMP  WALKLE~3.BMP  WALKLE~4.BMP
//WALKRI~1.BMP  WALKRI~2.BMP  WALKRI~3.BMP  WALKRI~4.BMP
//
//RUNBAC~1.BMP  RUNBAC~2.BMP  RUNBAC~3.BMP  RUNBAC~4.BMP
//RUNFRO~1.BMP  RUNFRO~2.BMP  RUNFRO~3.BMP  RUNFRO~4.BMP
//RUNLEF~1.BMP  RUNLEF~2.BMP  RUNLEF~3.BMP  RUNLEF~4.BMP
//RUNRIG~1.BMP  RUNRIG~2.BMP  RUNRIG~3.BMP  RUNRIG~4.BMP
//
//BIKEBA~1.BMP  BIKEBA~2.BMP  BIKEBA~3.BMP  BIKEBA~4.BMP
//BIKEFR~1.BMP  BIKEFR~2.BMP  BIKEFR~3.BMP  BIKEFR~4.BMP
//BIKELE~1.BMP  BIKELE~2.BMP  BIKELE~3.BMP  BIKELE~4.BMP
//BIKERI~1.BMP  BIKERI~2.BMP  BIKERI~3.BMP  BIKERI~4.BMP
//
//STARTB~1.BMP  STARTB~2.BMP  STARTB~3.BMP  STARTB~4.BMP
//STARTR~1.BMP  STARTR~2.BMP  STARTR~3.BMP  STARTR~4.BMP
//
//JIRACH~1.BMP
//JIRACH~2.BMP
//JIRACH~3.BMP
//JIRACH~4.BMP
//JI0638~1.BMP
//JIEACF~1.BMP
//JIDA85~1.BMP
//JI8AAE~1.BMP
//
//HILLGTL.BMP  HILLGT.BMP  HILLGTR.BMP
//HILLGL.BMP               HILLGR.BMP
//HILLGBL.BMP  HILLGB.BMP  HILLGBR.BMP
//
//HILLHTL.BMP  HILLHT.BMP  HILLHTR.BMP
//HILLHL.BMP               HILLHR.BMP
//HILLHBL.BMP  HILLHB.BMP  HILLHBR.BMP
//
//BACKGR~1.BMP
//CNTRGR~1.BMP
//GRASST~1.BMP
//GROUND~1.BMP
//HILLTILE.BMP
//TREEB.BMP
//TREES.BMP
//TREESB~1.BMP



//values start from 0
  //Each character represents a tile

char *walkBack[]={"0","WALKBA~1.BMP","WALKBA~2.BMP","WALKBA~3.BMP","WALKBA~4.BMP"};
char *walkFront[]={"0","WALKFR~1.BMP","WALKFR~2.BMP","WALKFR~3.BMP","WALKFR~4.BMP"};
char *walkLeft[]={"0","WALKLE~1.BMP","WALKLE~2.BMP","WALKLE~3.BMP","WALKLE~4.BMP"};
char *walkRight[]={"0","WALKRI~1.BMP","WALKRI~2.BMP","WALKRI~3.BMP","WALKRI~4.BMP"};

char *runBack[]={"0","RUNBAC~1.BMP","RUNBAC~2.BMP","RUNBAC~3.BMP","RUNBAC~4.BMP"};
char *runFront[]={"0","RUNFRO~1.BMP","RUNFRO~2.BMP","RUNFRO~3.BMP","RUNFRO~4.BMP"};
char *runLeft[]={"0","RUNLEF~1.BMP","RUNLEF~2.BMP","RUNLEF~3.BMP","RUNLEF~4.BMP"};
char *runRight[]={"0","RUNRIG~1.BMP","RUNRIG~2.BMP","RUNRIG~3.BMP","RUNRIG~4.BMP"};

char *bikeBack[]={"0","BIKEBA~1.BMP","BIKEBA~2.BMP","BIKEBA~3.BMP","BIKEBA~4.BMP"};
char *bikeFront[]={"0","BIKEFR~1.BMP","BIKEFR~2.BMP","BIKEFR~3.BMP","BIKEFR~4.BMP"};
char *bikeLeft[]={"0","BIKELE~1.BMP","BIKELE~2.BMP","BIKELE~3.BMP","BIKELE~4.BMP"};
char *bikeRight[]={"0","BIKERI~1.BMP","BIKERI~2.BMP","BIKERI~3.BMP","BIKERI~4.BMP"};

char *startBike[]={"0","STARTB~1.BMP","STARTB~2.BMP","STARTB~3.BMP","STARTB~4.BMP"};
char *startRun[]={"0","STARTR~1.BMP","STARTR~2.BMP","STARTR~3.BMP","STARTR~4.BMP"};

char *grassHill[]={"0",
  "HILLGTL.BMP","HILLGT.BMP","HILLGTR.BMP",
  "HILLGL.BMP",     "0"     , "HILLGR.BMP",
  "HILLGBL.BMP","HILLGB.BMP","HILLGBR.BMP"};

char *hill[]={"0",
  "HILLHTL.BMP","HILLHT.BMP","HILLHTR.BMP",
  "HILLHL.BMP",     "0"     , "HILLHR.BMP",
  "HILLHBL.BMP","HILLHB.BMP","HILLHBR.BMP"};

char *grass = "GRASST~1.BMP";
char *centregrass = "CNTRGR~1.BMP";
char *ground = "GROUND~1.BMP";
char *tree = "TREES.BMP";

#define joyX A9
#define joyY A8
#define buttonA 40
#define buttonB 38
#define buttonX 36
#define buttonY 34
#define SwVcc 30
#define SwGnd 32

bool bA = false;
bool bB = false;
bool bX = false;
bool bY = false;

bool Select = false;
bool Move = false;

int proLoc[]={0,0};
char proDir='b';//f,b,r,l


char Map[]={'0',
  'n','t','n','n','n','n','n','n','n','n','n','n','n','n','n','n',
  'n','t','g','g','g','n','n','n','n','n','n','n','n','n','n','n',
  'n','t','g','n','n','t','t','t','n','n','n','n','n','n','n','n',
  'n','n','g','g','g','n','n','t','n','n','n','n','n','n','n','n',
  'n','n','n','n','g','n','n','t','n','n','n','n','n','n','n','n',
  'n','n','g','g','g','n','n','n','n','n','n','n','n','n','n','n',
  'n','n','n','n','n','n','n','n','n','n','n','n','n','n','n','n',
  'n','n','n','n','n','n','n','n','n','n','n','n','n','n','n','n',
  'n','n','n','n','n','n','n','n','n','n','n','n','n','n','n','n',
  'n','n','n','n','n','n','n','n','n','n','n','n','n','n','n','n',
  'n','n','n','n','n','n','n','n','n','n','n','n','n','n','n','n',
  'n','n','n','n','n','n','n','n','n','n','n','n','n','n','n','n',
};

bool movementPermission []={0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

char preTile[] = {'0',
  'n','n','n','n','n','n','n','n',
  'n','n','n','n','n','n','n','n',
  'n','n','n','n','n','n','n','n',
  'n','n','n','n','n','n','n','n',
  'n','n','n','n','n','n','n','n',
  'n','n','n','n','n','n','n','n'};

const int MapL = 16;
const int MapB = 12;
const int ScreenL = 8;
const int ScreenB = 6;
const int startLoc = 0;//36

int Loc = 0;
int mapTileNum = 0;
int screenTileNum = 0;
char tile = 'n';

bool grassCentre = false;

void mapPlot(){
  Loc = startLoc - (proLoc[1]*MapL) + proLoc[0];
  for(int Y = 0;Y<ScreenB;Y++){
    for(int X = 1;X<=ScreenL;X++){
      mapTileNum = (Y*MapL)+X+Loc;
      screenTileNum = (Y*ScreenL)+X;
      tile = Map[mapTileNum];
      if(movementPermission[mapTileNum] == 0){
        if(tile == 'g' && preTile[screenTileNum] != tile){
          Serial.println("printing grass");
          bmpDraw(grass,(X-1)*tileSize,Y*tileSize);
          if((X-1)==4 && Y==4){
            grassCentre = true;
            Serial.println("centergrass");
          }
          else{
            grassCentre = false;
          }
          preTile[screenTileNum] = tile;
        }
        else if(tile == 't' && preTile[screenTileNum] != tile){
          Serial.println("printing grass");
          bmpDraw(tree,(X-1)*tileSize,Y*tileSize);
          preTile[screenTileNum] = tile;
        }
        else if(tile == 'n' && preTile[screenTileNum] != 'n'){
          Serial.println("printing ground");
          bmpDraw(ground,(X-1)*tileSize,Y*tileSize);
          if(preTile[screenTileNum] == 't'){
            bmpDraw(ground,(X-1)*tileSize,(Y+1)*tileSize);
          }
          preTile[screenTileNum] = 'n';
        }
      }
    }
    Serial.println();
  }
}



void setup()
{
  Serial.begin(9600);
  digitalWrite(35, HIGH);
  tft.reset();

  tft.begin(0x9341);//ili9341
  
  Serial.print("Initializing SD card...");
  
  while (!SD.begin(SD_CS))
  {
    Serial.println("failed!");
  }
  Serial.println("OK!");
  tft.setRotation(1);
  tft.fillScreen(0);
  
  pinMode(SwVcc, OUTPUT);
  pinMode(SwGnd, OUTPUT);
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
  pinMode(buttonX, INPUT);
  pinMode(buttonY, INPUT);
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  digitalWrite(SwVcc, HIGH);
  digitalWrite(SwGnd, LOW);
  
  delay(1000);
  bmpDraw("BACKGR~1.BMP", 0, 0);
//  for(int n = 0;n*tileSize<=240;n++){
//    for(int i=0;i*tileSize<=320;i++){
//      bmpDraw("GRASST~1.BMP", (tileSize*i)-tileSize, (tileSize*n)-tileSize);
//    }
//  }
  bmpDraw(walkBack[1], centreX, centreY);
//  bmpDraw("CNTRGR~1.BMP", centreX+20, centreY+60);
  mapPlot();    
  Serial.println();
}



void loop()
{
  
  joyRead();
  if(Move){
    if(Select){
      bike(proDir);
    }
    
    else{
      if(bB){
        Run(proDir);
      }
      else{
        walk(proDir);
      }
    }
    Serial.print(proLoc[0]);
    Serial.print("\t");
    Serial.print(proLoc[1]);
    Serial.print("\t");
    Serial.println(proDir);
  }
}



void walk(char Direction){
  if(Direction == 'l'){
    Serial.println("Left");
    bmpDraw(walkLeft[4], centreX, centreY);
    while(Move && Direction == 'l'){
      joyRead();
      if(Move && Direction == 'l'){
        proLoc[0]=proLoc[0]-1;
        bmpDraw(walkLeft[1], centreX, centreY);
        mapPlot();
        bmpDraw(walkLeft[2], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,centreX+20, centreY+60);
        }
      }
      joyRead();
      if(Move && Direction == 'l'){
        proLoc[0]=proLoc[0]-1;
        bmpDraw(walkLeft[3], centreX, centreY);
        mapPlot();
        bmpDraw(walkLeft[4], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
    }
    bmpDraw(walkLeft[1], centreX, centreY);
  }
  else if(Direction == 'r'){
    Serial.println("Right");
    bmpDraw(walkRight[4], centreX, centreY);
    while(Move && Direction == 'r'){
      joyRead();
      if(Move && Direction == 'r'){
        proLoc[0]=proLoc[0]+1;
        bmpDraw(walkRight[1], centreX, centreY);
        mapPlot();
        bmpDraw(walkRight[2], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
      joyRead();
      if(Move && Direction == 'r'){
        proLoc[0]=proLoc[0]+1;
        bmpDraw(walkRight[3], centreX, centreY);
        mapPlot();
        bmpDraw(walkRight[4], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
    }
    bmpDraw(walkRight[1], centreX, centreY);
  }
  else if(Direction == 'f'){
    Serial.println("Front");
    bmpDraw(walkFront[4], centreX, centreY);
    while(Move && Direction == 'f'){
      joyRead();
      if(Move && Direction == 'f'){
        proLoc[1]=proLoc[1]+1;
        bmpDraw(walkFront[1], centreX, centreY);
        mapPlot();
        bmpDraw(walkFront[2], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
      joyRead();
      if(Move && Direction == 'f'){
        proLoc[1]=proLoc[1]+1;
        bmpDraw(walkFront[3], centreX, centreY);
        mapPlot();
        bmpDraw(walkFront[4], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
    }
    bmpDraw(walkFront[1], centreX, centreY);
  }
  else if(Direction == 'b'){
    Serial.println("Back");
    bmpDraw(walkBack[4], centreX, centreY);
    while(Move && Direction == 'b'){
      joyRead();
      if(Move && Direction == 'b'){
        proLoc[1]=proLoc[1]-1;
        bmpDraw(walkBack[1], centreX, centreY);
        mapPlot();
        bmpDraw(walkBack[2], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
      joyRead();
      if(Move && Direction == 'b'){
        proLoc[1]=proLoc[1]-1;
        bmpDraw(walkBack[3], centreX, centreY);
        mapPlot();
        bmpDraw(walkBack[4], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
    }
    bmpDraw(walkBack[1], centreX, centreY);
    
  }
}




void Run(char Direction){
  if(Direction == 'l'){
    Serial.println("Left");
    bmpDraw(startRun[3], centreX, centreY);
    while(Move && Direction == 'l'){
      joyRead();
      if(Move && Direction == 'l'){
        proLoc[0]=proLoc[0]-1;
        bmpDraw(runLeft[1], centreX, centreY);
        mapPlot();
        bmpDraw(runLeft[2], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
      joyRead();
      if(Move && Direction == 'l'){
        proLoc[0]=proLoc[0]-1;
        bmpDraw(runLeft[3], centreX, centreY);
        mapPlot();
        bmpDraw(runLeft[4], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
    }
    bmpDraw(walkLeft[1], centreX, centreY);
  }
  else if(Direction == 'r'){
    Serial.println("Right");
    bmpDraw(startRun[4], centreX, centreY);
    while(Move && Direction == 'r'){
      joyRead();
      if(Move && Direction == 'r'){
        proLoc[0]=proLoc[0]+1;
        bmpDraw(runRight[1], centreX, centreY);
        mapPlot();
        bmpDraw(runRight[2], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
      joyRead();
      if(Move && Direction == 'r'){
        proLoc[0]=proLoc[0]+1;
        bmpDraw(runRight[3], centreX, centreY);
        mapPlot();
        bmpDraw(runRight[4], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
    }
    bmpDraw(walkRight[1], centreX, centreY);
  }
  else if(Direction == 'f'){
    Serial.println("Front");
    bmpDraw(startRun[2], centreX, centreY);
    while(Move && Direction == 'f'){
      joyRead();
      if(Move && Direction == 'f'){
        proLoc[1]=proLoc[1]+1;
        bmpDraw(runFront[1], centreX, centreY);
        mapPlot();
        bmpDraw(runFront[2], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
      joyRead();
      if(Move && Direction == 'f'){
        proLoc[1]=proLoc[1]+1;
        bmpDraw(runFront[3], centreX, centreY);
        mapPlot();
        bmpDraw(runFront[4], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
    }
    bmpDraw(walkFront[1], centreX, centreY);
  }
  else if(Direction == 'b'){
    Serial.println("Back");
    bmpDraw(startRun[1], centreX, centreY);
    while(Move && Direction == 'b'){
      joyRead();
      if(Move && Direction == 'b'){
        proLoc[1]=proLoc[1]-1;
        bmpDraw(runBack[1], centreX, centreY);
        mapPlot();
        bmpDraw(runBack[2], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
      joyRead();
      if(Move && Direction == 'b'){
        proLoc[1]=proLoc[1]-1;
        bmpDraw(runBack[3], centreX, centreY);
        mapPlot();
        bmpDraw(runBack[4], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
    }
    bmpDraw(walkBack[1], centreX, centreY);
    
  }
}





void bike(char Direction){
  if(Direction == 'l'){
    Serial.println("Left");
    bmpDraw(startBike[3], centreX, centreY);
    while(Move && Direction == 'l'){
      joyRead();
      if(Move && Direction == 'l'){
        proLoc[0]=proLoc[0]-1;
        bmpDraw(bikeLeft[1], centreX, centreY);
        mapPlot();
        bmpDraw(bikeLeft[2], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
      joyRead();
      if(Move && Direction == 'l'){
        proLoc[0]=proLoc[0]-1;
        bmpDraw(bikeLeft[3], centreX, centreY);
        mapPlot();
        bmpDraw(bikeLeft[4], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
    }
    bmpDraw(startBike[3], centreX, centreY);
  }
  else if(Direction == 'r'){
    Serial.println("Right");
    bmpDraw(startBike[4], centreX, centreY);
    while(Move && Direction == 'r'){
      joyRead();
      if(Move && Direction == 'r'){
        proLoc[0]=proLoc[0]+1;
        bmpDraw(bikeRight[1], centreX, centreY);
        mapPlot();
        bmpDraw(bikeRight[2], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
      joyRead();
      if(Move && Direction == 'r'){
        proLoc[0]=proLoc[0]+1;
        bmpDraw(bikeRight[3], centreX, centreY);
        mapPlot();
        bmpDraw(bikeRight[4], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
    }
    bmpDraw(startBike[4], centreX, centreY);
  }
  else if(Direction == 'f'){
    Serial.println("Front");
    bmpDraw(startBike[2], centreX, centreY);
    while(Move && Direction == 'f'){
      joyRead();
      if(Move && Direction == 'f'){
        proLoc[1]=proLoc[1]+1;
        bmpDraw(bikeFront[1], centreX, centreY);
        mapPlot();
        bmpDraw(bikeFront[2], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
      joyRead();
      if(Move && Direction == 'f'){
        proLoc[1]=proLoc[1]+1;
        bmpDraw(bikeFront[3], centreX, centreY);
        mapPlot();
        bmpDraw(bikeFront[4], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
    }
    bmpDraw(startBike[2], centreX, centreY);
  }
  else if(Direction == 'b'){
    Serial.println("Back");
    bmpDraw(startBike[1], centreX, centreY);
    while(Move && Direction == 'b'){
      joyRead();
      if(Move && Direction == 'b'){
        proLoc[1]=proLoc[1]-1;
        bmpDraw(bikeBack[1], centreX, centreY);
        mapPlot();
        bmpDraw(bikeBack[2], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
      joyRead();
      if(Move && Direction == 'b'){
        proLoc[1]=proLoc[1]-1;
        bmpDraw(bikeBack[3], centreX, centreY);
        mapPlot();
        bmpDraw(bikeBack[4], centreX, centreY);
        if(grassCentre){
          bmpDraw(grass,4*tileSize,3*tileSize);
        }
      }
    }
    bmpDraw(startBike[1], centreX, centreY);
    
  }
}







void joyRead()
{
  if(analogRead(joyX)>1000){
    proDir='b';
    Move = true;
  }
  else if(analogRead(joyX)<20){
    proDir='f';
    Move = true;
  }
  else if(analogRead(joyY)>1000){
    proDir='r';
    Move = true;
  }
  else if(analogRead(joyY)<20){
    proDir='l';
    Move = true;
  }
  else{
    Move = false;
  }

  bA = digitalRead(buttonA);
  bB = digitalRead(buttonB);
  bX = digitalRead(buttonX);
  bY = digitalRead(buttonY);
  if(bY){
    if(Select){
      Select = false;
      walk(proDir);
    }
    else{
      Select = true;
      bike(proDir);
    }
    while(bY){
      bY = digitalRead(buttonY);
    }
  }
}








#define BUFFPIXEL 20

void bmpDraw(char *filename, int x, int y) {

  File     bmpFile;
  int      bmpWidth, bmpHeight;   // W+H in pixels
  uint8_t  bmpDepth;              // Bit depth (currently must be 24)
  uint32_t bmpImageoffset;        // Start of image data in file
  uint32_t rowSize;               // Not always = bmpWidth; may have padding
  uint8_t  sdbuffer[3*BUFFPIXEL]; // pixel in buffer (R+G+B per pixel)
  uint16_t lcdbuffer[BUFFPIXEL];  // pixel out buffer (16-bit per pixel)
  uint8_t  buffidx = sizeof(sdbuffer); // Current position in sdbuffer
  boolean  goodBmp = false;       // Set to true on valid header parse
  boolean  flip    = true;        // BMP is stored bottom-to-top
  int      w, h, row, col;
  uint8_t  r, g, b;
  uint32_t pos = 0, startTime = millis();
  uint8_t  lcdidx = 0;
  boolean  first = true;

  if((x >= tft.width()) || (y >= tft.height())) return;

  Serial.println();
  //Serial.print("Loading image '");
  Serial.print(filename);
  Serial.println('\'');
  // Open requested file on SD card
  if ((bmpFile = SD.open(filename)) == NULL) {
    //Serial.println("File not found");
    return;
  }

  // Parse BMP header
  if(read16(bmpFile) == 0x4D42) { // BMP signature
    Serial.print("File size: "); Serial.println(read32(bmpFile));
    (void)read32(bmpFile); // Read & ignore creator bytes
    bmpImageoffset = read32(bmpFile); // Start of image data
    Serial.print("Image Offset: "); Serial.println(bmpImageoffset, DEC);
    // Read DIB header
    Serial.print("Header size: "); Serial.println(read32(bmpFile));
    bmpWidth  = read32(bmpFile);
    bmpHeight = read32(bmpFile);
    if(read16(bmpFile) == 1) { // # planes -- must be '1'
      bmpDepth = read16(bmpFile); // bits per pixel
      Serial.print("Bit Depth: "); Serial.println(bmpDepth);
      if((bmpDepth == 24) && (read32(bmpFile) == 0)) { // 0 = uncompressed

        goodBmp = true; // Supported BMP format -- proceed!
        
//        Serial.print("Image size: ");
//        Serial.print(bmpWidth);
//        Serial.print('x');
//        Serial.println(bmpHeight);

        // BMP rows are padded (if needed) to 4-byte boundary
        
        rowSize = (bmpWidth * 3 + 3) & ~3;

        // If bmpHeight is negative, image is in top-down order.
        // This is not canon but has been observed in the wild.
        
        if(bmpHeight < 0) {
          bmpHeight = -bmpHeight;
          flip      = false;
        }

        // Crop area to be loaded
        
        w = bmpWidth;
        h = bmpHeight;
        if((x+w-1) >= tft.width())  w = tft.width()  - x;
        if((y+h-1) >= tft.height()) h = tft.height() - y;

        // Set TFT address window to clipped image bounds
        
        tft.setAddrWindow(x, y, x+w-1, y+h-1);

        for (row=0; row<h; row++) { // For each scanline...
          
          // Seek to start of scan line.  It might seem labor-
          // intensive to be doing this on every line, but this
          // method covers a lot of gritty details like cropping
          // and scanline padding.  Also, the seek only takes
          // place if the file position actually needs to change
          // (avoids a lot of cluster math in SD library).
          
          if(flip) // Bitmap is stored bottom-to-top order (normal BMP)
            pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
          else     // Bitmap is stored top-to-bottom
            pos = bmpImageoffset + row * rowSize;
          if(bmpFile.position() != pos) { // Need seek?
            bmpFile.seek(pos);
            buffidx = sizeof(sdbuffer); // Force buffer reload
          }

          for (col=0; col<w; col++) { // For each column...
            
            // Time to read more pixel data?
            
            if (buffidx >= sizeof(sdbuffer)) { // Indeed
              // Push LCD buffer to the display first
              if(lcdidx > 0) {
                tft.pushColors(lcdbuffer, lcdidx, first);
                lcdidx = 0;
                first  = false;
              }
              bmpFile.read(sdbuffer, sizeof(sdbuffer));
              buffidx = 0; // Set index to beginning
            }

            // Convert pixel from BMP to TFT format
            
            b = sdbuffer[buffidx++];
            g = sdbuffer[buffidx++];
            r = sdbuffer[buffidx++];
            lcdbuffer[lcdidx++] = tft.color565(r,g,b);
          } // end pixel
        } // end scanline
        // Write any remaining data to LCD
        if(lcdidx > 0) {
          tft.pushColors(lcdbuffer, lcdidx, first);
        } 
        Serial.print("Loaded in ");
        Serial.print(millis() - startTime);
        Serial.println(" ms");
      } // end goodBmp
    }
  }

  bmpFile.close();
  if(!goodBmp) Serial.println("BMP format not recognized.");
}


// These read 16- and 32-bit types from the SD card file.
// BMP data is stored little-endian, Arduino is little-endian too.
// May need to reverse subscript order if porting elsewhere.


uint16_t read16(File f) {
  uint16_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read(); // MSB
  return result;
}


uint32_t read32(File f) {
  uint32_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read();
  ((uint8_t *)&result)[2] = f.read();
  ((uint8_t *)&result)[3] = f.read(); // MSB
  return result;
}
