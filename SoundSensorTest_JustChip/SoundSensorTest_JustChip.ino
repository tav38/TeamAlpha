#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int buttonPin = 2; // Button is connected to digital pin 2
int buttonState = 0;     // Variable to store the current state of the button
bool isDisplayOn = false;  // Variable to track whether the display is currently on or off

int sound_sensor = A0;
int soundValue = 0;
int button = 0;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() 
{
  Serial.begin(9600); //begin Serial Communication

  lcd.begin(16,2);
  lcd.clear();

  pinMode(buttonPin, INPUT);
}
 
void loop()
{
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState == HIGH) {
    // Wait for button release
    while (digitalRead(buttonPin) == HIGH);

  //Get sound value
  soundValue = 0; //create variable to store many different readings
  for (int i = 0; i < 32; i++){ 
    soundValue += analogRead(sound_sensor);  
  }
  
    soundValue >>= 5; //bitshift operation
  
    if (soundValue > 500) { 
      //Output if threshold is exceeded

      digitalWrite(6, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(1000);                      // wait for a second
      digitalWrite(6, LOW);   // turn the LED off by making the voltage LOW
    }
}
` //Delay next reading (If we want to loop it)
  delay(50);

}