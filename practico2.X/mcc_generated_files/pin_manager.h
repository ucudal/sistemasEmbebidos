#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>
#include <stdbool.h>

void PIN_MANAGER_Initialize (void);

void RB0_CallBack(void);

void RB1_CallBack(void);

void RB0_SetInterruptHandler(void (* InterruptHandler)(void));

void __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse RB0_SetInterruptHandler instead."))) RB0_SetIOCInterruptHandler(void *handler);


#define BTN2_SetHigh()          ( LATASET = (1 << 13) )

 
#define BTN2_SetLow()           ( LATACLR = (1 << 13) )

inline static void BTN2_SetValue(bool value)
{
  if(value)
  {
    BTN2_SetHigh();
  }
  else
  {
    BTN2_SetLow();
  }
}

#define BTN2_Toggle()           ( LATAINV = (1 << 13) )

#define BTN2_GetValue()         PORTAbits.RA13

#define BTN2_SetDigitalInput()   ( TRISASET = (1 << 13) )

#define BTN2_SetDigitalOutput()   ( TRISACLR = (1 << 13) )

#define BTN1_SetHigh()          ( LATBSET = (1 << 15) )

#define BTN1_SetLow()           ( LATBCLR = (1 << 15) )


inline static void BTN1_SetValue(bool value)
{
  if(value)
  {
    BTN1_SetHigh();
  }
  else
  {
    BTN1_SetLow();
  }
}

#define BTN1_Toggle()           ( LATBINV = (1 << 15) )

#define BTN1_GetValue()         PORTBbits.RB15

#define BTN1_SetDigitalInput()   ( TRISBSET = (1 << 15) )

#define BTN1_SetDigitalOutput()   ( TRISBCLR = (1 << 15) )

void PIN_MANAGER_Initialize (void);



void BTN2_CallBack(void);

/**
  @Summary
    Callback for BTN1 Pin.

  @Description
    This routine is callback for BTN1 Pin

  @Param
    None.

  @Returns
    None
 
 
  @Example 
    <code>
        BTN1_SetInterruptHandler(&BTN1_CallBack);
    </code>
*/
void BTN1_CallBack(void);


/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        BTN2_SetInterruptHandler(&BTN2_CallBack);
    </code>
*/
void BTN2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        BTN2_SetIOCInterruptHandler(&BTN2_CallBack);
    </code>
*/
void __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse BTN2_SetInterruptHandler instead."))) BTN2_SetIOCInterruptHandler(void *handler);

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        BTN1_SetInterruptHandler(&BTN1_CallBack);
    </code>
*/
void BTN1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        BTN1_SetIOCInterruptHandler(&BTN1_CallBack);
    </code>
*/
void __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse BTN1_SetInterruptHandler instead."))) BTN1_SetIOCInterruptHandler(void *handler);


#endif
