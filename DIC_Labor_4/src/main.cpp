#include <Arduino.h>

String inputString = "";         
bool stringComplete = false;  

void setup() {
  pinMode(6,OUTPUT); 
  Serial.begin(9600);
 
  inputString.reserve(200);
}

void loop() {

  if (stringComplete) {
    Serial.println(inputString);
      if (inputString =="on"){
        digitalWrite(6,HIGH); 
    }
    if (inputString =="off")
    {
      digitalWrite(6,LOW); 
    }

   
    
    inputString = "";
    stringComplete = false;
  }
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n'||inChar =='\r') {
      stringComplete = true;
    }
  }
}