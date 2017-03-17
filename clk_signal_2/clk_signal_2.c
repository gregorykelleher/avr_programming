
#include <avr/io.h>
#include <util/delay.h>
#include <Arduino.h>

void setup()
{
    pinMode(44,OUTPUT);

    // enable OCR5A and OCR5B in mode 15, fast PWM with OCR5A as TOP
    TCCR5A |= (1<<COM5A1) | (1<<COM5B0) | (1<<WGM51) | (1<<WGM50);

    // no prescaling CLK/1
    TCCR5B |= (1<<WGM53) | (1<<WGM52) | (1<<CS50);

    // no interrupts
    TIMSK5 = 0;

    // 33% duty cycle
    OCR5A = 3;
    OCR5B = 2;
}

void loop()
{

}

