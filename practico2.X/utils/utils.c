#include "utils.h"
#include "../mcc_generated_files/tmr2.h"

void UT_delay(void) {
    int n = UT_DELAY_CYCLES;
    while (n > 0) {
        n--;
    }
} 

void UT_delayms(int periodo){
    uint16_t inicial = TMR2_SoftwareCounterGet();
    uint16_t final = inicial + periodo;
    
    //Si se cumple la condicion es porque final hizo overflow, por lo que su valor es menor que el actual del timer
    // por lo que debo "quemar" los ciclos hasta el final primero, para luego contar hasta el final.
    if(final< inicial){
        while(TMR2_SoftwareCounterGet()< MAX_TMR_COUNT);
    }
    while(TMR2_SoftwareCounterGet()<final);
}
