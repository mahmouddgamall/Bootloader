//#include "diag/Trace.h"
//#include "std_types.h"
//#include "GPIO.h"
//#include "DMA_interface.h"
//#include "SCB_interface.h"
//#include "NVIC_interface.h"
//#include "UART_interface.h"
//#include "HRCC_interfac.h"
//#include "HUART_interface.h"
//#include "flash.h"
//#include"Delay.h"
//
//typedef struct
//{
//	u8* data;
//	u16 size;
//	u16 position;
//	u8 state;
//}UART_data_t;
//
//extern UART_data_t UART_RxBuffer;
//
//u8 BUFFER[10];
//u8 Data[11][1026];
//u8 flag = 0;
//u32 DataCounter;
//u16 count = 0;
//
//
//
//void receive(void){
//	flag++;
//}
//
//
//void hmada(void)
//{
//}
//#define     BL_VERIFY_OK                0x5555
//#define DELAY_VALUE   3000
//
//int
//main(int argc, char* argv[])
//{
//	HRCC_SetSysClock(HRCC_CLOCK_8_MHZ_ENTERNAL);
//
//
//	for (u32 i=7;i<=10;i++)
//	{
//		for (u32 j=0;j<1024;j++)
//		{
//			Data[i][j]=0xFF;
//		}
//	}
//	u16 OK = BL_VERIFY_OK;
//
//	HUART_voidInit(UART_CHANNEL_1);
//	UART_errSetCallBackRecieve(UART_CHANNEL_1,receive);
//	UART_errSetCallBackTrans  (UART_CHANNEL_1,receive);
//	HUART_errRecieve(UART_CHANNEL_1, BUFFER, 8);
//	static u8 PrevFlag = 255;
//	while(1)
//	{
//		if(flag == 1)
//		{
//			if (flag != PrevFlag)
//			{
//				PrevFlag = flag ;
//				for(u8 i = 0 ; i < 8 ; i ++)
//				{
//					trace_printf("%x\n", BUFFER[i]);
//				}
//				Delay_ms(DELAY_VALUE);
//				HUART_errTransmit(UART_CHANNEL_1, &OK, 2);
//			}
//		}
//
//		else if(flag == 2)
//		{
//			//	Delay_ms(500);
//
//			HUART_errRecieve(UART_CHANNEL_1, Data,1026 );
//
//		}
//		else if ( flag > 2 && flag < 24)
//		{
//			if ( flag != PrevFlag)
//			{
//				PrevFlag = flag ;
//				if (flag %2 != 0 )
//				{
//					DataCounter +=1;
//					trace_printf("===flag= %d \n",flag);
//					Delay_ms(DELAY_VALUE);
//					HUART_errTransmit(UART_CHANNEL_1, (u8*)&OK, 2);
//				}
//				else
//				{
//					HUART_errRecieve(UART_CHANNEL_1, &Data[DataCounter][0],1024 );
//					trace_printf("flag= %d \n",flag);
//				}
//			}
//		}
//
//		else if (flag >20)
//		{
//			trace_printf("\n\n\n\Finished\n");
//
//			for (u32 i=10;i<=10;i++)
//			{
//				for (u32 j=0;j<1024;j++)
//				{
//					trace_printf("%x",Data[i][j]);
//				}
//				trace_printf("\n");
//
//			}
//			while(1);
//		}
//	}
//	return 0;
//}
//
//
