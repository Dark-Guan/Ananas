/*自由分发,mylife1213@gmail.com*/

#ifndef QUN_h 
#define QUN_h

#include "Arduino.h"
#include <avr/interrupt.h>


extern void (*gao)();

#define M_CHANGE 0
#define M_RISING 2
#define M_FALLING 3

class QUN
{
  public:        

      void attachInterrupt(void (*f)(),unsigned char bytes);
      
     
  private:        

         


};

#endif