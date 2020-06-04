#ifndef NVIC_CONFIGA_H
#define NVIC_CONFIGA_H



/*
 * for STM32F10 you can use those
NVIC_GROUPS_16_SUBGROUPS_0 
NVIC_GROUPS_8_SUBGROUPS_2  
NVIC_GROUPS_4_SUBGROUPS_4  
NVIC_GROUPS_2_SUBGROUPS_8  
NVIC_GROUPS_0_SUBGROUPS_16 
else, check the data sheet for the proper numbers, or the code will not function properly and might go into a hard fault
*/
#define		NVIC_GROUP_SUBGROUP_RATIO			NVIC_GROUPS_4_SUBGROUPS_4
#define		NVIC_START_SUBGROUP_BIT				(u8)4

#endif
