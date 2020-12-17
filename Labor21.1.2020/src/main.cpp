#include <Arduino.h>

#define led1 2
#define led2 3
#define led3 4
#define tmp37 A0
float tmp;
int ledstate1; 
int ledstate2; 
int ledstate3; 
String inputString = "";     // a String to hold incoming data
bool stringComplete = false; // whether the string is complete
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(tmp37, INPUT);
  Serial.begin(9600);
  inputString.reserve(200);
}

void loop()
{
  tmp = (analogRead(tmp37) / 4.1);
  if (stringComplete)
  {
    
    if (inputString == "rt\n")
    {
      Serial.println(tmp);
    }
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  delay(1000);
 Serial.println(tmp + (String) ";"  + (String) + ledstate1 +  (String) ";"  + (String) + ledstate2 +  (String) ";"  + (String) + ledstate3); 
   Serial.println("Temp:"); 
 Serial.print(tmp); 
 Serial.print(" C°");
 
  if (tmp >= 24.00)
  { ledstate1 = 1; 
    digitalWrite(led1, HIGH);
  }
  else
  {
    ledstate1 = 0; 
    digitalWrite(led1, LOW);
  }
  if (tmp > 25.00)
  {
    ledstate1 = 1; 
    ledstate2 = 1; 
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else
  {
    ledstate2 = 0; 
    digitalWrite(led2, LOW);
  }
  if (tmp > 26.00)
  {
    ledstate1 = 1; 
    ledstate2 = 1; 
    ledstate3 = 1; 
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  else
  {
    ledstate3 = 0; 
    digitalWrite(led3, LOW);
  }
}

void serialEvent()
{
  while (Serial.available())
  {
   
    char inChar = (char)Serial.read();
     inputString += inChar;
    if (inChar == '\n')
    {
      stringComplete = true;
    }
  }
}

