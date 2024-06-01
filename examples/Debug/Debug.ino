#include <Arduino.h>
#include <ABW_IR_RING.h>

IR_Ring ring;

void setup() {
    Serial.begin(9600);
    ring.init();
}

void loop() {
    ring.update();
    Serial.print("Simple Direction: "); Serial.print(ring.get_direction_simple());
    Serial.print("\tStrength: "); Serial.print(ring.get_strength());
    Serial.print("\tAdvanced Direction: "); Serial.println(ring.get_direction_advanced());
}