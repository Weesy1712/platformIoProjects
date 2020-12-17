#include <Arduino.h>
int ledg = 3; 

void setup() {
 pinMode(3, OUTPUT); 

}
int nextTimeToExecute; 
void loop() {
 
      for (int i = 0; i <= 255; i++) 
      {
        delay(5); 
       analogWrite(ledg,i); 
      }

       for (int i = 255; i >= 0; i--) 
      {
        delay(5); 
       analogWrite(ledg,i); 
      }

 }