#ifndef TIMER2_H_
#define TIMER2_H_

#include <avr/io.h>
#include <avr/interrupt.h>

class myTimer2
{
private:
    /* data */
public:
    myTimer2();
    ~myTimer2();

    void start();
	void stop();
};

#endif