

#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

void sweep (void)
{
    int d_cnt = 4;
    for(int i=0; i<4; i++)
    {
        PORTD |= _BV(d_cnt);
        _delay_ms(100);
        d_cnt++;
    }

    for(int j=0; j<5; j++)
    {
        PORTB |= _BV(j);
        _delay_ms(100);
    }

    PORTB &= ~(0x1F);
    PORTD &= ~(0xE0);
}


int main (void)
{
    DDRD |= 0xFF;
    DDRB |= 0xFF;

    PORTB |= 0x00;
    PORTD |= 0x00;

    while(1) 
    {
        sweep();
    }
}

