/**************************************************** 
 	 Author: Mahmoud Gamal
 	 Version: 1.0
************************************************/
#ifndef BL_COM_INTERFACE_H
#define BL_COM_INTERFACE_H

#define		MARKER_NO_APP	0xCCCC
#define		MARKER_APP1		0xAAAA

typedef struct __attribute__((packed))
{
	u8 req_counter;
	u8 cmd;
}BL_comm_header_t;



typedef struct __attribute__((packed))
{

	u32 baseAddress;
	u16 fileSize;
	BL_comm_header_t BL_comm_header;
}new_app_t;


void BLcomm_handler(void);

#endif
