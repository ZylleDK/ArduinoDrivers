#include <Arduino.h>
#include "DS1804.h"


DS1804 pot(7, 6, 5);
  
uint8_t _pos = 0;
uint8_t _dir = 1;

int main() 
{

  while (1)
  {
    if (_dir == 1)
    {
      if (_pos < 100)
      {
        pot.stepUp();
        _pos++;
      }
      else
      {
        _dir = 0;
        pot.stepDown();
        _pos--;
      }     
    }
    else if (_dir == 0)
    {
      if (_pos > 0)
      {
        pot.stepDown();
        _pos--;
      }
      else
      {
        _dir = 1;
        pot.stepUp();
        _pos++;
      }
    }
  }
}