#include "utils.h"
#include "../mcc_generated_files/tmr2.h"

void UT_delay(void) {
    int n = UT_DELAY_CYCLES;
    while (n > 0) {
        n--;
    }
} 

void contarMili(){
}


void UT_delayms(int periodo){
    int final = TMR2_SoftwareCounterGet() + periodo;
    int max = 65535;
    
    if(final> max){
        final = max - final;
    }
    while(TMR2_SoftwareCounterGet()<final){
        Nop();
    }
    
}