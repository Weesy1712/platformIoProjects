#include <Arduino.h>
int pirPin = 9;
int relay1 = 13;
int relay2 = 12;
int relay3 = 11;
int relay4 = 10;

int Received=0;
int state1 =0;
int state2 = 0;
int state3 = 0;
int state4 = 0;

void setup(){
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);
}
void loop(){
  

   if(Serial.available()>0)
 { 
    Received = Serial.read();
     
 
 }
 if (state1 == 0 && Received == 1)
  { 
    
    state1 = 1; 
    Received=0;  
  }
   if (state1 == 1 && Received == 1)
  { 
    
    state1 = 0; 
    Received=0;  
  }
   if (state2 == 0 && Received == 2)
  { 
    
    state2 = 1; 
    Received=0;  
  }
   if (state2 == 1 && Received == 2)
  { 
    
    state2 = 0; 
    Received=0;  
  }
  
  
}
