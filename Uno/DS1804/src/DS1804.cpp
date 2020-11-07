#include "DS1804.h"

DS1804::DS1804(uint8_t Cs, uint8_t HL, uint8_t INC): _Cs{Cs}, _HL{HL}, _INC{INC}
{
    pinMode(_Cs, OUTPUT);
    pinMode(_HL, OUTPUT);
    pinMode(_INC, OUTPUT);
}

DS1804::~DS1804()
{
}

void DS1804::stepUp()
{
    digitalWrite(_Cs, LOW);
    _NOP();
    digitalWrite(_HL, HIGH);
    _NOP();
    _NOP();
    digitalWrite(_INC, LOW);
    _delay_us(500);
    digitalWrite(_INC, HIGH);
    _delay_us(500);
    digitalWrite(_Cs, HIGH);
    _NOP();

}

void DS1804::stepDown()
{
    digitalWrite(_Cs, LOW);
    _NOP();
    digitalWrite(_HL, LOW);
    _NOP();
    _NOP();
    digitalWrite(_INC, LOW);
    _delay_us(500);
    digitalWrite(_INC, HIGH);
    _delay_us(500);
    digitalWrite(_Cs, HIGH);
    _NOP();
}