#include <stdint.h>
#define UT_DELAY_CYCLES 500000
#define MAX_TMR_COUNT 65535
#define TIME_LEDA_ON 400
#define TIME_LEDA_OFF 800

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

typedef struct
{
    uint32_t startValue;
    UT_TMR_DELAY_STATE state;
}ut_tmrDelay_t;

void UT_delay(void);
void task_ledA();
void task_ledB();
void UT_delayms_blocker(int periodo);
bool UT_delayms(ut_tmrDelay_t* p_timer, uint32_t p_ms);