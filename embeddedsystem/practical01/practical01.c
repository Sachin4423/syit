#include <reg51.h>
void T0Delay(void);
void main(void)
{
	while(1)
	{
		P1 = 0xFF;
		T0Delay();
		P1 = 0x00;
		T0Delay();
	}
}
void T0Delay()
{
	TMOD = 0x01;
	
	TL0 = 0xFC;
	TH0 = 0x65;
	TR0 = 1;
	while (TF0 == 0);
	TR0 = 0;
	TF0 = 0;
}