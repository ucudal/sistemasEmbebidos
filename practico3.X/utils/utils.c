#include "../mcc_generated_files/tmr2.h"
#include "../mcc_generated_files/pin_manager.h"
#include <string.h>
#include <stdio.h>
#include "../platform/HardwareProfile.h"
#include "utils.h"

void UT_delay(void) {
    int n = UT_DELAY_CYCLES;
    while (n > 0) {
        n--;
    }
} 

void UT_delayms_blocker(int periodo){
    uint16_t inicial = TMR2_SoftwareCounterGet();
    uint16_t final = inicial + periodo;
    
    /** 
     Si se cumple la condicion es porque final hizo overflow, por lo que su valor es menor que el actual del timer
     por lo que debo "quemar" los ciclos hasta el final primero, para luego contar hasta el final.
     * */
    if(final < inicial){
        while(TMR2_SoftwareCounterGet()< MAX_TMR_COUNT);
    }
    while(TMR2_SoftwareCounterGet()<final);
}

bool UT_delayms(ut_tmrDelay_t* p_timer, uint32_t p_ms){
    if (p_timer->state == UT_TMR_DELAY_INIT){
        p_timer->startValue = TMR2_SoftwareCounterGet();
        p_timer->state = UT_TMR_DELAY_WAIT;
        return false;
    }else {
        uint16_t final = p_timer->startValue + p_ms;
        // (final < p_timer->startValue && TMR2_SoftwareCounterGet()< MAX_TMR_COUNT )
        if(TMR2_SoftwareCounterGet() < final)  {
            return false;
        }
        return true;
    }
}

void task_ledA(){
    
    static ut_tmrDelay_t LedAtmrDelay;
    static UT_LED_STATE LedAState = UT_LED_ON;
    
    switch(LedAState){
        case UT_LED_ON:
            LEDA_SetHigh();    
            LedAtmrDelay.state = UT_TMR_DELAY_INIT;
            LedAState = UT_LED_ON_WAIT;
            break;
            
        case UT_LED_ON_WAIT:
            if(UT_delayms(&LedAtmrDelay, TIME_LEDA_ON)){                    
                LedAState = UT_LED_OFF;
            }
            break;
            
        case UT_LED_OFF:
            LEDA_SetLow();
            LedAtmrDelay.state = UT_TMR_DELAY_INIT;
            LedAState = UT_LED_OFF_WAIT;
            break;
            
        case UT_LED_OFF_WAIT:
            if(UT_delayms(&LedAtmrDelay, TIME_LEDA_OFF)){                    
                LedAState = UT_LED_ON;
            }
            break;
            
    }
}

void task_ledB(){
    
    static ut_tmrDelay_t LedBtmrDelay;
    static UT_LED_STATE LedBState = UT_LED_ON;
    
    switch(LedBState){
        case UT_LED_ON:
            LEDB_SetHigh(); 
            LedBtmrDelay.state = UT_TMR_DELAY_INIT;
            LedBState = UT_LED_ON_WAIT;
            break;
            
        case UT_LED_ON_WAIT:
            if(UT_delayms(&LedBtmrDelay, TIME_LEDA_ON)){                    
                LedBState = UT_LED_OFF;
            }
            break;
            
        case UT_LED_OFF:
            LEDB_SetLow();
            LedBtmrDelay.state = UT_TMR_DELAY_INIT;
            LedBState = UT_LED_OFF_WAIT;
            break;
            
        case UT_LED_OFF_WAIT:
            if(UT_delayms(&LedBtmrDelay, TIME_LEDA_OFF)){                    
                LedBState = UT_LED_ON;
            }
            break;
            
    }
}