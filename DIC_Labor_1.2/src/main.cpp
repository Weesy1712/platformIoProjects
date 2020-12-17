#include <Arduino.h>
int ledr = 3; 

void setup() {
  Serial.begin(9600);
  pinMode(ledr, OUTPUT); 
  Serial.println("Zum Steuern müssen Sie in diesem Format eingeben!" );
  Serial.println("Zum Einschalten: "); 
  Serial.println("switch.on");
  Serial.println("switch.off"); 
}

void loop() {
int fadingState; 
 if(Serial.available()){
   if(Serial.read() == "switch.on"){
     fadingState = 1; 
     
   }
   if(Serial.read() == "h"){
     fadingState = 0; 
   }
  }
if(fadingState == 1){
  
  fading(); 
}

}
int millis2; 
void fading(){
  
    for (int i = 0; i <= 255; i++) 
      {millis2 = millis()+ 5; 
        //delay(5); 
        if(millis()>= millis2){

          analogWrite(ledr,i); 
        }
       
      }

       for (int i = 255; i >= 0; i--) 
      {
        //delay(5); 
      millis2 = millis()+ 5; 
        //delay(5); 
        if(millis()>= millis2){

          analogWrite(ledr,i); 
        }
      }

}

