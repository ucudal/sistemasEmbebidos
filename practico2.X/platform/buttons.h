#ifndef BUTTONS_H    /* Guard against multiple inclusion */
#define BUTTONS_H


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
    
    void BTN1_set(void);
    void BTN1_reset(void);
    bool BTN1_get(void);
    
    void BTN2_set(void);
    void BTN2_reset(void);
    bool BTN2_get(void);
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif 
