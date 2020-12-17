#include <Arduino.h>

void setupProcess1();
void loopProcess1();
unsigned long nextTimeExecutionProcess1 = 0;
int stateProcess1 = 0;
int sw1 = 0;
int sw2 = 0;

void setup()
{
  // put your setup code here, to run once:
  setupProcess1();
  DDRB |= 0b00000100;
  PORTB &= 0b11111011;
}

void loop()
{
  // put your main code here, to run repeatedly:
  loopProcess1();
}

void setupProcess1()
{
  DDRD |= 0b01100000;
  PORTD &= 0b10011111; //Turn off the LED
  //set SW1 and SW2 to input
  DDRC &= 0b11110011;
}

void loopProcess1()
{
  if (millis() >= nextTimeExecutionProcess1)
  {
    switch (stateProcess1)
    {
    case 0:
      PORTD &= 0b10011111;
      sw1 = PINC & 0b00000100; //PINC2 register einlesen
      sw2 = PINC & 0b00001000; //PINC3 reigster einlesen
      if (sw1 == 0b00000100)       // oder if(sw1 == 4) --- oder if(sw1)
      {
        stateProcess1 = 1;
      }
      else if (sw2 == 0b00001000)
      { // oder if(sw1 == 8) --- oder if(sw1)
        stateProcess1 = 2;
      }
      break;
      case 1:
      PORTD |= 0b00100000;
      nextTimeExecutionProcess1 = millis() + 100;
      stateProcess1 = 0;
      break;
      case 2:
      PORTD |= 0b01000000;
      nextTimeExecutionProcess1 = millis() + 100;
      stateProcess1 = 0;
      break;
    default:
      break;
    }
  }
}

