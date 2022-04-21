#include "buttons.h"

static bool boton1;
static bool boton2;

void BTN1_set() {
    boton1 = true;
}

void BTN1_reset(){
    boton1 = false;
}

bool BTN1_get(){
    return boton1;
}

void BTN2_set(){
    boton2 = true;
}
void BTN2_reset(){
    boton2 = false;
}

bool BTN2_get(){
 return boton2;
}