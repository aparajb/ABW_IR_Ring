/*!
 *  @file ABW_IR_RING.h
 *
 *  This is a library for the Advanced Botworks IR Ring.
 *
 *  Designed specifically to work with the LEGO Spike Prime platform.
 *
 *
 *  These sensors use Serial to communicate, the LEGO Spike Prime connectors are required to interface.
 *
 *
 *  A.Bogahawatta (Advanced Botworks)
 *
 *  GNU General Public License v3
 */
#ifndef ABW_IR_RING_H
#define ABW_IR_RING_H

#include <TSSP_Array.h>
#include <Colour_Sensor.h>

class IR_Ring {
public:
    // Main Functions
    IR_Ring() {}
    void init();
    void update();

    // Debug Functions
    uint8_t get_direction_advanced();
    uint8_t get_direction_simple();
    uint8_t get_strength();
    
private:
    uint16_t sensor_RGB[4];
    ColorSensor My_Device;
    TSSP_Array IR_Sensors;  
};

#endif // ABW_IR_RING_H
