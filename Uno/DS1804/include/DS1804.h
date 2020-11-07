/*
    Copyright 2020 Stefan Nielsen (ZylleDK)

    Redistribution and use in source and binary forms, with or without modification, are permitted 
    provided that the following conditions are met:

1.  Redistributions of source code must retain the above copyright notice, this list of 
    conditions and the following disclaimer.

2.  Redistributions in binary form must reproduce the above copyright notice, this list of 
    conditions and the following disclaimer in the documentation and/or other materials provided 
    with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR 
    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND 
    FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER 
    IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
    OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


    DS1804 is a 100-tap digital potentiometer.
    This is a driver to easy setup and use this potentiometer together with Arduino.

    This driver is focused at the Arduino Uno (ATMEGA328P)
    Other Arduinos use the same atmega chip, and the driver can therefor easily be used for these devices 
    as well as the Arduino Uno. However, I do not provide any guarantee that this driver will work for 
    your setup, you must ensure that your setup can be used with this driver! 
*/

#ifndef DS1804_H_
#define DS1804_H_

#include <Arduino.h>
#include <stdint.h>
#include <avr/interrupt.h>

class DS1804
{
private:
    uint8_t _Position = 0;
    uint8_t _Cs;
    uint8_t _HL;
    uint8_t _INC;

public:
    DS1804(uint8_t, uint8_t, uint8_t);
    ~DS1804();

    void stepUp();
    void stepDown();

};

#endif