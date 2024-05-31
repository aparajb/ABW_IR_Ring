#include "ABW_IR_RING.h"

IR_Ring::init() {
    IR_Sensors.init();
    My_Device.setSensorRGB_I(sensorRGB);
}

IR_Ring::update() {
    IR_Sensors.update();
    sensorRGB[0] = IR_Sensors.get_direction_simple();
    sensorRGB[1] = IR_Sensors.get_strength();
    sensorRGB[2] = IR_Sensors.get_direction_advanced();
    My_Device.process();
}

uint8_t IR_Ring::get_direction_advanced() {
    return IR_Sensors.get_direction_advanced();
}

uint8_t IR_Ring::get_direction_simple() {
    return IR_Sensors.get_direction_simple();
}

uint8_t IR_Ring::get_strength() {
    return IR_Sensors.get_strength();
}