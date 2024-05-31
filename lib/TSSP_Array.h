#ifndef TSSP_ARRAY_H
#define TSSP_ARRAY_H

#include "Arduino.h"
#include <Config.h>

class TSSP_Array {
public:
    TSSP_Array() {}
    void init();
    void update();
    uint8_t get_direction_advanced();
    uint8_t get_direction_simple();
    uint8_t get_strength();
private:
    uint8_t direction_advanced;
    uint8_t direction_simple;
    uint8_t strength;
    uint8_t pins[TSSP_NUM] = {PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7, PIN8, PIN9, PIN10, PIN11, PIN12};
    uint8_t values[TSSP_NUM] = {0};
    uint8_t sorted_values[TSSP_NUM] = {0};
    uint8_t indexes[TSSP_NUM] = {0};
    float x_values[TSSP_NUM] = {0};
    float y_values[TSSP_NUM] = {0};
};

#endif // TSSP_ARRAY_H