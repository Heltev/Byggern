/*
 * gr13.c
 *
 * Created: 27.08.2015 10:52:52
 *  Author: Administrator
 */ 


#include <avr/io.h>
#include <util/delay.h>


#define FOSC 4915200// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

int main(void)
{
	DDRA |= (1<<DDA1);
	
	
	      
	USART_Init(31);
    while(1)
	
    {
		 PORTA |= (1<<PINA1);
		 _delay_ms(1000);
		 PORTA &= ~(1<<PINA1);
		 _delay_ms(1000);
		 USART_Transmit('a');
		 USART_Transmit('b');
		 USART_Transmit('p');
		 USART_Transmit('e');
		 USART_Transmit('n');
		 USART_Transmit('i');
		 USART_Transmit('s');
		 USART_Transmit('2');
		 USART_Transmit('\n');

    }
}

void USART_Init(unsigned int ubrr){
	
	/* Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	/*Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	/*Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<URSEL0)|(1<<USBS0)|(3<<UCSZ00);
}

void USART_Transmit(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0)))
		;	
	
	UDR0=data;
}

unsigned char USART_Receive(){
	while( !(UCSR0A & (1<<RXC0))){
		
	}
	return UDR0;
}

/*void fdevopen(USART_Transmit(), USART_Receive()){
	

}*/