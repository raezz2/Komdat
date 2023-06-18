#include <mega32.h> 
#include <stdio.h>
#include <delay.h>

#asm
    .equ __lcd_port=0x15;PORTC

#endasm
#include <lcd.h>

int key = 20,step,op,a,b,c; 
char buff[33];

char keypad(){
    PORTD=0b11111110;
    if(PIND.7==0) {key=10;goto run;}        
    if(PIND.6==0) {key=9;goto run;}
    if(PIND.5==0) {key=8;goto run;}
    if(PIND.4==0) {key=7;goto run;} 
    
    PORTD=0b11111101;
    if(PIND.7==0) {key=11;goto run;}        
    if(PIND.6==0) {key=6;goto run;}
    if(PIND.5==0) {key=5;goto run;}
    if(PIND.4==0) {key=4;goto run;}
    
    PORTD=0b11111011;
    if(PIND.7==0) {key=12;goto run;}        
    if(PIND.6==0) {key=3;goto run;}
    if(PIND.5==0) {key=2;goto run;}
    if(PIND.4==0) {key=1;goto run;}        
    
    PORTD=0b11110111;
    if(PIND.7==0) {key=13;goto run;}        
    if(PIND.6==0) {key=14;goto run;}
    if(PIND.5==0) {key=0;goto run;}
    if(PIND.4==0) {key=15;goto run;}   
    
    run:
    return key;
}


void main (void){
    PORTD=0xF0;
    DDRD=0x0F;
    
    lcd_init(16);
    while(1){
        if(step==0){
            key=keypad();
            if(key<10){
                a=key;
                lcd_gotoxy(0,0);
                sprintf(buff,"%d",a);
                lcd_puts(buff); 
                step=1;
                }
                else step=0;
            }
        if(step==4){   
            key=keypad();
            if(key==15){
            lcd_clear();
            step=0;
            }
            else step=4;
        }
        if(step==1){
            key=keypad();
            if(key==10){
                op=4;
                sprintf(buff,"/");
                lcd_puts(buff);
                step=2;
            }    
            if(key==11){
                op=3;
                sprintf(buff,"x");
                lcd_puts(buff);
                step=2;
            } 
            if(key==12){
                op=2;
                sprintf(buff,"-");
                lcd_puts(buff);
                step=2;
            }       
            if(key==13){
                op=1;
                sprintf(buff,"+");
                lcd_puts(buff);
                step=2;
            }    
        }
            if(step==2){
                key=keypad();
                if(key<10){
                    b=key;
                    sprintf(buff,"%d ",b);
                    lcd_puts(buff);
                    step=3;
                }
                else step=2;
            }   
            if(step==3){
                if(op==1){
                    c=a+b;
                    key=keypad();
                    if(key==14){     
                        sprintf(buff,"= %d ",c);
                        lcd_puts(buff);
                        step=4; 
                    }
                else step=3;
                }  
                if(op==2){
                    c=a-b;
                    key=keypad();
                    if(key==14){     
                        sprintf(buff,"= %d ",c);
                        lcd_puts(buff);
                        step=4; 
                    }
                else step=3;
                } 
                if(op==3){
                    c=a*b;
                    key=keypad();
                    if(key==14){     
                        sprintf(buff,"= %d ",c);
                        lcd_puts(buff);
                        step=4; 
                    }
                else step=3;
                }  
                if(op==4){
                    c=a/b;
                    key=keypad();
                    if(key==14){     
                        sprintf(buff,"= %d ",c);
                        lcd_puts(buff);
                        step=4; 
                    }
                else step=3;
                }
            } 
            if(step==4){
                key=keypad();
                if(key==15){
                    lcd_clear();
                    step=0;
                }
                else step=4;
            }
        }    
    }
    