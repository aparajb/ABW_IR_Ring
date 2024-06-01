#include "ABW_IR_RING.h"

IR_Ring::IR_Ring() {
    My_Device = Colour_Sensor();
    IR_Sensors = TSSP_Array();  
}

void IR_Ring::init() {
    IR_Sensors.init();
    My_Device.setSensorRGB_I(sensor_RGB);
}

void IR_Ring::update() {
    IR_Sensors.update();
    sensor_RGB[0] = IR_Sensors.get_direction_simple();
    sensor_RGB[1] = IR_Sensors.get_strength();
    sensor_RGB[2] = IR_Sensors.get_direction_advanced();
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