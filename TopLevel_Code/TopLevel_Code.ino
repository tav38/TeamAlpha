#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <RotaryEncoder.h>

#define Rotary_A A2
#define Rotary_B A3
#define Crack_Start 10
#define Crack_End 11
#define Crack_Score 12


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
RotaryEncoder encoder(Rotary_A,Rotary_B, RotaryEncoder::LatchMode::TWO03);
int game_delay = 0;
bool Round_Sucess = 0;
int action = 0;
int curround = 0;
int num2win = 99;
const int buttonPin = 2; // Button is connected to digital pin 2
int buttonState = 0;     // Variable to store the current state of the button
bool isDisplayOn = false;  // Variable to track whether the display is currently on or off
int sound_sensor = A0;
int soundValue = 0;
int button = 0;

void setup() {
  // put your setup code here, to run once:
 
  lcd.begin(16,2);
  lcd.clear();
  //pin for noise sensor
  pinMode(buttonPin, INPUT);
  //pins for 
  game_delay = 5000;
  pinMode(Crack_Start,OUTPUT);
  pinMode(Crack_End, INPUT_PULLUP);
  pinMode(Crack_Score, INPUT_PULLUP);

}
void loop() {
    Round_Sucess = 1;
    game_delay = 5000;
    lcd.clear();
    lcd.print("Lets RobIT!");   
    curround = 0;
    static int rot_pos = 0;
    digitalWrite(Crack_Start,0);    
    while(Round_Sucess == 1 & curround < num2win){
    action = int(random(0,3)); //changed to not include 3rd input
    //make delay between actions smaller every time
    //in ms
    delay(game_delay);
    if(action == 0){
      int soundValue = 0; //create variable to store many different readings
      lcd.clear();
      lcd.print("GUARDS COMING!");
      delay(game_delay);
      //soundValue = 0; //create variable to store many different readings
      soundValue = analogRead(sound_sensor);   
      if (soundValue > 350) { 
        lcd.clear();
        Round_Sucess = 0;
        lcd.print("Womp Womp :(");
        delay(game_delay);
      }
      else{
      Round_Sucess = 1;
      lcd.clear();
      lcd.print("Guard Avoided!");
      delay(game_delay);
      }
    }

    ///TURN THE DIAL
    else if(action == 1){
      //start sequence
      lcd.clear();
      //generate random number
      int rot_code = int(random(0,100));
      //turn into string and display
      String rotcodes = String(rot_code);
      String placeholder = "Find : " + rotcodes;
      lcd.print(placeholder);
      //wait some amount of time so it displays
      delay(1000);
      //start timer
      unsigned long startTime = millis();
      //internal number rotation number
      int temp_rot = 0;
      //while loop to read encoder
      while (millis() - startTime < game_delay) { // 10-second timeout
          encoder.tick();
          int rot_pos = encoder.getPosition();
        //round win 
        if(rot_pos == rot_code){
            lcd.clear();
            lcd.print("Code Cracked");
            delay(3000);
            Round_Sucess = 1;
            break;
            }
        //new number fo
        else if(temp_rot != rot_pos) {
          lcd.clear();   
          lcd.print("pos:");
          String poss = String(rot_pos); 
          lcd.print(poss);
          temp_rot = rot_pos;
        }
      }
      //Round Loss
      if(Round_Sucess == 0){
        lcd.clear();
        lcd.print("Womp Womp");
        delay(game_delay);
        }  
      
    }
    
    else if(action == 2){
    lcd.clear();
    lcd.print("Crack the Code");  
    digitalWrite(Crack_Start,1);
    delay(500);
    digitalWrite(Crack_Start,0);
    while(digitalRead(Crack_End) == 0 ){
        int i = 0;                  
    }        
    Round_Sucess = digitalRead(Crack_Score);

    if(Round_Sucess == 0){
        lcd.clear();
        lcd.print("Womp Womp");
        delay(game_delay);
      }  
     else{
      Round_Sucess = 1;
      lcd.clear();
      lcd.print("Safe Opened!");
      delay(game_delay);
      }
    }
  
  game_delay = game_delay - 50;
  curround++;
  } 

  if(Round_Sucess == 0){
    lcd.clear();
    lcd.print("GAME OVER");
    delay(5000);
    String currround_string = String(curround);
    String disp = "SCORE : " + currround_string;
    lcd.clear();
    lcd.print(disp);
    delay(10000);
    lcd.clear();
    //break;
  }
  if(curround == num2win)
    {
      while(1){
      lcd.clear();
      lcd.print("WINNER");
      delay(2000);
      String currround_string = String(curround);
      String disp = "SCORE : " + currround_string;
      lcd.clear();
      lcd.print(disp);
      delay(10000);
      }
    }
  
  //}
}
