#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H



#define			NVIC_GROUPS_16_SUBGROUPS_0   	0b011
#define			NVIC_GROUPS_8_SUBGROUPS_2   	0b100
#define			NVIC_GROUPS_4_SUBGROUPS_4   	0b101
#define			NVIC_GROUPS_2_SUBGROUPS_8   	0b110
#define			NVIC_GROUPS_0_SUBGROUPS_16   	0b111

#define 		NVIC_WWDG												(u8)0		
#define 		NVIC_PVD												(u8)1	
#define 		NVIC_TAMPER											(u8)2			
#define 		NVIC_RTC												(u8)3	
#define 		NVIC_FLASH											(u8)4		
#define 		NVIC_RCC												(u8)5	
#define 		NVIC_EXTI0											(u8)6		
#define 		NVIC_EXTI1											(u8)7		
#define 		NVIC_EXTI2											(u8)8		
#define 		NVIC_EXTI3											(u8)9		
#define 		NVIC_EXTI4											(u8)10		
#define 		NVIC_DMA1_Channel1							(u8)11						
#define 		NVIC_DMA1_Channel2							(u8)12
#define 		NVIC_DMA1_Channel3							(u8)13										
#define 		NVIC_DMA1_Channel4							(u8)14									
#define 		NVIC_DMA1_Channel5							(u8)15									
#define 		NVIC_DMA1_Channel6							(u8)16									
#define 		NVIC_DMA1_Channel7							(u8)17									
#define 		NVIC_ADC1_2											(u8)18						
#define 		NVIC_USB_HP_CAN_TX							(u8)19									
#define 		NVIC_USB_LP_CAN_RX0							(u8)20										
#define 		NVIC_CAN_RX1										(u8)21						
#define 		NVIC_CAN_SCE										(u8)22						
#define 		NVIC_EXTI9_5										(u8)23						
#define 		NVIC_TIM1_BRK										(u8)24							
#define 		NVIC_TIM1_UP										(u8)25						
#define 		NVIC_TIM1_TRG_COM								(u8)26									
#define 		NVIC_TIM1_CC										(u8)27						
#define 		NVIC_TIM2												(u8)28					
#define 		NVIC_TIM3												(u8)29					
#define 		NVIC_TIM4												(u8)30					
#define 		NVIC_I2C1_EV										(u8)31						
#define 		NVIC_I2C1_ER										(u8)32						
#define 		NVIC_I2C2_EV										(u8)33						
#define 		NVIC_I2C2_ER										(u8)34						
#define 		NVIC_SPI1												(u8)35					
#define 		NVIC_SPI2												(u8)36					
#define 		NVIC_USART1											(u8)37						
#define 		NVIC_USART2											(u8)38						
#define 		NVIC_USART3											(u8)39						
#define 		NVIC_EXTI15_10									(u8)40							
#define 		NVIC_RTCAlarm										(u8)41						
#define 		NVIC_USBWakeup									(u8)42						
#define 		NVIC_TIM8_BRK										(u8)43						
#define 		NVIC_TIM8_UP										(u8)44					
#define 		NVIC_TIM8_TRG_COM								(u8)45								
#define 		NVIC_TIM8_CC										(u8)46					
#define 		NVIC_ADC3												(u8)47				
#define 		NVIC_FSMC												(u8)48				
#define 		NVIC_SDIO												(u8)49				
#define 		NVIC_TIM5												(u8)50				
#define 		NVIC_SPI3												(u8)51				
#define 		NVIC_UART4											(u8)52				
#define 		NVIC_UART5											(u8)53				
#define 		NVIC_TIM6												(u8)54				
#define 		NVIC_TIM7												(u8)55				
#define 		NVIC_DMA2_Channel1							(u8)56								
#define 		NVIC_DMA2_Channel2							(u8)57								
#define 		NVIC_DMA2_Channel3							(u8)58								
#define 		NVIC_DMA2_Channel4_5						(u8)59												


#define			NVIC_MAX_NUMBER_OF_Interrupts				(u8)60

extern ErrorStatus NVIC_errEnableInterrupt(u8 NVIC_Priority);

extern ErrorStatus NVIC_errDisableInterrupt(u8 NVIC_Priority);

extern ErrorStatus NVIC_errSetPendingFlag(u8 NVIC_Priority);

extern ErrorStatus NVIC_errClrPendingFlag(u8 NVIC_Priority);

extern ErrorStatus NVIC_errSetPriority(u8 NVIC_Priority, u8 In_u8Group, u8 In_u8SubGroup);

extern u8 NVIC_u8GetActiveFlag(u8 NVIC_Priority);

extern ErrorStatus SCB_errSetGroupSubgroupRatio(void);

extern void NVIC_voidDisableAllExceptions(void);

extern void NVIC_voidEnableAllExceptions(void);

extern void NVIC_voidEnableAllExternalInterrupt(void);

extern void NVIC_voidDisableAllExternalInterrupt(void);

extern void NVIC_voidSetBaseInterruptPriority(u8 In_u8Priority);
extern void NVIC_voidClearBaseInterruptPriority(void);


extern void NVIC_voidEnableBusFaultException(void);
extern void NVIC_voidDisableBusFaultException(void);

extern void NVIC_voidEnableUsageFaultException(void);
extern void NVIC_voidDisableUsageFaultException(void);

extern void NVIC_voidEnableMemoryFaultException(void);
extern void NVIC_voidDisableMemoryFaultException(void);


extern ErrorStatus NVIC_errSoftWareInterruptEnable(u8 NVIC_Priority);

#endif
