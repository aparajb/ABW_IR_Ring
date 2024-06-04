#include <Arduino.h>
#include <ABW_IR_RING.h>

IR_Ring ring;

void setup() {
    Serial.begin(9600);
    ring.init();
}

void loop() {
    ring.update();
}