#include <avr/io.h>

#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5

class myADC
{
private:
    
public:
    myADC();
    ~myADC();

    void turnOnPin(uint8_t pin);
    int readValue(uint8_t pin);
};
