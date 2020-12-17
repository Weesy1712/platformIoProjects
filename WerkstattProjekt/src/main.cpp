#include <Arduino.h>
#define aux A5
#define ledr 6
#define ledg 3
#define ledb 5
int amp;
void setup()
{
pinMode(aux,INPUT); 
pinMode(ledr,OUTPUT); 
pinMode(ledg,OUTPUT); 
pinMode(ledb,OUTPUT); 
Serial.begin(9600);

}
void loop()
{ 
  amp = analogRead(aux); 
  amp = map(amp,0,100,0,1000); 
  Serial.println(amp); 
 if(amp>)
}