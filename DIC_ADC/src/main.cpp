#include <Arduino.h>

void setup() {
 ADMUX |= 0b010000; 
 ADMUX &= 0b011100; 

 
}

void loop() {
 
}