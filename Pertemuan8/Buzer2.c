#include <mega32.h>
#include <delay.h>

void main (){

    DDRC.0=1;  
    
    while (1){
        PORTC.0=1;
        delay_ms(50);
        PORTC.0=0;
        delay_ms(50);
    }       
    
}