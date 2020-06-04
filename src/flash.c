/**************************************************** 
 	 Author: Mahmoud Gamal
 	 Version: 1.0
 ************************************************/
#include "std_types.h"
#include "flash.h"


#define	FLASH_KEY1					0x45670123
#define	FLASH_KEY2					0xCDEF89AB
#define	FLASH_ERASE_VALUE			0xFFFF

#define FLASH_SR_BSY_FLAG			0x00000001

#define	FLASH_CR_LOCK				0x00000080
#define	FLASH_CR_ENABLE_PROGRAM		0x00000001
#define FLASH_CR_DISABLE_PROGRAM	0xFFFFFFFE
#define	FLASH_CR_ENABLE_ERASE_PAGE	0x00000002
#define FLASH_CR_DISABLE_ERASE_PAGE	0xFFFFFFFD
#define	FLASH_CR_ENABLE_ERASE_FLASH	0x00000003
#define FLASH_CR_START_BIT			0x00000040

#define FLASH_START_ADDRESS (u32*)0x08000000
#define FLASH_END_ADDRESS	(u32*)0x08010000

#define RAM_START_ADDRESS   (u32*)0x20000000
#define RAM_END_ADDRESS 	(u32*)0x20005000



#define ISVALID_DESTINATION_ADDRESS(Address) ((Address >= FLASH_START_ADDRESS) && (Address <= FLASH_END_ADDRESS))
#define ISVALID_SOURCE_ADDRESS(sourceAddress) (((sourceAddress >= FLASH_START_ADDRESS) && (sourceAddress <= FLASH_END_ADDRESS))|| ((sourceAddress >= RAM_START_ADDRESS) && (sourceAddress <= RAM_END_ADDRESS)))




typedef struct 
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 AR;
	u32 reserved;
	u32 OBR;
	u32 WRPR;
}FLASH_t;


volatile FLASH_t * FLASH = (volatile  FLASH_t *)0x40022000;

void FLASH_unlockRegisters(void)
{
	if((FLASH->CR & FLASH_CR_LOCK))
	{
		FLASH->KEYR = FLASH_KEY1;
		FLASH->KEYR = FLASH_KEY2;
	}
}
void FLASH_lockRegisters(void)
{
	if((FLASH->CR & FLASH_CR_LOCK) == 0)
	{
		FLASH->CR |= FLASH_CR_LOCK;
	}
}

ErrorStatus FLASH_eraseSection(u16* startAddress)
{
	u8 state;
	if((FLASH->CR & FLASH_CR_LOCK) == 0)
	{
		FLASH->CR |= FLASH_CR_ENABLE_ERASE_PAGE;
		FLASH->AR = (u32)startAddress;
		FLASH->CR |= FLASH_CR_START_BIT;
		while(FLASH->SR & FLASH_SR_BSY_FLAG);
		if(*startAddress == FLASH_ERASE_VALUE)
		{
			state = OK;
		}
		else
		{
			state = NOK;
		}
		FLASH->CR &= FLASH_CR_DISABLE_ERASE_PAGE;

	}
	else
	{
		state = FLASH_LOCKED;
	}
	return state;

}
void FLASH_eraseFlash(void)
{
	if((FLASH->CR & FLASH_CR_LOCK) == 0)
	{
		FLASH->CR |= FLASH_CR_ENABLE_ERASE_FLASH;
		FLASH->CR |= FLASH_CR_START_BIT;
	}
}



ErrorStatus FLASH_writeHalfWord(u16* destinationAddress, u16* sourceAddress)
{
	u8 state = OK;
	if((FLASH->CR & FLASH_CR_LOCK) == 0)
	{
		if(ISVALID_DESTINATION_ADDRESS(destinationAddress) && ISVALID_SOURCE_ADDRESS(sourceAddress))
		{

			if((*destinationAddress) == FLASH_ERASE_VALUE)
			{

				FLASH->CR |= FLASH_CR_ENABLE_PROGRAM;
				*destinationAddress = (u16)(*sourceAddress);

				while(FLASH->SR & FLASH_SR_BSY_FLAG);
				if((u16)*destinationAddress == (u16)*sourceAddress)
				{
					state = OK;
				}
				else
				{
					state = NOK;
				}
			}

			else
			{
				state = NOK;
			}

		}
		else
		{
			state = INVALID_INPUT;
		}
		FLASH->CR &= FLASH_CR_DISABLE_PROGRAM;
	}
	else
	{
		state = FLASH_LOCKED;
	}
	return state;
}

ErrorStatus FLASH_writeData(u16* destinationAddress, u16* sourceAddress, u16 size)
{
	u8 state = OK;

	for(u16 i = 0; i < size ; i ++)
	{
		state |= FLASH_writeHalfWord(destinationAddress+i,sourceAddress+i);
	}

	return state;
}
ErrorStatus FLASH_writeDataStaticSource(u16* destinationAddress, u16* sourceAddress, u16 size)
{
	u8 state = OK;

	for(u16 i = 0; i < size ; i ++)
	{
		state |= FLASH_writeHalfWord(destinationAddress+i,sourceAddress);
	}

	return state;
}
