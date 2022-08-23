extern void GPIO_Inintialization        (char PORT_Name,int PIN_Number);
extern void TIMER_Initialization        (unsigned long DivisorForTimer);
extern void Interrupt_Initialization    (void);


char PORT_Name_Required='F';/*A,B,C,D,F*/
int  PIN_Number_Required=4;/*Starting From Zero*/

	/*
		TimeInterval =(1/Interval_Required ) * (1 sec)
		---Time Interval For Blinking Equals One Hundred Millisecond---
	*/
	
unsigned long Interval_Required=100; 

int main()
{


	
	GPIO_Inintialization     (PORT_Name_Required,PIN_Number_Required);
	TIMER_Initialization     (Interval_Required) ;
	Interrupt_Initialization (                 );
	while(1)
	{
	}
}