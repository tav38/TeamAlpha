int sound_sensor = A0; //assign to pin A2
int soundValue = 0;
int button = 0;
 
void setup() 
{
  Serial.begin(9600); //begin Serial Communication
  pinMode(6, OUTPUT);
  pinMode(5, INPUT);
}
 
void loop()
{
  button = digitalRead(5);

  //Will only signal if a button is pressed to test if it will work in a case statement
  if(button == 1) {
    soundValue = 0; //create variable to store many different readings
    for (int i = 0; i < 32; i++) //create a for loop to read 
    { soundValue += analogRead(sound_sensor);  } //read the sound sensor
  
    soundValue >>= 5; //bitshift operation 
    
  
  //if a value higher than 500 is registered, we will print the following
  //this is done so that we can clearly see if the threshold is met
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