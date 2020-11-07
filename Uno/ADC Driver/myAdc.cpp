#include "myAdc.h"

myADC::myADC()
{
    // Enable ADC interrupt flag when conversion done
    ADMUX = 0b01000000;
    // ADC enable
    // ADC interrupt disabled
    // ADC prescaler = 128 (=> ADC clock = 16 MHz / 128 = 125 kHZ)
    ADCSRA = 0b10000111; 
}

myADC::~myADC()
{

}

// Sets the corresponding pin as an input pin!
void myADC::turnOnPin(uint8_t pin)
{
    if ((pin >= 0) && (pin <= 5))
    {
        DDRC &= !(1<<pin);
    }
}

int myADC::readValue(uint8_t pin)
{
    if ((pin >= 0) && (pin <= 5))
    {
        // wire the specified channel to the ADC
        char admuxMap = (ADMUX & 0b11110000);
        char pinMap = (pin & 0b00001111);
        ADMUX = (admuxMap | pinMap);

        // Start conversion
        ADCSRA |= (1<<ADSC);
        // Wait for conversion finished.
        while (ADCSRA & 0b01000000)
        {}
        // Get value from ADC conversion
        return ADCW;
    }
}