#include <Arduino.h>
#include <Wire.h>                                                       // Library für I2C nötig 
#include <BME280_t.h>                                                   // Die BME280_Lite Library importieren

#define ASCII_ESC 27

#define MYALTITUDE  446.00                                              //Anfangsmeerehöhe definieren (Klagenfurt 446 m)

char bufout[10];

BME280<> BMESensor;                                                     // Sensor intialisieren

void setup()
{
  
  Serial.begin(9600);                                                 // Serrielle Baud-Rate definieren und initialisieren
 // Wire.begin(27,28);                                                      // I2C Pins vom Board definieren (SDA,SCL)
  Wire.begin(); 
  BMESensor.begin();                                                    // initalisiere BME280 Sensor
}

void loop() {
int time = millis()+1000; 

if (time <= millis() ){
 BMESensor.refresh();                                                  // Gelesene Sensor Daten aktualisieren 
 

  Serial.print("Temperature: ");
  Serial.print(BMESensor.temperature);                                  // Serielle Ausgabe der gemessenen Temperatur 
  Serial.println("C");

  Serial.print("Humidity:    ");
  Serial.print(BMESensor.humidity);                                     // Gemessene Luftfeuchtigkeit in %   
  Serial.println("%");

  Serial.print("Pressure:    ");
  Serial.print(BMESensor.pressure  / 100.0F);                           // Gemessener Druck in hPa
  Serial.println("hPa");

  float relativepressure = BMESensor.seaLevelForAltitude(MYALTITUDE);
  Serial.print("RelPress:    ");
  Serial.print(relativepressure  / 100.0F);                             // display relative pressure in hPa for given altitude
  Serial.println("hPa");   

  Serial.print("Altitude:    ");
  Serial.print(BMESensor.pressureToAltitude(relativepressure));         // Ungefähre Meereshöhe abhängig vom Luftdruck
  Serial.println("m");

}
 
                                                                            // Aktualisiert jede Sekunde 
}