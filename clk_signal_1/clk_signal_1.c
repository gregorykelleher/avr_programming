
#include <avr/io.h>
#include <util/delay.h>

// PL5 (OC5C) as pwm output
// fast PWM: PWM_frequency = clock_speed / [Prescaler_value * (1 + TOP_Value)]
// pwm frequency = (16,000,000)/(1*(1+3)) = 4,000,000 Hz

int main (void)
{

    DDRL = 0x20; // set port L bit five (PL5) to output

    // mode 14, fast pwm, set on match, clear at top, ICR5 holds TOP (TCCR5A = 0x0E)
    TCCR5A |= (1<<COM5C1) | (1<<COM5C0) | (1<<WGM51);

    // ICR5 as TOP, CLK prescaler /1 (TCCR5B = 0x19)
    TCCR5B |= (1<<WGM53) | (1<<WGM52) | (1<<CS50);

    // no interrupts
    TIMSK5 = 0;

    // 33% duty cycle
    OCR5C = 2;
    ICR5 = 3;

}

