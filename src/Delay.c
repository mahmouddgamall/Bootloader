
#include "std_types.h"
#include "Delay.h"
#define T1 (0.00539875f)
#define TM (0.634125f)
/*loop time (T1)=5.39875 us*/
/*calculation time (T2)=627.875 us*/
/*context switching time (T3)=3.995 us*/
/*context switching time (T4)=2.255 us*/
void Delay_ms(u32 Val)
{
  u32 i;
u32 count =   (u32)((float)Val-TM)/T1;
for (i=0;i<count;i++)
{
  asm("NOP");
}
}
