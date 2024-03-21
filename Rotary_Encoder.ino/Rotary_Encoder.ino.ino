#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <RotaryEncoder.h>

#define Rotary_A A2
#define Rotary_B A3

static int rot_pos;
static int sucess = 0;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
RotaryEncoder encoder(Rotary_A,Rotary_B, RotaryEncoder::LatchMode::FOUR3);

void setup() {
  lcd.begin(16,2);
  lcd.clear();
  rot_pos = 0;
}

void loop() {
  sucess = 0;
    lcd.clear();
    int rot_code = int(random(0,100));
    String rotcodes = String(rot_code);
    String placeholder = "Combo 1 : " + rotcodes;
    lcd.print(placeholder);
    delay(1000);
unsigned long startTime = millis();
int temp_rot = 0;
while (millis() - startTime < 10000) { // 10-second timeout
      encoder.tick();
      int rot_pos = encoder.getPosition();
      if(rot_pos == rot_code){
        lcd.clear();
        lcd.print("Code Cracked");
        delay(5000);
        sucess = 1;
        break;
      }
      else if(temp_rot != rot_pos) {
      lcd.clear();   
      lcd.print("pos:");
      String poss = String(rot_pos); 
      lcd.print(poss);
      temp_rot = rot_pos;
      }
      }
    
  
    if(rot_pos == rot_code){
      lcd.clear();
      lcd.print("Code Cracked");
      delay(10000);
    }
    
    if(sucess == 0){
      lcd.clear();
      lcd.print("Womp Womp");
      delay(5000);
    }
}
