#ifndef CONFIG_H
#define CONFIG_H

// TRIG CONSTANTS
#define DEGREES_TO_RADIANS 0.017453292519943295769236907684886
#define RADIANS_TO_DEGREES 57.295779513082320876798154814105

// TSSP
#define TSSP_NUM 12
#define READ_NUM 100
#define PIN1 17
#define PIN2 14
#define PIN3 20
#define PIN4 2
#define PIN5 10
#define PIN6 9
#define PIN7 8
#define PIN8 3
#define PIN9 6
#define PIN10 21
#define PIN11 15
#define PIN12 18

// MACRO
#define ARRAYSHIFTDOWN(a, lower, upper){          \
    if (upper == (sizeof(a)/sizeof(a[0])) - 1){   \
        for(int q = upper - 1; q >= lower; q--) { \
			*(a + q + 1) = *(a + q); }            \
	    } else {                                  \
		    for(int q = upper; q >= lower; q--) { \
			    *(a + q + 1) = *(a + q); }}}

#endif // CONFIG_H