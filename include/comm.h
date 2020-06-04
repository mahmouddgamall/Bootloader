#ifndef COMM_H
#define COMM_H

#define COM_PORT_NAME "\\\\.\\COM9"


void MAIN_initComm(void);
void MAIN_sendComm(char * buffer, u16 size);
void MAIN_readComm(char * buffer);


#endif