#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  //Set Common to output and low 
  DDRB |= 0b00000100; 
  PORTB &= 0b11111011; 
  setupProcess1(); 
}

void loop() {
  // put your main code here, to run repeatedly:
loopProcess1(); 
}
void setupProcess1(){
//set LEDs to Output 
//PORTD 5 and 6 
DDRD |= 0b01100000; 
PORTD &= 0b10011111; 
DDRC &= 0b11110011; 
 }
 unsigned long nextTimeExcutionProcess1=0; 
 int stateProcess1; 
 void loopProcess1(){
if (millis() >= nextTimeExcutionProcess1){
switch(stateProcess1) {
  case 0: 
  int sw1 = PINC & 0b00000100; 
  int sw2 = PINC & 0b00001000; 
  if(sw1 == 0b00000100){ //oder if(sw1 ==4)
   
    stateProcess1 = 1; 
  } 
  else if(sw2 == 0b00001000){ //oder if(sw2 == 8)
   
    stateProcess1 = 2; 
  } 
  break; 
  case 1: 
  DDRD | 0b01000000; //turn on LED R 
  nextTimeExcutionProcess1 = millis() +100; 
  stateProcess1 = 0; 
  break; 
  case 2: 
  PORTD |= 0b00100000; //turn on led B 
  nextTimeExcutionProcess1 = 0; 
  break; 
}
}
//Else--Wait...
 }

