/**
 Section: Included Files
 */
#include <stdio.h>
#include <string.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/clock.h"
#include "utils/utils.h"
#include "platform/HardwareProfile.h"
#include "platform/buttons.h"
#include "mcc_generated_files/tmr2.h"
#include "mcc_generated_files/usb/usb_device_cdc.h"
/*
 Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    while(1){
        
        CDCTxService();
        
        // USBDeviceTasks();
        if(!((USBGetDeviceState() < CONFIGURED_STATE) ||
                (USBIsDeviceSuspended() == true)))
        {
            int numBytes;
            char buffer[64]; 
            numBytes = getsUSBUSART(buffer,sizeof(buffer));
            
            if(numBytes > 0){
                if ((buffer[0] == '\r')) //Received ENTER End of Command
                {
                    putsUSBUSART("Echo");
                }  
            }
        }
    }
}


/*****
 * 
 * 
 PRIMERA PARTE 
 ejercicio 1
 * 
 
 * int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    while(1){
        
        CDCTxService();
        
        // USBDeviceTasks();
        if(!((USBGetDeviceState() < CONFIGURED_STATE) ||
                (USBIsDeviceSuspended() == true)))
        {
            int numBytes;
            char buffer[64]; 
            numBytes = getsUSBUSART(buffer,sizeof(buffer));
            
            if(numBytes > 0){
                if ((buffer[0] == '\r')) //Received ENTER End of Command
                {
                    putsUSBUSART("Echo");
                }  
            }
        }
    }
}
 
 * 
 * 
 *
 ejercicio 2 
 
 int main(void)
 {
    // initialize the device
    SYSTEM_Initialize();

    LEDA_SetDigitalOutput();
    LEDB_SetDigitalOutput();
    LEDA_SetLow();
    LEDB_SetLow();
    TMR2_Start();

    while (1)
    {
        task_ledA();
        UT_delayms_bloqueante(200);
        task_ledB();
    }
    return 1; 
 }
 
 */