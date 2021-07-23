#include <avr/io.h>
#include <util/delay.h>

unsigned char A[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned int i=0;
unsigned char d1,d2,d3,d4;
void init(void);
void ssd(void);
void decode(void);
int main(void){
	init();
	while(1){
		if(PIND & (1<<6)){
			while(i<10000){
				if(i==10000) i=0;
				ssd();
				decode();
				i++;
			}
		}
	}
    return 0;
}
void init(void){
	DDRB = 0xff;
	DDRA = 0xff;
	DDRD = DDRD | 1<<0 | 1<<1 |1<<2 |1<<3;
	DDRD = DDRD & ~(1<<6);
}
void ssd(void){

	PORTA = 0xff;
	
	PORTB = A[d4];
	PORTD = PORTD | (1<<3);
	_delay_ms(1);
	PORTD = PORTD & ~(1<<3);
		
	PORTB = A[d3];
	PORTD = PORTD | (1<<2);
	_delay_ms(1);
	PORTD = PORTD & ~(1<<2);
	
	PORTB = A[d2];
	PORTD = PORTD | (1<<1);
	_delay_ms(1);
	PORTD = PORTD & ~(1<<1);
	
	PORTB = A[d1];
	PORTD = PORTD | (1<<0);
	_delay_ms(1);
	PORTD = PORTD & ~(1<<0);
}
void decode(void){
	d1=i/1000;		
	d2=(i%1000)/100;
	d3=(i%100)/10;
	d4=i%10;
}

	

