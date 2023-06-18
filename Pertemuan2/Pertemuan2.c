#include <mega32.h>
#include <delay.h>

int i;
void main ()
{
	DDRC = 0xFF; //output
	while (1)
	{
	//place your code here
	PORTC = 0b10000000;
    delay_ms (200);
    for (i=0; i<7; i++) {
        PORTC >>= 1;
        delay_ms(200);
	}         
    
    PORTC = 0b00000001;
    delay_ms (200);
    for (i=0; i<7; i++) {
        PORTC <<= 1;
        delay_ms(200);
	}    
    }
}
