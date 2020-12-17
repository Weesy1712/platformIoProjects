#include <Arduino.h>
#define switch1 10
#define switch2 11
#define relais 9
int lightstate = 0; 

void setup() {
pinMode(switch1, INPUT_PULLUP); 
pinMode(switch2, INPUT); 
pinMode(relais,OUTPUT); 
Serial.begin(9600); 

  
}

void loop() {
 // Serial.println(digitalRead(switch1)); 
if(digitalRead(switch1)==LOW){

  digitalWrite(relais, HIGH);
}else{
  digitalWrite(relais, LOW); 
}

}