#include "TSSP_Array.h"

void TSSP_Array::init() {
    for(uint8_t i = 0; i < TSSP_NUM; i++) {
        pinMode(pins[i], INPUT);
        x_values[i] = cosf(RADIANS_TO_DEGREES * (450.0f - i * 30.0f));
        y_values[i] = sinf(RADIANS_TO_DEGREES * (450.0f - i * 30.0f));
	  }
}

void TSSP_Array::update() {
	for(uint8_t i = 0; i < READ_NUM; i++) {
		for(uint8_t j = 0; j < TSSP_NUM; j++) {
		    values[j] += 1 - digitalRead(pins[j]);
	    }
	}
	for(uint8_t i = 0; i < TSSP_NUM; i++) {
		sorted_values[i] = 0;
	}
    for(uint8_t i = 0; i < TSSP_NUM; i++) {
        for(uint8_t j = 0; j < TSSP_NUM; j++) {
            if(values[i] > sorted_values[j]) {
                if(j <= i) {
                    ARRAYSHIFTDOWN(sorted_values, j, i);
                    ARRAYSHIFTDOWN(indexes, j, i);
                }
                sorted_values[j] = values[i];
                indexes[j] = i;
                break;
            }
		}
	}
    strength = sorted_values[0];
    direction_simple = (strength == 0) ? 0 : indexes[0] + 1;
    direction_advanced = 0;

    // ballStr = ((3 * tsspSortedValues[0]) + (2 * tsspSortedValues[1]) + tsspSortedValues[2] + tsspSortedValues[3]) / 7;
    // ballVisible = (ballStr != 0);
    // float x = ((tsspSortedValues[0] * tsspXValues[tsspIndexes[0]]) + (tsspSortedValues[1] * tsspXValues[tsspIndexes[1]]) + (tsspSortedValues[2] * tsspXValues[tsspIndexes[2]]) + (tsspSortedValues[3] * tsspXValues[tsspIndexes[3]])) / 4;
    // float y = ((tsspSortedValues[0] * tsspYValues[tsspIndexes[0]]) + (tsspSortedValues[1] * tsspYValues[tsspIndexes[1]]) + (tsspSortedValues[2] * tsspYValues[tsspIndexes[2]]) + (tsspSortedValues[3] * tsspYValues[tsspIndexes[3]])) / 4;
    // ballDir = ballVisible ? 450 - RADIANS_TO_DEGREES * atan2f(y, x) : -1;
    // ballDir = ballDir > 360 ? ballDir - 360 : ballDir;

    // ballStr = tsspSortedValues[0];
    // ballDir = ballVisible ? tsspIndexes[0] * 30 : -1;

	for(uint8_t i = 0; i < TSSP_NUM; i++) {
		values[i] = 0;
		sorted_values[i] = 0;
		indexes[i] = 0;
	}
}


uint8_t TSSP_Array::get_direction_advanced() {
    return direction_advanced;
}

uint8_t TSSP_Array::get_direction_simple() {
    return direction_simple;
}

uint8_t TSSP_Array::get_strength() {
    return strength;
}