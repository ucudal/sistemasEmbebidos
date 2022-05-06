/**
 Generated main.c file from MPLAB Code Configurator
 
 @Company
 Microchip Technology Inc.
 
 @File Name
 main.c
 
 @Summary
 This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.
 
 @Description
 This source file provides main entry point for system initialization and application code development.
 Generation Information :
 Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
 Device            :  PIC32MM0256GPM064
 The generated drivers are tested against the following:
 Compiler          :  XC16 v1.70
 MPLAB 	          :  MPLAB X v5.50
 */

/*
 (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
 software and any derivatives exclusively with Microchip products.
 
 THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
 WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
 
 IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 
 MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
 TERMS.
 */

/**
 Section: Included Files
 */
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/usb/usb_device_cdc.h"
#include "utils/utils.h"
/*
 Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        task_1_ledA();
        task_2_ledB();
        //Keep trying to send data to the PC as required
        CDCTxService();
        
        // USBDeviceTasks();
        if(!((USBGetDeviceState() < CONFIGURED_STATE) ||
                (USBIsDeviceSuspended() == true)))
        {
            
             int numBytes;
             uint8_t buffer[64]; 
             /**
             if(USBUSARTIsTxTrfReady())
             {
             numBytes = getsUSBUSART(buffer,sizeof(buffer)); //until the buffer is free.
             
             if(numBytes > 0){
             putsUSBUSART(numBytes);
             }
             
             }
             */
            
            numBytes = getsUSBUSART(buffer,sizeof(buffer)); //until the buffer is free.
            
            if(numBytes > 0){                       
                
                
                //result[0] = 0;
               // TASK_parseCommand(buffer, result);
                putUSBUSART(buffer, numBytes);
            }            
        }
        
        
        
        
        
        
        
        
        
    }
    return 1; 
}
/**
 End of File
 */

