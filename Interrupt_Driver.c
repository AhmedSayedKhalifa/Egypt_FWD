#define INTERRUPT_CTRL_SYSTICK  (*(( volatile unsigned long *)0xE000ED04 ) ) /* 25th Bit Clear The Interupt Pending Flag & 26th Status Of Pending*/

#define CONTROL_SYSTICK        	(*(( volatile unsigned long *)0xE000E010 ) ) /* 111 First Bit Enables System Timer , Second Bit Enables Interrupt , Third Bit  Choose Clock Source -> System Clock 16 MegaHZ*/

/*Offset 3FC is added to open modification for all pins of port*/
/*1:PORT A*/
#define GPIO_PORTA_DATA_REGISTER (*(( volatile unsigned long *)0x400043FC ) ) /*DATA IN PORT WITH MASK FOR ALLOWING PINS*/

/*2:PORT B*/
#define GPIO_PORTB_DATA_REGISTER (*(( volatile unsigned long *)0x400053FC ) ) /*DATA IN PORT WITH MASK FOR ALLOWING PINS*/

/*3:PORT C*/
#define GPIO_PORTC_DATA_REGISTER (*(( volatile unsigned long *)0x400063FC ) ) /*DATA IN PORT WITH MASK FOR ALLOWING PINS*/

/*4:PORT D*/
#define GPIO_PORTD_DATA_REGISTER (*(( volatile unsigned long *)0x400073FC ) ) /*DATA IN PORT WITH MASK FOR ALLOWING PINS*/

/*5:PORT E*/
#define GPIO_PORTE_DATA_REGISTER (*(( volatile unsigned long *)0x400243FC ) ) /*DATA IN PORT WITH MASK FOR ALLOWING PINS*/

/*6:PORT F*/
#define GPIO_PORTF_DATA_REGISTER (*(( volatile unsigned long *)0x400253FC ) ) /*DATA IN PORT WITH MASK FOR ALLOWING PINS*/

void Interrupt_Initialization(void);






void Interrupt_Initialization(){
CONTROL_SYSTICK|=(1<<1);/*Enable Interupt Of SysTick*/
}
extern char PORT_Name_Required;
extern int  PIN_Number_Required;

void SysTick_Handler(void){
	if       (PORT_Name_Required =='A')
	{
		GPIO_PORTA_DATA_REGISTER^=(1<<(PIN_Number_Required));
	}
	else if  (PORT_Name_Required =='B')
	{
		GPIO_PORTB_DATA_REGISTER^=(1<<(PIN_Number_Required));
	}
	else if  (PORT_Name_Required =='C')
	{
		GPIO_PORTC_DATA_REGISTER^=(1<<(PIN_Number_Required));
	}
	else if  (PORT_Name_Required =='D')
	{
		GPIO_PORTD_DATA_REGISTER^=(1<<(PIN_Number_Required));
	}
	else if  (PORT_Name_Required =='E')
	{
		GPIO_PORTE_DATA_REGISTER^=(1<<(PIN_Number_Required));
	}
	else if  (PORT_Name_Required =='F')
	{
		GPIO_PORTF_DATA_REGISTER^=(1<<(PIN_Number_Required));
	}
	INTERRUPT_CTRL_SYSTICK |= (1<<25);
}