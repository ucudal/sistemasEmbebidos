#include <stdint.h>

#define UT_DELAY_CYCLES 500000
#define MAX_TMR_COUNT 65535
#define TIME_LEDA_ON 400
#define TIME_LEDA_OFF 800

void UT_delay(void);
void task_1_ledA();
void task_2_ledB();
typedef struct
{
    uint32_t startValue;
    UT_TMR_DELAY_STATE state;
}ut_tmrDelay_t;


typedef enum {
    UT_LED_ON,
            UT_LED_ON_WAIT,
            UT_LED_OFF,
            UT_LED_OFF_WAIT
}UT_LED_STATE;

typedef enum
{
    UT_TMR_DELAY_INIT,
            UT_TMR_DELAY_WAIT
}UT_TMR_DELAY_STATE;

