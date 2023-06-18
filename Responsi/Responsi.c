#include <mega32.h>
#include <delay.h>
#include <stdio.h>
#include <alcd.h>


char ConvertTo7Seg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};   // 7Seg Data Array

void main(void)

{
    int counter=0,i;

    DDRD=0xff;                            
    PORTD=0x00;                             
    
    DDRA.0=0;                               
    PORTA.0=1;                              
    PORTC.0=1;
    
    PORTD=ConvertTo7Seg[counter];   
    
    lcd_init(16);        

    while(1)                                
    {
        if(PINA.0==0)                       
        {
          if(counter<9)counter++;           
          PORTD=ConvertTo7Seg[counter];      
          
          for(i=0;i<20&&PINA.0==0;i++)      
          {                                 
           delay_ms(50);                                        
          }
          
          while(PINA.0==0)                  
          {
              counter++;                    
              if(counter>9)counter=0;       
              PORTD=ConvertTo7Seg[counter];  
              delay_ms(500);                
          }
        }     
        
    
        
          
    }  
    
    
    
    
    
}
