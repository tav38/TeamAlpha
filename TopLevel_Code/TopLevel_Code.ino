#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <RotaryEncoder.h>


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  // put your setup code here, to run once:
  int num2win = 99;
  int action;
  int curround = 0;
  lcd.begin(16,2);
  lcd.clear();
  #define Rotary_A A2
  #define Rotary_B A3
  int game_delay = 5000;
  bool Round_Sucess = 0;
  
  //pin code we will add later

}

void loop() {
  // put your main code here, to run repeatedly:
  action = rand(0,2)
  static int rot_pos = 0;
  encoder.tick();
  
  //make delay between actions smaller every time
  //in ms
  delay(game_delay)

  switch(action){

    ///GUARD IS COMING 
    case 0:

    ///DIAL
    case 1:
    int rot_code = rand(0,100) //value MAY BE WRONG
    lcd.print("Lock Combo 1 : ",rot_code)
    delay(game_delay)
    rot_pos = encoder.getPosition();
    //if negative, flip to posotive cvalue
    if(rot_pos < 0){
      rot_pos = 100 - rot_pos //SUBTRACTION VAL
    }
    
    if(rot_pos == rot_code){
      Round_Sucess = 1;
      lcd.display("Code Cracked")
    }
    else{
      Round_Sucess = 0;
      lcd.display("Womp Womp :(")
    }
    ///SPEAKER & KEYPAD
    case(2):
  }

  delay = delay - 50;

  if(curround == num2win)
  {
    lcd.print("WINNER");
    lcd.print("SCORE :",curround);
    //win actions
  }
  }


}
