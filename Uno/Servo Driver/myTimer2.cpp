#include "myTimer2.h"

myTimer2::myTimer2()
{
    // CTC Mode
    TCCR2A = 0b00000010;
    OCR2A = 249;

    // Enable timer interrupt
    TIMSK2 |= (1<<OCIE2A);
    sei();
}

myTimer2::~myTimer2()
{
}

void myTimer2::start()
{
    // f_clk/256
    TCCR2B |= 0b00000110;
}

void myTimer2::stop()
{
    // no clock
    TCCR2B &= 0b11111001;
}