/*#include<TM4C123GH6PM.h>*/
#define INTERRUPT_CTRL_SYSTICK  (*(( volatile unsigned long *)0xE000ED04 ) ) /* 25th Bit Clear The Interupt Pending Flag & 26th  */
#define LOAD_SYSTICK 	          (*(( volatile unsigned long *)0xE000E014 ) )   /* Number Of Counts To Raise Flag*/
#define CONTROL_SYSTICK        	(*(( volatile unsigned long *)0xE000E010 ) ) /* 111 First Bit Enables System Timer , Second Bit Enables Interrupt , Third Bit  Choose Clock Source -> System Clock 16 MegaHZ*/
#define VALUE_SYSTICK        	  (*(( volatile unsigned long *)0xE000E018 ) )   /* Initialization For Current Value In Register*/

void TIMER_Initialization(unsigned long DivisorForTimer);

void TIMER_Initialization(unsigned long DivisorForTimer)
{
	
	/*Source Clock is System Clock = 16 Mega HZ , So 16 MegaCycle Equals 1 Sec */
	LOAD_SYSTICK     = (16000000/DivisorForTimer)-1; /*Interupt Every = 1 Sec / Divisor*/
	
	CONTROL_SYSTICK |= 5;/*101*/ 
	VALUE_SYSTICK    = 0; 
}	
