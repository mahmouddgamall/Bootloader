/**************************************************** 
 	 Author: Mahmoud Gamal
 	 Version: 1.0
************************************************/
#ifndef FLASH_H
#define FLASH_H

#define FLASH_LOCKED				6

void FLASH_unlockRegisters(void);
void FLASH_lockRegisters(void);

ErrorStatus FLASH_eraseSection(u16* startAddress);
void FLASH_eraseFlash(void);

ErrorStatus FLASH_writeHalfWord(u16* destinationAddress, u16* sourceAddress);
ErrorStatus FLASH_writeData(u16* destinationAddress, u16* sourceAddress, u16 size);
ErrorStatus FLASH_writeDataStaticSource(u16* destinationAddress, u16* sourceAddress, u16 size);



#endif
