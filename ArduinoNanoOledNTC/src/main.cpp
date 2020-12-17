#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display1(OLED_RESET);
#define OLED_ADDR1 0x3C

int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup()
{
  Serial.begin(9600);
  display1.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR1);
  display1.clearDisplay();
  display1.setTextColor(WHITE);
  display1.setCursor(15, 20);

  display1.print("Hello!");
  display1.display();
  delay(3000);
}

void loop()
{

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  Tc = T - 273.15;

  Serial.print("Temperature: ");
  Serial.print(Tc);
  Serial.println(" C");
  display1.clearDisplay();
  display1.setCursor(15, 1);
  display1.setTextColor(WHITE);
  display1.setTextSize(1); 
  display1.print((String)"Temperature: " );
  display1.setCursor(15,15); 
  display1.setTextSize(2.5); 
  display1.print((double)Tc + (String)" C"); 


 
  display1.display();

  delay(500);
}