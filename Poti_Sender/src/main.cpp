#include <Arduino.h>

#define poti A1
int val;
void setup()
{
    pinMode(poti, INPUT);
    Serial.begin(9600);
}

void loop()
{
    val = analogRead(poti);
  //  val = map(val, 0, 1023, 0, 255);
    delay(50);
    Serial.println(val);
}
