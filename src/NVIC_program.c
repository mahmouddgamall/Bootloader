#include "std_types.h"

#include "NVIC_config.h"
#include "NVIC_interface.h"


#define	NVIC_SETENA0			*((volatile u32*)0xE000E100)
#define	NVIC_SETENA1			*((volatile u32*)0xE000E104)
#define	NVIC_SETENA2			*((volatile u32*)0xE000E108)
#define	NVIC_SETENA3			*((volatile u32*)0xE000E110)
#define	NVIC_SETENA4			*((volatile u32*)0xE000E114)
#define	NVIC_SETENA5			*((volatile u32*)0xE000E118)
#define	NVIC_SETENA6			*((volatile u32*)0xE000E120)
#define	NVIC_SETENA7			*((volatile u32*)0xE000E124)

#define	NVIC_CLRENA0			*((volatile u32*)0xE000E180)
#define	NVIC_CLRENA1			*((volatile u32*)0xE000E184)
#define	NVIC_CLRENA2			*((volatile u32*)0xE000E188)
#define	NVIC_CLRENA3			*((volatile u32*)0xE000E190)
#define	NVIC_CLRENA4			*((volatile u32*)0xE000E194)
#define	NVIC_CLRENA5			*((volatile u32*)0xE000E198)
#define	NVIC_CLRENA6			*((volatile u32*)0xE000E1A0)
#define	NVIC_CLRENA7			*((volatile u32*)0xE000E1A4)


#define	NVIC_SETPEND0			*((volatile u32*)0xE000E200)
#define	NVIC_SETPEND1			*((volatile u32*)0xE000E204)
#define	NVIC_SETPEND2			*((volatile u32*)0xE000E208)
#define	NVIC_SETPEND3			*((volatile u32*)0xE000E210)
#define	NVIC_SETPEND4			*((volatile u32*)0xE000E214)
#define	NVIC_SETPEND5			*((volatile u32*)0xE000E218)
#define	NVIC_SETPEND6			*((volatile u32*)0xE000E220)
#define	NVIC_SETPEND7			*((volatile u32*)0xE000E224)


#define	NVIC_CLRPEND0			*((volatile u32*)0xE000E280)
#define	NVIC_CLRPEND1			*((volatile u32*)0xE000E284)
#define	NVIC_CLRPEND2			*((volatile u32*)0xE000E288)
#define	NVIC_CLRPEND3			*((volatile u32*)0xE000E290)
#define	NVIC_CLRPEND4			*((volatile u32*)0xE000E294)
#define	NVIC_CLRPEND5			*((volatile u32*)0xE000E298)
#define	NVIC_CLRPEND6			*((volatile u32*)0xE000E2A0)
#define	NVIC_CLRPEND7			*((volatile u32*)0xE000E2A4)


#define	NVIC_ACTIVE0			*((volatile u32*)0xE000E300)
#define	NVIC_ACTIVE1			*((volatile u32*)0xE000E304)
#define	NVIC_ACTIVE2			*((volatile u32*)0xE000E308)
#define	NVIC_ACTIVE3			*((volatile u32*)0xE000E310)
#define	NVIC_ACTIVE4			*((volatile u32*)0xE000E314)
#define	NVIC_ACTIVE5			*((volatile u32*)0xE000E318)
#define	NVIC_ACTIVE6			*((volatile u32*)0xE000E320)
#define	NVIC_ACTIVE7			*((volatile u32*)0xE000E324)

#define	NVIC_PRI					((volatile u8*)0xE000E400)

#define	NVIC_SHCSR			*((volatile u32*)0xE000ED24)
#define	NVIC_STIR				*((volatile u32*)0xE000EF00)


#define SCB_AIRCR					*((volatile u32*)0xE000ED0C)

#define NVIC_BUS_FAULT_ENABLE						0x00020000
#define NVIC_BUS_FAULT_DISABLE					0xFFFDFFFF

#define NVIC_MEMORY_FAULT_ENABLE				0x00010000
#define NVIC_MEMORY_FAULT_DISABLE				0xFFFEFFFF

#define NVIC_USAGE_FAULT_ENABLE					0x00040000
#define NVIC_USAGE_FAULT_DISABLE				0xFFFBFFFF

#define	NVIC_HARD_FAULT_STATUS					*((volatile u32*)0xE000ED2A)


ErrorStatus NVIC_errEnableInterrupt(u8 In_u8Peripheral)
{
	u8 status = OK;
		/*	since the register is only 32 bits wide, 
		a check must be make to insure that this In_u8Peripheral is for the first register	*/
	if( (In_u8Peripheral < 32) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		NVIC_SETENA0 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 64) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 32;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts. 
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_SETENA1 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 96) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 64;
/*	Although the NVIC has got 240 ExtInt available to be use,
				some controllers don't implement all of them.
				Please Check that datasheet of your controller*/
		NVIC_SETENA2 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 128) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 96;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_SETENA3 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 160) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 128;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_SETENA4 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 192) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 160;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_SETENA5 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 224) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 192;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_SETENA6 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 224) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 256;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_SETENA7 |= (1<<In_u8Peripheral);
	}

	else
	{
		status =NOK;
	}
	return status;
}

ErrorStatus NVIC_errDisableInterrupt(u8 In_u8Peripheral)
{
	u8 status = OK;
		/*	since the register is only 32 bits wide, 
		a check must be make to insure that this In_u8Peripheral is for the first register	*/
	if( (In_u8Peripheral < 32) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		NVIC_CLRENA0 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 64) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 32;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts. 
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_CLRENA1 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 96) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 64;
/*	Although the NVIC has got 240 ExtInt available to be use,
				some controllers don't implement all of them.
				Please Check that datasheet of your controller*/
		NVIC_CLRENA2 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 128) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 96;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_CLRENA3 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 160) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 128;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_CLRENA4 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 192) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 160;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_CLRENA5 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 224) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 192;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_CLRENA6 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 224) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 256;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_CLRENA7 |= (1<<In_u8Peripheral);
	}

	else
	{
		status =NOK;
	}
	return status;
}

ErrorStatus NVIC_errSetPendingFlag(u8 In_u8Peripheral)
{
	u8 status = OK;
		/*	since the register is only 32 bits wide, 
		a check must be make to insure that this In_u8Peripheral is for the first register	*/
	if( (In_u8Peripheral < 32) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		NVIC_SETPEND0 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 64) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 32;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts. 
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_SETPEND1 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 96) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 64;
/*	Although the NVIC has got 240 ExtInt available to be use,
				some controllers don't implement all of them.
				Please Check that datasheet of your controller*/
		NVIC_SETPEND2 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 128) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 96;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_SETPEND3 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 160) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 128;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_SETPEND4 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 192) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 160;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_SETPEND5 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 224) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 192;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_SETPEND6 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 224) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 256;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_SETPEND7 |= (1<<In_u8Peripheral);
	}

	else
	{
		status =NOK;
	}
	return status;
}

ErrorStatus NVIC_errClrPendingFlag(u8 In_u8Peripheral)
{
	u8 status = OK;
		/*	since the register is only 32 bits wide, 
		a check must be make to insure that this In_u8Peripheral is for the first register	*/
	if( (In_u8Peripheral < 32) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		NVIC_CLRPEND0 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 64) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 32;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts. 
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_CLRPEND1 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 96) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 64;
/*	Although the NVIC has got 240 ExtInt available to be use,
				some controllers don't implement all of them.
				Please Check that datasheet of your controller*/
		NVIC_CLRPEND2 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 128) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 96;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_CLRPEND3 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 160) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 128;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_CLRPEND4 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 192) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 160;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_CLRPEND5 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 224) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 192;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_CLRPEND6 |= (1<<In_u8Peripheral);
	}
	else if( (In_u8Peripheral < 224) && (In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts) )
	{
		In_u8Peripheral -= 256;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts.
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		NVIC_CLRPEND7 |= (1<<In_u8Peripheral);
	}

	else
	{
		status =NOK;
	}
	return status;
}


u8 NVIC_u8GetActiveFlag(u8 In_u8Peripheral)
{
	u8 flag = 0;
		/*	since the register is only 32 bits wide, 
		a check must be make to insure that this In_u8Peripheral is for the first register	*/
	if( In_u8Peripheral < 32 )		
	{
		flag = (NVIC_ACTIVE0 >> In_u8Peripheral) & 1;
	}
	else if( In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts )
	{
		In_u8Peripheral -= 32;
/*	Although the NVIC has got 240 ExtInt available to be use,
				STM32F10 only has 59 Interrupts. 
				Please Check that datasheet of your controller,
				and feel free to change this driver accordingly*/
		flag = (NVIC_ACTIVE1 >> In_u8Peripheral) & 1;
	}
	
	return flag;
}


ErrorStatus NVIC_errSetPriority(u8 In_u8Peripheral, u8 In_u8Group, u8 In_u8SubGroup)
{
	u8 status = NOK;
	if( (In_u8Group<<(NVIC_GROUP_SUBGROUP_RATIO+1)) <= 0xFF )
	{
		status = OK;
		NVIC_PRI[In_u8Peripheral] = ((In_u8Group<<(NVIC_GROUP_SUBGROUP_RATIO+1))|In_u8SubGroup<<NVIC_START_SUBGROUP_BIT);
	}
	return  status;
}


ErrorStatus SCB_errSetGroupSubgroupRatio(void)
{
	u8 status = NOK;
	if(((NVIC_GROUP_SUBGROUP_RATIO >= 0x0) && (NVIC_GROUP_SUBGROUP_RATIO <= 0x7) ) )
	{
		status = OK;
		u32 Local_u32tempRegister =  SCB_AIRCR;
		Local_u32tempRegister &= 0x0000F0FF;
		Local_u32tempRegister = 0x05FA0000 | (NVIC_GROUP_SUBGROUP_RATIO<<8);
		SCB_AIRCR = Local_u32tempRegister;
	}
	return status;
}


void NVIC_voidDisableAllExternalInterrupt(void)
{
	asm("MOV R5,#1");
	asm("MSR PRIMASK, R5");
}


void NVIC_voidEnableAllExternalInterrupt(void)
{
	asm("MOV R5,#0");
	asm("MSR PRIMASK, R5");
}

void NVIC_voidDisableAllExceptions(void)
{
	asm("MOV R5,#1");
	asm("MSR FAULTMASK, R5");
}


void NVIC_voidEnableAllExceptions(void)
{
	asm("MOV R5,#0");
	asm("MSR FAULTMASK, R5");
}

void NVIC_voidSetBaseInterruptPriority(u8 NVIC_Priority)
{
	asm("LSLS R0, R0, #4");
	asm("MSR BASEPRI, R0");
}

void NVIC_voidClearBaseInterruptPriority(void)
{
	asm("MOV R5, #4");
	asm("MSR BASEPRI, R5");
}

extern void NVIC_voidEnableBusFaultException(void)
{
	NVIC_SHCSR |= NVIC_BUS_FAULT_ENABLE;
}
extern void NVIC_voidDisableBusFaultException(void)
{
	NVIC_SHCSR &= NVIC_BUS_FAULT_DISABLE;
}

extern void NVIC_voidEnableUsageFaultException(void)
{
		NVIC_SHCSR |= NVIC_USAGE_FAULT_ENABLE;
}
extern void NVIC_voidDisableUsageFaultException(void)
{
		NVIC_SHCSR &= NVIC_USAGE_FAULT_DISABLE;
}

extern void NVIC_voidEnableMemoryFaultException(void)
{
		NVIC_SHCSR |= NVIC_MEMORY_FAULT_ENABLE;

}
extern void NVIC_voidDisableMemoryFaultException(void)
{
	NVIC_SHCSR &= NVIC_MEMORY_FAULT_DISABLE;
}




extern ErrorStatus NVIC_errSoftWareInterruptEnable(u8 In_u8Peripheral)
{
	u8 status = NOK;
	if(In_u8Peripheral < NVIC_MAX_NUMBER_OF_Interrupts)
	{
		NVIC_STIR = In_u8Peripheral;
		status = OK;
	}
	return status;
}
