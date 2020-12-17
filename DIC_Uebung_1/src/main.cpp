#include <Arduino.h>

int state = 0;
int nextTimeToExecute = 0;
int millis2;

void setup()
{
    DDRB |= 0b00000100;
    //set common to high -> pin10 -> PB2
    PORTB &= 0b00000100; //PORTB = 0;
    //set LEDblue to output -> D5  -> PD5
    DDRD |= 0b01100000;
}
void loop()
{

    millis2 = millis();
    switch (state)
    {
    case 0:
        //Set led high
        PORTD = 0b01100000;
        state = 1;
        nextTimeToExecute = millis2 + 1000;
        break;
    case 1:
        //wait for 100ms
        if (millis2 < nextTimeToExecute)
        {
            //wir müssen noch weiter warten
        }
        else
        {
            //wartezeit ist vorrüber geh in den nächsten state
            state = 2;
        }
        break;
    case 2:
        //set led to low
        PORTD = 0b00100000;
        state = 3;
        nextTimeToExecute = millis2 + 1000;
        break;
    case 3:
        //wait
        if (millis2 > nextTimeToExecute)
        {
            //Wartezeit ist vorbei, gehe in den nächsten state
            state = 4;
        }
        break;
    case 4:
        PORTD = 0b01100000;
        state = 5;
        nextTimeToExecute = millis2 + 1000;
        break;
    case 5:
        if (millis2 > nextTimeToExecute)
        {
            //Wartezeit ist vorbei, gehe in den nächsten state
            state = 6;
        }
        break;
    case 6:
        PORTD = 0b00000000;
        state = 7;
        nextTimeToExecute = millis2 + 1000;
        break;
    case 7:
        if (millis2 > nextTimeToExecute)
        {
            //Wartezeit ist vorbei, gehe in den nächsten state
            state = 8;
        }
        break;
    case 8:
        PORTD = 0b01000000;
        state = 9;
        nextTimeToExecute = millis2 + 1000;
        break;
    case 9:
        if (millis2 > nextTimeToExecute)
        {
            //Wartezeit ist vorbei, gehe in den nächsten state
            state = 10;
        }
        break;
    case 10:
        PORTD = 0b00000000;
        state = 11;
        nextTimeToExecute = millis2 + 1000;
        break;
    case 11:
        if (millis2 > nextTimeToExecute)
        {
            //Wartezeit ist vorbei, gehe in den nächsten state
            state = 12;
        }
        break;
    case 12:
        PORTD = 0b01100000;
        state = 13;
        nextTimeToExecute = millis2 + 1000;
        break;
    case 13:
        if (millis2 > nextTimeToExecute)
        {
            //Wartezeit ist vorbei, gehe in den nächsten state
            state = 0;
        }
        break;
    }
}