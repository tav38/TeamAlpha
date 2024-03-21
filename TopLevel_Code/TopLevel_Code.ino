#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <RotaryEncoder.h>

#define Rotary_A A2
#define Rotary_B A3
#define KeyPad_OUT D1
#define KeyPad_In D2


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
RotaryEncoder encoder(Rotary_A,Rotary_B, RotaryEncoder::LatchMode::TWO03);

void setup() {
  // put your setup code here, to run once:
  int num2win = 99;
  int action = ;
  int curround = 0;
  lcd.begin(16,2);
  lcd.clear();
  //analog pins for rotary encoder
 
  //pin for noise sensor
  int sound_sensor = A0; //assign to pin A0
  //pins for 
  pinMode(KeyPad_OUT,OUTPUT);
  pinMode(KeyPad_In,INPUT);
  int game_delay = 10000;
  bool Round_Sucess = 0;
  //pin code we will add later
}

void loop() {
  Round_Sucess = 0;
  // put your main code here, to run repeatedly:
  lcd.print("Welcome, Lets Begin....")
  action = rand(0,2)

  //initalizations for rotary encoder
  static int rot_pos = 0;
  encoder.tick();
  //make delay between actions smaller every time
  //in ms
  delay(game_delay)

  switch(action){

    ///GUARD IS COMING 
    case 0:
      int soundValue = 0; //create variable to store many different readings
      for (int i = 0; i < 32; i++) //create a for loop to read 
      { soundValue += analogRead(sound_sensor);  } //read the sound sensor

      soundValue >>= 5; //bitshift operation 
      
      if(soundValue > 500){
         Round_Sucess = 0;
        lcd.display("Womp Womp :(")
        delay(1000);
      }
      else{
        Round_Sucess = 1;
        lcd.display("Guard Avoided!");
      }

    ///TURN THE DIAL
    case 1:
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
            delay(5000);
            Round_Sucesss = 1
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
        delay(5000);
        }  
    
    case(2):
    digitalWrite(KeyPad_OUT,1);
    delay(100);
    pinMode(KeyPad_OUT,OUTPUT);
    while(digitalRead(KeyPad_OUT)!= 1){
      //deadloop
      //waiting for game to end
    }
    Round_Sucess = digitalRead(KeyPad_In);
  }

  delay = delay - 50;

  if(Round_Sucess == 0){
    lcd.print("GAME OVER");
    delay(2000);
    lcd.print("SCORE :",curround);
    delay(10000);
    break;
  }

  if(curround == num2win)
  {
    while(1){
    lcd.print("WINNER");
    delay(2000);
    lcd.print("SCORE :",curround);
    }

  }
  }


}
