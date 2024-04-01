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
#define Crack_Start 11//10
#define Crack_End 12//11
#define Crack_Score 13 //12
//#define Bond_Play 13
#include <DFRobotDFPlayerMini.h>
#include "SoftwareSerial.h"

SoftwareSerial mySoftwareSerial(7, 6); // RX, TX
DFRobotDFPlayerMini myDFPlayer;




const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {3,2,10,0};//connect to the row pinouts of the keypad
byte colPins[COLS] = {9,8,5,4}; //connect to the column pinouts of the keypad

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
//pinMode(Bond_Play,INPUT);
//keypad.addEventListener(keypadEvent);
mySoftwareSerial.begin(9600);
myDFPlayer.begin(mySoftwareSerial);
myDFPlayer.setTimeOut(5000);
delay(200);
myDFPlayer.volume(25);  //Set volume value. From 0 to 30
delay(200);
//Serial.begin(9600);
}
  
void loop(){
  digitalWrite(Crack_End,0);
  if (digitalRead(Crack_Start) == 1){
    digitalWrite(Crack_End,0);
    codenum = int(random(2,7));
    Game_Status = 1;
    int num = 0;
    Serial.print("Playing Sound \n");
    delay(2000);
    myDFPlayer.play(codenum);
    delay(1000);
    index = 0;
    //speaker output
    while(Game_Status == 1){
      char key = keypad.getKey();
      if (key) {
      Serial.print("Key :");
      Serial.print(String(key));
      Serial.print("\n");
      if(codenum == 2){
        if(key == code1[index]){
          Win_Status = 1;
        }
        else{Win_Status = 0;
        Game_Status = 0;}
        index++;
      }
      
      else if(codenum == 3) {
        if(key == code2[index]){
          Win_Status = 1;
 
        }
        else{Win_Status == 0;
        Game_Status = 0;}
        index++;}
        
      else if(codenum == 4){
        if(key == code3[index]){
          Win_Status = 1;
          
       }
        else{Win_Status = 0;
        Game_Status = 0;}
        index++;}
      

      else if(codenum ==5){
        if(key == code4[index]){
          Game_Status = 1;
          
        }
        else{Win_Status = 0;
        Game_Status = 0;}
        index++;
        }
        

      else if(codenum == 6){
        if(key == code5[index]){
          Win_Status = 1;
          
        }
        else{Win_Status = 0;
        Game_Status = 0;}
        index++;
      }

      if(index == 4){
        break;
      }
      }
    }

    digitalWrite(Crack_End,1);
    digitalWrite(Crack_Score,Win_Status);
    
  }
}

  /*
  else if(digitalRead(Bond_Play) == 1){
    Serial.print(2000);
    myDFPlayer.play(codenum);
    delay(6000);
  }
  */

