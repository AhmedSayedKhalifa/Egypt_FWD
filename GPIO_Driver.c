/*Allow Clock to Work On GPIO*/
/*
SYSCTL_RCGCGPIO_REGISTER|=0x01; //For PORT A
SYSCTL_RCGCGPIO_REGISTER|=0x02; //For PORT B
SYSCTL_RCGCGPIO_REGISTER|=0x04; //For PORT C
SYSCTL_RCGCGPIO_REGISTER|=0x08; //For PORT D
SYSCTL_RCGCGPIO_REGISTER|=0x10; //For PORT E
SYSCTL_RCGCGPIO_REGISTER|=0x20; //For PORT F
SYSCTL_RCGCGPIO_REGISTER|=0x3F; //For ALL PORTs
*/
/*Allow Clock to Work On ADC0 , ADC1*/
/*
SYSCTL_RCGCADC_REGISTER|=0x01; //For ADC0
SYSCTL_RCGCADC_REGISTER|=0x01; //For ADC1
SYSCTL_RCGCADC_REGISTER|=0x03; //For ADC0 & ADC1
*/

#define SYSCTL_RCGCGPIO_REGISTER (*(( volatile unsigned long *)0x400FE608 ) ) /* ENABLE CLOCK FOR GPIO*/
#define SYSCTL_RCGCADC_REGISTER (*(( volatile unsigned long *)0x400FE638 ) ) /* ENABLE CLOCK FOR ADC0 or ADC1*/

/*1:PORT A*/
#define GPIO_PORTA_DATA_REGISTER (*(( volatile unsigned long *)0x400043FC ) ) /*DATA IN PORT*/
#define GPIO_PORTA_DIR_REGISTER  (*(( volatile unsigned long *)0x40004400 ) ) /*DATA DIRECTION OF PORT*/
#define GPIO_PORTA_DEN_REGISTER  (*(( volatile unsigned long *)0x4000451C ) ) /*DIGITAL FUNCTION ENABLE FOR PORT*/

/*2:PORT B*/
#define GPIO_PORTB_DATA_REGISTER (*(( volatile unsigned long *)0x400053FC ) ) 
#define GPIO_PORTB_DIR_REGISTER  (*(( volatile unsigned long *)0x40005400 ) ) 
#define GPIO_PORTB_DEN_REGISTER  (*(( volatile unsigned long *)0x4000551C ) )

/*3:PORT C*/
#define GPIO_PORTC_DATA_REGISTER (*(( volatile unsigned long *)0x400063FC ) ) 
#define GPIO_PORTC_DIR_REGISTER  (*(( volatile unsigned long *)0x40006400 ) ) 
#define GPIO_PORTC_DEN_REGISTER  (*(( volatile unsigned long *)0x4000651C ) )

/*4:PORT D*/
#define GPIO_PORTD_DATA_REGISTER (*(( volatile unsigned long *)0x400073FC ) ) 
#define GPIO_PORTD_DIR_REGISTER  (*(( volatile unsigned long *)0x40007400 ) ) 
#define GPIO_PORTD_DEN_REGISTER  (*(( volatile unsigned long *)0x4000751C ) )

/*5:PORT E*/
#define GPIO_PORTE_DATA_REGISTER (*(( volatile unsigned long *)0x400243FC ) ) 
#define GPIO_PORTE_DIR_REGISTER  (*(( volatile unsigned long *)0x40024400 ) ) 
#define GPIO_PORTE_DEN_REGISTER  (*(( volatile unsigned long *)0x4002451C ) )

/*6:PORT F*/
#define GPIO_PORTF_DATA_REGISTER (*(( volatile unsigned long *)0x400253FC ) ) 
#define GPIO_PORTF_DIR_REGISTER  (*(( volatile unsigned long *)0x40025400 ) ) 
#define GPIO_PORTF_DEN_REGISTER  (*(( volatile unsigned long *)0x4002551C ) )

void GPIO_Inintialization (char PORT_Name,int PIN_Number);

/*
ANALOG PIN

AN0	 PE3	6
AN1	 PE2	7
AN2	 PE1	8
AN3	 PE0	9
AN4	 PD3	64
AN5	 PD2	63
AN6	 PD1	62
AN7	 PD0	61
AN8	 PE5	60
AN9	 PE4	59
AN10 PB4	58
AN11 PB5	57

*/



void GPIO_Inintialization (char PORT_Name,int PIN_Number){
	SYSCTL_RCGCGPIO_REGISTER |=(1<<((PORT_Name)-'A'));
	if       (PORT_Name =='A')
	{
		GPIO_PORTA_DEN_REGISTER|=(1<<(PIN_Number));
		GPIO_PORTA_DIR_REGISTER|=(1<<(PIN_Number));/*0 FOR INPUT , 1 FOR OUTPUT*/
	}
	else if  (PORT_Name =='B')
	{
		GPIO_PORTB_DEN_REGISTER|=(1<<(PIN_Number));
		GPIO_PORTB_DIR_REGISTER|=(1<<(PIN_Number));/*0 FOR INPUT , 1 FOR OUTPUT*/
	}
	else if  (PORT_Name =='C')
	{
		GPIO_PORTC_DEN_REGISTER|=(1<<(PIN_Number));
		GPIO_PORTC_DIR_REGISTER|=(1<<(PIN_Number));/*0 FOR INPUT , 1 FOR OUTPUT*/
	}
	else if  (PORT_Name =='D')
	{
		GPIO_PORTD_DEN_REGISTER|=(1<<(PIN_Number));
		GPIO_PORTD_DIR_REGISTER|=(1<<(PIN_Number));/*0 FOR INPUT , 1 FOR OUTPUT*/
	}
	else if  (PORT_Name =='E')
	{
		GPIO_PORTE_DEN_REGISTER|=(1<<(PIN_Number));
		GPIO_PORTE_DIR_REGISTER|=(1<<(PIN_Number));/*0 FOR INPUT , 1 FOR OUTPUT*/
	}
	else if  (PORT_Name =='F')
	{
		GPIO_PORTF_DEN_REGISTER|=(1<<(PIN_Number));
		GPIO_PORTF_DIR_REGISTER|=(1<<(PIN_Number));/*0 FOR INPUT , 1 FOR OUTPUT*/
	}
}