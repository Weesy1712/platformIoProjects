#include <Arduino.h>
#include <Wire.h> 

#define address 0x4d
#define b 9600

byte v = 0;
void setup()
{
    Wire.begin();
    Serial.begin(b);
}

void loop()
  {
    Serial.print("Temperatur: ");

    int temp;

    Wire.beginTransmission(address);

    Wire.write(v);

    Wire.requestFrom(address, 1);
      if (Wire.available()) {
      temp = Wire.read();
      Serial.println(temp);
      }

      else {
      Serial.println("Warte auf Signal...");
      }
    delay(5000);
}
