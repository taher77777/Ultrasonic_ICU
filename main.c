#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "GIE_interface.h"
#include "USART_interface.h"
#include "util/delay.h"


void ISR();
void main()
{
	PORT_voidInit();
	USART_voidInit();
	ULTRASONIC_voidSetCallBack(ISR);
	ULTRASONIC_u8Init();
	GIF_voidEnable();


	while(1)
	{
		_delay_ms(1000);
		ULTRASONIC_voidStart();

	}
}

void ISR()
{
	UART_voidDisplayNumber(ULTRASONIC_u8GETReadCM());
}
