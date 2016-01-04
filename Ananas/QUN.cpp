/*���ɷַ�,mylife1213@gmail.com*/

#include "Arduino.h"
#include "QUN.h"


void (*gao)();


void QUN::attachInterrupt(void (*f)(),unsigned char bytes)
  {
    
    PORTD|=_BV(PORTD7);
    gao=f;
    DIDR1|=_BV(AIN1D)|_BV(AIN0D);
    ACSR=0;
    ACSR|=_BV(ACIE)|_BV(ACBG)|bytes; 
    SREG|=(1<<7); 
    
   
    }

ISR(ANALOG_COMP_vect) 
{
  (*gao)();
}
   


