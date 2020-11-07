#ifndef TIMER0_H_
#define TIMER0_H_

#include <avr/io.h>
#include <avr/interrupt.h>

class myTimer0
{
private:
    /* data */
public:
    myTimer0();
    ~myTimer0();

    void start();
	void stop();
};

#endif