#include "diag/Trace.h"
#include "std_types.h"
#include "GPIO.h"
#include "flash.h"
#include "DMA_interface.h"
#include "SCB_interface.h"
#include "NVIC_interface.h"
#include "UART_interface.h"
#include "HRCC_interfac.h"
#include "HUART_interface.h"
#include "bl_com_interface.h"

__attribute__((section(".BL_marker"),used))
const volatile u16 marker = MARKER_NO_APP ;		//must be volatile or the code specified at the switch case will be removed by the compiler

extern new_app_t new_app;

extern unsigned int _estack;


void setFlag(void);

u8 flag = 0;
volatile
u32 * ResetApp1;


/*
 * 1- if there is no app, the BL will always be waiting for an app
 * 2- If there is an app, the BL will run this APP by default
 * 3- If you need to flash a new App, connect the C14 to the GND
 *
 * */


int
main(int argc, char* argv[])
{
	u32 pinvalue=2;
	/*	point at the reset of the new app to be able to go to the startup code	*/
	ResetApp1 = (u32*)0x08003C04;
	ptr2func_t app1 = (ptr2func_t) *ResetApp1;
	/*	use port C as an input pull up so as to indicate the need to flash a new app	*/
	HRCC_EnablePeripheral(HRCC_PERIPHERAL_APB2ENR_IOPCEN);
	GPIO_InitPin(GPIO_PORT_C,GPIO_PIN14,GPIO_MODE_INPUT_PULLUP);
	GPIO_GetPinVal(GPIO_PORT_C,GPIO_PIN14,&pinvalue);

	if(pinvalue == GPIO_VALUE_HIGH)
	{
		switch (marker)
		{
		case MARKER_APP1:
			/*	point the stack pointer to the end of the stack so that the new app can have the full stack to its needs	*/
			asm("ldr r1, =_estack\n"
					"mov sp, r1");
			app1();
			break;

		default:


			HRCC_SetSysClock(HRCC_CLOCK_8_MHZ_ENTERNAL);
			HUART_voidInit(UART_CHANNEL_1);
			UART_errSetCallBackRecieve(UART_CHANNEL_1,setFlag);
			FLASH_unlockRegisters();
			HUART_errRecieve(UART_CHANNEL_1,(u8*)&new_app,8);
			while(1)
			{
				if(marker != MARKER_NO_APP)
				{
					/*	if there is an app, then reset all peripherals, reset all peripherals then reset the controller so as to be able to use it	*/
					HRCC_ResetPeripheral(HRCC_RST_ALL);

					SCB_Reset();
				}
				else
				{
						/*	this flag indactes that some data has been received	*/
					if (flag == 1)
					{
						/*	clearing the flag so as to be able to sense any new data	*/
						flag = 0;
						BLcomm_handler();
					}
				}
			}
		}
	}
	else if(pinvalue == GPIO_VALUE_LOW)
	{
		HRCC_SetSysClock(HRCC_CLOCK_8_MHZ_ENTERNAL);
		HUART_voidInit(UART_CHANNEL_1);
		UART_errSetCallBackRecieve(UART_CHANNEL_1,setFlag);
		FLASH_unlockRegisters();
		HUART_errRecieve(UART_CHANNEL_1,(u8*)&new_app,8);
		FLASH_eraseSection((u16*)&marker);

		u16 markerValue = MARKER_NO_APP;
		FLASH_writeHalfWord(&marker,&markerValue);
		while(1)
		{
			if(marker != MARKER_NO_APP)
			{
				HRCC_ResetPeripheral(HRCC_RST_ALL);

				SCB_Reset();
			}
			else
			{
				if (flag == 1)
				{
					flag = 0;
					BLcomm_handler();
				}
			}
		}
	}
}

// ----------------------------------------------------------------------------



void setFlag(void)
{
	flag = 1;
}













