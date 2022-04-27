/**
 Section: Included Files
 */
#include <stdio.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/clock.h"
#include "utils/utils.h"
#include "platform/HardwareProfile.h"
#include "platform/buttons.h"
#include "mcc_generated_files/tmr2.h"
/*
 Main application
 */
int main(void)
{
    int FLAGA = 0, FLAGB = 0, DELAY_TIME = 2000;
    // initialize the device
    SYSTEM_Initialize();
    
    BTN1_SetDigitalInput();
    BTN2_SetDigitalInput();
    LEDA_SetDigitalOutput();
    LEDB_SetDigitalOutput();
    BTN1_SetInterruptHandler(&BTN1_set);
    BTN2_SetInterruptHandler(&BTN2_set); 
    TMR2_Initialize();
    TMR2_Start();
    LEDA_SetLow();
    LEDB_SetLow();
    
    while(1){
        if( BTN1_get()){
           LEDA_SetHigh();
           UT_delayms(DELAY_TIME);
           LEDA_SetLow();
           BTN1_reset();
        }
        
        if( BTN2_get()){
           LEDB_SetHigh();
           UT_delayms(DELAY_TIME);
           LEDB_SetLow();
           BTN2_reset();
        }
    }
    return 1; 
}
/**
 * PARTE E
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
 
 if(BTN1_GetValue()){
 LEDA_SetHigh();
 }else {
 LEDA_SetLow();
 }
 
 if(BTN2_GetValue()){
 LEDB_SetHigh();
 }else {
 LEDB_SetLow();
 
 }
 }
 return 1; 
 }
 */

/**
 * PARTE F
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
 if(BTN1_GetValue()){
 FLAGA=1;
 }
 if(!BTN1_GetValue() && FLAGA){
 LEDA_Toggle();
 FLAGA=0;
 }
 if(BTN2_GetValue()){
 FLAGB=1;
 }
 if(!BTN2_GetValue() && FLAGB){
 LEDB_Toggle();
 FLAGB=0;
 } 
 }
 return 1; 
 }
 * 
 */


/****
 PARTE 2 E
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
 BTN1_SetInterruptHandler(BTN1_set);
 BTN2_SetInterruptHandler(BTN2_set); 
 LEDA_SetLow();
 LEDB_SetLow();
 
 
 while(1){
 
 if(!BTN1_GetValue() && BTN1_get()){
 LEDA_Toggle();
 BTN1_reset();
 }
 
 if(!BTN2_GetValue() && BTN2_get()){
 LEDB_Toggle();
 BTN2_reset();
 } 
 }
 return 1; 
 }
 
 */


/***
 
 PARTE 2 F 
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
 BTN1_SetInterruptHandler(&BTN1_set);
 BTN2_SetInterruptHandler(&BTN2_set); 
 LEDA_SetLow();
 LEDB_SetLow();
 
 
 while(1){
 
 if( BTN1_get()){
 LEDA_Toggle();
 BTN1_reset();
 }
 
 if(BTN2_get()){
 LEDB_Toggle();
 BTN2_reset();
 } 
 }
 return 1; 
 }
 
 */
