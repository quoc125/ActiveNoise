#ifndef ATMEL_START_H_INCLUDED
#define ATMEL_START_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "driver_init.h"
#include <math.h>

#define MAXSAMPLE  100
#define PHI M_PI /4

/**
 * Initializes MCU, drivers and middleware in the project
**/
void atmel_start_init(void);

#ifdef __cplusplus
}
#endif
#endif
