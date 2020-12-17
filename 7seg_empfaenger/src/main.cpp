#include <Arduino.h>
#define red 6
#define blue 5 
#define common 10

String inputString = "";        
bool stringComplete = false; 
int val;
int val2; 
void setup() {
  Serial.begin(9600);
 inputString.reserve(200);
 pinMode(red, OUTPUT); 
 pinMode(blue,OUTPUT);
 pinMode(common,OUTPUT); 
 digitalWrite(common, LOW); 
 
}

void loop() {
  if (stringComplete) {
    Serial.println(inputString);
    val = inputString.toInt()/4;
    val2 = 255- val;
      delay(10); 
    
  analogWrite(red,val); 
  analogWrite(blue,val2);
    inputString = "";
    stringComplete = false;
  }

  
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;

    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

