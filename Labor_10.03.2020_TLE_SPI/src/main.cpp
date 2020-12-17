#include <Arduino.h>
#include <SPI.h>

#define pot A0
//#define testled 8
const int slaveSelectPin = 10;
void setup() {
  pinMode(slaveSelectPin, OUTPUT);
  pinMode(pot, INPUT); 
  SPI.setDataMode(SPI_MODE1);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);    
}
void sendByte(int value); 
void loop() {
int potVal = analogRead(pot); 
int delay1 = 1;
delay1 = map(potVal,0,1023,1,10); 

 

int value = 0b00110000; 
value = 0b00111010;
sendByte(value); 
delay(delay1); 
value = 0b00111000;
sendByte(value); 
delay(delay1); 
value = 0b00111001;
sendByte(value); 
delay(delay1); 
value = 0b00110001;
sendByte(value); 
delay(delay1); 
value = 0b00110101;
sendByte(value); 
delay(delay1); 
value = 0b00110100;
sendByte(value);
delay(delay1);  
value = 0b00110110;
sendByte(value); 
delay(delay1); 
value = 0b00110010;
sendByte(value); 
delay(delay1); 

}

void sendByte(int value) {
  digitalWrite(slaveSelectPin, LOW);
  
  SPI.transfer(value); 
 
  digitalWrite(slaveSelectPin, HIGH);
}