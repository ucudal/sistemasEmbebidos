
#ifndef _HARDWARE_PROFILE_H    /* Guard against multiple inclusion */
#define _HARDWARE_PROFILE_H


#ifdef __cplusplus
extern "C" {
#endif


#define EXAMPLE_CONSTANT 0
#define LEDA_SetDigitalOutput() (TRISAbits.TRISA7 = 0)
#define LEDB_SetDigitalOutput() (TRISBbits.TRISB14 = 0)

    
#define LEDA_SetLow() (LATAbits.LATA7 = 0)
#define LEDA_SetHigh() (LATAbits.LATA7 = 1)
#define LEDB_SetLow() (LATBbits.LATB14 = 0)
#define LEDB_SetHigh() (LATBbits.LATB14 = 1)
#define LEDA_Toggle() (LATAbits.LATA7 = LATAbits.LATA7 ^ 1)
#define LEDB_Toggle() (LATBbits.LATB14 = LATBbits.LATB14 ^ 1)
#include <stdbool.h>

int ExampleFunction(int param1, int param2);


#ifdef __cplusplus
}
#endif

#endif 
