/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
*/
#include <Keypad.h>
#define Crack_Start 10
#define Crack_End 11
#define Crack_Score 12
#define Bond_Play 13
#include <DFRobotDFPlayerMini.h>
#include "SoftwareSerial.h"

SoftwareSerial mySoftwareSerial(7, 6); // RX, TX
DFRobotDFPlayerMini myDFPlayer;



const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns



char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,5,4};
 //connect to the row pinouts of the keypad
byte colPins[COLS] = {3,2,1,0}; //connect to the column pinouts of the keypad

char code1[4] ={'1','4','7','*' };
char code2[4] ={'0','2','5','8' };
char code3[4] ={'9','#','3','6' };
char code4[4] ={'2','B','D','A' };
char code5[4] ={'4','3','3','1' };
int Game_Status = 0;
int Win_Status = 0;
int index = 0;
int action;
int codenum = 0;


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
pinMode(Crack_End,OUTPUT);
pinMode(Crack_Start,INPUT);
pinMode(Crack_Score,OUTPUT);
pinMode(Bond_Play,INPUT);
keypad.addEventListener(keypadEvent);
mySoftwareSerial.begin(9600);
myDFPlayer.begin(mySoftwareSerial);
myDFPlayer.setTimeOut(5000);
delay(200);
myDFPlayer.volume(25);  //Set volume value. From 0 to 30
delay(200);
}
  
void loop(){
  digitalWrite(Crack_End,0);
  if(digitalRead(Crack_Start) == 1){
    digitalWrite(Crack_End,0);
    codenum = int(random(2,7));
    Game_Status = 1;
    int num = 0;
    delay(2000);
    myDFPlayer.play(codenum);
    delay(6000);
    //speaker output
    while(Game_Status == 1){
      //wait for input
      if (index >= 3){
        Game_Status == 0;
      }
      else{
      char key = keypad.getKey();}
      }
    digitalWrite(Crack_End,1);
    digitalWrite(Crack_Score,Win_Status);
  }
  else if(digitalRead(Bond_Play) == 1){
    delay(2000);
    myDFPlayer.play(codenum);
    delay(6000);
  }
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (codenum) {
      case 2:
        if(key == code1[index]){
          Win_Status == 1;
          index++;
        }
        else{Win_Status == 0;
        Game_Status == 0;}
      case 3:
        if(key == code2[index]){
          Win_Status == 1;
          index++;
        }
        else{Win_Status == 0;
        Game_Status == 0;}
      case 4:
        if(key == code3[index]){
          Win_Status == 1;
          index++;
        }
        else{Win_Status == 0;
        Game_Status == 0;}

      case 5:
        if(key == code4[index]){
          Game_Status == 1;
          index++;
        }
        else{Win_Status == 0;
        Game_Status == 0;}

      case 6:
        if(key == code5[index]){
          Win_Status == 1;
          index++;
        }
        else{Win_Status == 0;
        Game_Status == 0;}
    }
 
    }
