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
#define KeyPad_OUT D1
#define KeyPad_In D2



const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns



char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {3,2,1,0};
 //connect to the row pinouts of the keypad
byte colPins[COLS] = {7,6,5,4}; //connect to the column pinouts of the keypad

char code1 ={'1','4','7','*' }
char code2 ={'0','2','5','8' }
char code3 ={'9','#','3','6' }
char code4 ={'2','B','D','A' }
char code5 ={'4','3','3','1' }
int Game_Status = 0;
int Win_Status = 0;
int index = 0;
int action;


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
pinMode(KeyPad_OUT,OUTPUT);
pinMode(KeyPad_In,INPUT);
int codenum = 0;
keypad.addEventListener(keypadEvent);

}
  
void loop(){
  
  if(KeyPad_In == 1){
    action = rand(0,2);
    codenum =rand(0,4);
    pinMode(KeyPad_In,OUTPUT);
    digitalWrite(KeyPad_In,1);
    Game_Status = 1;
    //speaker output
    while(Game_Staus == 1){
      //wait for input
      char key = keypad.getKey();
    }
    digitWrite(KeyPad_Out,Win_Status);

    


  }
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch codenum {
      case 0:
        if(key == code1[index]){
          Game_Status == 1;
          index++;
        }
        else{Game_Status == 0;}
      case 1:
        if(key == code2[index]){
          Game_Status == 1;
          index++;
        }
        else{Game_Status == 0;}
      case 2:
        if(key == code3[index]){
          Game_Status == 1;
          index++;
        }
        else{Game_Status == 0;}

      case 3:
        if(key == code4[index]){
          Game_Status == 1;
          index++;
        }
        else{Game_Status == 0;}

      case 4:
        if(key == code5[index]){
          Game_Status == 1;
          index++;
        }
        else{Game_Status == 0;}
    }
 
    }
}
