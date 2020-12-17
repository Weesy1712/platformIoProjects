#include <Arduino.h>
void setupProzess1();
void setupProzess2();

void loopProzess1();
void loopProzess2();

void setup() {
  setupProzess1();
  setupProzess2();
  DDRB = 0b00000100;  //common auf output setzen
  //DDRD = 0b00100000;  // LED Blau auf output setzen
  //DDRD = 0b01000000;  // LED Rot auf output setzen
  PORTB = 0b00000000;  //common auf 0 setzen
}

void loop() {
  loopProzess1();
  loopProzess2();
}

void setupProzess1(){
  DDRD = DDRD | 0b00100000;
}

void setupProzess2(){
  DDRD |= 0b01000000;
}

unsigned long timeLeftState1 = 0;
unsigned long timeLeftState2 = 0;
int stateProzess1 = 0;
int stateProzess2 = 0;
int delayProzess1 = 1000;
int delayProzess2 = 3000;

void loopProzess1 (){
  switch(stateProzess1){
    case 0:
    PORTD |= 0b00100000;
    stateProzess1 = 1;
    timeLeftState1 = millis();
    break;
    case 1:
    if(timeLeftState1 + delayProzess1 < millis()){
      stateProzess1 = 2;
      timeLeftState1 = millis();
    }
    break;
    case 2:
    PORTD &= 0b11011111;
    stateProzess1 = 3;
    timeLeftState1 = millis();
    break;
    case 3:
    if(timeLeftState1 + delayProzess1 < millis()){
      stateProzess1 = 0;
      timeLeftState1 = millis();
    } 
    break;
    default:
    stateProzess1 = 0;
  }
}
void loopProzess2 (){
  switch(stateProzess2){
    case 0:
    PORTD |= 0b01000000;
    stateProzess2 = 1;
    timeLeftState2 = millis();
    break;
    case 1:
    if(timeLeftState2 + delayProzess2 < millis()){
      stateProzess2 = 2;
      timeLeftState2 = millis();
    }
    break;
    case 2:
    PORTD &= 0b10111111;
    stateProzess2 = 3;
    timeLeftState2 = millis();
    break;
    case 3:
    if(timeLeftState2 + delayProzess2 < millis()){
      stateProzess2 = 0;
      timeLeftState2 = millis();
    }
    break;
    default:
    stateProzess2 = 0;
  }
}
