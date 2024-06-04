#include "ABW_IR_RING.h"

void IR_Ring::init() {
    IR_Sensors.init();
    My_Device.setSensorRGB_I(sensor_RGB);
}

void IR_Ring::update() {
    #if (DEBUG_TSSPS && !DEBUG_COMMS)
        IR_Sensors.update();
        Serial.print("Simple Direction: "); Serial.print(IR_Sensors.get_direction_simple());
        Serial.print("\tStrength: "); Serial.print(IR_Sensors.get_strength());
        Serial.print("\tAdvanced Direction: "); Serial.println(IR_Sensors.get_direction_advanced());
    #elif (DEBUG_COMMS && !DEBUG_TSSPS)
        My_Device.process();
    #else
        IR_Sensors.update();
        sensor_RGB[0] = IR_Sensors.get_direction_simple();
        sensor_RGB[1] = IR_Sensors.get_strength();
        sensor_RGB[2] = IR_Sensors.get_direction_advanced();
        My_Device.process();
    #endif
    #if (DEBUG)
        if(My_Device.isConnected()) {
            Serial.print("Connected to SPIKE\t");
            Serial.print("Simple Direction: "); Serial.print(IR_Sensors.get_direction_simple());
            Serial.print("\tStrength: "); Serial.print(IR_Sensors.get_strength());
            Serial.print("\tAdvanced Direction: "); Serial.println(IR_Sensors.get_direction_advanced());
        } else {
            Serial.print("Not connected to SPIKE\t");
        } 
    #endif
}

uint16_t IR_Ring::get_direction_advanced() {
    return IR_Sensors.get_direction_advanced();
}

uint8_t IR_Ring::get_direction_simple() {
    return IR_Sensors.get_direction_simple();
}

uint8_t IR_Ring::get_strength() {
    return IR_Sensors.get_strength();
}