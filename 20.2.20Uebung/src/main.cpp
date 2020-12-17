#include <Arduino.h>

int segments[] = {4, 6, 2, 3, 5, 8, 7};
int digit[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111100, 0b00000111, 0b01111111, 0b01100111, 0b01110111, 0b01111100, 0b00111001, 0b01011110, 0b01111001, 0b01110001};
int commonLeft = 12;
int commonRight = 13;

void printSymol(int symbol);

void setup()
{
  pinMode(11,OUTPUT); 
  pinMode(commonLeft, OUTPUT);
  digitalWrite(commonLeft, HIGH);

  pinMode(commonRight, OUTPUT);
  digitalWrite(commonRight, HIGH);

  for (int i = 0; i < 7; i++)
  {
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], LOW);
  }
}
int left = 0;
int right = 0;
void setnumber(int num)
{
  left = (num / 10) % 10;
  right = num % 10;
}
void loop7seg()
{

  printSymol(left);

  digitalWrite(commonLeft, LOW);
  delay(2);
  digitalWrite(commonLeft, HIGH);
  printSymol(right);

  digitalWrite(commonRight, LOW);
  delay(2);
  digitalWrite(commonRight, HIGH);
}
unsigned long nextTimeToExecute = 0;
void loop()
{
loop7seg();
if(millis()>nextTimeToExecute){
  int currentNum = left * 10 + right; 
  int nextNum = (currentNum + 1) %99;
 
    tone(11,10 * nextNum, 100); 
  if(nextNum == 98){
     tone(11,200, 00);
  }
  
  setnumber(nextNum); 
  nextTimeToExecute = millis()+500; 

}

  
 
}

void printSymol(int symbol)
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segments[i], (digit[symbol] >> i) & 0x01);
  }
}