

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/clock.h"
#include "utils/utils.h"

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    BTN1_SetDigitalInput();
    BTN2_SetDigitalInput();
    LEDA_SetDigitalOutput();
    LEDB_SetDigitalOutput();
    LEDA_SetLow();
    LEDB_SetLow();
    while(1){
          
        if(BTN1_GetValue()){
            LEDA_SetHigh();
            UT_delay();
        }
        if(BTN2_GetValue()){
            LEDB_SetHigh();
            UT_delay();
             
        }
    }
    return 1; 
}

/**
 * PARTE 1 E
 * 
 * 
int main(void)
{
    int FLAGA = 0, FLAGB = 0;
    // initialize the device
    SYSTEM_Initialize();
    BTN1_SetDigitalInput();
    BTN2_SetDigitalInput();
    LEDA_SetDigitalOutput();
    LEDB_SetDigitalOutput();
    LEDA_SetLow();
    LEDB_SetLow();
    
    while(1){

            if(BTN1_GetValue()==1){
                LEDA_SetHigh();
            }else {
                 LEDA_SetLow();
            }

            if(BTN2_GetValue()==1){
                LEDB_SetHigh();
            }else {
                LEDB_SetLow();
               
            }
    }
    return 1; 
}
 */
  
/**
 * PARTE 1 F
 * 
 *
 int main(void)
{
    int FLAGA = 0, FLAGB = 0;
    // initialize the device
    SYSTEM_Initialize();
    BTN1_SetDigitalInput();
    BTN2_SetDigitalInput();
    LEDA_SetDigitalOutput();
    LEDB_SetDigitalOutput();
    LEDA_SetLow();
    LEDB_SetLow();
    
    while(1){

            if(BTN1_GetValue() && FLAGA==0){
                FLAGA=1;
            }
            if(BTN1_GetValue()== 0 && FLAGA== 1){
                LEDA_Toggle();
                FLAGA=0;
            }

            if(BTN2_GetValue() && FLAGB==0){
                 FLAGB=1;
            }
            if(BTN2_GetValue()==0 && FLAGB==1){
                LEDB_Toggle();
                 FLAGB=0;
            }
    }
    return 1; 
}
 * 
*/

