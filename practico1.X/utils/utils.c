#include "utils.h"

int global_data;

void UT_delay(void) {
    int n = UT_DELAY_CYCLES;
    while (n > 0) {
        n--;
    }
}
