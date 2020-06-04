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

int
main(int argc, char* argv[])
{
	ResetApp1 = (u32*)0x08005004;

	ptr2func_t app1 = (ptr2func_t) *ResetApp1;

	switch (marker)
	{
	case MARKER_APP1:
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













