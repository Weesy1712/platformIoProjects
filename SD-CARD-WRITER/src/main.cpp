#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
File myFile;

String inputString = "";        
bool stringComplete = false; 
int val;

void setup() {
  Serial.begin(9600);
 inputString.reserve(200);
 SD.begin();
 myFile = SD.open("test.txt", FILE_WRITE);
  myFile.println("Zeit in Millisekunden" + (String) ";Wert");
   
 myFile.close();
}

void loop() {
  SD.begin();
  if (stringComplete) {
    Serial.println(inputString);
    val = inputString.toInt();
    myFile = SD.open("test.txt", FILE_WRITE);
   
   
    myFile.println((String)millis() +(String)";"+ (String) (val));
    myFile.close();
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

