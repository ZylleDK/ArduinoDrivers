#include "myTimer0.h"

myTimer0::myTimer0()
{
    // CTC Mode
    TCCR0A = 0b00000010;
    OCR0A = 79;

    // Enable timer interrupt
    TIMSK0 |= (1<<OCIE0A);
    sei();
}

myTimer0::~myTimer0()
{
}

void myTimer0::start()
{
    // f_clk/64
    TCCR0B |= 0b00000001;
}

void myTimer0::stop()
{
    // no clock
    TCCR0B &= 0b11111110;
}