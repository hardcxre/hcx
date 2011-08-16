#ifndef hcx_value_h
#define hcx_value_h

#include "standard.h"

typedef unsigned char hcx_value_t;
#define HCX_VALUE_COUNT 256
#define HCX_VALUE_MAX 255

#define hcx_value_rand() (rand() % 256)

#endif
