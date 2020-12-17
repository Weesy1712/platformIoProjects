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
	Adafruit_SSD1306 display2(OLED_RESET);
	#define OLED_ADDR1 0x3C
	#define OLED_ADDR2 0x3D
	#define low A0
	#define band1 A1
	#define band2 A2
	#define band3 A3
	#define high A6
	#define master A7
	int vallow;
	int valmid1;
	int valmid2;
	int valmid3;
	int valhigh;
	int valmaster;
	void setup()
	{
	    pinMode(A0, INPUT);
	    pinMode(A1, INPUT);
	    pinMode(A2, INPUT);
	    pinMode(A3, INPUT);
	    pinMode(A4, INPUT);
	    pinMode(A5, INPUT);
	    display1.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR1);
	    display2.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR2);
	    display1.clearDisplay();
	    display2.clearDisplay();
	    display1.drawRect(0, 0, 127, 63, WHITE);
	    display2.drawRect(0, 0, 127, 63, WHITE);
	    display1.setTextSize(3);
	    display1.setTextColor(WHITE);
	    display1.setCursor(15, 20);
	    display1.print("Hallo!");
	    display1.display();
	    delay(1000);
	    display1.clearDisplay();
	    display1.drawRect(0, 0, 127, 63, WHITE);
	    display1.setCursor(20, 10);
	    display1.setTextSize(2);
	    display1.print("Spectrum");
	    display1.setCursor(20, 35);
	    display1.print("Analyser");
	    display1.display();
	    delay(2000);
	    display1.clearDisplay();
	    display1.drawRect(0, 0, 127, 63, WHITE);
	    display1.setCursor(20, 20);
	    display1.setTextSize(3);
	    display1.print("V: 1");
	    display1.display();
	    delay(1000);
	    display1.fillRect(1, 1, 125, 61, BLACK);
	    display1.display();
	}
	void loop()
	{
	    display1.clearDisplay();
	    display2.clearDisplay();
	    vallow = analogRead(low) * 10 + 5;
	    valmid1 = analogRead(band1) * 10 + 5;
	    valmid2 = analogRead(band2) * 10 + 5;
	    valmid3 = analogRead(band3) * 10 + 5;
	    valhigh = analogRead(high) * 10 + 5;
	    valmaster = analogRead(master) * 10 + 5;
	    display2.fillRect(110, 0, 30, vallow, WHITE);
	    display2.fillRect(60, 0, 30, valmid1, WHITE);
	    display2.fillRect(10, 0, 30, valmid2, WHITE);
	    display1.fillRect(110, 0, 30, valmid3, WHITE);
	    display1.fillRect(60, 0, 30, valhigh, WHITE);
	    display1.fillRect(10, 0, 30, valmaster, WHITE);
	    display1.display();
	    display2.display();
}