void setup() {
  Serial.begin(9600);
}

void loop() {
  while(1){
    if (Serial.available() > 0) {
      String teststr = Serial.readString();  //read until timeout
      teststr.trim();  
    }
    }

  while(1){
    if (Serial.availableForWrite()){
      Serial.write("Recieved");
      break;
    }
  }

  
    delay(2000);

}
