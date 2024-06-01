#include <Arduino.h>
#include <ABW_IR_RING.h>

IR_Ring ring;

void setup() {
    ring.init();
}

void loop() {
    ring.update();
}